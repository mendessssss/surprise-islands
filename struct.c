#include <stdio.h>
#include <string.h>

typedef struct inventaire {
    int or;
    char* arme;
    int degats;
    int rhum;
}t_inventaire;

typedef struct jackie {
    int pv;
    int attaque;
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

// int main () {

// t_inventaire truc = {
//     500,
//     "machette",
//     15,
//     946,
// };                                   
                                //AUTRE SYNTAXE DE D'INITIALISATION POSSIBLE 

// t_jackie boug={
//     600,
//     10,
// };

//    return 0;
//}