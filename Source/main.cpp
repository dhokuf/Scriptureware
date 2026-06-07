/* 
---------- Scriptureware ----------
Version  1.0.0
Authors: David Hokuf and Benjamin Van Grouw
Date: June 2026 
*/

#include "main.hpp"
#include "ui.hpp"
#include "verse.hpp"

// And so it begins...
int main() {

    ui::displayHomeScreen();

    mode = ui::askForMode();
    reference = ui::askForReference();
    currVerse = &initializeCurrVerse(reference);

    if (mode == REVIEW) {
        
        reviewed = correct = incorrectAttempt = 0;
        ui::displayReviewScreen(currVerse);
        while (!currVerse->endOfBookReached()) {

            attempt = ui::getAttempt(currVerse);
            if (attempt->at(0) == "quit") break;
            attemptAccuracy = currVerse->checkAccuracy(*attempt);
            
            if (attemptAccuracy == 100) { 
                
                reviewed++;
                ++(*currVerse);
                ui::displayCorrect();
                if (!incorrectAttempt) correct++;
                incorrectAttempt = false;

            } else { 

                incorrectAttempt = true;
                ui::displayTryAgain(currVerse); 
            }
            
        }

        ui::displayReviewExit(reviewed, correct);
    }

    else if (mode == MEMORIZE) {
        
        memorized = 0;
        while (!currVerse->endOfBookReached()) {
            
            do {
                ui::clearScreen();
                ui::displayMemorizeScreen(currVerse);
                ui::printObscuredVerse(currVerse);

                attempt = ui::getAttempt(currVerse);
                if (attempt->at(0) == "quit") {
                    ui::displayMemorizeExit(memorized);
                    exit(0);
                }
                attemptAccuracy = currVerse->checkAccuracy(*attempt);

                while (attemptAccuracy == 0) {
                    ui::displayTryAgain(currVerse);

                    attempt = ui::getAttempt(currVerse);
                    if (attempt->at(0) == "quit") {
                        ui::displayMemorizeExit(memorized);
                        exit(0);
                    }
                    attemptAccuracy = currVerse->checkAccuracy(*attempt);
                }
            } while (!currVerse->obscure());

            memorized++;
            ++(*currVerse);
        }

        ui::displayMemorizeExit(memorized);
    }

    return 0;
}

Verse& initializeCurrVerse(Reference ref) {
    return *(new Verse(ref));
}