/* 
---------- Scriptureware ----------
Version  1.0.0
Authors: David Hokuf and Benjamin Van Grouw
Date: June 2026 
*/

// Comment this line out to disable development mode and remove debug output
/**/ #define _DEVELOPMENT_MODE */

#ifdef _DEVELOPMENT_MODE
    #include <iostream>
    #define log(x) std::cout << "[DEBUG] " << x << std::endl
#else
    #define log(x);
#endif

#include "ui.hpp"
#include "verse.hpp"

namespace ui {

    void displayHomeScreen() {

        clearScreen();

        cout << TITLE << "\n\n-------------Scriptureware!-------------\n";
        cout << CREDITS << "Version: " << VERSION;
        cout << "Created by " << AUTHORS;
        cout << "Last update: " << LASTUPDATE;
        cout << "Currently supports: " << SUPPORT << RESET << endl;
    }

    Mode askForMode() {
        
        Mode mode;
        string userInput;
        bool ValidInput = false;
        
        cout << INSTRUCTIONS << "Enter <1> to review, <2> to memorize new material, "
            << "or <quit> to exit: " << RESET;
        
        while (!ValidInput) {
            cin >> userInput;

            clearInputBuffer();

            if (userInput == "1") {
                mode = REVIEW;
                ValidInput = true;
            }
            else if (userInput == "2") {
                mode = MEMORIZE;
                ValidInput = true;
            }
            else if (userInput == "quit") {
                displayExit();
                exit(0);
            }
            else {
                cout << "Please choose one of the provided options (: ";
            }
        }

        cout << endl;
        return mode;
    }

    void displayIndex() {

        vector<string>* index = loadIndex();
        cout << INSTRUCTIONS << "Index: \n\t" << ACCENT;

        int columnCounter = 0;
        for (int i = 0; i < index->size(); i++) {
            cout << left << setw(30) << (to_string((i+1)) + ": " + ((i>9) ? "" : " ") + index->at(i)); // Pretty slick, you must admit
            columnCounter++;
            if (columnCounter > 5) {
                cout << "\n\t";
                columnCounter = 0;
            }
        }
       cout << endl;

    }

    Reference askForReference() {

        int book;
        int chapter;
        int verse;
        Reference reference;
        bool done = false;

        
        displayIndex();
        cout << INSTRUCTIONS << "With what biblical text would you like to begin?\n";

        while (!done) {
            
            cout << ACCENT << "\tEnter a book: " << RESET;
            cin >> book;

            clearInputBuffer();

            if (cin.fail() || (book) > loadIndex()->size()) {
                cin.clear();
                clearInputBuffer();
                cout << INSTRUCTIONS << "\nInvalid reference. Please try again: " << RESET << endl;
                continue;
            }

            clearLine();

            cout << ACCENT << "\tEnter a chapter: " << loadIndex()->at(book-1) << " ";
            cin >> chapter;

            clearInputBuffer();

            clearLine();

            cout << ACCENT << "\tEnter a verse: " << loadIndex()->at(book-1) << " " << chapter << ":";
            cin >> verse;

            clearInputBuffer();

            cout << endl;

            reference.book = book - 1;
            reference.chapter = chapter;
            reference.verse = verse;

            Verse tempVerse(reference);
            if (tempVerse.loadVerse().empty()) {
                cout << INSTRUCTIONS << "Invalid reference. Please try again: " << RESET << endl;
            } else done = true;
        }

        return reference;
    }

    vector<string>* getAttempt(Verse* verse) {
        
        string inString;
        Reference reference = verse->getReference();
        cout << ACCENT << loadIndex()->at(reference.book) << " " << reference.chapter 
        << ":" << reference.verse << " > " << RESET;
        getline(cin >> ws, inString);
        istringstream input(inString);
        vector<string> *attempt = new vector<string>;
        attempt->reserve(100);
        string curr;
        while (input >> curr) {
            attempt->push_back(curr);
        }
        return attempt;

    }

    void clearInputBuffer() {
        //dump rest of input line if any
        string dump;
        getline(cin, dump);
    }

    void displayMemorizeScreen(Verse* verse) {

        clearScreen();
        string book = loadIndex()->at(verse->getReference().book);
        string chapterAndVerse = to_string(verse->getReference().chapter) + ":"
        + to_string(verse->getReference().verse);
        cout << TITLE << "-------------Memorizing" << book << " " << chapterAndVerse
            << "-------------\n";
        cout << ACCENT << "Enter each verse as prompted. Enter <quit> to exit." 
        << RESET << endl;
    }

    void displayReviewScreen(Verse* verse) {

        clearScreen();
        string book = loadIndex()->at(verse->getReference().book);
        string chapterAndVerse = to_string(verse->getReference().chapter) + ":"
        + to_string(verse->getReference().verse);
        cout << TITLE << "-------------Reviewing-------------\n";
        cout << ACCENT << "Enter each verse as prompted. Enter <quit> to exit.\n" 
        << RESET << endl;
    }

    void displayMemorizeExit(int memorized) {
        cout << TITLE << "---------- Exiting Memorization ----------" << endl;
        cout << ACCENT << "Memorization stats: you memorized " << memorized 
        << ((memorized == 1) ? " verse " : " verses ") << RESET << endl;
    }

    void displayReviewExit(int reviewed, int correct) {
        cout << TITLE << "---------- Exiting Review ----------" << endl;
        cout << ACCENT << "You reviewed " << reviewed << ((reviewed == 1) ? " verse " : " verses ")
        << "with " << correct << "/" << reviewed << " correct" << RESET << endl;
    }

    void printVerse(Verse* verse) {
        cout << verse->prettyPrint() << endl;
    }

    void printObscuredVerse(Verse* verse) {
        cout << verse->prettyPrintObscured() << endl;
    }

    void printMemorized() {
        cout << INSTRUCTIONS << "Memorization Complete!" << endl;
    }

    void displayTryAgain(Verse* verse) {

        cout << INSTRUCTIONS << "Incorrect! Please try again: " << endl;
        printVerse(verse);
    }

    void displayCorrect() {
        cout << INSTRUCTIONS << " Correct!" << RESET << endl;
    }

    void clearScreen() {
        cout << CLEARSCREEN << endl;
    }

    void clearLine() {
        cout << CLEARLINE << RESET << flush;
    }

    void displayExit() {
        cout << RESET << TITLE;
        cout << "\n-------------Exiting Scriptureware-------------\n" << endl;
        cout << RESET;
    }

}