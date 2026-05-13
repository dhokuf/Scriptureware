# Implementation

## Project Structure

It's like this, boys:

## Text Formatting

Scriptural texts are located in the `Texts` folder. Each book is located in its own file. Chapters are demarcated on a new line with `CHAPTER 1`, etc. Each verse is placed on a newline and preceded by its reference as an integer (e.g. `4 To an inheritance incorruptible, and undefiled, and that fadeth not away, reserved in heaven for you,`). The `Texts` folder also contains an `index.txt` file, which collects each file to be used in the program for convenience. The index file is formatted with a numerical index (`1`), a filename (`1peter.txt`), and the title in plain text, followed by a newline (`1 Peter`). In total: `1 1peter.txt 1 Peter`. Hopefully this should facilitate parsing as well as updates to the program.
