#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void sleep_ms(int milliseconds) {
    // Convert milliseconds to microseconds
    usleep(milliseconds * 1000);
}

void load_quete(char* fname) {
    FILE *file;
    char mot;
    file = fopen(fname, "r");
    if (NULL == file) {
        printf("Le fichier n'a pas pu s'ouvrir\n");
          exit(0);
    }
    while ((mot = fgetc(file)) != EOF) {
        printf("%c", mot);
        sleep_ms(30);
        fflush(stdout);
    }
    fclose(file);
}
