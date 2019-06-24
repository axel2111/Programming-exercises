/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 10 de mayo de 2019, 02:59 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesEstadisticas.h"
#define MAX  100
/*
 * 
 */
int main(int argc, char** argv) {
    int nota[MAX], numNotas =0 ;
    double prom,desEst ; 
    leerNotas(nota, &numNotas);
    prom = promedio (nota,numNotas);
    desEst = desviacionEstandar (prom,nota,numNotas);
    imprimeNotas(nota,numNotas);
    printf ("El promedio de notas es: %2.2lf\n" , prom);
    printf ("La desviacion estandar de notas es: %lf" , desEst);
    return (EXIT_SUCCESS);
}

