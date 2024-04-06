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
} CDATAFRAME;

CDATAFRAME *create_cdataframe(int num_columns, int num_lignes);
void input_user(CDATAFRAME* cdata);
void afficher_cdataframe(CDATAFRAME* cdata);
void rempli_en_dur(CDATAFRAME *cdata);
#endif //PROJET_CDATAFRAME_H
