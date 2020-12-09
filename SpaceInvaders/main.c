
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.\sleep(1);
 */

/* 
 * File:   main.c
 * Author: mateo
 *
 * Created on December 3, 2020, 1:22 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include"backend.h"
#include"hardware.h"
#include"allegro.h"
#include<unistd.h>
#include<time.h>// uso srand(time(NULL)) para incializar
//rand() % 10 + 1;10 rango 1 valor inicial
int main()
{
    int exit=0;
    //initallegro();//inicializa allegro
    //meterle un define o algo
   //initraspi();//inicializa librerias raspi
    //meterle define
    int nivel=15;
    int a=0;
    int space [LARGO][ANCHO];
    inimat(space,a);//inicializo la matriz
    ininav(space,nivel);
    printmat(space);
   /* do{
        
    }while((exit = exit_cond())!=0);
*/
return 0;
}