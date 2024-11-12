#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "types.c"
#include "scanfiles.c"
#include "load_quete.c"
#include "load_ile.c"
#include "appliquer_effet.c"
#define BUF_SIZE 255

int main () {

    printf("\n                   |    |     |\n                  )_)  )☠️)  )_)\n                 )___))___))___)\n                )____)____)_____)\n              _____|____|____|____\n    ________________________________\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    load_quete("Intro");
    printf("\n");
    printf("Vous etes equipés d'un couteau (ATK+10), vous disposez de %d points de vie, de %d pieces d'or et de %d bouteilles de rhum pour pouvoir naviguer.\n\n",m.pv, m.or, m.rhum);
    scanfiles ();
    
    return 0;
}
    