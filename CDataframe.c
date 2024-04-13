//
// Created by jadeb on 28/03/2024.
//

#include "CDataframe.h"
#include <stdlib.h>
#define MALLOC_SIZE 256
#include <stdio.h>

//Création CDataframe vide
CDATAFRAME *create_cdataframe(int num_columns, int num_lignes){
    CDATAFRAME* cdata = (CDATAFRAME*)malloc(sizeof(CDATAFRAME));
    if (cdata == NULL) {
        printf("Erreur lors de l'allocation de mémoire pour le CDataframe.\n");
        exit(EXIT_FAILURE);
    }
    cdata->num_lignes = num_lignes;
    cdata->num_columns = num_columns;
    cdata->tab = (double**)malloc(num_lignes * sizeof(double*));
    if (cdata->tab == NULL) {
        printf("Erreur lors de l'allocation de mémoire pour les données du CDataframe.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < num_lignes; i++) {
        cdata->tab[i] = (double*)malloc(num_columns * sizeof(double));
        if (cdata->tab[i] == NULL) {
            printf("Erreur lors de l'allocation de mémoire pour les données du CDataframe.\n");
            exit(EXIT_FAILURE);
        }
    }

    //Permet l'initialisation de plusieurs colonnes lors de la saisie utilisateur
    cdata->columns = (COLUMN**)malloc(num_columns * sizeof(COLUMN*));
    for (int i = 0; i < num_columns; i++) {
        cdata->columns[i] = (COLUMN*)malloc(sizeof(COLUMN));
        cdata->columns[i]->tl = num_lignes;
        cdata->columns[i]->tab = (int*)malloc(num_lignes * sizeof(int));
    }
    return cdata;
}

//Saisie Utilisateur
void input_user(CDATAFRAME* cdata){
    for (int i = 0; i < cdata->num_lignes; i++) {
        printf("Remplisser la ligne %d :\n", i+1);
        for (int j = 0; j < cdata->num_columns; j++) {
            printf("Veuillez mettre la valeur de la colonne %d :", j+1);
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

void afficher_limit_lignes(CDATAFRAME* cdata, int lim_ligne){
    printf("Affichage des %d premières lignes :\n", lim_ligne);
    for (int i = 0;  i < lim_ligne && i < cdata->num_lignes; i++) {
        for (int j = 0; j < cdata->num_columns; j++) {
            printf("%d\t", cdata->columns[j]->tab[i]);
        }
        printf("\n");
    }
}

void afficher_limit_col(CDATAFRAME* cdata, int lim_col) {
    printf("Affichage des %d colonnes :\n", lim_col);
    for (int i=0; i < cdata->num_lignes; i++){
        for (int j=0; j < lim_col && j < cdata->num_columns; j++){
            printf("%d\t", cdata->columns[j]->tab[i]);
        }
        printf("\n");
    }
}

void afficher_limit_colligne(CDATAFRAME* cdata, int lim_lignes, int lim_colo){
    printf("Affichage des %d colonne(s) ", lim_colo);
    printf("et des %d ligne(s)\n", lim_lignes);
    for (int i=0; i < lim_lignes && i < cdata->num_lignes; i++){
        for (int j=0; j < lim_colo && j < cdata->num_columns; j++){
            printf("%d\t", cdata->columns[j]->tab[i]);
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
    for (int i = index; i < cdata->num_lignes - 1; i++) {
        cdata->tab[i] = cdata->tab[i + 1];
    }

    cdata->num_lignes--;
}

void ajout_colonne_valeur(CDATAFRAME* cdata, double* val){
    cdata->num_columns++;

    for (int i = 0; i < cdata->num_lignes; i++) {
        cdata->tab[i] = (double*)realloc(cdata->tab[i], cdata->num_columns * sizeof(double));

        cdata->tab[i][cdata->num_columns - 1] = val[i];
    }
}

void delete_colonne_valeur(CDATAFRAME* cdata, int indice){
    for (int i = indice; i < cdata->num_columns - 1; i++) {
        cdata->tab[i] = cdata->tab[i + 1];
    }

    cdata->num_columns--;
}