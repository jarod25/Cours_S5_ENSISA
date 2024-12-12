#include <stdlib.h>
#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Droite {
    int a;
    int b;
};

struct Monome {
    int c;
    int n;
};

Point* discretise(Droite d) {
    Point* result = malloc(11 * sizeof(Point));
    for (float x = 0; x <= 10; x++) {
        float y = d.a * x + d.b;
        Point p = {x, y};
        result[x] = p;
    }
    return result;
}

int main() {
    struct Point p;
    p.x = 1;
    p.y = 5;

    struct Droite d;
    d.a = 2;
    d.b = 3;

    struct Monome m;
    m.c = 3;
    m.n = 2;

    struct Point p2 = {1, 5};
    struct Droite d2 = {2, 3};
    struct Monome m2 = {3, 2};

    return 0;
}