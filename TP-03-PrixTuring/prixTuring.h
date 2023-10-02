#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <assert.h>
#define maxSize 1000

char buffer [maxSize];

typedef struct{
    unsigned int annee;
    char* nomGagnant;
    char* descriptionPrix;
} gagnant;

int numberOfWinners(FILE* f);

char* readStringFromFileUntil(FILE* f,char delim);

void readWinner(FILE *f, gagnant *gagnant);

gagnant* readWinners(FILE* f);

void printWinners(gagnant* winners, int numberOfWinners, FILE* outFile);

void infoAnnee(gagnant *winners, unsigned int annee, int numberOfWinners);

void sortTuringWinnersByYear(gagnant* winners, int numberOfWinners);


















