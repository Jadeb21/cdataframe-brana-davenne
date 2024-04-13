//
// Created by jadeb on 28/03/2024.
//

#ifndef PROJET_CDATAFRAME_H
#define PROJET_CDATAFRAME_H

#include "function.h"

typedef struct {
    COLUMN **columns;
    int num_columns;
    int num_lignes;
    double** tab;
} CDATAFRAME;

CDATAFRAME *create_cdataframe(int num_columns, int num_lignes);
void input_user(CDATAFRAME* cdata);
void rempli_en_dur(CDATAFRAME *cdata);

void afficher_cdataframe(CDATAFRAME* cdata);
void afficher_limit_lignes(CDATAFRAME* cdata, int lim_lignes);
void afficher_limit_col(CDATAFRAME* cdata, int lim_col);
void afficher_limit_colligne(CDATAFRAME* cdata, int lim_lignes, int lim_col);

void ajout_ligne_valeur(CDATAFRAME* cdata, double* val);
void delete_ligne_valeur(CDATAFRAME* cdata, int index);
void ajout_colonne_valeur(CDATAFRAME* cdata, double* val);
void delete_colonne_valeur(CDATAFRAME* cdata, int indice);

#endif //PROJET_CDATAFRAME_H
