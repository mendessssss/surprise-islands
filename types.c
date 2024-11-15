
typedef struct jacquie {
    int pv;
    int or;
    int attack;
    int armes;
    int rhum;
} t_jacquie;


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
