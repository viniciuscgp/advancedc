/*
 * @author Vinicius 
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void dint(int v) {
    printf("%d", v);
}

void dstr(char *v) {
    printf("%s", v);
}

void lf(void) {
    printf("\n");
}

void title(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        printf("%c", '-');
    lf();
    printf("%s\n", str);
    for (int i = 0; i < len; i++)
        printf("%c", '-');
    lf();
}

void sub(char *str) {
    int len = strlen(str);
    printf("%s\n", str);
    for (int i = 0; i < len; i++)
        printf("%c", '_');
    lf();
}

void limpalf() {
    while (getchar() != '\n');
}

char *padzero(char *str, int size) {
    int len = strlen(str);
    int dif = (int) size - len;
    if (dif > 0) {
        str = (char *) realloc(str, strlen(str) + dif + 1);
        memcpy(str + dif, str, len);
        for (int i = 0; i < dif; i++) {
            str[i] = 48; // zero
        }
        str[len + dif] = '\0';
    }
    return str;
}



