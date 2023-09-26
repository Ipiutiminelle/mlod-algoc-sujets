#include "prixTuring.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.txt";
	FILE* f;
	FILE* of;
	f = fopen(filename,"r");
	of = fopen(outputFilename, "a");
	
	printf("%i \n", numberOfWinners(f));

	fclose(f);
	fclose(of);
	return EXIT_SUCCESS;

	
}
