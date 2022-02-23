/* 
 * File:   main.c
 * Author: viniciuscgp
 *
 * Created on February 15, 2022, 8:45 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "utils.h"
#include "BinaryNumbers.h"
#include "Pointers.h"
#include "TypeQualifiers.h"
#include "restrict.h"
#include "BitManipulation.h"
#include "Testes.h"
#include "StringFunctions.h"
#include "TypeQualifiers.h"
#include "Bitmasks.h"
#include "BitFields.h"

int main(int argc, char** argv) {

    setlocale(LC_ALL, "Portuguese");
    char *locale = setlocale(LC_ALL, NULL);
    printf("\tLocale: %s\n", locale);

    char cont = true;
    while (cont) {
        system(CLS);

        title("\tEstudo Avançado de Linguagem C                          ");
        printf("\tMenu de testes:\n");
        printf("\t_______________________________________\n");
        lf();
        printf("\t01-TypeQualifiesTests\n");
        printf("\t02-PointersTest\n");
        printf("\t03-RestrictTest\n");
        printf("\t04-BinaryNumbersTest\n");
        printf("\t05-BitManipulationTests\n");
        printf("\t06-String Functions Tests\n");
        printf("\t07-Bitmasks Tests\n");
        printf("\t08-Bitfields Tests\n");
        printf("\t20-Miscelaneous Tests\n");
        printf("\t99-Sair\n");
        int op = 0;
        printf("\n\tOpcoes: ");
        scanf("%d", &op);

        switch (op) {
            case 1: TypeQualifiesTests();
                break;
            case 2: PointersTest();
                break;
            case 3: RestrictTest();
                break;
            case 4: BinaryNumbersTest();
                break;
            case 5: BitManipulationTests();
                break;
            case 6: StringFunctionsTest();
                break;
            case 7: BitmasksTests();
                break;
            case 8: BitfieldsTest();
                break;
            case 20: Testes();
                break;
            case 99: cont = false;
                break;
        }
    }
    return (EXIT_SUCCESS);
}

