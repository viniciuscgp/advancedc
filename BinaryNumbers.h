/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryNumbers.h
 * Author: viniciuscgp
 *
 * Created on February 16, 2022, 7:46 PM
 */

#ifndef BINARYNUMBERS_H
#define BINARYNUMBERS_H

#ifdef __cplusplus
extern "C" {
#endif

void BinaryNumbersTest();
char *ToStrBin(int val);
char *ToStrBin2(short val);
short BinaryToInt(char *binstr);
short BinaryToInt2(long long num);

#ifdef __cplusplus
}
#endif

#endif /* BINARYNUMBERS_H */

