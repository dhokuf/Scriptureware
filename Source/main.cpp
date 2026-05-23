/* 
---------- Scriptureware ----------
Version  0.1.0 (alpha)
Authors: David Hokuf and Benjamin Van Grouw
Date: May 2026 
*/

#include "main.hpp"
#include "ui.hpp"
#include "verse.hpp"

// Comment this line out to disable development mode and remove debug output
/**/ #define _DEVELOPMENT_MODE */

#ifdef _DEVELOPMENT_MODE
    #include <iostream>
    #define log(x) std::cout << "[DEBUG] " << x << std::endl
#else
    #define log(x)
#endif

// And so it begins...
int main() {

    ui::displayHomeScreen();

    mode = ui::askForMode();
    reference = ui::askForReference();
    currVerse = &initializeCurrVerse(reference);
    if (mode == REVIEW) {
        ui::displayReviewScreen(currVerse);

        while (!currVerse->endOfBookReached()) {
            
            attempt = ui::getAttempt(currVerse);

            attemptAccuracy = currVerse->checkAccuracy(attempt);
            
            if (attemptAccuracy == 100) { currVerse++;       }
            else                        { ui::displayTryAgain(); }

        }
    }

    else if (mode == MEMORIZE) {
        
        ui::displayMemorizeScreen(currVerse);

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
    }

    log("Build test success!");
    return 0;
}

Verse& initializeCurrVerse(Reference ref) {
    return *(new Verse(ref));
}