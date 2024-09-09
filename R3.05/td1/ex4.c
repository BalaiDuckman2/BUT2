
#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *ent;
    int count = 0;

    dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_name[0] != '.') {
            printf("%s\n", ent->d_name);
            count++;
        }
    }

    closedir(dir);

    printf("Total objects listed: %d\n", count);

    return 0;
}
