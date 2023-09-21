int main() {
    int choix;
    do {
        printf("\nMenu :\n");
        printf("1. Ajouter une nouvelle tache\n");
        printf("2. Afficher toutes les taches\n");
        printf("3. Supprimer une tache \n");
        printf("4. Rechercher une tache \n");
	printf("5. Afficher les Statistiques \n");
        printf("6. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                case 1:
                    int choice;
		    do {
                    printf("1.ajouter une nouvelle taches \n");
                    printf("2.quitter \n");
                    printf("entrez votre choix: ");
                    scanf("%d",&choice);
    
                    switch (choice) {
                    case 1 :
                    ajouterTache();
                    break ;
                    case 2 :
                    printf("retour au menu principale \n");
                    break ;
                    default:
                    printf("Choix invalide. Veuillez reessayer.\n");
                    }
                    }while (choice != 2)
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
			default:
                        printf("Choix invalide. Veuillez reessayer.\n");
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
    } while (choix != 6);

    return 0;
}
