#include "global.h"

void bagarre (struct perso, struct rouge) {
    int degat = rand() % perso.attaque + 1;
    rouge.pv -= degat;
    if (rouge.pv < 0) rouge.pv = 0;
    printf (" %d de dégâts coup critique sur %s!\n", degat, rouge.nom);
}

void etat_status (char *perso, char *rouge) {
    printf("\n-- Statut --\n");
    printf("%s: %d/%d PV\n", perso.nom, perso.pv);
    printf("%s: %d/%d PV\n", rouge.nom, rouge.pv);
}

int main() {
    
    srand(time(NULL));

    printf ("%s VS %s prépares-toi pour le duel zebi !\n", perso.nom, rouge.nom);

    while (perso.pv > 0 && rouge.pv > 0) {
        etat_status(&perso, &rouge);

        printf ("1. Attaquer\n");
        printf ("Choisis une arme : ");
        
        // int choix;
        // scanf("%d", &choix);

        char choix [255]; memset (choix, 0, 255);
        fgets (choix, 255, stdout);

        switch (char choix) {
            case 1 :
                bagarre(&perso, &rouge);
                break;
            
            default :
                printf("Saisie invalide.\n");
            continue;
        }

        // au tour du méchant 
        if (rouge.pv > 0) {
            bagarre(&rouge, &perso);
        }
    }

    // pronostique de qui s'est fait allumé + fin du duel
    if (perso.pv <= 0) {
        printf("\nAyyyy tié m0rt ...\n");
    } else if (rouge.pv <= 0) {
        printf("\n%s à terre, tu l'as bien niqué ce batard tié un crack !\n", rouge.nom);
    }

    return 0;
}
