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

#include "verse.hpp"
#include "ui.hpp"

vector<string>* loadIndex() {

    vector<string>* index = new vector<string>;
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
    if (attempt == text) return 100;
    return 0;

}

bool Verse::obscure() {

    return true;

}

Reference Verse::getReference() {

    return reference;

}

vector<string> Verse::getObscuredVerse() {

    return vector<string>();

}

Verse& Verse::operator++() {

    return *(new Verse(reference));

}

bool Verse::endOfBookReached() {
    
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
            log(currChapter);
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
            verse >> currWord;
            while (currWord != "\n") {
                returnVerse.push_back(currWord);
                verse >> currWord;
            }
        }
    }
    return returnVerse;

}