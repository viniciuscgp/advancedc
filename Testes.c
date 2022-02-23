#include <stdio.h>
#include <stdlib.h>
#include "Testes.h"
#include "utils.h"
#include "limits.h"

void Testes() {
    system(CLS);
    sub("Tamanho, em bytes, dos principais tipos:");
    lf();
    printf("Size of char      : %ld byte  \n", sizeof (char));
    printf("Size of short     : %ld bytes \n", sizeof (short));
    printf("Size of int       : %ld bytes \n", sizeof (int));
    printf("Size of long      : %ld bytes \n", sizeof (long));
    printf("Size of long long : %ld bytes \n", sizeof (long long));
    lf();
    lf();
    printf("Size of float     : %ld bytes \n", sizeof (float));
    printf("Size of double    : %ld bytes \n", sizeof (double));
    lf();

    system(PAUSE);
}
