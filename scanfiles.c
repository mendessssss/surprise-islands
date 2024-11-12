#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 255

void load_ile(char * fname);

void scanfiles () {
    
    while (1) {
    struct dirent *fileinfo;
    int count = 0;
    char buf[BUF_SIZE]; memset(buf, 0, BUF_SIZE);

    // opendir() renvoie un pointeur de type DIR. 
    DIR *dd = opendir("/home/namoux/Documents/Exo C/Projet C/RPG Textuels/surprise-islands/iles"); 

    if (dd == NULL) { 
    printf("Impossible d'ouvrir le répertoire.\n"); 
    return; 
    }

        printf("\nOu veut tu aller?\n");
        while ((fileinfo = readdir(dd)) != NULL) {
            if ( strcmp( fileinfo->d_name, "." ) && strcmp( fileinfo->d_name, ".." ) ) {
                printf("- %s\n", fileinfo->d_name);
                count++;
                }
        }
        printf("Il y a %d iles sur la carte\n", count);
        closedir(dd);

        fgets(buf, BUF_SIZE, stdin);
        buf[strlen(buf)-1] = 0;
        int ile = atoi(buf);

        m.rhum = m.rhum - 10;
        printf("Le trajet est long! Vous buvez 10 bouteilles de rhums pour passer le temps, il vous reste %d bouteilles\n\n", m.rhum);



        // Vérification du choix de l'utilisateur
        if (ile >= 0 && ile < count) {
            // Construction du chemin complet vers le fichier de l'île choisie
            char * path;
            sprintf(path, "/home/namoux/Documents/Exo C/Projet C/RPG Textuels/surprise-islands/iles/ile%d", ile);
            
            // Chargement de la quête pour l'île choisie
            load_ile(path);
        } else {
            printf("Tu veux te perdre au milieu de l'ocean ?\n");
        }
    }
}