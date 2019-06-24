/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 12 de mayo de 2019, 02:35 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_NOTAS  100
#include "FuncionesEstadisticas.h"
/*
 * 
 */
int main(int argc, char** argv) {
    int notas[MAX_NOTAS]= {0}  ;
    int contNotas[20] = {0};
    double porcentajeNotas[MAX_NOTAS] = {0};
    int numeroDeNotas = 0 ;
    double prom , desvEst , porcentajeA; 
    leerNotas(notas,&numeroDeNotas);
    contarNotas(notas,contNotas,numeroDeNotas) ;
    porcentajeA = porcentajeAprob(notas, numeroDeNotas);
    prom = promedio (notas,numeroDeNotas); 
    desvEst = desviacionEstandar (prom , notas , numeroDeNotas);
    imprimeResultados  (contNotas,prom , desvEst,numeroDeNotas,porcentajeA) ; 
    return (EXIT_SUCCESS);
}

