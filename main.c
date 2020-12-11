#include <stdio.h>
#include <math.h>

void menue() {
    printf("\n");
    printf("1 - Eingabe Zahl1\n");
    printf("2 - Eingabe Zahl2\n");
    printf("3 - Ausgabe Summe\n");
    printf("4 - Ausgabe Produkt\n");
    printf("5 - Ausgabe Subtraktion\n");
    printf("6 - Ausgabe Division mit Div0 Prüfung\n");
    printf("7 - Ausgabe aller möglichen Multiplikationen von (1...Zahl1) * (1...Zahl2)\n");
    printf("8 - Quadratwurzel für Zahl1 nach Heron-Verfahren\n");
    printf("9 - Beenden\n");
    printf("\n");
}

int main() {
    int zahl1, zahl2;
    int auswahl;
    do {
        menue();
        printf("Auswahl: ");
        scanf("%i", &auswahl);
        printf("\n");
        switch (auswahl) {
            case 1: {
                printf("Gebe Zahl1 ein: ");
                scanf("%i", &zahl1);
                break;
            }
            case 2: {
                printf("Gebe Zahl2 ein: ");
                scanf("%i", &zahl2);
                break;
            }
            case 3: {
                printf("Das Ergebnis lautet: %i", zahl2 + zahl1);
                break;
            }
            case 4: {
                printf("Das Ergebnis lautet: %i", zahl2 * zahl1);
                break;
            }
            case 5: {
                printf("Das Ergebnis lautet: %i", zahl1 - zahl2);
                break;
            }
            case 6: {
                if (zahl2 != 0) {
                    printf("Das Ergebnis lautet: %fl", zahl1 / zahl2);
                } else {
                    printf("Division durch 0!!!");
                }
                break;
            }
            case 7: {
                for (int i = 1; i <= zahl1; ++i) {
                    for (int j = 1; j <= zahl2; ++j) {
                        printf("%i mal %i ist %i\n", i, j, i*j);
                    }
                }
                break;
            }
            case 8: {
                double x = zahl1 / 2.0;
                double y;
                int n = 15;
                for (int i = 0; i < n; ++i) {
                    y = (zahl1 + x * x) / (2 * x);
                    x = y;
                }
                double a = 1, b = 1;
                do {
                    a = b;
                    b = (a + (zahl1/a))/2;
                } while (fabs(a - b) >= 0.000001);
                printf("Die Wurzel aus %i ist %f", zahl1, b);
                break;
            }
            case 9: {
                printf("Goodbye <3!\n");
                break;
            }
        }
        printf("\n");
    } while (auswahl != 9);

    return 0;
}
