#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "utils.h"
#include "BinaryNumbers.h"

/**
 * Testa operações com números binários
 */

void BinaryNumbersTest() {
     system(CLS);
     title("Binary Numbers");
     int n = 0;
     char *bitstr;
     sub("ToStrBin2() Decimal -> Binario");
     lf();
     while (true) {
         printf("Numero em decimal (-1 prox): ");
         scanf("%d", &n);
         if (n == -1) break;
         bitstr = ToStrBin2(n);
         printf("Resultado: %sb\n", bitstr);
         free(bitstr);
         lf();
     }
     lf();
     sub("BinaryToInt2() Binario -> Decimal");
     lf();
     long long bin = 0;
     while (true) {
         printf("Numero em binario (-1 sair): ");
         scanf("%lld", &bin);
         if (bin == -1) break;
         limpalf();
         printf("Resultado: %hi\n", BinaryToInt2(bin));
         lf();
     }
}

/**
 * Converte Inteiros para Binário. 
 * @return uma string no formato 11111111
 * @param val - valor a ser convertido
 **/

char *ToStrBin2(short val) {
    struct s_bits {
        unsigned short h1:1, h2:1, h3:1, h4:1, h5:1, h6:1, h7:1, h8:1;
        unsigned short l1:1, l2:1, l3:1, l4:1, l5:1, l6:1, l7:1, l8:1;
    };
    union u_byte{
        struct s_bits bits;
        unsigned short byte;
    } conv;
    
    conv.byte = (unsigned short) val;
    char *buffer = (char *) malloc(sizeof(char) * 17);
    
    snprintf(buffer, 17, "%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu%hhu", 
            conv.bits.l8,conv.bits.l7,conv.bits.l6,conv.bits.l5,
            conv.bits.l4,conv.bits.l3,conv.bits.l2,conv.bits.l1,
            conv.bits.h8,conv.bits.h7,conv.bits.h6,conv.bits.h5,
            conv.bits.h4,conv.bits.h3,conv.bits.h2,conv.bits.h1
            );
    return buffer;
}    

/**
 * Converte um valor decimal para uma String binária
 * @param val - valor inteiro a ser convertido
 * @return string do tipo 111010101 terminada em zero lpsz
 */

char *ToStrBin(int val){
    char *bits = (char *) malloc(sizeof(char) * 32);
    memset(bits, 0, sizeof(char) * 32);
    
    char bit;
    int pos = 0;
    while (val > 0) {
        bit = val % 2;
        val = (int) val / 2;
        bits[pos++] = (char) 48 + bit;
    }
    
    /* 
     * Os bits estão invertidos 0001, vamos inverter-los 1000
     */
    
    int len = strlen(bits);
    char *bitsr = (char *) malloc(sizeof(char) * len + 1);
    memset(bitsr, 0, sizeof(char) * len + 1);

    pos = len - 1;
    while(pos >= 0) {
        bit = bits[pos];
        // len = 8  - pos = 7  - 1 = 0
        bitsr[len - pos - 1] = bit;
        pos--;
    }
    free(bits);
    
    return bitsr;
}

/**
 * Converte uma string binária para inteiro decimal
 * @param binstr - string no formato 1010101
 * @return Valor valor decimal convertido
 */

short BinaryToInt(char *binstr){
    short len = (short) strlen(binstr);
    /* 1001111 */
    int ret = 0;
    for (int i = len - 1; i >= 0; i--) {
        short digit = binstr[i] - 48;
        ret = ret + (short) pow(2, (len - i - 1)) * digit;
    }
    return ret;
}

/**
 * Converte um numero que somente contenha 1 ou 0 (long long ) para decimal
 * @param num  - numero binario escrito em um long
 * @return numero inteiro na base 10
 */

short BinaryToInt2(long long num) {
    int dig;
    short ret = 0, i = 0;
    
    while (num != 0) {
        dig = num % 10;
        num =  (long long) num / 10;
        ret = ret + (pow(2, i) * dig);
        i++;
    }
    return ret;
}
