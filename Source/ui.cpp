/* 
---------- Scriptureware ----------
Version  0.1.0 (alpha)
Authors: David Hokuf and Benjamin Van Grouw
Date: May 2026 
*/

#include "ui.hpp"

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
        bool waitingForValidInput = true;
        
        cout << INSTRUCTIONS << "Enter <1> to review, <2> to memorize new material, "
            << "or <quit> to exit: " << RESET;
        
        while (waitingForValidInput) {
            cin >> userInput;

            if (userInput == "1") {
                mode = REVIEW;
                waitingForValidInput = false;
            }
            else if (userInput == "2") {
                mode = MEMORIZE;
                waitingForValidInput = false;
            }
            else if (userInput == "quit") {
                exit(0);
            }
            else {
                cout << "\nPlease choose one of the provided options :) ";
            }
        }

        cout << endl;

        return mode;
    }

    Reference askForReference() {

        string book;
        int chapter;
        int verse;

        cout << INSTRUCTIONS << "What biblical text would you like to begin with?\n";
        cout << ACCENT << right << setw(10) << "Book: " << RESET;
        cin >> book;

        clearLine();

        cout << right << setw(10) << "Chapter: " << book << " ";
        cin >> chapter;

        clearLine();

        cout << right << setw(10) << "Verse: " << book << " " << chapter << ":";
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