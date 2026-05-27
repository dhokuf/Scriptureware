/* 
---------- Scriptureware ----------
Version  0.1.0 (alpha)
Authors: David Hokuf and Benjamin Van Grouw
Date: May 2026 
*/

// Comment this line out to disable development mode and remove debug output
/**/ #define _DEVELOPMENT_MODE */

#ifdef _DEVELOPMENT_MODE
    #include <iostream>
    #define log(x) std::cout << "[DEBUG] " << x << std::endl
#else
    #define log(x)
#endif

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
    text = loadVerse(reference);
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

vector<string> Verse::loadVerse(Reference reference) {
    
    vector<string> verse;
    verse.push_back("Peter, an apostle of Jesus Christ, to the strangers scattered throughout Pontus, Galatia, Cappadocia, Asia, and Bithynia,");
    return verse;

}