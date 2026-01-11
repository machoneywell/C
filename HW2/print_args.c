/*
Manipulating Command Line Arguments
To get us started, you must write a simple program in print_args.c that prints the command line
arguments that it invokes
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 0;
}