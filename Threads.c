/**
 Theads
 */
#ifdef _WIN32
#include <Windows.h>
#define sleep(n) Sleep(n * 1000)
#else
#include <getopt.h>
#include <unistd.h>
#endif
#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include "Threads.h"

#define MAX_THREAD 30

int qtde_thread = 0;
int counter = 0;

pthread_mutex_t mutex;
pthread_mutex_t mutexfuel;
pthread_cond_t condfuel;

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

static void* counter_mutex_thf(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

static void* counter_thf(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        counter++;
    }
    return NULL;
}

static void* getprime_thf(void* arg) {
    int* n = (int*)arg;
    sleep(2);
    printf("->%d\n", primes[*n]);
    free(n);
    return NULL;
}

static void* soma5_thf(void* arg) {
    int index = *(int*)arg;
    printf("Metade parte: %d\n", index);
    dash();
    int soma = 0;
    soma = 0;
    for (int i = index; i < index + 5; i++) {
        printf("Posicao %d valor %d\n", i, primes[i]);
        soma += primes[i];
    }
    *(int*)arg = soma;

    return arg;
}

int fuel = 0;

/* Produtor */
static void* recebe_bombustivel_thf(void* arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutexfuel);
        fuel += 35;
        printf("Bomba recebendo mais combustivel: %d\n", fuel);
        pthread_mutex_unlock(&mutexfuel);
        pthread_cond_signal(&condfuel); /* Envia sinal para que as threads 'acordem'*/
        sleep(2);
    }
    return NULL;
}

/* Produtor */
static void* recebe_bombustivelbroad_thf(void* arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutexfuel);
        fuel += 35;
        printf("|#|/* Bomba recebendo mais combustivel: %d\n", fuel);
        pthread_mutex_unlock(&mutexfuel);
        pthread_cond_broadcast(&condfuel); /* Envia sinal para que as threads 'acordem'*/
        sleep(2);
    }
    return NULL;
}

/* Consumidor */
static void* carro_abastece_thf(void* arg) {
    pthread_mutex_lock(&mutexfuel);
    while (fuel < 40) {
        printf("[X] Carro tentando abastecer...\n");
        pthread_cond_wait(&condfuel, &mutexfuel); /* aguarda pelo sinal */
    }
    fuel -= 40;
    printf("|O|/* Carro encheu o tanque. Saido do posto. %d\n", fuel);
    pthread_mutex_unlock(&mutexfuel);
    return NULL;
}

