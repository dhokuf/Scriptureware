# Implementation

# v1.0.0

## Project Structure

V0.00 will be implemented using a procedural programming approach. Later versions may become object-oriented, especially if a graphical user interface is desired. Program logic flow at a high level will be controlled by `main` in `main.cpp`. Each major task will be delegated to sub-functions, which will be placed in a separate file along with any helper functions required to perform the task. The major tasks for V0.00 are:
| Task | File |
| :--- | ---: |
| Control of program logic flow | `main.cpp` |
| Parsing and manipulation of inputs and outputs | `text.cpp` |
| Menu and UI handling | `ui.cpp` |
| Accuracy evaluation, logic, and input handling | `logic.cpp` |

### `main.cpp`

This file will just contain the `main` function. Its role will essentially just be calling other functions.

### `text.cpp`

This file will contain the code for all parsing and manipulation of file inputs and outputs. Its major tasks will include:
| Task | Function|
| :--- | ---:|
| Loading texts from a file and parsing them into a vector | `vector<string> load` |
| Returning a verse by reference | `string getVerse` |
| Obscuring texts by removing two words at a time by replacing letters with 'X' | `bool obscure` |


### `ui.cpp`

This file will contain the code for all handling of the main menu and general user interface. This is mostly just output functions and global inputs:
| Task | Function |
| :--- | ---: |
| displaying homescreen main menu | `void displayHomeScreen` |
| clearing the entire screen | `void clearScreen` |
| clearing a single line | `void clearLine` |
| printing a verse | `void printVerse` |
| printing message after memorization completion | `void printMemorized` |
| printing message after incorrect verse input | `void printTryAgain` |
| printing exit screen | `void printExit` |

### `logic.cpp`

This file will contain the code for handling user input and evaluating user accuracy:
| Task | Function |
| :--- | ---: |
| checking user inputs against the currently selected text to check accuracy (0 or 100 for v1.0.0)| `int checkAccuracy` |
| reading user input into a vector if not "quit" (otherwise quit program) | `vector<string> userAttempt` |

Detailed specifications of the individual functions are placed in the relevant header files.

## Text Formatting and Specs

Scriptural texts are located in the `Texts` folder. Each book is located in its own file. Chapters are demarcated on a new line with `CHAPTER 1`, etc. Each verse is placed on a newline and preceded by its reference as an integer (e.g. `4 To an inheritance incorruptible, and undefiled, and that fadeth not away, reserved in heaven for you,`). The `Texts` folder also contains an `index.txt` file, which collects each file to be used in the program for convenience. The index file is formatted with a numerical index (`1`), a filename (`1peter.txt`), and the title in plain text, followed by a newline (`1 Peter`). In total: `1 1peter.txt 1 Peter`. Hopefully this should facilitate parsing as well as updates to the program.
