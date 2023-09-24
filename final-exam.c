int main() {
    int choix;
    do {
        printf("****************\n");
        printf("\nMenu :\n");
        printf("1. Ajouter une nouvelle tache.\n");
        printf("2. Afficher toutes les taches.\n");
        printf("3. Supprimer une tache.\n");
        printf("4. Rechercher une tache.\n");
        printf("5. Modifier une tache.\n");
        printf("6. Afficher les Statistiques.\n");
        printf("7. Quitter\n");
        printf("****************\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                int choice;
                do {
                    printf("1. Ajouter une nouvelle tache\n");
                    printf("2. Quitter\n");
                    printf("Entrez votre choix : ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            ajouterTache();
                            break;
                        case 2:
                            printf("Retour au menu principal\n");
                            break;
                        default:
                            printf("Choix invalide. Veuillez reessayer.\n");
                    }
                } while (choice != 2);
                break;
            case 2:
                int aff;
                do {
                    printf("1. Trier les tâches par ordre alphabétique.\n");
                    printf("2. Trier les tâches par deadline.\n");
                    printf("3. Afficher les tâches dont le deadline est dans 3 jours ou moins.\n");
                    printf("4. Retour au menu principal.\n");
                    printf("Entrez votre choix : ");
                    scanf("%d", &aff);
                    switch (aff) {
                        case 1:
                            // Mettez ici la logique pour trier par ordre alphabétique
                            printf("Trier par ordre alphabétique\n");
                            break;
                        case 2:
                            // Mettez ici la logique pour trier par deadline
                            printf("Trier par deadline\n");
                            break;
                        case 3:
                            // Mettez ici la logique pour afficher les tâches avec un délai de 3 jours ou moins
                            printf("Afficher les tâches avec un délai de 3 jours ou moins\n");
                            break;
                        case 4:
                            printf("Retour au menu principal\n");
                            break;
                        default:
                            printf("Choix invalide. Veuillez reessayer.\n");
                    }
                } while (aff != 4);
                break;
            case 3:
                if (nombreDeTaches > 0) {
                    int idASupprimer;
                    printf("Entrez l'identifiant de la tache a supprimer : ");
                    scanf("%d", &idASupprimer);
                    supprimerTache(idASupprimer);
                } else {
                    printf("La liste de taches est vide.\n");
                }
                break;
            case 4:
                if (nombreDeTaches > 0) {
                    int choixRechercher;
                    printf("1. Chercher par ID.\n");
                    printf("2. Chercher par titre.\n");
                    printf("Entrez votre choix : ");
                    scanf("%d", &choixRechercher);
                    switch (choixRechercher) {
                        case 1:
                            int idARechercher;
                            printf("Entrez l'identifiant de la tache a rechercher : ");
                            scanf("%d", &idARechercher);
                            rechercherTache1(idARechercher);
                            break;

                        case 2:
                            char titreARechercher[50];
                            printf("Entrez le titre de la tache a rechercher : ");
                            scanf(" %[^\n]", titreARechercher);
                            rechercherTache2(titreARechercher);
                            break;
                        default:
                            printf("Choix invalide. Veuillez reessayer.\n");
                    }
                } else {
                    printf("La liste de taches est vide.\n");
                }
                break;
            case 5:
                modifyTask();
                break;
            case 6:
                int stat;
                do {
                    printf("1. Afficher le nombre total des tâches.\n");
                    printf("2. Afficher le nombre de tâches complètes et incomplètes.\n");
                    printf("3. Afficher le nombre de jours restants jusqu'au délai de chaque tâche.\n");
                    printf("4. Retour au menu principal.\n");
                    printf("Entrez votre choix : ");
                    scanf("%d", &stat);
                    switch (stat) {
                        case 1:
                            stat1();
                            break;
                        case 2:
                            stat2();
                            break;
                        case 3:
                            stat3();
                            break;
                        case 4:
                            printf("Retour au menu principal\n");
                            break;
                        default:
                            printf("Choix invalide. Veuillez reessayer.\n");
                    }
                } while (stat != 4);
                break;
            case 7:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 7);

    return 0;
}
