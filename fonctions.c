int struct_init () {

    inventaire trucs;
    trucs.or = 500;
    trucs.degats = 15;
    trucs.arme = "machette";
    trucs.rhum = 946;
    
    jackie perso;
    perso.nom = "Jackie"
    perso.pv = 600;
    perso.attaque = 100;

    ennemis rouge;
    rouge.nom = "pirate"
    rouge.nb = 17;
    rouge.pv = 100;
    rouge.attack = 40;
}

int game_over (struct jackie *f) {
    printf("GAME OVER\n");
    return 0;
}

int victoire (struct inventaire *p) {
    if (p->or == 1000) {
        printf("Vous êtes le king des océans bravo, votre fortune s'élève à 1 000 pièces d'or hamdoullah");
        return 0;
    }
}

int déplacement (struct inventaire *m, int voyage, char * mvt) {
    while (voyage > 1) {
    mvt ++;
    m->rhum --;
    continue;   // ou return 1;
    }
}

void save(){
FILE* fichier = fopen ("save", "w");
fprintf(fichier, "pv: %d \nrhum : %d\nor : %d\n", perso.pv, trucs.rhum, trucs.or);
if (fichier == NULL){
    printf("erreur ouverture fichier.");
}
fclose(fichier);
}

FILE* fd = fopen ("save", "r+");
char buf[255];memset (buf, 0, 255);

while (fgets(buf, sizeof(buf), fd) != NULL) {
    if (strncmp (buf, "pv:", 3) == 0) {
        char * token = strtok (buf, ":");
        token = strtok (NULL, "\n");
        if  (token != NULL) {
        perso.pv = atoi(token);
    }
    }
} 

printf ("pv: %d \nrhum : %d\nor : %d\n", perso.pv, trucs.rhum, trucs.or);




