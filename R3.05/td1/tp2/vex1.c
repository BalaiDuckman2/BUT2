#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int ctrlCCount = 0;

void mon_action(int sig)
{
    if (sig == SIGINT)
    {
        ctrlCCount++;
        printf("Reçu un CTRL+C.\n");
        printf("Pour arrêter le programme il faut taper 5 fois CTRL+C.\n");
        printf("Il en manque encore %d.\n", 5 - ctrlCCount);

        if (ctrlCCount >= 5)
        {
            printf("Nombre de CTRL+C atteint. Arrêt du programme.\n");
            exit(0);
        }
    }else if (sig==SIGSTOP)
    {
        ctrlCCount=0;
        printf("Remise à zéro du compteur des CTRL+C.\n");
    }
    
}

int main()
{
    int loop;
    printf("%d\n", getpid());
    signal(SIGINT, mon_action);
    for (loop = 0; loop < 600; loop++)
    {
        printf("PID %d - Passage %d\n", getpid(), loop);
        sleep(1);
    }
    return 0;
}