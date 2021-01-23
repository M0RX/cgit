#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    time_t sec;
    sec = time(NULL);
    srand(sec);
    int game = 1;
    do {
        printf("Willkommen.\n");
        int random = rand() % 15;
        random++;
        int tries = 0;
        int input;
        do {
            printf("Gib bitte eine Zahl ein du Hurensohn: \n");
            scanf("%d", &input);
            if (input > random) {
                printf("Die eingegebene Zahl war zu groß!\n");
            } else if (input < random) {
                printf("Die eingegebene Zahl war zu klein!\n");
            } else {
                printf("Du hast gewonnen!");
                tries = 4;
            }
            tries++;
        } while (tries < 3);
        printf("Möchtest du nochmal spielen? 0 = Nein, 1 = Ja\n");
        scanf("%d", &game);
    } while (game > 0);

    return 0;
}
