# Implementation

# v1.0.0

## Project Structure

V0.00 will be implemented using a simple object oriented programming approach. Program logic flow at a high level will be controlled by `main` in `main.cpp`. A verse class will contain all data and functions relating to the current verse. Other major tasks will be delegated to sub-functions, which will be placed in separate files along with any helper functions required to perform the task. Other than the verse class, the major tasks for V0.00 are:
| Task | File |
| :--- | ---: |
| Control of program logic flow | `main.cpp` |
| Parsing and manipulation of inputs and outputs | `text.cpp` |
| Menu and UI handling | `ui.cpp` |
| low-level logic and helper functions | `logic.cpp` |

### `main.cpp`

This file will just contain the `main` function. Its role will essentially just be calling other functions.

### `text.cpp`

This file will contain the code for all parsing and manipulation of file inputs and outputs. Its major tasks will include:
| Task | Function|
| :--- | ---:|
| Loading texts from a file and parsing them into a vector | `vector<string> load` |
| Returning a verse by reference | `string getVerse` |

### `ui.cpp`

This file will contain the code for all handling of the main menu and general user interface. This is mostly just output functions and global inputs:
| Task | Function |
| :--- | ---: |
| displaying homescreen main menu | `void displayHomeScreen` |
| clearing the entire screen | `void clearScreen` |
| clearing a single line | `void clearLine` |
| printing a verse | `void printVerse` |
| printing message after memorization completion | `void printMemorized` |
| printing message after incorrect verse input | `void displayTryAgain` |
| printing exit screen | `void displayExit` |
| reading user input into a vector if not "quit" (otherwise quit program) | `vector<string> getUserAttempt` |

### `logic.cpp`

This file will contain the code for lower level logic:

| Task | Function |
| :--- | ---: |
| construct current verse | `void initializeCurrVerse` |

### 'verse.cpp`

This file will contain the code for the verse class which will contain private data members: the vector of strings representing the verse text, an identical vector that is obscured during memorization, the verse's book, chapter, and verse number, mutator and accessor functions, and friend functions that perform the logic tasks that partain directly to the verse. The tasks excluding simple accessing and mutating are:

| Task | Function |
| :--- | ---: |
| checking user inputs against the current verse to check accuracy (0 or 100 for v1.0.0)| `int checkAccuracy` |
| Obscuring texts by removing two words at a time by replacing letters with 'X' | `bool obscure` |
| Printing the verse text | `void printVerse` |
| Printing the obscured verse | `void printObscureVerse` |
| Updating verse text to the next verse | `verse operator++` |

Detailed specifications of the individual functions are placed in the relevant header files.

## Text Formatting and Specs

Scriptural texts are located in the `Texts` folder. Each book is located in its own file. Chapters are demarcated on a new line with `CHAPTER 1`, etc. Each verse is placed on a newline and preceded by its reference as an integer (e.g. `4 To an inheritance incorruptible, and undefiled, and that fadeth not away, reserved in heaven for you,`). The `Texts` folder also contains an `index.txt` file, which collects each file to be used in the program for convenience. The index file is formatted with a numerical index (`1`), a filename (`1peter.txt`), and the title in plain text, followed by a newline (`1 Peter`). In total: `1 1peter.txt 1 Peter`. Hopefully this should facilitate parsing as well as updates to the program.
