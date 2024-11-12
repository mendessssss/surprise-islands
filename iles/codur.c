#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF_SIZE 255

int main () {

    char line[BUF_SIZE]; memset(line, 0, BUF_SIZE);
    char buf[BUF_SIZE]; memset(buf, 0, BUF_SIZE);
    int choix;

    FILE *file = file = fopen("ile4", "r");
    // Connaitre la taille du fichier
    fseek(file ,0, SEEK_END);
    int sizeFile = ftell(file);
    char text_content[sizeFile]; memset(buf, 0, BUF_SIZE);
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
            printf("%s",choix1);
        } 
        if (choix == 2) {
            printf("%s",choix2); 
        }    
        if (choix == 3) {
            printf("%s",choix3);
        } 
        else if (choix <= 0 || choix >= 4) {
            printf("Choix invalide\n");
        }
    }

return 0;
}