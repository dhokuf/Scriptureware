/* 
---------- Scriptureware ----------
Version  1.0.0
Authors: David Hokuf and Benjamin Van Grouw
Date: June 2026 
*/

#pragma once

// Comment this line out to disable development mode and remove debug output
/**/ #define _DEVELOPMENT_MODE */

#ifdef _DEVELOPMENT_MODE
    #include <iostream>
    #define log(x) std::cout << "[DEBUG] " << x << std::endl
#else
    #define log(x)
#endif

#include "verse.hpp"
#include "ui.hpp"

#include <vector>
#include <string>

using namespace std;

Verse& initializeCurrVerse(Reference ref);

Mode mode;
Reference reference;
vector<string>* attempt;
Verse* currVerse = nullptr;

int memorized;
int reviewed;
int correct;
int attemptAccuracy;
bool incorrectAttempt;
