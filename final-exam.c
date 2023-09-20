int main() {
    int choix;
    do {
        printf("\nMenu :\n");
        printf("1. Ajouter une nouvelle tache\n");
        printf("2. Afficher toutes les taches\n");
        printf("3. Supprimer une tache \n");
        printf("4. Rechercher une tache \n");
        printf("5. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterTache();
                break;
            case 2:
                afficherToutesLesTaches();
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
                    printf("1.chercher par id.\n");
                    printf("2.chercher par titre.\n");
		    printf("choix: ");
                    scanf("%d", &choixRechercher);
                    switch (choixRechercher) {
                        case 1 :
                             int idARechercher;
                             printf("Entrez l'identifiant de la tache a rechercher : ");
                             scanf("%d", &idARechercher);
                             rechercherTache(idARechercher);
                        break;
                        
                        case 2 :
                             int titleRechercher;
                             printf("Entrez le titre de la tache a rechercher : ");
                             scanf("%d", &titleRechercher);
                             rechercherTache(titleRechercher);
                             break ;
                        } 
                }    
                else {
                    printf("La liste de taches est vide.\n");
                }
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 5);

    return 0;
}
