#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 255

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

int déplacement (struct jackie *m, int voyage, char * mvt) {
    while (voyage > 1) {
    mvt ++;
    m->rhum --;
    continue;   // ou return 1;
    }
}

int main () {

    printf("\n");
    printf("                   |    |    |\n");
    printf("                  )_)  )☠️)  )_)\n");
    printf("                 )___))___))___)\n");
    printf("                )____)____)_____)\n");
    printf("              _____|____|____|____\n");
    printf("    ________________________________\n");
    printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("\n");

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
 
    struct dirent *info;
    int count = 0;
    char buf[BUF_SIZE]; memset(buf, 0, BUF_SIZE);
// opendir() renvoie un pointeur de type DIR. 
    DIR *ile = opendir("home/user/langage_c/projets/surprise_islands/les_iles"); 


    if (ile) {
        while ((info = readdir (ile)) != NULL) {
            if (strcmp (info->d_name, ".") && strcmp (info->d_name, "..")) {
                printf("%d) - %s\n", count + 1, info->d_name); // count +1 pour éviter de faire apparaitre le "0" devant le premier choix
                count++;
            }
        }
        closedir (ile);
    }
    printf("\nIl y a %d îles sur la carte\n", count);
    printf("Où veux-tu aller ?\n");
        
    fgets (buf, sizeof(BUF_SIZE), stdin);

    fclose (fopen ("inventaire.save", "a"));
    FILE* fi = fopen ("inventaire.save", "r+"); 

    fprintf (fi, "PV : %d\nRhum : %d\nPièces : %d\n", perso.pv, perso.rhum, perso.or);
    fprintf (fi, "Equipement : %s %d\n", perso.arme, perso.degats);
    fclose (fi);

// Accès écriture et lecture SANS SUPPRESSION DE DONNEES
    fclose (fopen ("save", "a"));
    FILE* fs = fopen ("save","r+");
    char save[255];memset(save,0,255);  
    printf ("%s\n",save);                      

    if (fs == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        return -1;
    }

    fread (save, sizeof(save), 1, fs);
    fclose (fs);
    printf ("La partie a été sauvegardée\n");   

    return 0;
}