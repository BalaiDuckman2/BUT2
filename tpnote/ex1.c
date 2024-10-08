#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  char chaine[50];


typedef struct { 
    chaine nom;
    float prix; 
    int quantite; 
} tproduit ;

typedef struct elem { 
    tproduit prod;
    struct elem* svt;
} telement ;

typedef telement* tliste;

void init(tliste *panier) {
    *panier = NULL;
}

void afficherPanier(tliste panier) {
    telement* current = panier;
    printf("Panier:\n");
    while (current != NULL) {
        printf("Produit: %s, Prix: %.2f, Quantité: %d\n", current->prod.nom, current->prod.prix, current->prod.quantite);
        current = current->svt;
    }
}


void ajouterProduit(tliste* panier, chaine nom, float prix, int quantite) {
    telement* nouvelElement = (telement*)malloc(sizeof(telement));
    strcpy(nouvelElement->prod.nom, nom);
    nouvelElement->prod.prix = prix;
    nouvelElement->prod.quantite = quantite;
    nouvelElement->svt = *panier;
    *panier = nouvelElement;
}


float calculerTotal(tliste panier) {
    telement* current = panier;
    float total = 0.0;
    while (current != NULL) {
        total += current->prod.prix * current->prod.quantite;
        current = current->svt;
    }
    return total;
}


int trouverProduit(tliste panier, chaine nomProduit) {
    telement* current = panier;
    while (current != NULL) {
        if (strcmp(current->prod.nom, nomProduit) == 0) {
            return 1;
        }
        current = current->svt;
    }
    return 0;
}


int modifierQuantite(tliste panier, chaine nomProduit, int nouvelleQuantite) {
    telement* current = panier;
    while (current != NULL) {
        if (strcmp(current->prod.nom, nomProduit) == 0) {
            current->prod.quantite = nouvelleQuantite;
            return 1;
        }
        current = current->svt;
    }
    return 0;
}


tproduit* trouverProduitLePlusCher(tliste panier) {
    if (panier == NULL) return NULL;

    telement* current = panier;
    telement* produitLePlusCher = current;
    while (current != NULL) {
        if (current->prod.prix > produitLePlusCher->prod.prix) {
            produitLePlusCher = current;
        }
        current = current->svt;
    }
    return &(produitLePlusCher->prod);
}


void suprimerProduit(tliste* panier, chaine nomProduit) {
    if (*panier == NULL) {
        printf("Le panier est vide.\n");
        return;
    }

    telement* current = *panier;
    telement* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->prod.nom, nomProduit) == 0) {
            
            if (previous == NULL) {
                *panier = current->svt;
            } else {
                previous->svt = current->svt;
            }
            free(current);
            printf("Produit \"%s\" supprimé du panier.\n", nomProduit);
            return;
        }
        previous = current;
        current = current->svt;
    }
    
    printf("Produit \"%s\" non trouvé dans le panier.\n", nomProduit);
}



void viderPanier(tliste* panier) {
    telement* current = *panier;
    telement* temp;

    while (current != NULL) {
        temp = current;  
        current = current->svt;
        free(temp);  
    }

    *panier = NULL;
    printf("Le panier a été vidé.\n");
}



int main() {
    tliste panier;
    init(&panier);

    ajouterProduit(&panier, "Pomme", 2.50, 5);
    ajouterProduit(&panier, "Banane", 1.00, 10);
    ajouterProduit(&panier, "Orange", 3.00, 7);

    printf("Affichage du panier:\n");
    afficherPanier(panier);

    printf("\nTotal du panier: %.2f\n", calculerTotal(panier));

    tproduit* produitCher = trouverProduitLePlusCher(panier);
    printf("\nProduit le plus cher: %s, Prix: %.2f\n", produitCher->nom, produitCher->prix);
    

    printf("\nModification de la quantité des pommes à 8.\n");
    modifierQuantite(panier, "Pomme", 8);
    afficherPanier(panier);

    printf("\nSuppression du premier produit.\n");
    suprimerProduit(&panier, "Banane");
    afficherPanier(panier);

    printf("\nVidage du panier.\n");
    viderPanier(&panier);
    afficherPanier(panier);

    return 0;
}
