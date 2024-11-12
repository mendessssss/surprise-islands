#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.c"

int main () {

t_inventaire trucs;
trucs.or;
trucs.arme;
trucs.degats;
trucs.rhum;

t_jackie boug;
boug.pv;

FILE* fd = fopen ("save", "r+");
char buf[255];memset (buf, 0, 255);

while (fgets(buf, sizeof(buf), fd) != NULL) {
    if (strncmp (buf, "pv:", 3) == 0) {
        char * token = strtok (buf, ":");
        token = strtok (NULL, "\n");
        if  (token != NULL) {
        boug.pv = atoi(token);
    }
    }
} 

printf ("pv: %d \nrhum : %d\nor : %d\n", boug.pv, trucs.rhum, trucs.or);

return 0;
}