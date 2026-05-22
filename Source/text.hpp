/* 
---------- Scriptureware ----------
Version  0.1.0 (alpha)
Authors: David Hokuf and Benjamin Van Grouw
Date: May 2026 
*/

#pragma once

#include <string>
#include <vector>

#include "verse.hpp"

using namespace std;

vector<string> load(Reference reference);
string getVerse(Reference reference);