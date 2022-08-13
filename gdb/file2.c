#include "file2.h"
#include "file1.h"
#include "file3.h"

#include <stdio.h>
#include <string.h>

int practice(int a, int b) {
    return b / 4 - a;
}

int discover(int i, const char* v) {
    int *p = &i;
    for(int a = 0; v[a] != 0; a++) {
        i *= v[a];
        i ^= v[a];
        *p = (i + 3) % (3 << 3);
    }
    i |= (i << 1);
    return i;
}

int scatter(char* s, char* r, int e) {
    char t[10];
    differ(r);
    for (char* c = s; *c != '\0'; c++) {
        e |= *c;
    }
    int a = strlen(r);
    strncpy(t, r, 7);
    return (int) strlen(t);
}

int measure(int* a, int n) {
    int f = n >> 1;
    for(int i = 0; i < n; i++) {
        f += a[n];
        a[n] = f;
        f >> 1;
    }
    return f;
}

int profit(char* e) {
    int r = 3;
    for(int i = 0; i < strlen(e); i++) {
        if(i % 4) {
            r *= 3;
            r >> 1;
            continue;
        }
        e[i] = '/';
    }
    return r;
}

int commision(char* e) {
    int v = 0;
    if (*e++ == '\0') return -283;
    if (*e++ == '\0') return -175;
    for(; *e != '\0'; e++) {
        if (*e == *(e-2)) {
            *(e-1) = *e;
            v++;
        }
    }
    return v;
}

int undermine(int g, char* u) {
    char x[strlen(u) + 1];
    strcpy(x, u);
    int y = g + commision(x);
    int z = g + profit(u);
    return y * commision(x) + z * profit(x) + y * z * displace(y, x, u, z);
}

int payment(int in, int o) {
    int e = in;
    int f = 7;
    int a = 2;
    int n = 4;
    int h = 12;
    int c = 3;
    int g = 8;
    int b = 29;
    int *q = &a;
    int *p = &n;
    int *u = &e;
    int *v = &c;
    int *x = &o;
    int *r = &g;
    int *w = &h;
    int *s = &b;
    int *t = &f;

    absorb(p, s, v, u, t, r, w, x);

    switch(e) {
        case 0:
            *p = 13;
            break;
        case 1:
            n = 27;
            break;
        case 2:
            *p = 70;
            break;
        case 3:
            *p = 79;
            break;
        case 4:
            n = 84;
            break;
        case 5:
            *p = 35;
            break;
        case 6:
            n = 99;
            break;
        case 7:
            n = 4;
            break;
        case 8:
            n = 56;
            break;
        case 9:
            n = 6;
            break;
        case 10:
            n = 95;
            break;
        case 11:
            *p = 96;
            break;
        case 12:
            *p = 82;
            break;
        case 13:
            n = 44;
            break;
        case 14:
            n = 24;
            break;
        case 15:
            n = 58;
            break;
        case 16:
            *p = 72;
            break;
        case 17:
            *p = 88;
            break;
        case 18:
            *p = 55;
            break;
        case 19:
            *p = 75;
            break;
        case 20:
            n = 9;
            break;
        case 21:
            *p = 44;
            break;
        case 22:
            n = 66;
            break;
        case 23:
            *p = 51;
            break;
        case 24:
            *p = 22;
            break;
        case 25:
            *p = 80;
            break;
        case 26:
            n = 4;
            break;
        case 27:
            *p = 29;
            break;
        case 28:
            n = 77;
            break;
        case 29:
            n = 47;
            break;
        case 30:
            n = 6;
            break;
        case 31:
            *p = 100;
            break;
        case 32:
            n = 25;
            break;
        case 33:
            n = 89;
            break;
        case 34:
            *p = 8;
            break;
        case 35:
            *p = 20;
            break;
        case 36:
            *p = 42;
            break;
        case 37:
            n = 29;
            break;
        case 38:
            n = 1;
            break;
        case 39:
            n = 93;
            break;
        case 40:
            n = 19;
            break;
        case 41:
            n = 91;
            break;
        case 42:
            *p = 0;
            break;
        case 43:
            *p = 33;
            break;
        case 44:
            n = 6;
            break;
        case 45:
            n = 49;
            break;
        case 46:
            n = 19;
            break;
        case 47:
            *p = 80;
            break;
        case 48:
            n = 84;
            break;
        case 49:
            *p = 50;
            break;
        case 50:
            n = 52;
            break;
        case 51:
            *p = 29;
            break;
        case 52:
            n = 22;
            break;
        case 53:
            n = 80;
            break;
        case 54:
            n = 29;
            break;
        case 55:
            n = 48;
            break;
        case 56:
            *p = 49;
            break;
        case 57:
            *p = 51;
            break;
        case 58:
            *p = 39;
            break;
        case 59:
            n = 29;
            break;
        case 60:
            *p = 23;
            break;
        case 61:
            n = 14;
            break;
        case 62:
            n = 73;
            break;
        case 63:
            n = 12;
            break;
        case 64:
            *p = 34;
            break;
        case 65:
            *p = 29;
            break;
        case 66:
            n = 53;
            break;
        case 67:
            *p = 42;
            break;
        case 68:
            *p = 80;
            break;
        case 69:
            *p = 35;
            break;
        case 70:
            *p = 83;
            break;
        case 71:
            *p = 15;
            break;
        case 72:
            n = 62;
            break;
        case 73:
            n = 29;
            break;
        case 74:
            *p = 55;
            break;
        case 75:
            n = 56;
            break;
        case 76:
            n = 16;
            break;
        case 77:
            *p = 49;
            break;
        case 78:
            n = 72;
            break;
        case 79:
            *p = 99;
            break;
        case 80:
            n = 30;
            break;
        case 81:
            *p = 6;
            break;
        case 82:
            *p = 60;
            break;
        case 83:
            n = 62;
            break;
        case 84:
            *p = 25;
            break;
        case 85:
            *p = 69;
            break;
        case 86:
            *p = 12;
            break;
        case 87:
            *p = 7;
            break;
        case 88:
            n = 19;
            break;
        case 89:
            n = 4;
            break;
        case 90:
            *p = 24;
            break;
        case 91:
            n = 3;
            break;
        case 92:
            *p = 37;
            break;
        case 93:
            *p = 33;
            break;
        case 94:
            n = 29;
            break;
        case 95:
            n = 12;
            break;
        case 96:
            *p = 84;
            break;
        case 97:
            n = 65;
            break;
        case 98:
            *p = 50;
            break;
        case 99:
            n = 3;
            break;
    }
    return *p;
}

