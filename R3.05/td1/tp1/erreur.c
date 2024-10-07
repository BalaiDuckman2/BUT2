#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // voir SYNOPSIS dans man 2 rmdir
#include <errno.h>  // voir SYNOPSIS dans man 3 errno
int main()
{
    int ret;
    ret = rmdir("D1");
    if (ret == -1)
    { // Erreur
        if (errno == ENOENT)
        { // On traite manuellement celle-ci
            printf("D1 n'existe pas !\n");
        }
        else
        {                              // On confie les autres à perror()
            perror("Erreur inconnue"); // Mon msg + celui d’errno
        }
        return EXIT_FAILURE; // 1 seul return serait mieux ! :-)
    }
    else
    { // C’est forcément 0, signifiant que tout est OK
        printf("D1 supprimé\n");
    }
    return EXIT_SUCCESS;
}