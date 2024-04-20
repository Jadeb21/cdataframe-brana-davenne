//
// Created by jadeb on 28/03/2024.
//
#include <stdio.h>
#include <malloc.h>
#include "colomn.h"
#define MALLOC_SIZE 256

COLUMN *create_column(char* title) {
    COLUMN *col = (COLUMN *)malloc(sizeof(COLUMN));
    col->title = title;
    col->tl = 0;
    col->tp = 0;
    col->tab = NULL;
    return col;
}

int insert_value(COLUMN* column, int value) {
    if (column->tab == NULL || column->tl >= column->tp) {

        int new_tp = column->tp + MALLOC_SIZE;
        int *new_tab = (int *)realloc(column->tab, new_tp * sizeof(int));
        column->tab = new_tab;
        column->tp = new_tp;
    }

    column->tab[column->tl] = value;
    column->tl++;

    return 1;
}

void delete_column(COLUMN **col){
    if (col == NULL || *col == NULL) {
        return;
    }
    free((*col)->title);
    free((*col)->tab);
    free(*col);
    *col = NULL;
}

void print_col(COLUMN* col){
    printf("Titre de la colonne : %s\n", col->title);
    printf("Contenu de la colonne :\n");
    for (int i = 0; i<col->tl; i++){
        printf("[%d] %d\n", i, col->tab[i]);
    }
}

int count_occurences(COLUMN *col, int value) {
    int count = 0;
    for (int i = 0; i < col->tl; i++) {
        if (col->tab[i] == value) {
            count++;
        }
    }
    return count;
}

int value_position(COLUMN *col, int position) {
    if (position < 0 || position >= col->tl){
        printf("Position invalide");
    }
    return col->tab[position];
}

int more_value(COLUMN *col, int value) {
    int count = 0;
    for (int i=0; i<col->tl; i++){
        if (col->tab[i]>value) {
            count++;
        }
    }
    return count;
}

int less_value(COLUMN *col, int value) {
    int count=0;
    for (int i=0 ;i<col->tl; i++){
        if (col->tab[i]<value){
            count++;
        }
    }
    return count;
}

int equal_value(COLUMN *col, int value) {
    int count=0;
    for (int i=0 ;i<col->tl; i++){
        if (col->tab[i]==value){
            count++;
        }
    }
    return count;
}