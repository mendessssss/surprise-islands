#include "global.h"
#define BUF_SIZE 255


int main () {

    printf("\n");
    printf("                   |    |     |\n");
    printf("                  )_)  )☠️)  )_)\n");
    printf("                 )___))___))___)\n");
    printf("                )____)____)_____)\n");
    printf("              _____|____|____|____\n");
    printf("    ________________________________\n");
    printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("\n");




    

    FILE* fd = fopen ("save", "a+"); 
    char sauvegarde[255]; memset (sauvegarde, 0, 255);

    //fclose (fopen ("inventaire.save", "a+"));
    if(fd != NULL) {
        fscanf(fd, "pv: %d \nrhum : %d\nor : %d\n", boug.pv, trucs.rhum, trucs.or);
        printf("pv: %d \nrhum : %d\nor : %d\n", boug.pv, trucs.rhum, trucs.or);
    }
    fclose(fd);

    // fprintf (fd, "PV : %d\nRhum : %d\nPièces : %d\n", boug.pv, trucs.rhum, trucs.or);
    // fprintf (fd, "Equipement : %s %d\n", trucs.arme, trucs.degats);
    // fclose (fd);

    //Accès écriture et lecture SANS SUPPRESSION DE DONNEES
    // char check[255]; memset(check,0,255);  

    // fclose (fopen ("save", "a+"));
    
    // FILE* fs = fopen ("save", "r+");

    // fclose (fs);

    // printf ("La partie a été sauvegardée\n");   
                        

    return 0;
}