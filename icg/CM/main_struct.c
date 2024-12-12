#include <stdio.h>
#include <stdlib.h>

struct Heure {
    int h;
    int m;
};

void affiche(struct Heure heure) {
    if (heure.h < 10) {
        printf("0");
    }
    if (heure.m == 0) {
        printf("%d:00\n", heure.h);
    } else {
        printf("%d:%d\n", heure.h, heure.m);
    }
}

int minutes_depuis_minuit(struct Heure heure) {
    return heure.h * 60 + heure.m;
}

struct Heure heure_depuis_minuit(int duree) {
    struct Heure heure;
    heure.h = duree / 60;
    heure.m = duree % 60;
    if (heure.h >= 24) {
        heure.h %= 24;
    }
    return heure;
}

struct Heure ajoute_minutes(struct Heure heure, int minutes) {
    int min = minutes_depuis_minuit(heure);
    min += minutes;
    return heure_depuis_minuit(min);
}

int main() {
    struct Heure heure_courante;
    heure_courante.h = 10;
    heure_courante.m = 59;
    affiche(heure_courante);
    printf("%d\n", minutes_depuis_minuit(heure_courante));
    affiche(ajoute_minutes(heure_courante, 780));
}

