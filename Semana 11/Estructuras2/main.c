/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 16 de junio de 2019, 12:54 PM
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "LeerFunciones.h"
#include "Facturas.h"
#include "Cadenas.h"
/*
 * 
 */
int main(int argc, char** argv) {


    
    struct Facturas facturas[30];
    int numFacturas  = 0 ; 
    for (int i = 0 ; i < 30 ; i++) facturas[i].total = 0;
    leerFacturas(facturas,&numFacturas);
    
    for (int i =0 ; i < numFacturas ; i++){
        printf ("%d)%s %.2lf\n",i+1 , facturas[i].persona.nombre , facturas[i].total);
    }
     
    ordenarDatos(facturas,numFacturas);
    printf ("DATOS ORDENADOS \n") ; 
    for (int i =0 ; i < numFacturas ; i++){
        printf ("%d) %6d %-40s %02d/%02d/%4d %8.2lf\n",i+1 ,facturas[i].persona.dni, facturas[i].persona.nombre 
                ,facturas[i].fecha.dd,facturas[i].fecha.dd, facturas[i].fecha.aa
                , facturas[i].total);
    }
    
    return (EXIT_SUCCESS);
}

