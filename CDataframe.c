//
// Created by jadeb on 28/03/2024.
//

#include "CDataframe.h"
#include <stdlib.h>
#define MALLOC_SIZE 256
#define MAX_TITLE_LENGTH 50
#include <stdio.h>
#include <string.h>

//Création CDataframe vide
CDATAFRAME *create_cdataframe(int num_columns, int num_lignes){
    CDATAFRAME* cdata = (CDATAFRAME*)malloc(sizeof(CDATAFRAME));
    if (cdata == NULL) {
        printf("Erreur.\n");
        exit(EXIT_FAILURE);
    }
    cdata->num_lignes = num_lignes;
    cdata->num_columns = num_columns;
    cdata->tab = (double**)malloc(num_lignes * sizeof(double*));
    if (cdata->tab == NULL) {
        printf("Erreur.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_lignes; i++) {
        cdata->tab[i] = (double*)malloc(num_columns * sizeof(double));
        if (cdata->tab[i] == NULL) {
            printf("Erreur.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Allouer de la mémoire pour les noms de colonnes
    cdata->columns = (COLUMN**)malloc(num_columns * sizeof(COLUMN*));
    if (cdata->columns == NULL) {
        printf("Erreur.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_columns; i++) {
        cdata->columns[i] = (COLUMN*)malloc(sizeof(COLUMN));
        if (cdata->columns[i] == NULL) {
            printf("Erreur.\n");
            exit(EXIT_FAILURE);
        }
        // Allouer de la mémoire pour le titre de la colonne
        cdata->columns[i]->title = (char*)malloc(MAX_TITLE_LENGTH * sizeof(char));
        if (cdata->columns[i]->title == NULL) {
            printf("Erreur.\n");
            exit(EXIT_FAILURE);
        }
        cdata->columns[i]->tl = num_lignes;
        cdata->columns[i]->tab = (int*)malloc(num_lignes * sizeof(int));
        if (cdata->columns[i]->tab == NULL) {
            printf("Erreur.\n");
            exit(EXIT_FAILURE);
        }
    }

    return cdata;
}

//Saisie Utilisateur
void input_user(CDATAFRAME* cdata){
    for (int i = 0; i < cdata->num_lignes; i++) {
        printf("Remplisser la ligne %d :\n", i+1);
        for (int j = 0; j < cdata->num_columns; j++) {
            printf("Saisir la valeur de la colonne %d :\n", j+1);
            scanf("%lf", &cdata->tab[i][j]);
        }
    }
}

void rempli_en_dur(CDATAFRAME *cdata) {
    if (cdata == NULL || cdata->tab == NULL) {
        printf("Erreur : CDataframe non initialisé ou tableau de données non alloué.\n");
        return;
    }

    for (int i = 0; i < cdata->num_lignes; i++) {
        for (int j = 0; j < cdata->num_columns; j++) {
            cdata->tab[i][j] = (double)(i * cdata->num_columns + j + 1);
        }
    }
}

void afficher_cdataframe(CDATAFRAME* cdata){
    if (cdata == NULL || cdata->tab == NULL) {
        printf("CDataframe non initialisé ou tableau de données non alloué.\n");
        return;
    }

    printf("CDataframe :\n");
    for (int i = 0; i < cdata->num_lignes; i++) {
        for (int j = 0; j < cdata->num_columns; j++) {
            printf("%.2f\t", cdata->tab[i][j]);
        }
        printf("\n");
    }
}

void afficher_limit_lignes(CDATAFRAME* cdata, int lim_ligne) {
    printf("Affichage des %d premières lignes :\n", lim_ligne);
    for (int i = 0; i < lim_ligne && i < cdata->num_lignes; i++) {
        for (int j = 0; j < cdata->num_columns; j++) {
            printf("%.2f\t", cdata->tab[i][j]);
        }
        printf("\n");
    }
}

void afficher_limit_col(CDATAFRAME* cdata, int lim_col) {
    printf("Affichage des %d premières colonnes :\n", lim_col);
    for (int i = 0; i < cdata->num_lignes; i++) {
        for (int j = 0; j < lim_col && j < cdata->num_columns; j++) {
            printf("%.2f\t", cdata->tab[i][j]);
        }
        printf("\n");
    }
}

void afficher_limit_colligne(CDATAFRAME* cdata, int lim_lignes, int lim_colo) {
    printf("Affichage des %d colonnes ", lim_colo);
    printf("et des %d ligne(s):\n", lim_lignes);
    for (int i = 0; i < lim_lignes && i < cdata->num_lignes; i++) {
        for (int j = 0; j < lim_colo && j < cdata->num_columns; j++) {
            printf("%.2f\t", cdata->tab[i][j]);
        }
        printf("\n");
    }
}

void ajout_ligne_valeur(CDATAFRAME* cdata, double* val){
    cdata->num_lignes++;
    cdata->tab = (double**)realloc(cdata->tab, cdata->num_lignes * sizeof(double*));
    cdata->tab[cdata->num_lignes - 1] = (double*)malloc(cdata->num_columns * sizeof(double));
    for (int i = 0; i < cdata->num_columns; i++) {
        cdata->tab[cdata->num_lignes - 1][i] = val[i];
    }
}

void delete_ligne_valeur(CDATAFRAME* cdata, int index){
    if (index < 0 || index >= cdata->num_lignes) {
        printf("Erreur : Indice de ligne invalide.\n");
        return;
    }

    // Libérer la mémoire allouée pour la ligne à supprimer
    free(cdata->tab[index]);

    for (int i = index; i < cdata->num_lignes - 1; i++) {
        cdata->tab[i] = cdata->tab[i + 1];
    }
    cdata->tab = (double**)realloc(cdata->tab, (cdata->num_lignes - 1) * sizeof(double*));

    cdata->num_lignes--;
}

void ajout_colonne_valeur(CDATAFRAME* cdata, double* val){
    cdata->num_columns++;

    for (int i = 0; i < cdata->num_lignes; i++) {
        cdata->tab[i] = (double*)realloc(cdata->tab[i], cdata->num_columns * sizeof(double));

        cdata->tab[i][cdata->num_columns - 1] = val[i];
    }
}

void delete_colonne_valeur(CDATAFRAME* cdata, int index){
    if (index < 0 || index >= cdata->num_columns) {
        printf("Erreur : Indice de colonne invalide.\n");
        return;
    }

    // Libérer la mémoire allouée pour la colonne à supprimer
    for (int i = 0; i < cdata->num_lignes; i++) {
        for (int j = index; j < cdata->num_columns - 1; j++) {
            cdata->tab[i][j] = cdata->tab[i][j + 1];
        }
        // Réallouer la mémoire
        cdata->tab[i] = (double*)realloc(cdata->tab[i], (cdata->num_columns - 1) * sizeof(double));
    }
    for (int i = index; i < cdata->num_columns - 1; i++) {
        cdata->columns[i] = cdata->columns[i + 1];
    }
    cdata->num_columns--;
}

void rename_title(CDATAFRAME* cdata, int column_index, char* new_title) {

    if (column_index < 0 || column_index >= cdata->num_columns) {
        printf("Erreur : Index de colonne invalide.\n");
        return;
    }

    if (new_title == NULL) {
        printf("Erreur : Le nouveau titre est vide.\n");
        return;
    }

    strncpy(cdata->columns[column_index]->title, new_title, MALLOC_SIZE - 1);
    cdata->columns[column_index]->title[MALLOC_SIZE - 1] = '\0';

    printf("La colonne %d se nomme maintenant %s.\n", column_index, cdata->columns[column_index]->title);
}

int valeurExiste(CDATAFRAME* cdata, double value) {
    int test;
    for (int i = 0; i < cdata->num_lignes; i++) {
        for (int j = 0; j < cdata->num_columns; j++) {

            if (cdata->tab[i][j] == value) {
                test = cdata->tab[i][j];
            }

        }
    }
    if (test == value) {
    printf("La valeur est présente !\n");
}
    else {
printf("La valeur n'est pas présente dans le cdataframe.\n");
}
}



void replace_valeur(CDATAFRAME* cdata, int ligne, int column, double new_value) {
    if (cdata == NULL) {
        printf("Erreur.\n");
        return;
    }

    if (ligne < 0 || ligne >= cdata->num_lignes || column < 0 || column >= cdata->num_columns) {
        printf("Erreur : Indice de la ligne ou de la colonne invalide.\n");
        return;
    }

    cdata->tab[ligne][column] = new_value;
    printf("La valeur à la ligne %d et à la colonne %d a été remplacée par %.2lf.\n", ligne, column, new_value);
}

void nom_colonne(CDATAFRAME* cdata) {
    printf("Noms des colonnes :\n");
    for (int i = 0; i < cdata->num_columns; i++) {
        printf("%s\t", cdata->columns[i]->title);
    }
    printf("\n");
}

int nombre_Lignes(CDATAFRAME *cdata) {
    return cdata->num_lignes;
}

int nombre_Colonnes(CDATAFRAME *cdata) {
    return cdata->num_columns;
}

int compter_egal(CDATAFRAME* cdata, double x) {
    int count = 0;
    for (int i = 0; i < cdata->num_lignes; ++i) {
        for (int j = 0; j < cdata->num_columns; ++j) {
            if (cdata->tab[i][j] == x) {
                count++;
            }
        }
    }

    return count;
}

int compter_superieures(CDATAFRAME* cdata, double x) {
    int count = 0;
    for (int i = 0; i < cdata->num_lignes; ++i) {
        for (int j = 0; j < cdata->num_columns; ++j) {
            if (cdata->tab[i][j] > x) {
                count++;
            }
        }
    }

    return count;
}

int compter_inferieures(CDATAFRAME* cdata, double x) {
    int count = 0;
    for (int i = 0; i < cdata->num_lignes; ++i) {
        for (int j = 0; j < cdata->num_columns; ++j) {
            if (cdata->tab[i][j] < x) {
                count++;
            }
        }
    }

    return count;
}

void free_cdataframe(CDATAFRAME* cdata) {
    if (cdata == NULL) {
        return;
    }

    // Libérer la mémoire allouée pour le tableau de données
    for (int i = 0; i < cdata->num_lignes; i++) {
        free(cdata->tab[i]);
    }
    free(cdata->tab);

    // Libérer la mémoire allouée pour chaque colonne
    for (int i = 0; i < cdata->num_columns; i++) {
        free(cdata->columns[i]->tab);
        free(cdata->columns[i]);
    }
    free(cdata->columns);

    // Libérer la mémoire allouée pour la structure CDATAFRAME elle-même
    free(cdata);
}
