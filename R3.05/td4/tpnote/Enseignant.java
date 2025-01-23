public class Enseignant extends Personne {

    public Enseignant(String nom) {
        super(nom);
    }

    public void recevoirPlainte(Etudiant etudiant, String plainte) {
        System.out.println("Plainte de " + etudiant.getNom() + " reçue par " + this.nom + ": " + plainte);
    }
}
