/**
 Manipulação de Bits
 */
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "BitManipulation.h"
#include "BinaryNumbers.h"

void BitManipulationTests() {
    system(CLS);    
    title("Manipulação de Bits (CTRL + C sair)");
    lf();
    unsigned short n1 = 0;
    unsigned short n2 = 0;
    printf("Valor para n1: ");
    scanf("%hi", &n1);
    limpalf();
    printf("Valor para n2: ");
    scanf("%hi", &n2);
    limpalf();
    
    printf("End  n1 %p\n", &n1);
    printf("End  n2 %p\n", &n2);

    printf("n1      %s = %hi\n", ToStrBin2((short) n1), (short) n1);
    printf("n2      %s = %hi\n", ToStrBin2((short) n2), (short) n2);
    printf("----------------------------------------------\n");
    printf("n1 | n2 %s = %hhi\n", ToStrBin2((short) n1 | n2), n1 | n2);
    printf("n1 & n2 %s = %hhi\n", ToStrBin2((short) n1 & n2), n1 & n2);
    printf("n1 ^ n2 %s = %hhi\n", ToStrBin2((short) n1 ^ n2), n1 ^ n2);
    printf("n1~     %s = %hhi\n", ToStrBin2((short) ~n1), (short) ~n1);
    printf("n2~     %s = %hhi\n", ToStrBin2((short) ~n2), (short) ~n2);
    lf();
    system(PAUSE);
    sub("Deslocamento de Bits\n"); lf();
    unsigned short s1 = 1;
    int c = 1;
    while (c-- > 0) {
        printf("Deslocamento a esquerda << (efeito multiplica)\n");
        for (int i = 0; i < 7; i++) {
            printf("%s = %hu\n", ToStrBin2(s1), s1);
            s1 = s1 << 1;
        }
        s1 = s1 >> 1;
        printf("Deslocamento a direita >> (efeito divide)\n");
        for (int i = 0; i < 7; i++) {
            printf("%s = %hu\n", ToStrBin2(s1), s1);
            s1 = s1 >> 1;
        }
    }
    system(PAUSE);

}



