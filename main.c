#include <stdio.h>
#include <malloc.h>
#include "colomn.h"
#include "CDataframe.h"
#define MALLOC_SIZE 256

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
    printf("2. CDataframe rempli en dur  \n");
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
    while(choix !=18) {
        printf("Veuillez choisir une option\n");
        printf("1. Afficher le CDataframe en entier\n");
        printf("2. Afficher le CDataframe avec des lignes choisi\n");
        printf("3. Afficher le CDataframe avec des colonnes choisi\n");
        printf("4. Afficher le CDataframe avec des lignes et des colonnes choisi\n");
        printf("5. Ajouter une ligne de valeur\n");
        printf("6. Supprimer une ligne de valeur\n");
        printf("7. Ajouter une colonne de valeur\n");
        printf("8. Supprimer une colonne de valeur\n");
        printf("9. Renommer une colonne\n");
        printf("10. Vérifier l'existance d'une valeur dans le cdataframe\n"); //ne fonctionne pas
        printf("11. Accéder/remplacer la valeur se trouvant dans une cellule du CDATAFRAME\n");
        printf("12. Afficher le nom des colonnes\n");
        printf("13. Afficher le nombre de ligne\n");
        printf("14. Afficher le nombre de colonne\n");
        printf("15. Afficher le nombre de cellules égales à une valeur donnée\n");
        printf("16. Afficher le nombre de cellules supérieurs à une valeur donnée\n");
        printf("17. Afficher le nombre de cellules inférieurs à une valeur donnée\n");
        printf("18. Quitter\n");
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
                break;
            case 6:{
                int index;
                printf("ATTENTION : la case 1 correspond à la colonne et à la ligne 0\n");
                printf("Entrer la ligne que vous souhaitez supprimer :");
                scanf("%d", &index);
                delete_ligne_valeur(cdata, index);
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
                break;
            }
            case 8:
            {
                int indice;
                printf("ATTENTION : la case 1 correspond à la colonne et à la ligne 0\n");
                printf("Entrer la colonne que vous souhaitez supprimer :");
                scanf("%d", &indice);
                delete_colonne_valeur(cdata, indice);
                printf("Voici le cdataframe après la suppression de colonne :\n");
                afficher_cdataframe(cdata);
                break;
            }
            case 9:
            {
                int colonne;
                char nouveau_titre[MALLOC_SIZE];
                printf("ATTENTION : la case 1 correspond à la colonne et à la ligne 0\n");
                printf("Entrez le numéro de colonne que vous souhaitez renommer :\n");
                scanf("%d", &colonne);
                printf("Entrez le nouveau titre pour la colonne :\n");
                scanf("%s", nouveau_titre);
                rename_title(cdata, colonne, nouveau_titre);
                break;
            }
            case 10:
                printf("Entrez la valeur à rechercher :\n");
                int value;
                scanf("%d", &value);
                valeurExiste(&cdata, value);
                break;
            case 11:
                printf("ATTENTION : la case 1 correspond à la colonne et à la ligne 0\n");
                printf("Quelle ligne voulez-vous replacer ?\n");
                int ligne;
                scanf("%d", &ligne);
                int colonne;
                printf("Quelle colonne voulez-vous replacer ?\n");
                scanf("%d", &colonne);
                printf("Quel sera la nouvelle valeur ?\n");
                int nouvelle_valeur;
                scanf("%d", &nouvelle_valeur);
                replace_valeur(cdata, ligne, colonne, nouvelle_valeur);
                printf("Voici le nouveau CDataframe :\n");
                afficher_cdataframe(cdata);
                break;
            case 12:
                nom_colonne(cdata);
                break;
            case 13:
            {
                int lignes = nombre_Lignes(cdata);
                printf("Nombre de lignes : %d\n", lignes);
            }
                break;
            case 14:
            {
                int colonnes = nombre_Colonnes(cdata);
                printf("Nombre de colonnes : %d\n", colonnes);
            }
                break;
            case 15:{
                double x;
                printf("Saisissez la valeur x :\n");
                scanf("%lf", &x);
                printf("Nombre de cellules contenant la valeur %lf : %d\n", x, compter_egal(cdata, x));
                break;
            }
            case 16: {
                double x;
                printf("Saisissez la valeur x :\n");
                scanf("%lf", &x);
                printf("Nombre de cellules contenant une valeur supérieure à %lf : %d\n", x, compter_superieures(cdata, x));
                break;
            }
            case 17: {
                double x;
                printf("Saisissez la valeur x :\n");
                scanf("%lf", &x);
                printf("Nombre de cellules contenant une valeur inférieure à %lf : %d\n", x, compter_inferieures(cdata, x));
                break;
            }
            case 18:
                printf("Merci d'avoir utilisé notre cdataframe, a bientot !");
                break;
            default:
                printf("Choix invalide. Veuillez choisir une option valide.\n");
                break;
    }
    }
    free_cdataframe(cdata);
    return 0;
}

