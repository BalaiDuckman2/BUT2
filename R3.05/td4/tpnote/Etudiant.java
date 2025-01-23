public class Etudiant extends Personne {
    public Etudiant(String nom) {
        super(nom);
    }

    public void deposerPlainte(Enseignant enseignant, SystemePlainte systeme, String plainte) {
        systeme.enregistrerPlainte(this, enseignant, plainte);
    }
}
