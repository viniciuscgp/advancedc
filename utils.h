/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utils.h
 * Author: viniciuscgp
 *
 * Created on February 15, 2022, 9:47 AM
 */

#ifndef UTILS_H
#define UTILS_H
#define REGUA    "0123456789|123456789|123456789|1234567890"
#define REGUA8   "76543210"
#define REGUA16  "7654321|76543210"
#define REGUA32C "      24      16       8       0"
#define REGUA32  "7654321|7654321|7654321|76543210"

#ifdef _WIN32_WINNT
#define CLS "cls"
#define PAUSE "pause"
#else
#define CLS "clear"
#define PAUSE "echo Press enter to continue; read dummy;"
#endif

#ifdef __cplusplus
extern "C" {
#endif
    void dint(int v);
    void dstr(char *v);
    void lf(void);
    void title(char *str);
    void sub(char *str);
    void limpalf();
    char *padzero(char *str, int size);

#ifdef __cplusplus
}
#endif

#endif /* UTILS_H */

