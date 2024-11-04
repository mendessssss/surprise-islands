#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF_SIZE 255
 
int main () {
    struct dirent *dir;
    int count = 0;
    char buf[BUF_SIZE]; memset(buf, 0, BUF_SIZE);

    // opendir() renvoie un pointeur de type DIR. 
    DIR *dd = opendir("/home/namoux/Documents/Exo C/Projet C/RPG Textuels/surprise-islands/iles"); 

    if (dd) {
        printf("Ou veut tu aller?\n");
        while ((dir = readdir(dd)) != NULL) {
            if ( strcmp( dir->d_name, "." ) && strcmp( dir->d_name, ".." ) ) {
                printf("%zu) - %s\n", count + 1, dir->d_name);
                count++;
                }
        }
        printf("Il y a %d iles sur la carte\n", count);
        closedir(dd);
    }

    fgets(buf, BUF_SIZE, stdin);
    buf[strlen(buf)-1] = 0;
    int ile = atoi(buf);

    return 0;
}