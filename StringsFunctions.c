#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"


void StringFunctionsTest() {
    
    char str1[512];
    char str2[512];
    char *lista[] = {" José", " João", " Vinicius", " Pedro", " Ambrozio"};
    char c;
    int op;
    short len = 5;
    char *ret;
    char *part;
    int pos;

inicio:    
    system(CLS);
    lf();
    lf();
    printf("\t+--------------------+\n");    
    printf("\t| Testes com Strings |\n");    
    printf("\t|--------------------+--------------------+\n");    
    printf("\t| 01-strncat() / strcat()                 |\n");
    printf("\t| 02-strcspn()                            |\n");
    printf("\t| 03-strchr()                             |\n");
    printf("\t| 04-strstr()                             |\n");
    printf("\t| 05-strtok()                             |\n");
    printf("\t| 06-strpbrk()                            |\n");
    printf("\t|                                         |\n");
    printf("\t| 99-Sair                                 |\n");
    printf("\t+-----------------------------------------+\n");    
    
    printf("\n\t\tOpcao:"); scanf("%d", &op);
    limpalf();
    
    switch(op) {
        case 1: goto opcao1; break;
        case 2: goto opcao2; break;
        case 3: goto opcao3; break;
        case 4: goto opcao4; break;
        case 5: goto opcao5; break;
        case 6: goto opcao6; break;
        
        case 99: return;
        default:
            printf("Selecione uma opção!");
            goto inicio;
    }
    
opcao1:
    strncpy(str1, "Os nomes sao:\n", 255);
    for (int i = 0; i < len; i++) {
        strncat(str1, lista[i], 15);
    }
    printf("%s\n", str1);
    lf(); lf();
    system(PAUSE);
    goto inicio;
opcao2:
    /*--------------------------------------------------------------------*/     
    title("strcspn()");
    strncpy(str1, "ABCD EFG 1234 56 XZ", 255);
    strncpy(str2, "XZ", 255);
    printf("->Retorna o n. de caracteres de s1 que NAO estao em s2\n\n");
    printf("->%s\n", REGUA);
    printf("->%s\n", str1);
    printf("->%s\n", str2);
    printf("->%d\n", (int) strcspn(str1, str2));
    /*--------------------------------------------------------------------*/     
    system(PAUSE);
    system(CLS);
    
    goto inicio;
opcao3:
    title("strchr(const char*, int c)");
    printf("| Esta funcao retorna a posicao em forma de ponteiro da primeira ocorrencia de C |\n\n");
   
    strncpy(str1, "O Rato Roeu a Roupa do Rei Arthur de Roma\n", 255);
    pos = 0;
    c = '\0';

    while (1) {
        printf("->%s\n", REGUA);
        printf("->%s\n", str1);
        printf("Digite o caracter a ser pesquisado: "); scanf("%c", &c);
        if (c == '\n') break;
        limpalf();
        ret = strchr(str1, (int) c);
        if (ret == NULL) {
            printf("O caracter informado não existe na string!\n");
            continue;
        }
        pos = ret - str1;
        printf("Encontrado na posicao: %i\n", pos);
    }
    goto inicio;
    
opcao4:
    title("char *strstr ( const char *s1 , const char *s2  )");
    printf("| Esta funcao procura pela primeira ocrrencia de s2 em s1. Retorna NULL se nao acahar.|\n\n");
    strncpy(str1, "Mais vale um passaro na mao que dois voando...", 255);
    strncpy(str2, "\0", 255);

    while (1) {
        printf("->%s\n", REGUA);
        printf("->%s\n", str1);
        printf("Digite a string a ser pesquisada (--q p/sair): "); scanf("%s", str2);
        if (strcmp("--q", str2) == 0) break;
        limpalf();
        ret = strstr(str1, str2);
        if (ret == NULL) {
            printf("A string informada não existe em str1!\n");
            continue;
        }
        pos = ret - str1;
        printf("Encontrado na posicao: %i\n", pos);
    }
    goto inicio;

opcao5:
    while (1) {
        system(CLS);
        title("char *strtok(char *str, const char *delim)");
        printf("| Esta funcao procura pela primeira ocrrencia de delim em str e retorna a string ou NULL. Cada chamada ele vai retornar o proximo token.|\n\n");
        strncpy(str2, "", 2);
        strncpy(str1, "Batata-Cenoura-Inhame-Mandioca|pera-maca-uva-laranja-mexerica-manga", 255);
        printf("->%s\n", REGUA);
        printf("->%s\n", str1);
        printf("\nDigite o token (--q p/sair): "); scanf("%s", str2);
        if (strcmp("--q", str2) == 0) 
            break;
        
        limpalf();
        part = strtok(str1, str2);
        while (part != NULL) {
            printf(">%s\n", part);
            part = strtok(NULL, str2);
        }
        puts("\n\nPressione Enter");
        getchar();
    }
    goto inicio;
    
opcao6:
    title("char *strpbrk(const char *str1, const char *str2)");
    printf("| Esta funcao encontra o primeiro carater\n em str1 que contiver em str2 |\n\n");
   
    strncpy(str1, "O Rato Roeu a Roupa do Rei Arthur de Roma\n", 255);
    pos = 0;
    c = '\0';

    while (1) {
        printf("->%s\n", REGUA);
        printf("->%s\n", str1);
        printf("Digite os caracteres (--q quit): "); scanf("%s", str2);
        if (strcmp(str2, "--q") == 0) break;
        limpalf();
        ret = strpbrk(str1, str2);
        if (!ret) {
            printf("Os caracteres informados não existem em str1!\n");
            continue;
        }
        pos = ret - str1;
        printf("Encontrado na posicao: %i\n", pos);
    }
    goto inicio;
    
    
}