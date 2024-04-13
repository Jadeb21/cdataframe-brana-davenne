#include <stdio.h>
#include <malloc.h>
#include "function.h"
#include "CDataframe.h"


int main(){
    int num_lignes, num_columns;
    int choice;
    int choix;
    printf("Bonjour et bienvenue dans le menu du CDataframe !\n");
    printf("Merci de suivre les informations suivantes\n");
    printf("Saisir le nombre de colonnes :");
    scanf("%d", &num_columns);
    printf("Saisir le nombre de lignes :");
    scanf("%d", &num_lignes);
    CDATAFRAME* cdata = create_cdataframe(num_columns, num_lignes);
    printf("Veuillez choisir une option : \n");
    printf("1. CDataframe rempli par saisie utilisateur \n");
    printf("2. CDataframe rempli en dur  \n"); //ne fonctionne pas
    printf("3. Quitter \n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            input_user(cdata);
            break;
        case 2:
            rempli_en_dur(cdata);
            break;
        case 3:
            printf("Merci d'avoir utilisé notre cdataframe, a bientot !");
            break;
        default:
            printf("Erreur\n");
            break;
    }
    printf("Veuillez choisir une option\n");
    printf("1. Afficher le CDataframe en entier\n");
    printf("2. Afficher le CDataframe avec des lignes choisi\n");
    printf("3. Afficher le CDataframe avec des colonnes choisi\n");
    printf("4. Afficher le CDataframe avec des lignes et des colonnes choisi\n");
    printf("5. Ajouter une ligne de valeur\n");
    printf("6. Supprimer une ligne de valeur\n");
    printf("7. Ajouter une colonne de valeur\n");
    printf("8. Supprimer une colonne de valeur\n");
    printf("15. Quitter\n");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            printf("Voici le CDataframe en entier :\n");
            afficher_cdataframe(cdata);
            break;
        case 2:
            printf("Entrer le nombre de ligne que vous voulez afficher :\n");
            int lim_ligne;
            scanf("%d", &lim_ligne);
            afficher_limit_lignes(cdata, lim_ligne);
            break;
        case 3:
            printf("Entrer le nombre de colonne que vous voulez afficher :\n");
            int lim_col;
            scanf("%d", &lim_col);
            afficher_limit_col(cdata, lim_col);
            break;
        case 4:
            printf("Entrer le nombre de colonne que vous voulez afficher :\n");
            int lim_colo;
            scanf("%d", &lim_colo);
            printf("Entrer le nombre de ligne que vous voulez afficher :\n");
            int lim_lignes;
            scanf("%d", &lim_lignes);
            afficher_limit_colligne(cdata, lim_colo, lim_lignes);
            break;
            double *new_row;
        case 5:
            new_row = (double*)malloc(cdata->num_columns * sizeof(double));
            printf("Entrez les valeurs de la nouvelle ligne :\n");
            for (int i = 0; i < cdata->num_columns; i++) {
                printf("Valeur pour la colonne %d :", i + 1);
                scanf("%lf", &new_row[i]);
            }
            ajout_ligne_valeur(cdata, new_row);
            printf("Voici maintenant le cdataframe après l'ajout de ligne :\n");
            afficher_cdataframe(cdata);
            break;
        case 6:{
            int index;
            printf("Entrer la ligne que vous souhaitez supprimer :");
            scanf("%d", &index);
            delete_ligne_valeur(cdata, index);
            printf("Voici maintenant le cdataframe après la suppression de ligne :\n");
            afficher_cdataframe(cdata);
            break;
        }
        case 7:
        {
            double values[cdata->num_lignes];
            printf("Entrez les valeurs pour la nouvelle colonne :\n");
            for (int i = 0; i < cdata->num_lignes; i++) {
                printf("Ligne %d :", i+1);
                scanf("%lf", &values[i]);
            }
            ajout_colonne_valeur(cdata, values);
            afficher_cdataframe(cdata);
            break;
        }
        case 8:
        {
            int indice;
            printf("Entrer la colonne que vous souhaitez supprimer :");
            scanf("%d", &indice);
            delete_colonne_valeur(cdata, indice);
            printf("Voici le cdataframe après la suppression de colonne :\n");
            afficher_cdataframe(cdata);
            break;
        }
        case 15:
            printf("Merci d'avoir utilisé notre cdataframe, a bientot !");
            break;

    }
    return 0;
}