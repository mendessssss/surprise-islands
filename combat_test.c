#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *name;
    int health;
    int maxHealth;
    int attackPower;
} Character;

void attack(Character *attacker, Character *defender) {
    int damage = rand() % attacker->attackPower + 1;
    defender->health -= damage;
    if (defender->health < 0) defender->health = 0;
    printf("%s inflige %d dégâts à %s!\n", attacker->name, damage, defender->name);
}

void heal(Character *player) {
    int healAmount = rand() % 20 + 10;
    player->health += healAmount;
    if (player->health > player->maxHealth) player->health = player->maxHealth;
    printf("%s se soigne de %d points de vie!\n", player->name, healAmount);
}

void displayStatus(Character *player, Character *enemy) {
    printf("\n-- Statut --\n");
    printf("%s: %d/%d PV\n", player->name, player->health, player->maxHealth);
    printf("%s: %d/%d PV\n", enemy->name, enemy->health, enemy->maxHealth);
}

int main() {
    
    srand(time(NULL));

    Character player = {"Joueur", 100, 100, 20};
    Character enemy = {"Ennemi", 80, 80, 15};

    printf("Début du combat entre %s et %s!\n", player.name, enemy.name);

    while (player.health > 0 && enemy.health > 0) {
        displayStatus(&player, &enemy);

        printf("\nActions disponibles:\n");
        printf("1. Attaquer\n");
        printf("2. Se soigner\n");
        printf("3. Fuir\n");
        printf("Choisissez une action: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                attack(&player, &enemy);
                break;
            case 2:
                heal(&player);
                break;
            case 3:
                printf("%s décide de fuir le combat!\n", player.name);
                return 0;
            default:
                printf("Choix invalide.\n");
                continue;
        }

        // Tour de l'ennemi si l'ennemi est encore en vie
        if (enemy.health > 0) {
            attack(&enemy, &player);
        }
    }

    // Fin du combat
    if (player.health <= 0) {
        printf("\n%s a été vaincu...\n", player.name);
    } else if (enemy.health <= 0) {
        printf("\n%s a été vaincu! Vous avez gagné!\n", enemy.name);
    }

    return 0;
}
