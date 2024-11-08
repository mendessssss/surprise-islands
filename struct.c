typedef struct inventaire {
    int or;
    char* arme;
    int rhum;
}t_inventaire;

typedef struct jackie {
    int pv;
    int attaque;
    int degats;
    struct inventaire;
} t_jackie;


typedef struct ennemis {
    int nb;
    int pv;
    int attack;
} t_ennemis;

typedef struct ile {
    int or;
    struct ennemis mad;
} t_ile; 
