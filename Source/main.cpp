/* 
---------- Scriptureware ----------
Version  0.1.0 (alpha)
Authors: David Hokuf and Benjamin Van Grouw
Date: May 2026 
*/

// Comment this line out to disable development mode and remove debug output
/**/ #define _DEVELOPMENT_MODE */

// If development mode is enabled, define a log function for debug output
#ifdef _DEVELOPMENT_MODE
    #include <iostream>
    #define log(x) std::cout << "[DEBUG] " << x << std::endl;

// Otherwise, do nothing when a log statement is encountered
#else
    #define log(x)

#endif

// And so it begins...
int main() {
    /*

    displayHomeScreen();

    askForMode();

    askForReference();                                 // for initial currVerse

    initializeCurrVerse();

    if (reviewing) {
        displayReviewScreen();

        while (!endOfBookReached) {
            
            askForAttempt();

            currVerse.checkAccurracy(attempt);
            
            if (attemptAccurracy == 100) { currVerse++;       }
            else                         { displayTryAgain(); }
        }
    }
    else {                                                     // if memorizing
        displayMemorizeScreen();

        while (!endOfBookReached) {
            while (currVerse.obscure()) {
                currVerse.printObscureVerse();

                askForAttempt();

                currVerse.checkAccuracy(attempt);

                while (attemptAccurracy == 0) {
                    displayTryAgain();

                    currVerse.printVerse();

                    askForAttempt();

                    currVerse.checkAccuracy(attempt);
                }
            }

            currVerse++;
        }
    }

    /**/

    log("Build test success!");
    return 0;
}