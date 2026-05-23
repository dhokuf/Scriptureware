/* 
---------- Scriptureware ----------
Version  0.1.0 (alpha)
Authors: David Hokuf and Benjamin Van Grouw
Date: May 2026 
*/

// Comment this line out to disable development mode and remove debug output
/**/ #define _DEVELOPMENT_MODE */

#ifdef _DEVELOPMENT_MODE
    #include <iostream>
    #define log(x) std::cout << "[DEBUG] " << x << std::endl
#else
    #define log(x)
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

            if (userInput == "1") {
                mode = REVIEW;
                ValidInput = true;
            }
            else if (userInput == "2") {
                mode = MEMORIZE;
                ValidInput = true;
            }
            else if (userInput == "quit") {
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
            cout << left << setw(30) << (to_string((i+1)) + ": " + index->at(i));
            columnCounter++;
            if (columnCounter > 2) {
                cout << "\n\t";
                columnCounter = 0;
            }
        }
       cout << endl;

    }

    Reference askForReference() {

        string book;
        int chapter;
        int verse;

        displayIndex();
        cout << INSTRUCTIONS << "What biblical text would you like to begin with?\n";
        cout << ACCENT << "\tEnter a book: " << RESET;
        cin >> book;

        clearLine();

        cout << ACCENT << "\tEnter a chapter: " << loadIndex()->at(stoi(book)-1) << " ";
        cin >> chapter;

        clearLine();

        cout << ACCENT << "\tEnter a verse: " << loadIndex()->at(stoi(book)-1) << " " << chapter << ":";
        cin >> verse;
        cout << endl;

        // make book match name of its txt file
        for (int i = 0; i < book.size(); i++) {
            if (book.at(i) == ' ') {
                book.erase(i, 1);
            }
            book.at(i) = tolower(book.at(i));
        }

        Reference reference;

        reference.book = book;
        reference.chapter = chapter;
        reference.verse = verse;

        return reference;
    }

    vector<string> getAttempt(Verse* verse) {
        
        return vector<string>();

    }

    void displayMemorizeScreen() {
        cout << "-------------Memorizing-------------"; //FIXME: must say reference
        cout << "Enter each verse as prompted. Enter <quit> to exit.";
        //FIXME finish implementation
    }

    void displayReviewScreen() {

    }

    void printVerse(Verse* verse) {

    }

    void printObscuredVerse(Verse* verse) {

    }

    void printMemorized() {

    }

    void displayTryAgain() {

    }

    void clearScreen() {
        cout << CLEARSCREEN;
    }

    void clearLine() {
        cout << CLEARLINE << RESET;
    }

    void displayExit() {
        
    }

}