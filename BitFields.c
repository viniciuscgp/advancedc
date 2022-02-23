#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "limits.h"
#include "BitFields.h"
#include "BinaryNumbers.h"

struct packed_struct {
    unsigned int : 3;
    unsigned int f1 : 1;
    unsigned int f2 : 1;
    unsigned int f3 : 1;
    unsigned int type : 8;
    unsigned int index : 18;
};

union packed_union {
    struct packed_struct packed_data;
    unsigned int value;
};

void BitfieldsTest() {
    system(CLS);
    sub("Estrutura com campos de bits 32 bits = 4 bytes   ");
    lf();
    printf("struct packed_struct {\n");
    printf("    unsigned int : 3;\n");
    printf("    unsigned int f1 : 1;\n");
    printf("    unsigned int f2 : 1;\n");
    printf("    unsigned int f3 : 1;\n");
    printf("    unsigned int type : 8;\n");
    printf("    unsigned int index : 18;\n");
    printf("};\n");
    lf();
    sub("Uniao (para acessar 'value' e mostrar o binario):");
    lf();
    printf("union packed_union {\n");
    printf("    struct packed_struct packed_data;\n");
    printf("    unsigned int value;\n");
    printf("};\n");

    union packed_union pack_data;
    pack_data.value = 0;
    pack_data.packed_data.f1 = 1;
    pack_data.packed_data.f2 = 1;
    pack_data.packed_data.f3 = 1;
    pack_data.packed_data.type = 64;
    pack_data.packed_data.index = 300;

    printf("            %s\n", REGUA32C);
    printf("            %s\n", REGUA32);
    printf("pack_data = %s\n", padzero(ToStrBin(pack_data.value), 32));
    printf("            ^                 ^       ^  ^Filler\n");
    printf("            |index            |type   | f1-f3\n");

    lf();
    lf();

    system(PAUSE);
}
