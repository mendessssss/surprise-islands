#pragma once
#include "global.h"

int struct_init () {

    jacquie heros;
    heros.nom = "Jacquie";
    heros.pv = 100;
    heros.or = 100; 
    heros.rhum = 100;
    heros.arme = "machette";

    squelette nullos;
    nullos.nom = "squelette";
    nullos.pv = 20;

    BarbeNoire easy;
    easy.nom = "Barbe Noire";
    easy.pv = 40;
    
    BarbeRousse bof;
    bof.nom = "Barbe Rousse";
    bof.pv = 70;
    
    BarbeBleue dur;
    dur.nom = "Barbe Bleue";
    dur.pv = 100;

    DavyJones boss;
    boss.nom = "Davy Jones";
    boss.pv = 130;
}

void game_over () {
    if (m.pv <= 0) {
        printf("Vous etes morts!!! Vous partez dans la fierté, tel un vrai pirate!! \n");
    }
        printf("\n|--------------------------------------------------------------------|\n ******************************GAME OVER****************************** \n|--------------------------------------------------------------------|\n");
}

void victoire () {
    if (m.or >= 200) {
        printf("\nVous êtes le king des océans bravo, votre fortune s'élève à %d pièces d'or hamdoullah\n Sah, Vous pouvez flamber comme bon vous semble!!!\n", m.or);
    }
}

int déplacement (jacquie *heros, int voyage, char * mvt) {

    while (voyage > 1) {
    mvt ++;
    heros->rhum --;
    continue;   // ou return 1;
    }
}


void write_save (jacquie *heros) {

    FILE* fichier = fopen ("save", "w");
    fprintf(fichier, "pv: %d \nrhum : %d\nor : %d\n", heros.pv, heros.rhum, heros.or);

    if (fichier == NULL){
            printf("erreur ouverture fichier.");
    }

    fclose(fichier);

    FILE* fd = fopen ("save", "r+");
    char buf[255];memset (buf, 0, 255);

    while (fgets(buf, sizeof(buf), fd) != NULL) {
        if (strncmp (buf, "pv:", 3) == 0) {
            char * token = strtok (buf, ":");    
            token = strtok (NULL, "\n");
            if  (token != NULL) {
                heros.pv = atoi(token);
            }
        }
    }

    printf ("pv: %d \nrhum : %d\nor : %d\n", heros.pv, heros.rhum, heros.or);
}

// void combat (jacquie *heros, squelette *ennemi) {
    
//     printf("%s VS %s !\n", heros->nom, ennemi->nom);

//     while (heros->pv > 0 && ennemi->pv > 0) {
//         status(heros, ennemi);

//         printf("Que comptez-vous faire ?\n");
//         printf("1. Attaquer\n");
//         printf("2. Fuir\n");
        
//         int choix;
//         scanf("%d", &choix);

//         if (choix == 1) {
//             int degats_j = 10; 
//             printf("\n%s VS %s préparez-vous pour le duel !\n", ennemi->nom, heros->nom);
//             ennemi->pv -= degats_j;

//             int degats_ennemi = 5; // rendre aléatoire ?
//             printf("%s vous attaque et inflige %d dégâts !\n", ennemi->nom, degats_ennemi);
//             heros->pv -= degat_ennemi;
//         }

//         if (ennemi->pv <= 0) {
//             printf("\n%s est mort, vous remportez ce duel !\n", ennemi->nom);
//         }

//         if (choix == 2) {
//             return 0;

//         } else {
//             printf("Saisie invalide ...\n");
//         }
        
//         if (choix == 2) {
//             printf("\nVous prenez la fuite. Le combat est terminé.\n");
//             break;

//         } else {
//             printf("\nChoix invalide\n");
        

//         if (heros->pv <= 0) {
//             printf("\nVous avez atteint vos limites, puisse les dieux chanter vos louanges au Valhalla ... \n");
//             break;
//         }
//     }
// }

void read_save () {
    FILE* fd = fopen ("save", "r+");
    char buf[255];memset (buf, 0, 255);
    while (fgets(buf, sizeof(buf), fd) != NULL) {
        if (strncmp (buf, "pv :", 3) == 0) {
            char * token = strtok (buf, ":");
            token = strtok (NULL, "\n");
            if  (token != NULL) {
            m.pv = atoi(token);
            }
        } else if (strncmp (buf, "rhum :", 3) == 0) {
            char * token = strtok (buf, ":");
            token = strtok (NULL, "\n");
            if  (token != NULL) {
            m.rhum = atoi(token);
            }
        } else if (strncmp (buf, "or :", 3) == 0) {
            char * token = strtok (buf, ":");
            token = strtok (NULL, "\n");
            if  (token != NULL) {
            m.or = atoi(token);
            }
        } else if (strncmp (buf, "atk :", 3) == 0) {
            char * token = strtok (buf, ":");
            token = strtok (NULL, "\n");
            if  (token != NULL) {
            m.attack = atoi(token);
            }
        } 
    } 
}

int appliquer_effet(char* effet, int stat) {

    // Appliquer l'effet (POJ pour pièces d'or, PVJ pour points de vie, RHUMJ pour le rhum, ATKJ pour l'attaque, QUIT pour quitter l'ile)
    if (strcmp(effet, "POJ") == 0) {
        m.or = m.or + stat;
        printf("Vous avez maintenant %d pièces d'or.\n", m.or);
        write_save();
            if(m.or <= 0) {
                printf("La faillite totale!!! Dur la vie, vous deprimez!! \n");
                m.pv = m.pv -10;
                m.rhum = m.rhum;
                printf("Vous avez maintenant %d points de vie.\n", m.pv);
                printf("Vous avez maintenant %d bouteilles de rhum.\n", m.rhum);
                write_save();
            }
    } else if (strcmp(effet, "PVJ") == 0) {
        m.pv = m.pv + stat;
        printf("Vous avez maintenant %d points de vie.\n", m.pv);
        write_save();
    } else if (strcmp(effet, "RHUMJ") == 0) {
        m.rhum = m.rhum + stat;
        printf("Vous avez maintenant %d bouteilles de rhum.\n", m.rhum);
        write_save();
            if (m.rhum <= 0) {
                printf("Vous n'avez plus de rhum, dur dur, alcoolique que vous etes, vous ne vous sentez pas bien...\n");
                m.pv = m.pv -10;
                printf("Vous avez maintenant %d points de vie.\n", m.pv);
                write_save();
            }           
    } else if (strcmp(effet, "ATKJ") == 0) {
        m.attack = m.attack + stat;
        printf("Vous avez maintenant %d points d'attaque.\n", m.attack);
        write_save();
    } else if (strcmp(effet, "QUIT") == 0) {
        return 0;
    } else {
        printf("Aucun effet\n");
    }
}

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
        for (int i = 0; i < nbQuetes; i++) {
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