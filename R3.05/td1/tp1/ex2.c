
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    struct stat file_info;
    const char *filename = "ORIG";

    if (stat(filename, &file_info) == -1) {
        perror("Error getting file information");
        return 1;
    }

    printf("Informations sur le fichier %s:\n", filename);
    printf("Numéro d'inode: %lu\n", file_info.st_ino);
    printf("Droits sur le fichier (format octal): %o\n", file_info.st_mode & 0777);
    printf("User ID (UID) du propriétaire: %d\n", file_info.st_uid);
    printf("Groupe ID (GID) du groupe propriétaire: %d\n", file_info.st_gid);
    printf("Taille du fichier (en octets): %ld\n", file_info.st_size);

    return 0;
}
