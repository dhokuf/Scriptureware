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

#include "parse.hpp"
#include "ui.hpp"
#include "logic.hpp"
#include "algorithm.hpp"

// And so it begins...
int main() {

    log("Build test success!");
    return 0;
}