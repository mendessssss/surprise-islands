#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 255
#include "struct.c"
#include "fonctions.c"

int main () {

    printf("\n");
    printf("                   |    |     |\n");
    printf("                  )_)  )☠️)  )_)\n");
    printf("                 )___))___))___)\n");
    printf("                )____)____)_____)\n");
    printf("              _____|____|____|____\n");
    printf("    ________________________________\n");
    printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("\n");

    char* mvt;

    
    if (f->rhum == 0) {
        f->pv --;
        return game_over();
    }

    t_inventaire;
    inventaire.or = 500;
    inventaire.arme = "machette";
    inventaire.degats_arme = 15;
    
    inventaire.rhum = 946;

    t_jackie;
    jackie.pv = 600;
    jackie.attaque;
    struct inventaire;

    t_ennemis ratepi;
    ratepi.nb = 17;
    ratepi.pv = 100;
    ratepi.attack = 40;

    struct dirent *info;
    int count = 0;
    char buf[BUF_SIZE]; memset(buf, 0, BUF_SIZE);
// opendir() renvoie un pointeur de type DIR. 
    DIR *ile = opendir("home/user/langage_c/projets/surprise_islands/les_iles"); 


    if (ile) {
        while ((info = readdir (ile)) != NULL) {
            if (strcmp (info->d_name, ".") && strcmp (info->d_name, "..")) {
                printf("%d) - %s\n", count + 1, info->d_name); // count +1 pour éviter de faire apparaitre le "0" devant le premier choix
            }
        }
        closedir (ile);
    }

    count++;        

    fclose (fopen("save","a"));
    FILE* fd = fopen ("save", "w+"); 
    char sauvegarde[255]; memset (sauvegarde, 0, 255);

    fgets (sauvegarde, 255, fd);

    printf("\nIl y a %d îles sur la carte\n", count);
    printf("Où veux-tu aller ?\n");
    fgets (buf, sizeof(BUF_SIZE), stdin);

    printf("\nIl y a %d îles sur la carte\n", count);
    printf("Où veux-tu aller ?\n");
    fgets (buf, sizeof(BUF_SIZE), stdin);

    fclose(fd);


    // fclose (fopen ("inventaire.save", "a"));

    // fprintf (fi, "PV : %d\nRhum : %d\nPièces : %d\n", inventaire.pv, inventaire.rhum, inventaire.or);
    // fprintf (fi, "Equipement : %s %d\n", inventaire.arme, inventaire.degats);
    // fclose (fi);

    // Accès écriture et lecture SANS SUPPRESSION DE DONNEES
    // char check[255]; memset(check,0,255);  

    // fclose (fopen ("save", "a"));
    
    // FILE* fs = fopen ("save", "r+");

    // fclose (fs);

    // printf ("La partie a été sauvegardée\n");   
                         

    return 0;
}