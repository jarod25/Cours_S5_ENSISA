#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int pid1 = fork();
    int pid2 = fork();

    if (pid1==0 && pid2 != 0) {
        for (int i = 1; i <= 50; i++)
        {
            printf("%i\n", i);
        }
    }

    if (pid1 !=0 && pid2 == 0) {
        for (int i = 51; i <= 100; i++)
        {
            printf("%i\n", i);
        }
    }
    return 0;
}
