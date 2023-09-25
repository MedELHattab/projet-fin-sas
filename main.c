#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Déclaration de tableaux pour stocker les données des tâches
#define MAX_TACHES 100

int id[MAX_TACHES];
char titres[MAX_TACHES][50];
char descriptions[MAX_TACHES][100];
char deadlines[MAX_TACHES][20];
char statuts[MAX_TACHES][20];

int nombreDeTaches = 0;

// Fonction pour ajouter une nouvelle tâche
void ajouterTache() {
    if (nombreDeTaches >= MAX_TACHES) {
        printf("La liste de taches est pleine.\n");
        return;
    }

    id[nombreDeTaches] = nombreDeTaches + 1;

    printf("Titre de la tache : ");
    scanf(" %[^\n]", titres[nombreDeTaches]);

    printf("Description de la tache : ");
    scanf(" %[^\n]", descriptions[nombreDeTaches]);

    printf("Deadline (JJ/MM/AAAA) : ");
    scanf(" %s", deadlines[nombreDeTaches]);

    printf("Statut (A faire/En cours/Finalisee) : ");
    scanf(" %s", statuts[nombreDeTaches]);

    nombreDeTaches++;
}

// Fonction pour afficher toutes les tâches
void afficherToutesLesTaches() {
    printf("\nListe de taches :\n");
    for (int i = 0; i < nombreDeTaches; i++) {
        printf("ID : %d\n", id[i]);
        printf("Titre : %s\n", titres[i]);
        printf("Description : %s\n", descriptions[i]);
        printf("Deadline : %s\n", deadlines[i]);
        printf("Statut : %s\n", statuts[i]);
        printf("-----------------------\n");
    }
}

// Fonction pour supprimer une tâche par identifiant
void supprimerTache(int idASupprimer) {
    int indexASupprimer = -1;
    for (int i = 0; i < nombreDeTaches; i++) {
        if (id[i] == idASupprimer) {
            indexASupprimer = i;
            break;
        }
    }

    if (indexASupprimer != -1) {
        for (int i = indexASupprimer; i < nombreDeTaches - 1; i++) {
            id[i] = id[i + 1];
            strcpy(titres[i], titres[i + 1]);
            strcpy(descriptions[i], descriptions[i + 1]);
            strcpy(deadlines[i], deadlines[i + 1]);
            strcpy(statuts[i], statuts[i + 1]);
        }
        nombreDeTaches--;
    } else {
        printf("Tache avec l'identifiant %d non trouvee.\n", idASupprimer);
    }
}

// Fonction pour rechercher une tâche par identifiant
void rechercherTache1(int idARechercher) {
    printf("\nResultats de la recherche :\n");
    for (int i = 0; i < nombreDeTaches; i++) {
        if (id[i] == idARechercher) {
            printf("ID : %d\n", id[i]);
            printf("Titre : %s\n", titres[i]);
            printf("Description : %s\n", descriptions[i]);
            printf("Deadline : %s\n", deadlines[i]);
            printf("Statut : %s\n", statuts[i]);
            printf("-----------------------\n");
            return;
        }
    }
    printf("Tache avec l'identifiant %d non trouvee.\n", idARechercher);
}

void rechercherTache2(char *titreARechercher) {
    printf("\nResultats de la recherche :\n");
    for (int i = 0; i < nombreDeTaches; i++) {
        if (strcmp(titres[i], titreARechercher) == 0) {
            printf("ID : %d\n", id[i]);
            printf("Titre : %s\n", titres[i]);
            printf("Description : %s\n", descriptions[i]);
            printf("Deadline : %s\n", deadlines[i]);
            printf("Statut : %s\n", statuts[i]);
            printf("-----------------------\n");
        }
    }
}

// Fonction pour modifier une tâche par son ID
void modifyTask() {
    int idmodify;
    printf("Entrer l'ID de la tâche que vous voulez modifier : ");
    scanf("%d", &idmodify);

    int found = 0;
    for (int i = 0; i < nombreDeTaches; i++) {
        if (id[i] == idmodify) {
            found = 1;
            printf("La description actuelle : %s\n", descriptions[i]);
            printf("Entrer la nouvelle description : ");
            scanf(" %[^\n]", descriptions[i]);

            printf("Le deadline actuel : %s\n", deadlines[i]);
            printf("Entrer le nouveau deadline : ");
            scanf(" %[^\n]", deadlines[i]);

            printf("Le statut actuel : %s\n", statuts[i]);
            printf("Entrer le nouveau statut : ");
            scanf(" %[^\n]", statuts[i]);
            printf("Tâche avec l'ID %d a été modifiée avec succès.\n", idmodify);
            break;
        }
    }

    if (!found) {
        printf("Tâche avec l'ID %d n'a pas été trouvée.\n", idmodify);
    }
}

// Fonction pour afficher le nombre total de tâches
void stat1() {
    printf("Nombre total de taches : %d\n", nombreDeTaches);
}

// Fonction pour afficher le nombre de tâches complètes et incomplètes
void stat2() {
    int complete = 0;
    int incomplete = 0;

    for (int i = 0; i < nombreDeTaches; i++) {
        if (strcmp(statuts[i], "Finalisee") == 0) {
            complete++;
        } else {
            incomplete++;
        }
    }

    printf("Nombre de taches completes : %d\n", complete);
    printf("Nombre de taches incompletes : %d\n", incomplete);
}

// Fonction pour afficher le nombre de jours restants jusqu'à la deadline de chaque tâche
void stat3() {
    printf("\nJours restants pour chaque tache :\n");

    // Obtenir la date actuelle
    time_t now;
    struct tm *tm_info;
    time(&now);
    tm_info = localtime(&now);

    for (int i = 0; i < nombreDeTaches; i++) {
        // Convertir la date de la deadline en structure tm
        struct tm deadline_tm;
        sscanf(deadlines[i], "%d/%d/%d", &deadline_tm.tm_mday, &deadline_tm.tm_mon, &deadline_tm.tm_year);
        deadline_tm.tm_mon -= 1; // Mois commence à 0 (janvier)

        // Convertir les deux dates en timestamps
        time_t deadline_time = mktime(&deadline_tm);
        time_t current_time = mktime(tm_info);

        // Calculer la différence en jours
        double diff = difftime(deadline_time, current_time);
        int jours_restants = (int)(diff / (60 * 60 * 24));

        printf("ID : %d\n", id[i]);
        printf("Titre : %s\n", titres[i]);
        printf("Jours restants : %d jours\n", jours_restants);
        printf("-----------------------\n");
    }
}

int main() {
    int choix;
    do {
        printf("******\n");
        printf("\nMenu :\n");
        printf("1. Ajouter une nouvelle tache.\n");
        printf("2. Afficher toutes les taches.\n");
        printf("3. Supprimer une tache.\n");
        printf("4. Rechercher une tache.\n");
        printf("5. Modifier une tache.\n");
        printf("6. Afficher les Statistiques.\n");
        printf("7. Quitter\n");
        printf("******\n");
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
