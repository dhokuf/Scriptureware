/* 
---------- Scriptureware ----------
Version  0.1.0 (alpha)
Authors: David Hokuf and Benjamin Van Grouw
Date: May 2026 
*/

#pragma once

#include "verse.hpp"
#include "ui.hpp"

#include <vector>
#include <string>

using namespace std;

Mode mode;
Reference reference;
vector<string> attempt;
Verse* currVerse = nullptr;

int attemptAccuracy;
