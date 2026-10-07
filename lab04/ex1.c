#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void) {
    clock_t start = clock();

    pid_t c1 = fork();
    if (c1 == 0) 
	{
        clock_t s = clock();
        printf("Child1: PID=%d PPID=%d time=%.3f ms\n", getpid(), getppid(), (double)(clock() - s) * 1000.0 / CLOCKS_PER_SEC);
        exit(EXIT_SUCCESS);
    }

    pid_t c2 = fork();
    if (c2 == 0) 
	{
        clock_t s = clock();
        printf("Child2: PID=%d PPID=%d time=%.3f ms\n", getpid(), getppid(), (double)(clock() - s) * 1000.0 / CLOCKS_PER_SEC);
        exit(EXIT_SUCCESS);
    }

    printf("Main:   PID=%d PPID=%d time=%.3f ms\n", getpid(), getppid(), (double)(clock() - start) * 1000.0 / CLOCKS_PER_SEC);

    return 0;
}