/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 14 de junio de 2019, 03:43 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FuncionesAUX.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char *nombre[200];
    int operaciones[200] , numOperaciones=0; 
    double tiempo ; 
    printf ("  Tiempo de transaccion: ") ,scanf("%lf" , &tiempo); 
    leerDatos(nombre,operaciones,&numOperaciones);
    mostrarReporte(tiempo,nombre,operaciones,numOperaciones);
    return (EXIT_SUCCESS);
}

