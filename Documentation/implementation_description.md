# Implementation

# v1.0.0

## Project Structure

V0.00 will be implemented using a simple object oriented programming approach. Program logic flow at a high level will be controlled by `main` in `main.cpp`. A verse class will contain all data and functions relating to the current verse. Other major tasks will be delegated to sub-functions, which will be placed in separate files along with any helper functions required to perform the task. Other than the verse class, the major tasks for V0.00 are:
| Task | File |
| :--- | ---: |
| Control of program logic flow | `main.cpp` |
| Menu and UI handling | `ui.cpp` |
| Verse class | `verse.cpp` |

### `main.cpp`

This file will contain the `main` function, which will contain the main application loop and call the other functions. It will also contain helper functions for basic tasks in order to keep `main` as clean as possible.
| Task | Function|
| :--- | ---:|
| Loading texts from a file and parsing them into a vector | `int main` |
| construct current verse | `void initializeCurrVerse` |

### `ui.cpp`

This file will contain the code for all handling of the main menu and general user interface. This is mostly just output functions and global inputs:
| Task | Function |
| :--- | ---: |
| Displaying the Scriptureware header | `void displayHeader` |
| Displaying homescreen main menu | `void displayHomeScreen` |
| Display memorize screen | `void displayMemorizeScreen` |
| Display review screen | `void displayReviewScreen` |
| Clearing the entire screen | `void clearScreen` |
| Clearing a single line | `void clearLine` |
| Printing a verse | `void printVerse` |
| Printing the obscured vers | `void printObscuredVerse` |
| Ask for the mode | `Mode getMode` |
| Printing message after memorization completion | `void printMemorized` |
| Printing message after incorrect verse input | `void displayTryAgain` |
| Printing exit screen | `void displayExit` |
| Reading user input into a vector if not "quit" (otherwise quit program) | `vector<string> getAttempt` |

### `verse.cpp`

This file will contain the code for the verse class which will contain private data members: the vector of strings representing the verse text, an identical vector that is obscured during memorization, the verse's book, chapter, and verse number, mutator and accessor functions, and friend functions that perform the logic tasks that partain directly to the verse. The tasks excluding simple accessing and mutating are:

| Task | Function |
| :--- | ---: |
| Constructor; initializing data | `Verse` |
| Checking user inputs against the current verse to check accuracy (0 or 100 for v1.0.0)| `int checkAccuracy` |
| Obscuring texts by removing two words at a time by replacing letters with 'X' | `bool obscure` |
| Get the verse text | `void getVerse` |
| Returning a verse by reference (helper function) | `vector<string> loadVerse` |
| Get the obscured verse text | `void getObscuredVerse` |
| Updating verse text to the next verse | `Verse& operator++` |

Detailed specifications of the individual functions are placed in the relevant header files.

## Text Formatting and Specs

- Scriptural texts are located in the `Texts` folder. Each book is located in its own file. Chapters are demarcated on a new line with `CHAPTER 1`, etc. Each verse is placed on a newline and preceded by its reference as an integer (e.g. `4 To an inheritance incorruptible, and undefiled, and that fadeth not away, reserved in heaven for you,`). The `Texts` folder also contains an `index.txt` file, which collects each file to be used in the program for convenience. The index file is formatted with a numerical index (`1`), a filename (`1peter.txt`), and the title in plain text, followed by a newline (`1 Peter`). In total: `1 1peter.txt 1 Peter`. Hopefully this should facilitate parsing as well as updates to the program.
