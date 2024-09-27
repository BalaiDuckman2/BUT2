
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char chaine20[21];

typedef struct {
    chaine20 nom;
    int population;
    int superficie;
} t_capitale;

typedef struct {
    chaine20 nom;
    t_capitale capitale;
} t_pays;

void init_pays(t_pays *t) {
    printf("Nom du pays : ");
    scanf("%20s", t->nom);
    printf("Nom de la capitale : ");
    scanf("%20s", t->capitale.nom);
    printf("Population de la capitale : ");
    scanf("%d", &t->capitale.population);
    printf("Superficie de la capitale (en km²) : ");
    scanf("%d", &t->capitale.superficie);

}

void affiche_pays(t_pays t) {
    printf("Pays : %s\n", t.nom);
    printf("Capitale : %s\n", t.capitale.nom);
    printf("Population de la capitale : %d\n", t.capitale.population);
    printf("Superficie de la capitale : %d km²\n", t.capitale.superficie);
}

int main() {
    // Test avec une structure statique
    t_pays pays_statique;
    printf("Initialisation d'un pays (statique) :\n");
    init_pays(&pays_statique);
    printf("\nAffichage du pays (statique) :\n");
    affiche_pays(pays_statique);

    // Test avec une structure dynamique
    t_pays *pays_dynamique = (t_pays *)malloc(sizeof(t_pays));
    printf("\nInitialisation d'un pays (dynamique) :\n");
    init_pays(pays_dynamique);
    printf("\nAffichage du pays (dynamique) :\n");
    affiche_pays(*pays_dynamique);

    return 0;
}
