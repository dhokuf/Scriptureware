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

Verse& initializeCurrVerse();

// And so it begins...
int main() {

    displayHomeScreen();

    mode = askForMode();

    askForReference();                                 // for initial currVerse

    currVerse = &initializeCurrVerse();

    if (mode = REVIEW) {
        displayReviewScreen();

        while (!currVerse->endOfBookReached()) {
            
            attempt = getAttempt(currVerse);

            attemptAccuracy = currVerse->checkAccuracy(attempt);
            
            if (attemptAccuracy == 100) { currVerse++;       }
            else                         { displayTryAgain(); }
        }
    }
    else if (mode = MEMORIZE) {                                                     // if memorizing
        displayMemorizeScreen();

        while (!currVerse->endOfBookReached()) {
            while (currVerse->obscure()) {
                printObscuredVerse(currVerse);

                attempt = getAttempt(currVerse);

                attemptAccuracy = currVerse->checkAccuracy(attempt);

                while (attemptAccuracy == 0) {
                    displayTryAgain();

                    printVerse(currVerse);

                    attempt = getAttempt(currVerse);
                    currVerse->checkAccuracy(attempt);
                }
            }

            currVerse++;
        }
    }

    log("Build test success!");
    return 0;
}

Verse& intializeCurrVerse(Reference reference) {
    return *(new Verse(reference));
}