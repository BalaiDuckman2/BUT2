public class Directeur {
    private static Directeur instance;
    private String nom;

    private Directeur(String nom) {
        this.nom = nom;
    }

    public static Directeur getInstance(String nom) {
        if (instance == null) {
            instance = new Directeur(nom);
        }
        return instance;
    }

    public void notifier(String message) {
        System.out.println("Directeur " + nom + " a été averti : " + message);
    }
}
