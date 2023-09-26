#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 5
void matrix_print(int64_t mat[][SIZE]);
void matrix_mult(int64_t matriceResultat[][SIZE], int64_t matrice1[][SIZE], int64_t matrice2[][SIZE]);


typedef struct{
    uint16_t nbreLignes;
    uint16_t nbreColonnes;
    int** valeurs;
};


struct Matrice { //3 cases réservées en memoire
int valeurInitiale;
int nbreColonnes;
int nbreLignes;
}; 
