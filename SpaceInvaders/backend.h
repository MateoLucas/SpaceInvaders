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
#define ENEMYSHOT 2//tipos de naves entre 1 a 7
#define PLAYER 9
#define MURO 8
#define DER 1
#define IZQ 2
int exit_cond(void);
void inimat (int [][ANCHO],int );
void printmat (int [][ANCHO]);
void ininav(int[][ANCHO],int);
int ciclo (int [][ANCHO],int);
#ifdef __cplusplus
}
#endif

#endif /* BACKEND_H */

