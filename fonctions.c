int struct_init () {

    t_inventaire trucs;
    trucs.or = 500;
    trucs.degats = 15;
    trucs.arme = "machette";
    trucs.rhum = 946;
    
    t_jackie lui;
    lui.pv = 600;
    lui.attaque = 100;

    t_ennemis ennemis;
    ennemis.nb = 17;
    ennemis.pv = 100;
    ennemis.attack = 40;
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
fprintf(fichier, "pv: %d \nrhum : %d\nor : %d\n", boug.pv, trucs.rhum, trucs.or);
if (fichier == NULL){
    printf("erreur ouverture fichier.");
}
fclose(fichier);
}





