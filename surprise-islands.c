#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 255
#define SAVE_SIZE 255
#define VOYAGE 0

typedef struct jackie {
    int pv;
    int or;
    int attack;
    char* arme;
    int degats;
    int rhum;
} t_jacquie;

typedef struct ennemis {
    int nb;
    int pv;
    int attack;
} t_ennemis;

typedef struct ile {
    int or;
    struct ennemis mad;
} t_ile; 

int game_over (struct jackie *f) {
    if (f->rhum == 0) {
        f->pv --;
        printf("GAME OVER\n");
        return 0;
    }
}

int victoire (struct jackie *p) {
    if (p->or == 1000) {
        printf("Vous êtes le king des océans bravo, votre fortune s'élève à 1 000 pièces d'or hamdoullah");
        return 0;
    }
}

int déplacement (struct jackie *m, char * mvt) {
    while (VOYAGE > 1) {
    mvt ++;
    m->rhum --;
    continue;
    }
}

int main () {

    printf("\n");
    printf("                   |    |     |\n");
    printf("                  )_)  )☠️)  )_)\n");
    printf("                 )___))___))___)\n");
    printf("                )____)____)_____)\n");
    printf("              _____|____|____|____\n");
    printf("    ________________________________\n");
    printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    char* mvt;

    t_jacquie perso;
    perso.pv = 600;
    perso.or = 500;
    perso.attack = 100;
    perso.arme = "machette";
    perso.degats = 15;
    perso.rhum = 946;

    t_ennemis ratepi;
    ratepi.nb = 17;
    ratepi.pv = 100;
    ratepi.attack = 40;

    t_ile bourbon;
    bourbon.or = 80;
    struct ennemis *mad;

 
    struct dirent *dir;
    int count = 0;
    char buf[BUF_SIZE]; memset(buf, 0, BUF_SIZE);

    // opendir() renvoie un pointeur de type DIR. 
    DIR *dd = opendir("user/langage_c/projets/surprise_islands/les_iles"); 

    if (dd) {
        printf("Il y a %d iles sur la carte\n", count);
        printf("Où veux-tu aller?\n");
        while ((dir = readdir(dd)) != NULL) {
            if ( strcmp( dir->d_name, "." ) && strcmp( dir->d_name, ".." ) ) {
                printf("%d) - %s\n", count + 1, dir->d_name); // count +1 pour éviter de faire apparaitre le "0" devant le premier choix
                count++;
            }
        }
        closedir(dd);
    }

    fclose (fopen("inventaire.save", "a"));

    FILE* fd = fopen("inventaire.save", "r+"); 

    fprintf(fd, "PV : %d\nEndurance : %d\nPièces : %d\n", perso.pv, perso.or);
    fprintf(fd, "Equipement : %s %d\n", perso.arme, perso.degats);
    fprintf(fd, "La première île est occupée par %d pirates et il y a %d trésors\n", ratepi.nb, bourbon.or);
    
    fclose(fd);

// Accès écriture et lecture SANS SUPPRESSION DE DONNEES
    fclose (fopen("save", "a"));
    FILE* fe = fopen("save","r+");
    char save[SAVE_SIZE];memset(save,0,SAVE_SIZE);      //à modifier
    printf("%s\n",save);                                    

    return 0;
}