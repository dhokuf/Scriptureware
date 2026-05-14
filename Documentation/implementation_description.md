# Implementation

## v1.0.0

### Project Structure

V0.00 will be implemented using a procedural programming approach. Later versions may become object-oriented, especially if a graphical user interface is desired. Program logic flow at a high level will be controlled by `main` in `main.cpp`. Each major task will be delegated to sub-functions, which will be placed in a separate file along with any helper functions required to perform the task. The major tasks for V0.00 are:
| Task | File |
| :--- | ---: |
| Control of program logic flow | `main.cpp` |
| Loading and parsing of index and texts | `parse.cpp` |
| Menu and UI handling | `ui.cpp` |
| Accuracy evaluation, logic, and input handling | `logic.cpp` |
| Memorization word-removal algorithm | `algorithm.cpp` |

Detailed specifications of the individual functions are placed in the relevant header files.

### Text Formatting and Specs

Scriptural texts are located in the `Texts` folder. Each book is located in its own file. Chapters are demarcated on a new line with `CHAPTER 1`, etc. Each verse is placed on a newline and preceded by its reference as an integer (e.g. `4 To an inheritance incorruptible, and undefiled, and that fadeth not away, reserved in heaven for you,`). The `Texts` folder also contains an `index.txt` file, which collects each file to be used in the program for convenience. The index file is formatted with a numerical index (`1`), a filename (`1peter.txt`), and the title in plain text, followed by a newline (`1 Peter`). In total: `1 1peter.txt 1 Peter`. Hopefully this should facilitate parsing as well as updates to the program.
