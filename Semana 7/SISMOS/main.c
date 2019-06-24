/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 11 de mayo de 2019, 08:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_SISMOS 100
#include "FuncionesSis.h"
/*
 * 
 */
int main(int argc, char** argv) {
    int contSismos[MAX_SISMOS]={0} ; 
    double sismos[MAX_SISMOS]={0} ;
    int fechaSismos[MAX_SISMOS] = {0};
    int cantSismos = 0 ; 
    int dI,mI,aI ,dF,mF,aF, fechaI, fechaF;
    leerSismos(sismos , &cantSismos,fechaSismos);
    printf ("Desde: ") , scanf ("%d/%d/%d" , &dI,&mI,&aI);
    printf ("Hasta: ") , scanf ("%d/%d/%d" ,&dF,&mF,&aF);
    fechaI = aI*10000 + mI*100 +dI;
    fechaF = aF*10000 + mF*100 +dF;
    contarSismos(fechaSismos,sismos,cantSismos,contSismos,fechaI,fechaF);
    printf ("      REPORTE DE SISMOS ENTRE EL  %02d/%02d/%d %02d/%02d/%d \n" ,dI,mI,aI ,dF,mF,aF);
    printf ("   CANTIDAD DE SISMOS       INTENSIDADES           GRAFICA\n");
    mostrarSismos(sismos,contSismos,cantSismos);
    return (EXIT_SUCCESS);
}

