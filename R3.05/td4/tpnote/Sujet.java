public interface Sujet {
    void ajouterObservateur(Observateur observateur);
    void supprimerObservateur(Observateur observateur);
    void notifierObservateurs(String message);
}