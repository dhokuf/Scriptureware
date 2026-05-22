/* 
---------- Scriptureware ----------
Version  0.1.0 (alpha)
Authors: David Hokuf and Benjamin Van Grouw
Date: May 2026 
*/

#pragma once

#include "verse.hpp"

using namespace std;

enum Mode { REVIEW, MEMORIZE };

void displayHeader();
void displayHomeScreen();
void displayMemorizeScreen();
void displayReviewScreen();
Mode askForMode();
void askForReference();
void clearScreen();
void clearLine();
void printVerse(Verse* verse);
void printObscuredVerse(Verse* verse);
void printMemorized();
void displayTryAgain();
void displayExit();
vector<string> getAttempt(Verse* verse);
