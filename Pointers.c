#include <stdio.h>
#include <stdlib.h>
#include "Pointers.h"
#include "utils.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

void PointersTest()
{
    system(CLS);
    char *str = "I'am being po-po-pointed";
    char **pstr = &str;
    char ***ppstr = &pstr;
    title("Pointer of a pointer that points to some string");
    
    printf("%s\n", **ppstr);
    
    system(PAUSE);
}