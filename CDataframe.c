//
// Created by jadeb on 28/03/2024.
//

#include "CDataframe.h"
#include <stdlib.h>
#define MALLOC_SIZE 256
#include <stdio.h>

//Création CDataframe vide
CDATAFRAME *create_cdataframe(int num_columns, int num_lignes){
    CDATAFRAME *cdata = (CDATAFRAME *)malloc(sizeof(CDATAFRAME));
    cdata->num_lignes = num_lignes;
    cdata->num_columns = num_columns;

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
    for (int i = 0; i< cdata->num_columns; i++){
        printf("Remplisser la colonne %d :\n", i+1);
        for (int j=0; j<cdata->num_lignes; j++){
            printf("Veuillez mettre la valeur de la ligne %d : \n", j+1);
            scanf("%d", &(cdata->columns[i]->tab[j]));
        }
    }
}

void rempli_en_dur(CDATAFRAME *cdata) {
    for (int i = 0; i < cdata->num_lignes; i++) {
        for (int j = 0; j < cdata->num_columns; j++) {
            cdata->columns[j]->tab[i] = i * cdata->num_columns + j + 1;
        }
    }
}

void afficher_cdataframe(CDATAFRAME* cdata){
    printf("CDataframe :\n");
    for (int i = 0; i < cdata->num_lignes; i++) {
        printf("Ligne %d : ", i+1);
        for (int j = 0; j < cdata->num_columns; j++) {
            printf("%d\t", cdata->columns[j]->tab[i]);
        }
        printf("\n");
    }
}