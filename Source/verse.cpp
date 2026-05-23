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
    index->push_back("Fake test data");
    index->push_back("Fake test data");
    index->push_back("Fake test data");
    index->push_back("Fake test data");
    index->push_back("Fake test data");
    return index;
}

Verse::Verse(Reference reference) {

    this->reference = reference;
    text = loadVerse(reference);
    obscuredText = text;
    obscurityMask = vector<bool>(obscuredText.size(), false);

}

int Verse::checkAccuracy(vector<string> attempt) {

    return 100;

}

bool Verse::obscure() {

    return true;

}

vector<string> Verse::getVerse() {

    return vector<string>();

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
    
    return vector<string>();

}