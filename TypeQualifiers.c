#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "TypeQualifiers.h"

void TypeQualifiesTests(void) {

    title("Qualificador CONST");

    printf("PI %.2f\n", PI);

    for (int i = 0; i < 4; i++) {
        dint(days[i]);
        lf();
    }

    typedef const int zip;
    zip q = 9; /* const is idepontent*/
    lf();
    dstr("q Value: ");
    dint(q);
    lf();
    lf();

    title("Apontador com VALOR constante");
    const float *pf; /* pf points to a constant foat value */
    /* In this case, the VALUE cannot be changed */

    float value = 100.0;
    float value2 = 200.0;
    pf = &value;
    printf("pf Aponta para 'value': %f\n", *pf);
    printf("Declaração: 'const float *pf;'\n\n");

    /* *pf = 200;  We cannot do that */
    pf = &value2; /* but we CAN do that*/
    printf("pf Aponta para 'value2'(apontador modificado) : %f\n\n", *pf);

    printf("Apontador Constante com valor modificavel\n");
    printf("Declaração: 'float const *pf;'\n\n");
    float * const pf2 = &value; /* neste caso o apontador é que é constante*/
    *pf2 = 300; /* podemos porque o valor não é const neste caso*/
    /* pf2 = &value2; nao podemos porque o APONTADOR é constante */
    printf("pf2 Aponta para 'value': %f\n", *pf2);
    *pf2 = 400; /* podemos porque o valor não é const neste caso*/
    printf("pf2 APonta para 'value' (valor modificado): %f\n\n", *pf2);

    title("Parametros CONTS");
    int nums[] = {1, 2, 3, 4, 5};
    display(nums, 5);
    system(PAUSE);
}

void display(const int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
    }
    lf();
}