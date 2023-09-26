/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/
#include "prixTuring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

FILE* lectureFichier(char NomFichier[]){
	FILE* f;
f = fopen(NomFichier,"r");
return f;
};


/*
void EcritureFichier(char NomFichier[],int DonneesTexte){
	FILE* f;
f = fopen(NomFichier,"a");
fputc(DonneesTexte,NomFichier);
};
*/
int numberOfWinners(FILE* f){
	int caractere;
	int count = 1;
	
	while ((caractere = fgetc(f)) != EOF) {
    	if (caractere=='\n')
		{
			count++;
		}
  	}
	return count;
}
