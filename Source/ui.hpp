/* 
---------- Scriptureware ----------
Version  1.0.0
Authors: David Hokuf and Benjamin Van Grouw
Date: June 2026 
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "verse.hpp"

using namespace std;

// Metadata
#define VERSION "0.1.0 (alpha)\n"
#define AUTHORS "David Hokuf and Benjamin Van Grouw\n"
#define LASTUPDATE "June 2026\n"
#define SUPPORT "Whole Bible [ESV]\n"

// Escape Codes
// Source: https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

#define CLEARSCREEN "\033[2J\033[1;1H"
#define CLEARLINE "\033[A\033[2K"

#define TITLE "\x1b[1;38;5;68m"
#define CREDITS "\x1b[1;38;5;130m"
#define INSTRUCTIONS "\x1b[1;38;5;68m"
#define ACCENT "\x1b[1;38;5;130m"
#define RESET "\x1b[0m"

enum Mode { REVIEW, MEMORIZE };

namespace ui {
    void displayHomeScreen();
    Mode askForMode();
    Reference askForReference();
    void displayMemorizeScreen(Verse* verse);
    void displayMemorizeExit(int memorized);
    void displayReviewScreen(Verse* verse);
    void displayReviewExit(int reviewed, int correct);
    void clearScreen();
    void clearLine();
    void printVerse(Verse* verse);
    void printObscuredVerse(Verse* verse);
    void printMemorized();
    void displayCorrect();
    void displayTryAgain(Verse* verse);
    void displayExit();
    void displayIndex();
    vector<string>* getAttempt(Verse* verse);
    void clearInputBuffer();
}