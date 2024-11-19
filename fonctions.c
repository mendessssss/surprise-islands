#pragma once
#include "global.h"

void game_over () {
    if (jack.pv <= 0) {
        printf("Vous etes morts!!! Vous partez dans la fierté, tel un vrai pirate!! \n");
    }
        printf("\n|--------------------------------------------------------------------|\n ******************************GAME OVER****************************** \n|--------------------------------------------------------------------|\n");

    FILE* fichier = fopen ("save", "w");
    t_perso jack = {100, 100, 5, 10, 100};
    fprintf(fichier, "pv : %d \nrhum : %d\nor : %d\natk : %d", jack.pv, jack.rhum, jack.or, jack.atk);
    fclose(fichier);
}

void victoire () {
    if (jack.or >= 1000) {
        printf("\nVous êtes le king des océans bravo, votre fortune s'élève à %d pièces d'or\nLe ONE PIECE est à vous!!!\n", jack.or);
    }
}

void write_save(){
    FILE* fichier = fopen ("save", "w");
    fprintf(fichier, "pv : %d \nrhum : %d\nor : %d\natk : %d", jack.pv, jack.rhum, jack.or, jack.atk);
    if (fichier == NULL){
        printf("Pas de sauvegarde");
    }
    fclose(fichier);
}

void read_save () {
    FILE* fd = fopen ("save", "r+");
    char buf[255];memset (buf, 0, 255);
    while (fgets(buf, sizeof(buf), fd) != NULL) {
        if (strncmp (buf, "pv :", 3) == 0) {
            char * token = strtok (buf, ":");
            token = strtok (NULL, "\n");
            if  (token != NULL) {
            jack.pv = atoi(token);
            }
        } else if (strncmp (buf, "rhum :", 3) == 0) {
            char * token = strtok (buf, ":");
            token = strtok (NULL, "\n");
            if  (token != NULL) {
            jack.rhum = atoi(token);
            }
        } else if (strncmp (buf, "or :", 3) == 0) {
            char * token = strtok (buf, ":");
            token = strtok (NULL, "\n");
            if  (token != NULL) {
            jack.or = atoi(token);
            }
        } else if (strncmp (buf, "atk :", 3) == 0) {
            char * token = strtok (buf, ":");
            token = strtok (NULL, "\n");
            if  (token != NULL) {
            jack.atk = atoi(token);
            }
        } 
    } 
}

int appliquer_effet(char* effet, int stat) {

    // Appliquer l'effet (POJ pour pièces d'or, PVJ pour points de vie, RHUMJ pour le rhum, ATKJ pour l'attaque, QUIT pour quitter l'ile)
    if (strcmp(effet, "POJ") == 0) {
        jack.or = jack.or + stat;
        printf("Vous avez maintenant %d pièces d'or.\n", jack.or);
        write_save();
            if(jack.or <= 0) {
                printf("La faillite totale!!! Dur la vie, vous deprimez!! \n");
                jack.pv = jack.pv -10;
                jack.rhum = jack.rhum;
                printf("Vous avez maintenant %d points de vie.\n", jack.pv);
                printf("Vous avez maintenant %d bouteilles de rhum.\n", jack.rhum);
                write_save();
            }
    } else if (strcmp(effet, "PVJ") == 0) {
        jack.pv = jack.pv + stat;
        printf("Vous avez maintenant %d points de vie.\n", jack.pv);
        write_save();
    } else if (strcmp(effet, "RHUMJ") == 0) {
        jack.rhum = jack.rhum + stat;
        printf("Vous avez maintenant %d bouteilles de rhum.\n", jack.rhum);
        write_save();
            if (jack.rhum <= 0) {
                printf("Vous n'avez plus de rhum, dur dur, alcoolique que vous êtes, vous ne vous sentez pas bien...\n");
                jack.pv = jack.pv -10;
                printf("Vous avez maintenant %d points de vie.\n", jack.pv);
                write_save();
            }           
    } else if (strcmp(effet, "ATKJ") == 0) {
        jack.atk = jack.atk + stat;
        printf("Vous avez maintenant %d points d'attaque.\n", jack.atk);
        write_save();
    } else if (strcmp(effet, "QUIT") == 0) {
        return EXIT_SUCCESS;
    } else {
        printf("Aucun effet\n");
    }
}

