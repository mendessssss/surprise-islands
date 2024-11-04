#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "fonctions.c"
#define BUF_SIZE 255

struct perso {
    int pv;
    int endurance;
    int pièces;
};

struct armes {
    char * arme;
    int degats;
};

struct ile1 {
    int pirates;
    int trésor;
};

int main () {

    printf("                   |    |     |\n");
    printf("                  )_)  )☠️)  )_)\n");
    printf("                 )___))___))___)\\\n");
    printf("                )____)____)_____)\\\\\n");
    printf("              _____|____|____|____\\\\\\\n");
    printf("    \\______________________________\\__\\\n");
    printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    struct perso boug;
    boug.pv = 600;
    boug.endurance = 500;
    boug.pièces = 100;

    struct armes piu;
    piu.arme = "machette";
    piu.degats = 100;

    struct ile1 lieu;
    lieu.pirates = 48;
    lieu.trésor = 4;

    fclose(fopen("save", "a"));

    FILE* ile  =fopen("ile", "r+");

    fprintf (ile, "Ile des baléares");
    fprintf (ile, "Ile Honshū");
    fprintf (ile, "Ile Quesako");
    fprintf (ile, "Ile Coupter");
   

    fclose(ile);

    fclose(fopen("ile", "a"));

    FILE* save  =fopen("save", "r+");

    fprintf (save, "Charger une partie");
    fprintf (save, "Créer une nouvelle partie");
    fprintf (save, "Sauvegarder la partie en cours");

    fclose(save);

    fclose (fopen("inventaire.save", "a"));

    FILE* fd = fopen("inventaire.save", "r+"); 

    fprintf(fd, "PV : %d\nEndurance : %d\nPièces : %d\n", boug.pv, boug.endurance, boug.pièces);
    fprintf(fd, "Equipement : %s %d\n", piu.arme, piu.degats);
    fprintf(fd, "La première île est occupée par %d pirates, il y a %d trésors et il est possible d'avoir %d loot\n", lieu.pirates, lieu.trésor);
    
    fclose(fd);

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
    return 0;
}