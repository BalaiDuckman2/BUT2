import java.util.ArrayList;
import java.util.List;

public class SystemePlainte implements Sujet {
    private List<Observateur> observateurs = new ArrayList<>();

    @Override
    public void ajouterObservateur(Observateur observateur) {
        observateurs.add(observateur);
    }

    @Override
    public void supprimerObservateur(Observateur observateur) {
        observateurs.remove(observateur);
    }

    @Override
    public void notifierObservateurs(String message) {
        for (Observateur observateur : observateurs) {
            observateur.miseAJour(message);
        }
    }

    public void enregistrerPlainte(Personne plaignant, Enseignant enseignant, String plainte) {
        String message = "Nouvelle plainte déposée par " + plaignant.getNom() +
                         " concernant " + enseignant.getNom() + ": " + plainte;
        System.out.println("Enregistrement de la plainte : " + message);
        notifierObservateurs(message);
    }
}
