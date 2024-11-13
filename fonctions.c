#pragma once
#include "global.h"

// int game_over (struct jackie *f) {
//     printf("GAME OVER\n");
//     return 0;
// }

// int victoire (struct inventaire *p) {
//     if (p->or == 1000) {
//         printf("Vous êtes le king des océans bravo, votre fortune s'élève à 1 000 pièces d'or hamdoullah");
//         return 0;
//     }
// }

// int déplacement (struct inventaire *m, int voyage, char * mvt) {
//     while (voyage > 1) {
//     mvt ++;
//     m->rhum --;
//     continue;   // ou return 1;
//     }
// }

// void write_save(){
// FILE* fichier = fopen ("save", "w");
// fprintf(fichier, "pv: %d \nrhum : %d\nor : %d\n", m.pv, m.rhum, m.or);
// if (fichier == NULL){
//     printf("Pas de sauvegarde");
// }
// fclose(fichier);
// }

// void read_save () {
// FILE* fd = fopen ("save", "r+");
// char buf[255];memset (buf, 0, 255);
// while (fgets(buf, sizeof(buf), fd) != NULL) {
//     if (strncmp (buf, "pv:", 3) == 0) {
//         char * token = strtok (buf, ":");
//         token = strtok (NULL, "\n");
//         if  (token != NULL) {
//         m.pv = atoi(token);
//     }
//     }
// } 
// printf ("pv: %d \nrhum : %d\nor : %d\n", m.pv, m.rhum, m.or);
// }

void load_ile (char* fname) {

    char line[BUFSIZ]; memset(line, 0, BUFSIZ);
    char buf[BUFSIZ]; memset(buf, 0, BUFSIZ);
    int choix;

    FILE *file; file = fopen(fname, "r");
    // Connaitre la taille du fichier
    fseek(file ,0, SEEK_END);
    int sizeFile = ftell(file);
    char text_content[sizeFile]; memset(text_content, 0, BUF_SIZE);
    // Remettre le curseur du fichier au debut
    fseek(file ,0, SEEK_SET);

    if (NULL == file) {
        printf("Le fichier n'a pas pu s'ouvrir\n");
          exit(0);
    }

    // Get file content and nbQuetes
    int nbQuetes = 1;
    fread(text_content, sizeFile, sizeof(char), file);
    int i = 0;
    while(text_content[i] != EOF){
        if(text_content[i] == '$'){
            nbQuetes++;
        }
        i++;
    }

    // Fill the array of quests with each quest
    char quetes[nbQuetes][BUF_SIZE*10];
    memset(quetes, 0, BUF_SIZE*10*nbQuetes);
    for (int i = 0; i < nbQuetes; i++)
    {
        char* quete;
        if(i == 0){
            quete = strtok(text_content,"$");
        }else{
            quete = strtok(NULL,"$");
        }
        strcpy(quetes[i], quete);
    }

    // For each quest of the quests array
    for (int i = 0; i < nbQuetes; i++) {
        // print text quest
        // and prints every answers
        char buf_quete[BUF_SIZE*10];
        strcpy(buf_quete, quetes[i]);
        strtok(buf_quete, "#");
        printf("%s\n", buf_quete);
        
        // all those informations are going to be parsed with strtok
        printf("Quel choix fais-tu ? ");
        fgets(buf, BUF_SIZE, stdin);
        buf[strlen(buf)-1] = 0;
        choix = atoi(buf);

        char* choix1 = strtok(NULL, "#");
        choix1 = &(choix1[1]);
        char* choix2 = strtok(NULL, "#");
        choix2 = &(choix2[1]);
        char* choix3 = strtok(NULL, "#");
        choix3 = &(choix3[1]);

        if (choix == 1) {
            printf("%s", choix1);
        } else if (choix == 2) {
            printf("%s", choix2);
        } else if (choix == 3) {
            printf("%s", choix3);
        } else {
            printf("Choix invalide\n");
            }
        }
}

void scanfiles () {
    
    while (1) {
    struct dirent *fileinfo;
    int count = 0;
    char buf[BUF_SIZE]; memset(buf, 0, BUF_SIZE);

    // opendir() renvoie un pointeur de type DIR. 
    DIR *dd = opendir("iles"); 

    if (dd == NULL) { 
    printf("Impossible d'ouvrir le répertoire.\n"); 
    return; 
    }

        printf("\nOu veut tu aller?\n");
        while ((fileinfo = readdir(dd)) != NULL) {
            if ( strcmp( fileinfo->d_name, "." ) && strcmp( fileinfo->d_name, ".." ) ) {
                printf("- %s\n", fileinfo->d_name);
                count++;
                }
        }
        printf("Il y a %d iles sur la carte\n", count);
        closedir(dd);

        fgets(buf, BUF_SIZE, stdin);
        buf[strlen(buf)-1] = 0;
        int ile = atoi(buf);

        m.rhum = m.rhum - 10;
        printf("Le trajet est long! Vous buvez 10 bouteilles de rhums pour passer le temps, il vous reste %d bouteilles\n\n", m.rhum);

        // Vérification du choix de l'utilisateur
        if (ile >= 1 && ile <= count) {
            // Construction du chemin complet vers le fichier de l'île choisie
            char path[BUF_SIZE]; memset(path, 0, BUF_SIZE);
            sprintf(path, "iles/ile%d", ile);
            printf("%d\n", ile);
            // Chargement de la quête pour l'île choisie
            load_ile(path);
        } else {
            printf("Tu veux te perdre au milieu de l'ocean ?\n");
        }
    }
}

void sleep_ms(int milliseconds) {
    // Convert milliseconds to microseconds
    usleep(milliseconds * 1000);
}

void load_quete(char* fname) {

    FILE *file;
    char mot;
    file = fopen(fname, "r");
    if (NULL == file) {
        printf("Le fichier n'a pas pu s'ouvrir\n");
          exit(0);
    }
    while ((mot = fgetc(file)) != EOF) {
        printf("%c", mot);
        sleep_ms(30);
        fflush(stdout);
    }
    fclose(file);
}