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

class Verse {

    public:
        Verse(vector<int> reference);
        int checkAccuracy(string attempt);
        bool obscure();
        void printVerse();
        void printObscuredverse();
        Verse& operator++();

    private:
        vector<int> reference;     // [book, chapter, verse]
        vector<string> text;
        vector<string> obscuredText;
        int obscurityLevel;
        vector<bool> obscurityMap;


};