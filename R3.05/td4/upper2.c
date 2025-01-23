#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define PIPE_NAME "tube"

int main() {
    int fd;

    fd = open(PIPE_NAME, O_RDONLY);

    close(fd);

    return 0;
}
