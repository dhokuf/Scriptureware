/* 
---------- Scriptureware ----------
Version  0.1.0 (alpha)
Authors: David Hokuf and Benjamin Van Grouw
Date: May 2026 
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
        
        ui::displayMemorizeScreen(currVerse);
        // Note: you have to prefix it like this and dereference the pointer
        ++(*currVerse);
        ui::displayMemorizeScreen(currVerse);
        /*
        while (!currVerse->endOfBookReached()) {
            while (currVerse->obscure()) {
                ui::printObscuredVerse(currVerse);

                attempt = ui::getAttempt(currVerse);

                attemptAccuracy = currVerse->checkAccuracy(attempt);

                while (attemptAccuracy == 0) {
                    ui::displayTryAgain();

                    ui::printVerse(currVerse);

                    attempt = ui::getAttempt(currVerse);
                    currVerse->checkAccuracy(attempt);
                }
            }

            currVerse++;
        }
        */
    }

    return 0;
}

Verse& initializeCurrVerse(Reference ref) {
    return *(new Verse(ref));
}