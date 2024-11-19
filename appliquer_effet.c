#pragma once
#include "global.h"

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