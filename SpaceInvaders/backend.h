/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   backend.h
 * Author: jandro1111
 *
 * Created on 8 de diciembre de 2020, 16:01
 */

#ifndef BACKEND_H
#define BACKEND_H

#ifdef __cplusplus
extern "C" {
#endif
#define LARGO 16 //el largo de la matriz
#define ANCHO 16
#define ENEMY 1//despues agrego mas tipos de naves
#define ENEMYSHOT 2//tipos de naves entre 1 a 5 el 2 es el q dispara
#define NAVNOD 5//siempre se mueve de izq a der, ocupa 2 bloques
#define PSHOT 7   
#define ESHOT 6
#define PLAYER 9
#define MURO 8
#define DER 1
#define IZQ 2
#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#include <stdint.h>
#include<unistd.h>
int exit_cond(int *);
void inimat (int [][ANCHO] );
void printmat (int [][ANCHO]);
void ininiv(int[][ANCHO],int);
int ciclonaves (int [][ANCHO],int);
void ciclodisp(int [][ANCHO],int*,int*);
int verparams(int [][ANCHO],int);
void navdisp(int [][ANCHO],int *,int *,int *);
void pmov(int [][ANCHO],int *); 
void matniv(int [][ANCHO]);
#ifdef __cplusplus
}
#endif

#endif /* BACKEND_H */