void load_ile (char* fname) {
    
    char line[BUFSIZ]; memset(line, 0, BUFSIZ);
    char buf[BUFSIZ]; memset(buf, 0, BUFSIZ);
    int choix;
    FILE *file; file = fopen(fname, "r");perror("fopen");
    // Connaitre la taille du fichier
    fseek(file ,0, SEEK_END);
    int sizeFile = ftell(file);
    char text_content[sizeFile]; memset(text_content, 0, sizeFile);

    // Remettre le curseur du fichier au debut
    fseek(file ,0, SEEK_SET);

    if (NULL == file) {
        printf("Le fichier n'a pas pu s'ouvrir\n");
          exit(0);
    }

    // Get file content and nbQuetes
    // Ici on lit le fichier et si on tombe sur des $, cela compte les quetes
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
    // double tableau, on transfert la quete dans un tableau
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
    // On repere les # et pour chaque quete on a une reponse
    for (int i = 0; i < nbQuetes; i++) {
        // print text quest
        // and prints every answers
        char buf_quete[BUF_SIZE*10];
        strcpy(buf_quete, quetes[i]);
        strtok(buf_quete, "#");
        printf("%s\n", buf_quete); 
        
        
        // Seg fault ends
        
        // all those informations are going to be parsed with strtok
        //  Les tokens a recuperer en fonction du choix de l'utilsateur
        printf("Quel choix fais-tu ? ");
        fgets(buf, BUF_SIZE, stdin);
        buf[strlen(buf)-1] = 0;
        choix = atoi(buf);

        char *choix1 = strtok(NULL, "#");
        choix1 = &(choix1[1]);
           char* line_effet1 = strtok(NULL, "#");
            line_effet1 = &(line_effet1[1]);
        char *choix2 = strtok(NULL, "#");
        choix2 = &(choix2[1]);
            char *line_effet2 = strtok(NULL, "#");
            line_effet2 = &(line_effet2[1]);
        char *choix3 = strtok(NULL, "#");
        choix3 = &(choix3[1]);
            char *line_effet3 = strtok(NULL, "#");
            line_effet3 = &(line_effet3[1]);

            char name[BUF_SIZE]; memset(name, 0, BUF_SIZE);
            int stat1; 

        if (choix == 1) {
            printf("%s", choix1);
            fgets(line_effet1, BUF_SIZE ,file);
            sscanf(line_effet1, "%s %d", name, &stat1);
            appliquer_effet(name, stat1);
        } else if (choix == 2) {
            printf("%s", choix2);
            fgets(line_effet2, BUF_SIZE ,file);
            sscanf(line_effet2, "%s %d", name, &stat1);
            appliquer_effet(name, stat1);
        } else if (choix == 3) {
            printf("%s", choix3);
            fgets(line_effet3, BUF_SIZE ,file);
            sscanf(line_effet3, "%s %d", name, &stat1);
            appliquer_effet(name, stat1);
        } else {
            printf("Choix invalide\n");
        }
    }

        fclose(file);
    
}

void scanfiles () {
    
    while (jack.or < 1000 && jack.pv > 0) {
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

        // Deplacement qui coute du rhum
        jack.rhum = jack.rhum - 10;
        printf("! Vous buvez 10 bouteilles de rhums pour passer le temps, il vous reste %d bouteilles\n\n", jack.rhum);

        // Vérification du choix de l'utilisateur
        if (ile >= 1 && ile <= count) {
            // Construction du chemin complet vers le fichier de l'île choisie
            char path[BUF_SIZE]; memset(path, 0, BUF_SIZE);
            sprintf(path, "iles/ile%d", ile);
            printf("%d\n", ile);

            // segfault starts
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

    // teste intro qui s'affiche petit a petit
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

// int déplacement (struct inventaire *m, int voyage, char * mvt) {
//     while (voyage > 1) {
//     mvt ++;
//     m->rhum --;
//     continue;   // ou return 1;
//     }
// }