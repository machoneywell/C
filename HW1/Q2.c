/*
You are given a number N, where N is a natural number such that N >=1. Write a program
that prints all the prime numbers between 1 and N (inclusive). The program will accept a
single command-line argument which is N. The output will include on the first line the
number N, followed by a prime on each of the following lines. As an example, calling ./a.out
10 should print:
10
1
2
3
5
7
*/

#include<stdio.h>
#include<math.h>

int main() {
    int N;
    int i;
    int j;
    
    printf("Enter an integer >= 1: ");
    scanf("%d", &N);
    printf("%d \n", N);

    for (i = 1; i <= N; i++) {
        int prime = 1;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                prime = 0;
                break;
            }
        }
        if (prime == 1) { 
            printf("%d \n", i);
        }
    }
    return 0;
}