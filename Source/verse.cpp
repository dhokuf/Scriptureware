/* 
---------- Scriptureware ----------
Version  0.1.0 (alpha)
Authors: David Hokuf and Benjamin Van Grouw
Date: May 2026 
*/

#include "verse.hpp"
#include "ui.hpp"

vector<string>* loadIndex() {
    vector<string>* index = new vector<string>;
    index->push_back("1 Peter");
    index->push_back("Matthew");
    index->push_back("Mark");
    index->push_back("Luke");
    index->push_back("3 John");
    index->push_back("Jude");
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