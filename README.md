# 0x16. C - Simple Shell
## Introduction
The simple shell project is a collaboration between Ronald Altamirano and Kenny Reyes, Full Stack Software Engineering students at Holberton School, with which we can emulate the operation of a shell, which contains some of its most basic characteristics, such as : Handle PATH, Handle command lines with arguments, Must handle "end of file" condition

## Description
Simple_shell is a Command line interpreter, which includes the basic functionality of a Unix shell

## Requirements
simple_shell is designed to run in the Ubuntu 14.04 LTS linux environment and to be compiled using the GNU compiler collection v. gcc 4.8.4 with flags-Wall, -Werror, -Wextra, and -pedantic.

## Installation
Clone this repository: "https://github.com/ronLabs/simple_shell"

- Change directories into the repository: cd simple_shell
- Compile: see installation instructions later
- Run the shell: ./sh

## Compilation
- Compile: gcc -Wall -Werror -Wextra -pedantic * .c -o sh
- Our main files will include your main header file(simple_shell.h): #include simple_shell.h

## Usage
- The simple_shell is designed to execute commands in a similar manner to sh, however with more limited functionality.

## Extra Information
### Whats Included?

|     FILE      |         DESCRIPTION        		|
|---------------|---------------------------------------|
|built-in.c     |   contains enviroments functions	|
|searchpath.c   |  contains functions to seek the PATH	|
|shell.c        |    contains the main functions	|
|simple_shell.h |    contains prototypes and libraries	|
|str_func.c     | contains manipulation string functions|

### Output
Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)

Example of error with sh:
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$

Same error with your program sh:
$ echo "qwerty" | ./sh
./sh: 1: qwerty: not found
$ echo "qwerty" | ./././sh
./././hsh: 1: qwerty: not found
$

### Testing

Your shell should work like this in interactive mode:

$ ./sh
($) /bin/ls
built-in.c sh shell.c 
($)
($) exit
$

But also in non-interactive mode:                                               

$ echo "/bin/ls" | ./sh
built-in.c sh shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./sh
sh shell.c test_ls_2
sh shell.c test_ls_2
