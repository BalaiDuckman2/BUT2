#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#define PIPE_NAME "tube"

void handle_sigpipe(int sig) {
    printf("Signal SIGPIPE reçu (code : %d) - Échec d'écriture dans le tube\n", sig);
}

int main(int argc, char *argv[]) {
    int fd;

    signal(SIGPIPE, handle_sigpipe);

    fd = open(PIPE_NAME, O_WRONLY);

    for (int i = 1; i < argc; i++) {
        int ret = write(fd, argv[i], strlen(argv[i]));
        printf("write() retourne : %d, errno : %d\n", ret, errno);
        perror("Résultat du write");

        if (i < argc - 1) {
            ret = write(fd, " ", 1);
            printf("write() retourne : %d, errno : %d\n", ret, errno);
            perror("Résultat du write");
        }
    }

    int ret = write(fd, "\n", 1);
    printf("write() retourne : %d, errno : %d\n", ret, errno);
    perror("Résultat du write");

    close(fd);

    return 0;
}
