//
// Created by jadeb on 28/03/2024.
//

#ifndef PROJET_FUNCTION_H
#define PROJET_FUNCTION_H

typedef struct {
    char *title;
    int tl; //taille logique
    int tp; //taille physique
    int *tab; //donnée
}COLUMN;

COLUMN *create_column(char* title);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);
int count_occurences(COLUMN *col, int value);
int value_position(COLUMN *col, int position);
int more_value(COLUMN *col, int value);
int less_value(COLUMN *col, int value);
int equal_value(COLUMN *col, int value);

#endif //PROJET_FUNCTION_H
