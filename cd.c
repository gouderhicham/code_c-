#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int val;
    struct element *suivant;
} element;

element *creerListe() {
    return NULL;
}

element *chargerListe(int Tab[], int n, element *liste) {
    element *L = creerListe();
    for (int i = n - 1; i >= 0; i--) {
        element *nouveau = (element *)malloc(sizeof(element));
        nouveau->val = Tab[i];
        nouveau->suivant = L;
        L = nouveau;
    }
    return L;
}

void afficherListe(element *L) {
    while (L != NULL) {
        printf("%d -> ", L->val);
        L = L->suivant;
    }
    printf("NULL\n");
}

element *supprimerEnFin(element *L) {
    if (L == NULL || L->suivant == NULL) {
        free(L);
        return NULL;
    }

    element *current = L;
    while (current->suivant->suivant != NULL) {
        current = current->suivant;
    }

    free(current->suivant);
    current->suivant = NULL;
    return L;
}

element *ajouterEnDebut(element *L, int val) {
    element *nouveau = (element *)malloc(sizeof(element));
    nouveau->val = val;
    nouveau->suivant = L;
    return nouveau;
}

void viderListe(element *L) {
    while (L != NULL) {
        element *temp = L;
        L = L->suivant;
        free(temp);
    }
    printf("la liste est vide\n");
}

int main() {
    int Tab[10] = {1, 3, 5, 7, 8, 10, 9, 11, 13, 20};
    element *liste = creerListe();
    element *L = chargerListe(Tab, 10, liste);

    afficherListe(L);

    element *L1 = supprimerEnFin(L);
    afficherListe(L1);

    element *L2 = ajouterEnDebut(L1, 40);
    afficherListe(L2);

    viderListe(L2);

    return 0;
}
