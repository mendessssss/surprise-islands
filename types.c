#define BUF_SIZE 255


typedef struct perso {
    int pv;
    int or;
    int atk;
    int armes;
    int rhum;
} t_perso;

// Jack : PV : 100, Or : 100, Attack : 5, Armes : 10, Rhum : 100
t_perso jack = {100, 100, 5, 10, 100};

char* mvt;
