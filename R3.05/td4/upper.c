#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char c;

    fd = open("tube", O_RDONLY);


    while (read(fd, &c, sizeof(char)) > 0) {
        if ((c >= 'a') && (c <= 'z')) {
            c = c - 'a' + 'A';
        }
        printf("%c", c);
    }

    close(fd);

    return 0;
}