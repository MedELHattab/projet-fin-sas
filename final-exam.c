int main() {
    Tache taches[MAX_TACHES];
    int nombreDeTaches = 0;

    int choix;
    do {
        printf("\nMenu :\n");
        printf("1. Ajouter une nouvelle tache\n");
        printf("2. Afficher toutes les taches\n");
        printf("3. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                nombreDeTaches = ajouterTache(taches, nombreDeTaches);
                break;
            case 2:
                afficherToutesLesTaches(taches, nombreDeTaches);
                break;
            case 3:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 3);
        return 0;
}
