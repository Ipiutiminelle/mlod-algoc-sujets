#include "prixTuring.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	

	char* filename = argv[argc-1];


	if (argc != 4 && argc != 5) {
        printf("Usages:\n %s -o <nom_fichier_output> <nom_fichier_input>\n", argv[0]);
        printf("%s --info <annee > <nom_fichier_input>\n", argv[0]);
		printf("valeur de argc: %d \n", argc);
		return 0;
    }

//Absorption des données du fichier d'entrée

	 FILE* inFile = fopen(filename, "r");
    if (inFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return EXIT_FAILURE;
    }
	
	int n = numberOfWinners(inFile);
    gagnant* gagnant = readWinners(inFile);
    fclose(inFile);

// Créer fichier de sortie
	// seulement si le deuxième argument est '-o'
	if (argc == 4 && strcmp(argv[1], "-o") == 0) {
		FILE* outFile = fopen(argv[2], "w");
        printWinners(gagnant, n, outFile);
		fclose(outFile);
    }
	
	//si le deuxième argument est '--info' on affiche les infos de l'année demandée
	if (argc == 4 && strcmp(argv[1], "--info") == 0) {
        int annee = atoi(argv[2]);
        infoAnnee(gagnant, annee, n);
    }

	if (argc == 5 && strcmp(argv[1], "--sort") == 0 && strcmp(argv[2], "-o") == 0) {
        sortTuringWinnersByYear(gagnant, n);
        FILE *sortedFile = fopen(argv[3], "w");
        printWinners(gagnant, n, sortedFile);
        fclose(sortedFile);
    }

 // Libération de la mémoire 
    int i;
    for (i = 0; i < n; i++) {
        free(gagnant[i].nomGagnant);
        free(gagnant[i].descriptionPrix);
    }
    free(gagnant);

    return EXIT_SUCCESS;
}




