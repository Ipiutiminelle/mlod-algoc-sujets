/**
 Compilation
 gcc -W -Wall main-EVANNE.c prixTuring.c -o main-EVANNE

 Exécution
 ./prixTuring < turingWinners.csv > out.csv

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

char* readStringFromFileUntil(FILE* f,char delim){
    int bufferIndex=0;
    char* info;
    char c;
    memset(buffer,0,maxSize);
    while ((c=fgetc(f)) != delim ) {
        buffer[bufferIndex] = c;
        bufferIndex++;
    }
    buffer[bufferIndex+1] = '\0'; 
    info=(char*)calloc(bufferIndex+2,sizeof(char));
    for (int k=0;buffer[k]!='\0';k++){
        info[k]=buffer[k];
    }
    info[bufferIndex+2] = '\0'; 
    return info;
}

void readWinner(FILE *f, gagnant *gagnant){
	fscanf(f, "%i", &gagnant->annee);
	gagnant->nomGagnant=readStringFromFileUntil(f, ';');
	gagnant->descriptionPrix=readStringFromFileUntil(f, ';');
};

gagnant* readWinners(FILE* f) {
    int capacite = numberOfWinners(f);
    gagnant* listeGagnants = (gagnant*)malloc(capacite * sizeof(gagnant));
    for (int i = 0; i < capacite; i++) {
        readWinner(f, &listeGagnants[i]);
    }
    return listeGagnants;
}

void printWinners(gagnant* winners, int numberOfWinners, FILE* f) {
    if (f == NULL) {
        perror("Erreur ouverture out.csv");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numberOfWinners; i++) {
        fprintf(f, "%u;%s;%s\n", winners[i].annee, winners[i].nomGagnant, winners[i].descriptionPrix);
    }
}

void infoAnnee(gagnant *winners, unsigned int annee, int numberOfWinners)
{
	for (int i = 0; i < numberOfWinners; i++)
	{
		if (winners[i].annee == annee)
		{
			printf("L'annee %d, le(s) gagnant(s) ont ete : %s\n", winners[i].annee, winners[i].nomGagnant);
			printf("Nature des travaux : %s", winners[i].descriptionPrix);
			
		}
		
	}
}

void sortTuringWinnersByYear(gagnant* winners, int numberOfWinners) {
    gagnant tempo;
    for (int i = 0; i < numberOfWinners; i++) {
        for (int j = i + 1; j < numberOfWinners; j++) {
            if (winners[j].annee < winners[i].annee) {
                tempo = winners[i];
                winners[i] = winners[j];
                winners[j] = tempo;
            }
        }
    }
}
