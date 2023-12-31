#include <stdio.h>

void fusion(int A[], int gauche, int milieu, int droite) {
    int i, j, k;
    int n1 = milieu - gauche + 1;
    int n2 = droite - milieu;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[gauche + i];
    for (j = 0; j < n2; j++)
        R[j] = A[milieu + 1 + j];

    i = 0;
    j = 0;
    k = gauche;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void trier(int A[], int gauche, int droite) {
    if (gauche < droite) {
        int milieu = gauche + (droite - gauche) / 2;

        trier(A, gauche, milieu);
        trier(A, milieu + 1, droite);

        fusion(A, gauche, milieu, droite);
    }
}

void lire(int A[], int d) {
    for (int i = 0; i < d; i++) {
        scanf("%d", &A[i]);
    }
}

void afficher(int A[], int d) {
    for (int i = 0; i < d; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int d;
    printf("Enter the number of elements: ");
    scanf("%d", &d);

    int A[d];

    printf("Enter the elements: ");
    lire(A, d);

    printf("Original array: ");
    afficher(A, d);

    trier(A, 0, d - 1);

    printf("Sorted array: ");
    afficher(A, d);

    return 0;
}
