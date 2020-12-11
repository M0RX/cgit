#include <stdio.h>
#include <malloc.h>

int main() {
    unsigned int res, n;
    double *a, *b;

    do {
        printf("Dimension: ");
        scanf("%i", &n);
    } while (n < 1);


    a = (double*) malloc(n*sizeof(double));
    b = (double*) malloc(n*sizeof(double));
    printf("////////////////////////////////////////////////////\n");
    for (int j = 0; j < n; ++j) {
        printf("Gib die %i Dimension für den Vektor a an: ", j);
        scanf("%lf", &a[j]);
    }
    printf("////////////////////////////////////////////////////\n");
    for (int j = 0; j < n; ++j) {
        printf("Gib die %i Dimension für den Vektor b an: ", j);
        scanf("%lf", &b[j]);
    }
    res = 0;
    for (int j = 0; j < n; ++j) {
        res = res + (a[j] * b[j]);
    }
    printf("////////////////////////////////////////////////////\n");
    printf("Das Skalarprodukt ist %i", res);
    free(a);
    free(b);
    return 0;
}