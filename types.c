#pragma once
#include "global.h"

// typedef struct jacquie {
//     int pv;
//     int or;
//     int attack;
//     char * armes;
//     int rhum;
// } t_jacquie;


// typedef struct squelette {
//     int pv;
//     int attack;
// } t_squelette;

// typedef struct ennemis {
//     int nb;
//     int pv;
//     int attack;
// } t_ennemis;

// typedef struct ile {
//     int or;
//     struct squelette* Mechant1;
//     struct ennemis mad;
// } ile; 

typedef struct jacquie {
    char* nom;
    int pv;
    int or;
    int rhum; 
    char* arme;
} jacquie;

typedef struct squelette {
    char* nom;
    int pv;
} squelette;

typedef struct BarbeNoire {
    char* nom;
    int pv;
} BarbeNoire;

typedef struct BarbeRousse {
    char* nom;
    int pv;
} BarbeRousse;

typedef struct BarbeBleue {
    char* nom;
    int pv;
} BarbeBleue;

typedef struct DavyJones {
    char* nom;
    int pv;
} DavyJones;