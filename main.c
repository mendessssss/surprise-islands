#include "global.h"

int main () {

    printf ("\n");
    printf ("                   |    |     |\n");
    printf ("                  )_)  )☠️)  )_)\n");
    printf ("                 )___))___))___)\n");
    printf ("                )____)____)_____)\n");
    printf ("              _____|____|____|____\n");
    printf ("    ________________________________\n");
    printf (" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("\n");

    printf ("Bienvenue dans l'aventure de %s, le pirate intrépide !\n", heros.nom);
    
    srand (time(NULL));
    
    save ();
    struct_init ();
    printf ("\n");
    status (heros, ennemi);
    //printf ("Vous etes equipés d'une machette (ATK+10), vous disposez de %d points de vie, de %d pieces d'or et de %d bouteilles de rhum pour pouvoir naviguer.\n\n",heros.pv, m.or, m.rhum);
    scanfiles ();



    
    combat (&heros, &ennemi);


    return 0;
}
          