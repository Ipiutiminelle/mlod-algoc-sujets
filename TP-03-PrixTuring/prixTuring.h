#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct{
    uint16_t annee;
    char* nomGagnant;
    char* descriptionPrix;
} Gagnant;

int numberOfWinners(FILE* f);

