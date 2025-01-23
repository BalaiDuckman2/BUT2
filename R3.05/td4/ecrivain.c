#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define PIPE_NAME "tube"

int main(int argc, char *argv[]) {
    int fd = open(PIPE_NAME, O_WRONLY);

    for (int i = 1; i < argc; i++) {
        write(fd, argv[i], strlen(argv[i]));
        if (i < argc - 1) {
            write(fd, " ", 1);
        }
    }

    write(fd, "\n", 1);

    close(fd);
    return 0;
}
