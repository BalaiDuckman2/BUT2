typedef char chaine20[21];

typedef struct
{
    chaine20 nom;
    int population;
    chaine20 capitale;
} t_region;

int main(int argc, char const *argv[])
{
    // Question 1
        t_region P1;
        printf("Entrez le nom de la région : ");
        scanf("%20s", P1.nom);
        printf("Entrez la population de la région : ");
        scanf("%d", &P1.population);
        printf("Entrez la capitale de la région : ");
        scanf("%20s", P1.capitale);
    
        printf("\nRégion : %s\n", P1.nom);
        printf("Population : %d\n", P1.population);
        printf("Capitale : %s\n\n", P1.capitale);
    
        // Question 2
        typedef t_region* pt_region;
        pt_region ptr = (pt_region)malloc(sizeof(t_region));
        
        strcpy(ptr->nom, "Bretagne");
        ptr->population = 600000;
        strcpy(ptr->capitale, "Rennes");
        
    
        printf("Région : %s\n", ptr->nom);
        printf("Population : %d\n", ptr->population);
        printf("Capitale : %s\n\n", ptr->capitale);
    
        // Question 3
        printf("Entrez le nom de la nouvelle région : ");
        scanf("%20s", ptr->nom);
        printf("Entrez la population de la nouvelle région : ");
        scanf("%d", &ptr->population);
        printf("Entrez la capitale de la nouvelle région : ");
        scanf("%20s", ptr->capitale);
    
        printf("\nNouvelle région : %s\n", ptr->nom);
        printf("Population : %d\n", ptr->population);
        printf("Capitale : %s\n", ptr->capitale);
    
    
    return 0;
}
