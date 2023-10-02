#include "prixTuring.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	

char filename[]="turingWinners.csv";
char outputFilename[]="out.csv";


//Absorption des données du fichier d'entrée

	 FILE* inFile = fopen(filename, "r");
    if (inFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return EXIT_FAILURE;
    }

	

	int n = numberOfWinners(inFile);
    gagnant* gagnant = readWinners(inFile);

    printWinners(gagnant, n, outputFilename);
    printf('%i', n);

    fclose(inFile);




 // Libération de la mémoire 
    int i;
    for (i = 0; i < n; i++) {
        free(gagnant[i].nomGagnant);
        free(gagnant[i].descriptionPrix);
    }
    free(gagnant);

    return EXIT_SUCCESS;
}




