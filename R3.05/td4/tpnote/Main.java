public class Main {
    public static void main(String[] args) {
        // Création du directeur (Singleton)
        Directeur directeur = Directeur.getInstance("Dupont");

        // Ajout du directeur comme observateur
        DirecteurObserver directeurObserver = new DirecteurObserver(directeur);
        SystemePlainte systemePlainte = new SystemePlainte();
        systemePlainte.ajouterObservateur(directeurObserver);

        // Création des enseignants et étudiants
        Enseignant tournesol = new Enseignant("Tournesol");
        Etudiant zigomar = new Etudiant("Zigomar");

        // Déposer une plainte
        zigomar.deposerPlainte(tournesol, systemePlainte, "Problème de toner sur l'imprimante");
    }
}
