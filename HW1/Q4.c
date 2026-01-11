/*
As part of this problem, you will write a program that has as input a CSV file and outputs
another CSV file. The program will be invoked with the names of the input and output files
as arguments. The input file has two columns that include positive integers. The program
will output a file with the same two columns as the input CSV. In addition, the last column is
the sum of the first two columns.
Example: Consider the input to the program is a file input.csv that includes the following
content:
Revised 09/26/2024
0,9
1,2
4,5
11,434
3232,999
The output will be: 0,9,9
1,2,3
4,5,9
11,434,445
3232,999,4231
*/

#include<stdio.h>
#include<stdlib.h>

void process_csv(const char *input_file, const char *output_file) {
    FILE *in_file;
    FILE *out_file;
    int num1;
    int num2;
    int sum;

    in_file = fopen(input_file, "r");
    if (in_file == NULL) {
        perror("Error opening input file");
        return;
    }

    out_file = fopen(output_file, "w");
    if (out_file == NULL) {
        perror("Error opening output file");
        fclose(in_file);
        return;
    }

    while (fscanf(in_file, "%d,%d", &num1, &num2) == 2) {
        sum = num1 + num2;
        fprintf(out_file, "%d,%d,%d\n", num1, num2, sum);
    }

    fclose(in_file);
    fclose(out_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input CSV file> <output CSV file>\n", argv[0]);
        return 1;
    }

    process_csv(argv[1], argv[2]);

    return 0;
}
