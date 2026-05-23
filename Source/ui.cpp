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

        cout << "------------ Scriptureware! ------------\n";
        cout << right << setw(20) << "Version:" << " 0.1.0 (alpha)\n";
        cout << right << setw(20) << "Created by:" 
            << " David Hokuf and Benjamin Van Grouw\n";
        cout << right << setw(20) << "Last update:" << " May 2026\n";
        cout << right << setw(20) << "Currently supports:" 
            << " 1 Peter [5 chapters]\n\n";
    }

    Mode askForMode() {
        
        Mode mode;
        string userInput;
        bool ValidInput = false;
        
        cout << "Enter <1> to review, <2> to memorize new material, "
            << "or <quit> to exit: ";
        
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

    Reference askForReference() {

        string book;
        int chapter;
        int verse;

        cout << "At what biblical text would you like to start?\n";
        cout         << right << setw(10) << "Book: ";

        cin.ignore();
        getline(cin, book);

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
        cout << "\033[2J\033[1;1H";
    }

    void clearLine() {
        cout << "\033[A\033[2K";
    }

    void displayExit() {
        
    }

}