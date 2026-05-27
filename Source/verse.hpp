/* 
---------- Scriptureware ----------
Version  0.1.0 (alpha)
Authors: David Hokuf and Benjamin Van Grouw
Date: May 2026 
*/

#pragma once

#ifdef _DEVELOPMENT_MODE
    #include <iostream>
    #define log(x) std::cout << "[DEBUG] " << x << std::endl
#else
    #define log(x)
#endif

#include <vector>
#include <string>
using namespace std;

#define TEXTFOLDER "../Texts/"

struct Reference {

    int book;
    int chapter;
    int verse;
};

vector<string>* loadIndex();

class Verse {

    public:
        Verse(Reference reference);
        int checkAccuracy(vector<string> attempt);
        bool obscure();
        vector<string> getVerse() { return text; }
        Reference getReference();
        vector<string> getObscuredVerse();
        Verse& operator++();
        bool endOfBookReached();
        vector<string> loadVerse();

    private:
        
        Reference reference;
        vector<string> text;
        vector<string> obscuredText;
        vector<bool> obscurityMask;


};