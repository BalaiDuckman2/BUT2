#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t pid;
    int val = 10;
    int boucle=0;
    printf("Avant fork(), je suis PID %d", getpid());
    printf(" et val = %d\n", val);
    pid = fork();
    if (pid == 0)
    { // Fils ⓸
        printf("Je suis le fils, mon PID est %d et mon pere a le PID %d\n", getpid(), getppid());
        printf("Chez le fils, val = %d\n", val);
        val = 20;
    }
    else
    { // Pere ⓺
        printf("Je suis le pere, mon PID est %d et je viens de creer un fils de PID %d\n", getpid(), pid);
        for(int i=0;i<300;i++){
            boucle++;
            printf("passage %d",boucle);
            
            
        }
        sleep(1);
        
        printf("Chez le père, val = %d\n", val);
    }
    printf("Je suis PID %d et val = %d\n", getpid(), val);
    return EXIT_SUCCESS;
}