/* 
---------- Scriptureware ----------
Version  0.1.0 (alpha)
Authors: David Hokuf and Benjamin Van Grouw
Date: May 2026 
*/

// Comment this line out to disable development mode and remove debug output
/**/ #define _DEVELOPMENT_MODE */

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "verse.hpp"
#include "ui.hpp"

vector<string>* loadIndex() {

    vector<string>* index = new vector<string>;
    index->reserve(100);
    ifstream indexFile("../Texts/index");
    string line;
    string bookTitle;

    while (getline(indexFile, line)) {
        istringstream currLine(line);
        // Consume the file name
        currLine >> bookTitle;
        // Get the rest of the line
        getline(currLine, bookTitle);
        index->push_back(bookTitle);
    }

    indexFile.close();
    return index;
}

Verse::Verse(Reference reference) {

    this->reference = reference;
    text = loadVerse();
    obscuredText = text;
    obscurityMask = vector<bool>(obscuredText.size(), false);

}

int Verse::checkAccuracy(vector<string> attempt) {
    string entered, correct;
    for (string curr : attempt) entered += curr;
    for (string curr : text) correct += curr;
    log(entered);
    log(correct);
    if (attempt == text) return 100;
    return 0;

}

bool Verse::obscure() {

    bool selected = false;
    int index;
    int obscured = true;

    for (bool i : obscurityMask) {
        if (!i) {
            obscured = false; 
        }
    }

    if (obscured) return true;

    srand(time(0));
    while (!selected) {
        index = rand() % (obscurityMask.size());
        if (!obscurityMask.at(index)) {
            obscurityMask.at(index) = true;
            selected = true;
        }
    }

    string input = obscuredText.at(index);
    string output;
    for (int i = 0; i < input.length(); i++) output += "X";
    obscuredText[index] = output;
    return false;

}

Reference Verse::getReference() {

    return reference;

}

vector<string> Verse::getObscuredVerse() {

    return vector<string>();

}

Verse& Verse::operator++() {

    reference.verse += 1;
    if (endOfChapterReached()) {
        reference.chapter += 1;
        reference.verse = 0;
    }

    text = obscuredText = loadVerse();
    obscurityMask = vector<bool>(obscuredText.size(), false);

    return *this;

}

string Verse::prettyPrint() {

    string returnVal;
    for (string currWord : text) {
        returnVal += currWord += " ";
    }
    return returnVal;
}

string Verse::prettyPrintObscured() {

    string returnVal;
    for (string currWord : obscuredText) {
        returnVal += currWord += " ";
    }
    return returnVal;
}

bool Verse::endOfBookReached() {

    if (!endOfChapterReached()) return false;
    Reference tempRef = reference;
    tempRef.chapter += 1;
    tempRef.verse = 0;
    Verse tempVerse(tempRef);
    if (tempVerse.loadVerse().empty()) return true;
    return false;

}

bool Verse::endOfChapterReached() {

    if (loadVerse().empty()) return true;
    return false;
}

vector<string> Verse::loadVerse() {

    vector<string> returnVerse;
    string textFolder = TEXTFOLDER;
    ifstream index(textFolder + "index");
    string bookIndex;
    for (int i = 0; i <= reference.book; i++) {
        getline(index, bookIndex);
    }
    istringstream line(bookIndex);
    string fileName;
    line >> fileName;
    ifstream book(textFolder + fileName);
    string token;
    int currChapter;
    while (book >> token) {
        if (token == "CHAPTER") {
            book >> currChapter;
            if (currChapter == reference.chapter) break;
        }
    }
    book.ignore(); // Go to the end of the line
    string currLine;
    int verseIndex;
    while (getline(book, currLine)) {
        istringstream verse(currLine);
        verse >> verseIndex;
        if (verseIndex == reference.verse) {
            string currWord;
            while (verse >> currWord) {
                returnVerse.push_back(currWord);
            }
            break;
        }
    }
    return returnVerse;

}