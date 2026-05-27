/* 
---------- Scriptureware ----------
Version  0.1.0 (alpha)
Authors: David Hokuf and Benjamin Van Grouw
Date: May 2026 
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
vector<string> attempt;
Verse* currVerse = nullptr;

int attemptAccuracy;
