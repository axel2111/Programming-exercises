/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 10 de junio de 2019, 01:00 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
#include <time.h>
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archEmpleados, *archBonos;
    archEmpleados = abrirArchivo ("empleados.txt","r");
    archBonos = abrirArchivo ("bonos.txt" , "r"); 
    
    double premios[20];
    int numPremios=0;
    int codigo [500] , numCodigos=0; 
    leerArregloD(premios,&numPremios ,archBonos);
    leerArregloI(codigo,&numCodigos,archEmpleados);
    eliminarPosicion(premios,numPremios,codigo,numCodigos);

    return (EXIT_SUCCESS);
}

