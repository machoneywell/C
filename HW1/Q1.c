/*
You are given a number N, where N is a natural number such that N >=1. Write a program
that prints the first Fibonacci numbers. The program will accept a single command-line
argument which is N. The output will include the first N Fibonacci numbers, each printed
on a new line. As an example, calling ./a.out 10 should print:
0
1
1
2
3
5
8
13
21
34
55
*/

#include<stdio.h>

int main() {
    int N;
    int i;
    int older = 0;
    int old = 1;
    int new = 0;
    printf("Enter an integer >= 1: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++ ) {
        if (i == 0) {
            printf("%d \n", older);
            printf("%d \n", old);
        } else {
            new = (older + old);
            printf("%d \n", new);
            older = old;
            old = new;
            }
        }
    return 0;
}
