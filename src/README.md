Project 1: Tokenizer
====================
This program is a tokenizer. It takes a string as an input, and tokenizes
it. Each string entered as input, excluding commands, is stored in a history
of strings entered to be tokenized. This history can later be viewed, and a
command, such as !# will retrieve a specific string and tokenize it.

# Instructions:

If this project has been previously run, you can use the command 'make clean'
to clean the previous object files that were created by using the program.

To compile this program, use the command 'make' while in the directory.

To run this program, use the command './tokenizer'.

The program will prompt the user to enter a sentence or string of words to
tokenize.

If the user enters !q, it will quit the program.

If the user enters !h, it will print a list of the history.

If the user enters !#, where # is an index, it will retrieve and tokenize the
string stored at the index.

After using the program, you can use the command 'make clean' to delete the
files created during compilation.
