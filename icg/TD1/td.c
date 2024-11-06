#include <stdio.h>
#include <math.h>

float ps[3];
float cs[11];

float sn(float x) {
    return 4 * x * (M_PI - x) / pow(M_PI, 2);
}

float f(float x) {
    return 0.5 - sn(x) + x;
}

float pf() {
    float x = 0.1;
    int nb_iter = 0;
    while ((x - f(x)) * (x - f(x)) > 0.00001) {
        x = f(x);
        nb_iter++;
    }
    printf("Nombre d'iterations %d\n", nb_iter);
    return x;
}

float g(float x) {
    return 3.99 * x * (1 - x);
}

float exo4(float x) {
    for (int i = 0; i < 10; i++) {
        x = g(x);
        printf("%f\n", x);
    }
    return x;
}

void def_cs() {
    float d = M_PI / 10;
    for (int i = 0; i <= 10; i++) {
        cs[i] = sn(i * d);
    }
}

void def_ps() {
    // Définir les valeurs pour ps[i] selon les besoins
    ps[0] = 1; // x_0
    ps[1] = 2; // x_1
    ps[2] = 3; // x_2
}

// float calc_p(float i) {
//     float d = M_PI / 10;
//     float result = 0.0;
//     for (int j = 0; j <= 2; j++) {
//         result += ps[j] * pow(i * d, j);
//     }
//     return result;
// }

void exo5(const float i) {
    def_cs();
    def_ps();
    // printf("p(%f) = %f\n", i, calc_p(i));
} ;

void main() {
    // Exercice 1
    printf("=========== Exercice 1 ===========\n\n");
    printf("PI/2 : %f\n", sn(M_PI / 2));
    printf("PI/3 : %f\n", sn(M_PI / 3));
    printf("PI/4 : %f\n", sn(M_PI / 4));

    // Exercice 2
    printf("\n=========== Exercice 2 ===========\n\n");
    printf("%f\n", pf());

    // Exercice 4
    printf("\n=========== Exercice 4 ===========\n\n");
    exo4(0.123);

    // Exercice 5
    printf("\n=========== Exercice 5 ===========\n\n");
    exo5(1);

}
