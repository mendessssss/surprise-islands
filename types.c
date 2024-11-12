typedef struct jacquie {
    int pv;
    int or;
    int attack;
    int armes;
    int rhum;
} t_jacquie;

t_jacquie m = {100, 100, 5, 10, 100};

typedef struct squelette {
    int pv;
    int attack;
} t_squelette;

typedef struct ile {
    int or;
    struct squelette* Mechant1;
} ile; 

char* mvt;


