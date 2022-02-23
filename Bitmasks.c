/**
 Manipulação de Bits
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "utils.h"
#include "BinaryNumbers.h"
#include "Bitmasks.h"

unsigned static short flags = 349;
unsigned static short mask = 1;

void BitmasksTests() {
    bool continua = true;
    char op = 0;
    while (continua) {
        system(CLS);
        title("Mascaras de Bits (CTRL + C sair)");
        lf();
        lf();

        printf("\tMenu de Testes\n");
        printf("\t_______________________________________\n");
        lf();
        printf("\t01-Testar um BIT\n");
        printf("\t02-Desativar um BIT\n");
        printf("\t03-Ativar um BIT\n");
        printf("\t04-Flip/flop\n");
        printf("\t99-Voltar\n");
        lf();
        printf("\tOpcao:");
        scanf("%2d", &op);

        switch (op) {
            case 1:
                system(CLS);
                sub("Teste iterativo de BIT utilizando AND = &");
                printf("Para isso, utilizamo uma mascara com AND.\n\n");
                printf("          %s\n", REGUA16);
                printf("Flags    :%s\n", ToStrBin2(flags));
                while (1) {
                    printf("\nQual bit voce deseja TESTAR (0-15) (-1 sair) ? ");
                    short hQualBit = 0;
                    scanf("%hi", &hQualBit);
                    lf();
                    if (hQualBit == -1) break;

                    mask = 1;
                    for (int i = 0; i < hQualBit; i++) {
                        mask = mask << 1;
                    }
                    printf("           %s\n", REGUA16);
                    printf("Flags    : %s\n", ToStrBin2(flags));
                    printf("Mascara  : %s\n", ToStrBin2(mask));
                    printf("Reultado : %s\n", (flags & mask) == mask ? "LIGADO" : "DESLIGADO");
                }
                system(PAUSE);
                break;
            case 2:
                system(CLS);
                sub("Teste iterativo de DESTIVAR BIT utilizando ~ e AND            ");
                printf("Para desativar um BIT, basta setarmos esse bit na mascara\n");
                printf("Ou seja, 2 ^ N. Depois precisamos inverter os bits com ~ (NOT)\n");
                printf("e entao aplicamos a Mascara nos Flags com AND.\n\n");
                printf("          %s\n", REGUA16);
                printf("Flags    :%s\n", ToStrBin2(flags));
                while (1) {
                    printf("\nQual bit de 'Flags' voce deseja DESATIVAR (0-15) (-1 sair) ? ");
                    short hQualBit = 0;
                    scanf("%hi", &hQualBit);
                    if (hQualBit == -1) break;
                    mask = (unsigned short) pow(2, hQualBit); // 000000000001000
                    mask = ~mask; // 111111111110111
                    flags = flags & mask;
                    lf();
                    printf("           %s\n", REGUA16);
                    printf("Flags    : %s\n", ToStrBin2(flags));
                    printf("Mascara  : %s\n", ToStrBin2(mask));
                }
                system(PAUSE);
                break;
            case 3:
                system(CLS);
                sub("Teste iterativo de ATIVAR BIT utilizando OR '|'              ");
                printf("Para ATIVAR um BIT, basta setarmos esse bit na mascara\n");
                printf("Ou seja, 2 ^ N. Depois aplicamos a Mascara nos Flags com | .\n");
                printf("          %s\n", REGUA16);
                printf("Flags    :%s\n", ToStrBin2(flags));
                while (1) {
                    printf("\nQual bit de 'Flags' voce deseja ATIVAR (0-15) (-1 sair) ? ");
                    short hQualBit = 0;
                    scanf("%hi", &hQualBit);
                    if (hQualBit == -1) break;
                    mask = (unsigned short) pow(2, hQualBit); // 000000000001000
                    flags = flags | mask;
                    lf();
                    printf("           %s\n", REGUA16);
                    printf("Flags    : %s\n", ToStrBin2(flags));
                    printf("Mascara  : %s\n", ToStrBin2(mask));
                }
                system(PAUSE);
                break;

            case 4:
                system(CLS);
                sub("Teste iterativo de ALTERNAR BIT utilizando XOR '|'              ");
                printf("Para ALTERNAR um BIT, basta setarmos esse bit na mascara\n");
                printf("Ou seja, 2 ^ N. Depois aplicamos a Mascara nos Flags com ^ 'xor'.\n");
                printf("          %s\n", REGUA16);
                printf("Flags    :%s\n", ToStrBin2(flags));
                while (1) {
                    printf("\nQual bit de 'Flags' voce deseja ALTERNAR (0-15) (-1 sair) ? ");
                    short hQualBit = 0;
                    scanf("%hi", &hQualBit);
                    if (hQualBit == -1) break;
                    mask = (unsigned short) pow(2, hQualBit); // 000000000001000
                    flags = flags ^ mask;
                    lf();
                    printf("           %s\n", REGUA16);
                    printf("Flags    : %s\n", ToStrBin2(flags));
                    printf("Mascara  : %s\n", ToStrBin2(mask));
                }
                system(PAUSE);
                break;

            case 99:
                continua = false;
                break;

        }
    }
}

