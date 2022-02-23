#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "restrict.h"
#include "utils.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

void RestrictTest()
{
    system(CLS);
    title("Restrict Pointers");
    lf();
    
    int n;
    int array[10];
    int * restrict restar = (int *) malloc(10 * sizeof(int));
    int * test = restar;
    int *par = array;
    memset(restar, 0, 10 * sizeof(int));
    
    for (n = 0; n < 10; n++) {
        par[n] += 5;
        restar[n] += 5;
        array[n] *= 2;
        par[n] += 3;
        restar[n] += 3;
    }
    for (n = 0; n < 10; n++) {
        printf("restar %d -> %d\n", n, restar[n]);
    }
    system(PAUSE);
}