void ThreadsTests() {
    srand((unsigned int)time(NULL));
    bool continua = true;
    pthread_t th[MAX_THREAD];
    char op = 0;
    void* (*tempf) (void*) = NULL;

    while (continua) {
        system(CLS);
        title("Threads (CTRL + C sair)");
        lf();
        lf();
        printf("\tMenu de Testes\n");
        printf("\t_______________________________________\n");
        lf();
        printf("\t01-Com Mutext ou sem Mutext ?\n");
        printf("\t02-Passagem de Parametros - Mostra array\n");
        printf("\t03-Numeros primos-Soma metade\n");
        printf("\t04-Producer/Consumer 2 Threads\n");
        printf("\t05-Producer/Consumer n Threads\n");
        printf("\t06-Producer/Consumer n Threads (Broadcast)\n");
        printf("\t99-Voltar\n");
        lf();
        printf("\tOpcao:");
        scanf("%hhd", &op);
        switch (op) {
        case 1:
            system(CLS);
            qtde_thread = 10;
            title("THREADS - Execuçao concorrente sem Mutext e com Mutex");
            sub("Sem a (Mu)tual (E)xclusion (mutex) observa-se erro de concorrencia");
            pthread_mutex_init(&mutex, NULL);

            printf("%d Threads executando COM o Mutex\n", qtde_thread);
            counter = 0;
            int i;
            for (i = 0; i < qtde_thread; i++) {
                if (pthread_create(th + i, NULL, &counter_mutex_thf, NULL) != 0) {
                    printf("Erro creating the thread!\n");
                }
            }
            for (i = 0; i < qtde_thread; i++) {
                if (pthread_join(th[i], NULL) != 0) {
                    printf("Erro joining!\n");
                };
            }
            pthread_mutex_destroy(&mutex);
            printf("Valor de 'count':%d\n\n", counter);

            /*******************************************************
             * Now, without using Mutext to sincronize
             */

            printf("%d Threads executando SEM o Mutex\n", qtde_thread);
            counter = 0;

            for (i = 0; i < qtde_thread; i++) {
                if (pthread_create(th + i, NULL, &counter_thf, NULL) != 0) {
                    printf("Erro creating the thread!\n");
                }
            }
            for (i = 0; i < qtde_thread; i++) {
                if (pthread_join(th[i], NULL) != 0) {
                    printf("Erro joining!\n");
                };
            }
            printf("Valor de 'count':%d\n", counter);
            system(PAUSE);
            break;
        case 2:
            system(CLS);
            title("THREADS - Passagem de parametros-Indice de array");
            sub("Parametros são apontadores para seus dados - Devem estar no heap ?");
            qtde_thread = 10;
            for (i = 0; i < qtde_thread; i++) {
                int* param = (int*)malloc(sizeof(int));
                *param = i;
                if (pthread_create(th + i, NULL, &getprime_thf, param) != 0) {
                    printf("Erro creating the thread!\n");
                }
            }
            for (i = 0; i < qtde_thread; i++) {
                
                if (pthread_join(th[i], NULL) != 0) {
                    printf("Erro joining!\n");
                }
            }
            system(PAUSE);
            break;

        case 3:
            system(CLS);
            title("THREADS - Passagem e retorno de parametros - Soma de array global");
            puts("Os numeros estao em uma array - O indice sera passado para thread");
            puts("A Thread retornara o valor da soma pelo proprio parametro recebido.");
            dash();
            qtde_thread = 2;

            for (i = 0; i < qtde_thread; i++) {
                int* param = (int*)malloc(sizeof(int));
                *param = i * 5;
                if (pthread_create(th + i, NULL, &soma5_thf, param) != 0) {
                    printf("Erro creating the thread!\n");
                }
            }
            int total = 0;
            void* result;

            for (i = 0; i < qtde_thread; i++) {
                if (pthread_join(th[i], &result) != 0) {
                    printf("Erro joining!\n");
                };
                total += *(int *) result;
                free(result);
            }
            printf("\nTotal das duas partes: %d\n", total);
            system(PAUSE);
            break;

        case 4:
            system(CLS);
            title("THREADS - Produtor / Consumidor Design Pattern");
            printf("A Thread que consome tem que aguardar até que tenha combustivel sufuciente.\n");
            printf("A funcao pthread_cond_signal() envia um sinal\n");
            printf("A Thread que produz, gera um sinal ao encher o tanque com combustivel.\n");
            dash();
            qtde_thread = 2;
            fuel = 0;
            pthread_mutex_init(&mutexfuel, NULL);
            pthread_cond_init(&condfuel, NULL);

            for (i = 0; i < qtde_thread; i++) {
                tempf = (i % 2 == 0) ? &recebe_bombustivel_thf : &carro_abastece_thf;
                if (pthread_create(th + i, NULL, tempf, NULL) != 0) {
                    printf("Erro creating the thread!\n");
                }
            }

            for (i = 0; i < qtde_thread; i++) {
                if (pthread_join(th[i], NULL) != 0) {
                    printf("Erro joining!\n");
                };
            }
            pthread_cond_destroy(&condfuel);
            pthread_mutex_destroy(&mutexfuel);
            system(PAUSE);
            break;

        case 5:
        case 6:
            system(CLS);
            title("THREADS - Produtor / Consumidor Design Pattern");
            printf("A Thread que CONSOME tem que aguardar até que tenha combustivel sufuciente.\n");
            if(op == 5)
                printf("Com a função pthread_cond_signal() apenas uma das Threads acorda\n");
            else
                printf("Com a funcao pthread_cond_broadcast() todas as Threads acordam (embora apenas 1 consegue abastecer)\n");
            dash();
            qtde_thread = 5;
            fuel = 0;
            pthread_mutex_init(&mutexfuel, NULL);
            pthread_cond_init(&condfuel, NULL);

            for (i = 0; i < qtde_thread; i++) {
                if (op == 5)
                    tempf = (i == 0) ? &recebe_bombustivel_thf : &carro_abastece_thf;
                else
                    tempf = (i == 0) ? &recebe_bombustivelbroad_thf : &carro_abastece_thf;
                if (pthread_create(th + i, NULL, tempf, NULL) != 0) {
                    printf("Erro creating the thread!\n");
                }
            }

            for (i = 0; i < qtde_thread; i++) {
                if (pthread_join(th[i], NULL) != 0) {
                    printf("Erro joining!\n");
                };
            }
            pthread_cond_destroy(&condfuel);
            pthread_mutex_destroy(&mutexfuel);
            system(PAUSE);
            break;

        case 99:
            continua = false;
            break;
        }
    }
}
