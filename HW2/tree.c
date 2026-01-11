#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t pid0 = fork();
    if (pid0 == 0) {
        pid_t pid1 = fork();
        if (pid1 == 0) {
            exit(1);
        } else {
            int status1;
            waitpid(pid1, &status1, 0);  
            int sum1 = WEXITSTATUS(status1);  
            exit(sum1 + 1);
        }
    } else {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            exit(1);
        } else {
            int status0, status2;
            waitpid(pid0, &status0, 0);  
            waitpid(pid2, &status2, 0);  
            
            int sum0 = WEXITSTATUS(status0);  
            int sum2 = WEXITSTATUS(status2);  
            int total_sum = sum0 + sum2 + 1;  
            
            printf("Total sum: %d\n", total_sum); 
        }
    }

    return 0;
}