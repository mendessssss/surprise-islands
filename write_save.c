#include <stdio.h>
#include <string.h>
#include "struct.c"

void save(){
FILE* fichier = fopen ("save", "w");
fprintf(fichier, "pv: %d \nrhum : %d\nor : %d\n", boug.pv, trucs.rhum, trucs.or);
if (fichier == NULL){
    printf("erreur ouverture fichier.");
}
fclose(fichier);
}