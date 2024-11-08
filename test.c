#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 255

int main () {

    struct dirent *info;
    char buf[BUF_SIZE]; memset(buf, 0, BUF_SIZE);
    int count = 0;
    // opendir() renvoie un pointeur de type DIR.
    DIR *ile = opendir("home/user/langage_c/projets/surprise_islands/les_iles"); 


    if (ile) {
        while ((info = readdir (ile)) != NULL) {
            if (strcmp (info->d_name, ".") && strcmp (info->d_name, "..")) {
                printf("(%d) - %s\n", count + 1, info->d_name); // count +1 pour éviter de faire apparaitre le "0" devant le premier choix
                count++;        
            }
        }

        closedir (ile);
    }

    printf("\nIl y a %d îles sur la carte\n", count);
    printf("Où veux-tu aller ?\n");

    return 0;
}