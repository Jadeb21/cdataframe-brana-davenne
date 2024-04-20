//
// Created by jadeb on 28/03/2024.
//

#ifndef PROJET_CDATAFRAME_H
#define PROJET_CDATAFRAME_H

#include "colomn.h"

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
void rename_title(CDATAFRAME* cdata, int column_index, char* new_title);
int valeurExiste(CDATAFRAME* cdata, int value);
void replace_valeur(CDATAFRAME* cdata, int ligne, int column, double new_value);
void nom_colonne(CDATAFRAME* cdata);

int nombre_Lignes(CDATAFRAME *cdata);
int nombre_Colonnes(CDATAFRAME *cdata);
int compter_egal(CDATAFRAME* cdata, double x);
int compter_superieures(CDATAFRAME* cdata, double x);
int compter_inferieures(CDATAFRAME* cdata, double x);

void free_cdataframe(CDATAFRAME* cdata);

#endif //PROJET_CDATAFRAME_H
