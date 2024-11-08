#include "struct.c"

int struct_init () {

    t_jackie inventaire;
    inventaire.pv = 600;
    inventaire.or = 500;
    inventaire.attack = 100;
    inventaire.arme = "machette";
    inventaire.degats = 15;
    inventaire.rhum = 946;

    t_ennemis ratepi;
    ratepi.nb = 17;
    ratepi.pv = 100;
    ratepi.attack = 40;
}

int game_over (struct jackie *f) {
    printf("GAME OVER\n");
    return 0;
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

void sauvegarde () {
    fclose (fopen("save","a"));
    FILE* fd = fopen ("save", "w+"); 
    char sauvegarde[255]; memset (sauvegarde, 0, 255);
    fgets (sauvegarde, 255, fd);
}