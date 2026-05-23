/* 
---------- Scriptureware ----------
Version  0.1.0 (alpha)
Authors: David Hokuf and Benjamin Van Grouw
Date: May 2026 
*/

#pragma once

#include <vector>
#include <string>
using namespace std;

struct Reference {

    string book;
    int chapter;
    int verse;
};

class Verse {

    public:
        Verse(Reference reference);
        int checkAccuracy(vector<string> attempt);
        bool obscure();
        vector<string> getVerse();
        Reference getReference();
        vector<string> getObscuredVerse();
        Verse& operator++();
        bool endOfBookReached();

    private:
        vector<string> loadVerse(Reference reference);
        Reference reference;
        vector<string> text;
        vector<string> obscuredText;
        vector<bool> obscurityMask;


};