
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
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

int main()
{
    int exit=0;
    initallegro();//inicializa allegro
    //meterle un define o algo
    initraspi();//inicializa librerias raspi
    //meterle define
   
    do{
        
    }while((exit = exit_cond())!=0);

return 0;
}