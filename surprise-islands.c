#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct perso {
    int pv;
    int endurance;
    int pièces;
};

struct ile1 {
    int pirates;
    int trésor;
    int loot;
};

int game_over (char * perso, int pv) {
    if (pv == 0) {
        printf("GAME OVER\n");
        return 0;
    }
}


int main () {

    struct perso boug;
    boug.pv = 600;
    boug.endurance = 500;
    boug.pièces = 100;

    fclose(fopen("inventaire.save", "a"));

    FILE* fd = fopen("inventaire.save", "r+"); 
    fprintf(fd, "PV : %d\nEndurance : %d\n", boug.pv, boug.endurance);
    fclose(fd);

    return 0;
}