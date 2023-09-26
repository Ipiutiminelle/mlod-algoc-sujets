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

char *readStringFromFileUntil(FILE *f, char lecteur){
	int caractere;
	char result = (char) malloc(2048*sizeof(char));
	int i = 0;
	while ((caractere = fgetc(f)) != EOF) {
    if (caractere==lecteur)
		{
			return result;
		}
		result[i]=caractere;
		i++;
  }
};

void readWinners(FILE *f, Gagnant *Gagnant){
	fscanf(f, "%i", &ligne->annee);
	ligne->nom=readStringFromFileUntil(f, ';');
	ligne->travaux=readStringFromFileUntil(f, ';');
};