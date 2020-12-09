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
           for(i=1;i<4;i+=2){     
                for(j=1;j<LARGO;j+=4){//seteo enemigos
                    space[i][j]=ENEMY;
                }       
            }
           for(i=5;i<6;++i){
               for(j=1;j<LARGO;j+=4){
                   space[i][j]=ENEMYSHOT;
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
           for(i=1;i<6;i+=2){     
                for(j=1;j<LARGO;j+=4){//seteo enemigos
                    space[i][j]=ENEMY;
                }       
            }
           for(i=7;i<8;++i){
               for(j=1;j<LARGO;j+=4){
                   space[i][j]=ENEMYSHOT;
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
            for(i=1;i<6;i+=2){     
                for(j=1;j<LARGO;j+=3){//seteo enemigos
                    space[i][j]=ENEMY;
                }       
            }
            for(i=7;i<8;++i){
               for(j=1;j<LARGO;j+=3){
                   space[i][j]=ENEMYSHOT;
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
            for(i=7;i<8;++i){
               for(j=1;j<LARGO;j+=3){
                   space[i][j]=ENEMYSHOT;
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
int ciclo (int space[LARGO][ANCHO],int direccion){//mueva las naves en la matriz
    int i=0;
    int j=0;
    int bajar=0;//defino si bajo o no 1 para si
    if(direccion==DER){//si va para la derecha me fijo la col de la derecha
        for(i=0;i<ANCHO;++i){
            if((space[i][ANCHO-1]>=1)&&(space[i][ANCHO-1]<=7)){//si hay algo en la ultima col
                direccion=IZQ;//invierto direccion
                bajar=1;//indico q tengo q bajar
            }
        }
    }else{//me fijo en la col de la izquierda
        for(i=0;i<ANCHO;++i){//si va para la izq
            if((space[i][0]>=1)&&(space[i][0]<=7)){//si hay algo en la primer col
                direccion=DER;//invuerto direccion
                bajar=1;//indico q tengo q bajar
            }
        }
    }
    for(i=(ANCHO-2),j=0;j<LARGO;++j){//verifico la penultima fil
        if((space[i][j]>=1)&&(space[i][j]<=7)){//si hay naves en la penultima fil no bajo
            bajar=0;
        }
    }
    if(bajar==0){//si no tiene q bajar
        if(direccion==DER){//muevo las naves a la derecha
            for(i=(ANCHO-2);i>=0;--i){
                for(j=(ANCHO-1);j>=0;--j){
                    if((space[i][j]>=1)&&(space[i][j]<=7)){//si hay nave
                        space[i][j+1]=space[i][j];//muevo la nave
                        space[i][j]=0;//borro la posicion anterior de esa nave;
                    }
                }
            }
        }else{//muevo las naves a la izquierda
            for(i=(ANCHO-2);i>=0;--i){
                for(j=0;j<ANCHO;++j){
                    if((space[i][j]>=1)&&(space[i][j]<=7)){//si hay nave
                        space[i][j-1]=space[i][j];//muevo la nave
                        space[i][j]=0;//borro la posicion anterior de esa nave;
                    }
                }
            }
        }
    }else{
            for(i=(ANCHO-2);i>=0;--i){
                    for(j=0;j<ANCHO;++j){
                        if((space[i][j]>=1)&&(space[i][j]<=7)){//si hay nave
                            space[i+1][j]=space[i][j];//muevo la nave
                            space[i][j]=0;//borro la posicion anterior de esa nave;
                        }
                    }
                }
    }
    return direccion;
}
int exit_cond(void){//devuelve si se sale del programa o no
    int exit=1;
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
    printf("\n");
}



