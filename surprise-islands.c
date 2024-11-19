#include "global.h"

int main () {

    printf("\n                   |    |     |\n                  )_)  )☠️)  )_)\n                 )___))___))___)\n                )____)____)_____)\n              _____|____|____|____\n    ________________________________\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    // load_quete("Intro");
    printf("\n");
    read_save();
    printf("Vous etes equipés d'un pistolet et d'un couteau, vous disposez de %d points de vie, de %d pieces d'or et de %d bouteilles de rhum pour pouvoir naviguer.\n\n", jack.pv, jack.or, jack.rhum);
    scanfiles ();
    victoire ();
    game_over();
    return 0;
}
