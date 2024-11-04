typedef struct jacquie {
    int pv;
    int or;
    int attack;
    char* armes;
    int endurance;
} jacquie;

typedef struct squelette {
    int pv;
    int attack;
} squelette;

typedef struct ile {
    int or;
    struct squelette;
} ile; 

