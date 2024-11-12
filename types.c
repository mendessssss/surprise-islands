typedef struct jacquie {
    int pv;
    int or;
    int attack;
    int armes;
    int rhum;
} t_jacquie;

// Jackie m : PV : 100, Or : 100, Attack : 5, Armes : 10, Rhum : 100
t_jacquie m = {100, 100, 5, 10, 100};

typedef struct squelette {
    int pv;
    int attack;
} t_squelette;

typedef struct ennemis {
    int nb;
    int pv;
    int attack;
} t_ennemis;

typedef struct ile {
    int or;
    struct squelette* Mechant1;
    struct ennemis mad;
} ile; 

char* mvt;




