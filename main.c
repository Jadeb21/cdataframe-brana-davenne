#include <stdio.h>
#include <malloc.h>
#include "function.h"
#include "CDataframe.h"


int main(){
    int num_lignes, num_columns;
    int choice;
    printf("Veillez choisir une option : \n");
    printf("1. CDataframe rempli par saisie utilisateur \n");
    printf("2. CDataframe rempli en dur  \n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Saisir le nombre de colonnes :");
            scanf("%d", &num_columns);
            printf("Saisir le nombre de lignes :");
            scanf("%d", &num_lignes);
            CDATAFRAME* cdata = create_cdataframe(num_columns, num_lignes);
            input_user(cdata);
            afficher_cdataframe(cdata);
            break;

        case 2:
            rempli_en_dur(cdata);
            break;
    }



    return 0;
}