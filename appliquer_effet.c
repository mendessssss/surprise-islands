#pragma once 
#include "global.h"

void appliquer_effet(char* effet) {
    // Appliquer l'effet basé sur la commande donnée (PO pour pièces d'or, PA pour points de vie)
    if (strncmp(effet, "PO", 2) == 0) {
        int loot = atoi(effet + 3);  // Extraire l'effet sur l'or (après "PO")
        m.or = m.or + loot;
        printf("Vous avez maintenant %d pièces d'or.\n", m.or);
    } else if (strncmp(effet, "PV", 2) == 0) {
        int loot = atoi(effet + 3);  // Extraire l'effet sur les points de vie (après "PV")
        m.pv = m.pv + loot;
        printf("Vous avez maintenant %d points de vie.\n", m.pv);
    } else {
        printf("Aucun effet\n");
    }
}