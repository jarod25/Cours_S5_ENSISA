#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* range(int n) {
    int* array = malloc((n + 1) * sizeof(int));
    if (array == NULL) {
        return NULL;
    }
    *array = n;
    for (int i = 1; i <= n; i++) {
        *(array + i) = i;
    }
    return array;
}

int* map(int (*f)(int), int* array) {
    int* result = malloc((array[0] + 1) * sizeof(int));
    if (result == NULL) {
        return NULL;
    }
    *result = array[0];
    for (int i = 1; i <= array[0]; i++) {
        *(result + i) = f(*(array + i));
    }
    return result;
}

int square(int x) {
    return x * x;
}

int sum(int* array) {
    int n = *array;
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += *(array + i);
    }
    return total;
}

int main() {
    int n = 5;
    int* array = range(n);
    if (array == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        return 1;
    }

    printf("Intervalle : ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");

    int* squared_array = map(square, array);
    if (squared_array == NULL) {
        free(array);
        printf("Erreur d'allocation de mémoire\n");
        return 1;
    }

    printf("Carrés : ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", *(squared_array + i));
    }
    printf("\n");

    printf("Somme : %d\n", sum(array));
    printf("Somme : %d\n", sum(squared_array));

    free(array);
    free(squared_array);
    return 0;
}
