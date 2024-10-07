#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main() {
    int orig_fd, old_fd;
    ssize_t read_bytes, write_bytes;
    char buffer[BUFFER_SIZE];

    // Ouvrir le fichier ORIG en lecture
    orig_fd = open("ORIG", O_RDONLY);
    if (orig_fd == -1) {
        perror("Erreur lors de l'ouverture du fichier ORIG");
        return EXIT_FAILURE;
    }

    // Ouvrir ou créer le fichier OLD en écriture
    old_fd = open("OLD", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (old_fd == -1) {
        perror("Erreur lors de la création du fichier OLD");
        close(orig_fd);
        return EXIT_FAILURE;
    }

    // Lire de ORIG et écrire dans OLD
    while ((read_bytes = read(orig_fd, buffer, BUFFER_SIZE)) > 0) {
        write_bytes = write(old_fd, buffer, read_bytes);
        if (write_bytes != read_bytes) {
            perror("Erreur lors de l'écriture dans le fichier OLD");
            close(orig_fd);
            close(old_fd);
            return EXIT_FAILURE;
        }
    }

    if (read_bytes == -1) {
        perror("Erreur lors de la lecture du fichier ORIG");
    }

    // Fermer les fichiers
    close(orig_fd);
    close(old_fd);

    printf("Copie terminée avec succès.\n");
    return EXIT_SUCCESS;
}