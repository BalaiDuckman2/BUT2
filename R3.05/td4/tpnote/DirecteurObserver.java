public class DirecteurObserver implements Observateur {
    private Directeur directeur;

    public DirecteurObserver(Directeur directeur) {
        this.directeur = directeur;
    }

    @Override
    public void miseAJour(String message) {
        directeur.notifier(message);
    }
}
