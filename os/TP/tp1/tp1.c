#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
/* 
I.1) Quelques commandes utiles  
1) : il n'y a que 2 processus, bash et ps

2) : ps x

3) : ps j

4) : on voit en temps réel l'évolution du processus avec sa consomation de GPU et de RAM

I.2) Création de processus en C
*/

// 1)
void getParentAndChildPID() {
    int pid = fork();
    if (pid == 0) {
        printf("Je suis le fils, mon PID est %d et le PID de mon père est %d\n", getpid(), getppid());
    } else {
        printf("Je suis le père, mon PID est %d et le PID de mon fils est %d\n", getpid(), pid);
    }
}


// 2)
void createArchi() {
    int status;
    int pid = fork();
    int pid2 = fork();

    if (pid == 0) {
        if (pid2 == 0) {
            printf("Je suis le petit fils, mon PID est %d et le PID de mon père est %d\n", getpid(), getppid());
        } else {
            printf("Je suis le fils1, mon PID est %d et le PID de mon père est %d\n", getpid(), getppid());
            wait(&status);
        }
    } else {
        if (pid2 == 0) {
            printf("Je suis le fils2, mon PID est %d et le PID de mon père est %d\n", getpid(), getppid());
        } else {
            printf("Je suis le père, mon PID est %d et le PID de mon fils est %d\n", getpid(), pid);
            wait(&status);
        }
    }
    
}

// 3)
void execCommand() {
    int pid = fork();
    if (pid == 0) {
        execlp("date", "date", NULL);
    } else {
        printf("Hello, World!\n");
    }
}

// 4)
void createKill() {
    int pid = fork();
    if (pid == 0) {
        while (1) printf("Hello, World!\n");
    } else {
        sleep(3);
        kill(pid, 9);
    }
}

// 5)
void killFather() {
    int i;
    printf("Pid de ce processus : %d\n", getpid());
    printf("Pid du père de ce processus : %d\n", getppid());
    kill(getppid(), 9);
}

void main(int argc, char* argv[]) {
    // getParentAndChildPID();
    // createArchi();
    // execCommand();
    // createKill();
    killFather();
}