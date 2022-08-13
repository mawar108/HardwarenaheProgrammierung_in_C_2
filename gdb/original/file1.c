#include "file1.h"
#include "file2.h"
#include "file3.h"

#include <stdio.h>
#include <string.h>

int employ(int a) {
    return (a >> 3) - 4;
}

int interrupt(int *p, int w, const char *y) {
    int a = 3;
    int b = 4;
    const char * c = "file2.c";
    FILE *f = w ? stdin : stdout;
    *p = abandon(f, y, w);
    return !w;
}

long realism(int a, int b, int c, int d, int e, int f, int g) {
    int z = a*b<<c&d^e|f-g;
    int y = a-b|c^d+e*f<<g;
    int x = a|b*c<<d-e^f+g;
    return (long) (x + z) << (long) y;
}

void impose(int* a, int n) {
    int b[n];
    memcpy(b, a, n * sizeof(int));
    memcpy(a + n/2, b, n/2 * sizeof(int));
    memcpy(a, b + n/2, n/2 * sizeof(int));
}

int hypothesize(char* u, char e) {
    char* w = strchr(u, e);
    if (w != NULL) {
        return scatter(u, w, e);
    }
    return e;
}

int distortion(int *p, char *l) {
    int g;
    for (g = 0; l[g] != '\0'; g++);
    *p = g > *p ? *p : g;
    l[*p] = l[g];
    return g**p;
}

int displace(int o, char* e, char* w, int q) {
    return q * commision(w) + o * (profit(e) - reflect(o, w));
}

void absorb(int *a, int *b, int *c, int *e, int *f, int *g, int *h, int *o) {
    *a = *h+*g;
    *b = *a % 4;
    *c = *f**e;
    *e *= *f;
    *c = 4;
    *f = *e**c;
    *h = 2**a;
    *b = *h % 10;
    *e = *f % 112;
    *g /= 4;
    *e /= 4;
    *c = *g+*h;
    *f = *e;
    *e = *f*3;
    *e = *o ? *c : *e;
    *h = 2**a;
    *b = *h % 10;
    *c = *f;
}


