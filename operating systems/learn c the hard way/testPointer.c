#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int x;
    x = 10;
    printf("%p \n", &x);
    printf("%d \n", x);

    // le pointeur
    int *px; // reserve un emplace,ent pour stocker une adresse memoire
    px = &x; // Ecrit l'adresse de x dans cet emplacement

    printf("%p \n", px);
    printf("%d \n", *px);

    *px = 20;
    printf("%d \n", x);
    printf("%d \n", *px);

    // pointeurs et tableaux
    int Tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d \n", *Tab);
    printf("%p \n", &Tab);

    printf("pointer tableau \n");
    int *pTab = Tab;
    printf("%d \n", *pTab); // both do the same thing
    *pTab++;
    pTab[0]++;
    printf("%d \n", pTab[0]);

    printf("%d \n", Tab[100]);
    printf("%d \n", *(Tab + 100));

    // Arithmetique des pointeurs
    printf("%d \n", *(Tab + 1));
    pTab++;
    printf("%d \n", *pTab); // or pTab[0]

    // Pointeurs et allocation dynamique de la memoire
    // malloc need #include <stdlib.h>
    int *p = malloc(10*sizeof(int));
    if (p)
    {
        p[0] = 5;
        printf("%d", p[0]);
        free(p);
    }

    // pointer comme parametres de fonctions
    void exchange(int *x, int *y)
    {
        int tmp;
        tmp = *x;
        *x = *y;
        *y = tmp;
    }

    int a;
    int b;
    a = 5;
    b = 10;
    printf("a = %d \nb = %d\n", a, b);
    exchange(&a, &b);
    printf("a = %d \nb = %d\n", a, b);

    int max(int *tab, int n)
    {
        int x;
        int nmax;
        nmax = 0;

        for (x = 0; x < n; x++) {
            if (tab[x] > nmax) {
                nmax = tab[x];
            };
        };

        return nmax;
    }

    int newTab[] = {12, 6, 16, 7, 3, 11, 15, 7, 11, 9};
    printf("%d", max(newTab, 10));

    int(*pmax)(int*, int);
    pmax = max;

    printf("%d", pmax(newTab, 10));

    return 0;
}
