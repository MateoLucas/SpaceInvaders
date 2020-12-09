/***************************************************************************//**
  @file     backend
  @brief   backend generico para raspi y para allegro
  @author   Alejandro Alatsis
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include"backend.h"
#include<stdio.h>
#include<time.h>
/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/



/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/



/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ******************************************************************************/

// +ej: unsigned int anio_actual;+


/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static void falta_envido (int);+


/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static const int temperaturas_medias[4] = {23, 26, 24, 29};+


/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static int temperaturas_actuales[4];+


/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
void inimat(int space[][ANCHO],int a){ //inicializa la mat como vacia
    int i=0, j=0;
    for(i=0;i<LARGO;++i){     
        for(j=0;j<ANCHO;++j){
            space[i][j]=a;
        }       
    }
}
void ininav(int space[][ANCHO],int nivel){//inicializa las naves enemigas y la del jugador
    //harcodeo la nave del player
    space[15][7]=PLAYER;
    //
    int i,j;
   switch(nivel){
       case 1:
           for(i=1;i<6;i+=2){     
                for(j=1;j<LARGO;j+=4){//seteo enemigos
                    space[i][j]=ENEMY;
                }       
            }
           for(i=13;i<15;++i){     
                for(j=1;j<LARGO;j+=3){//seteo defensas
                    space[i][j]=MURO;
                    ++j;
                    space[i][j]=MURO;
                    ++j;
                    space[i][j]=MURO;
                }       
            }
           break;
       case 2:
           for(i=1;i<8;i+=2){     
                for(j=1;j<LARGO;j+=4){//seteo enemigos
                    space[i][j]=ENEMY;
                }       
            }
           for(i=13;i<15;++i){     
                for(j=1;j<LARGO;j+=3){//seteo defensas
                    space[i][j]=MURO;
                    ++j;
                    space[i][j]=MURO;
                    ++j;
                    space[i][j]=MURO;
                }       
            }
           break;
       case 3:
            for(i=1;i<8;i+=2){     
                for(j=1;j<LARGO;j+=3){//seteo enemigos
                    space[i][j]=ENEMY;
                }       
            }
            for(i=13;i<15;++i){     
                for(j=1;j<LARGO;j+=3){//seteo defensas
                    space[i][j]=MURO;
                    ++j;
                    space[i][j]=MURO;
                    ++j;
                    space[i][j]=MURO;
                }       
            }
           break;
        default:
            for(i=1;i<8;i+=2){     
                for(j=1;j<LARGO;j+=3){//seteo enemigos
                    space[i][j]=ENEMY;
                }       
            }
            for(i=13;i<15;++i){     
                for(j=1;j<LARGO;j+=3){//seteo defensas
                    space[i][j]=MURO;
                    ++j;
                    space[i][j]=MURO;
                    ++j;
                    space[i][j]=MURO;
                }       
            }
           break;
               
   } 
}
int exit_cond(void){//devuelve si se sale del programa o no
    int exit=0;
    return exit;
}


/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
void printmat(int space[][ANCHO]){//para testeo
    int m=0;
    int n=0;
    for(m=0;m<LARGO;++m){     /*mientras el contador de filas sea distinto a la cant. de filas, me fijo en las columnas*/
        for (n=0;n<ANCHO;++n){    /*mientras el contador de cols. sea distinto a la cant. de cols.imprime lo que haya en ese lugar de la matriz*/
            printf("%d", space[m][n]);
        }
        printf("\n");
    }
}



