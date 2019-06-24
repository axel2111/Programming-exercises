/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 1 de mayo de 2019, 05:28 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesEstadisticas.h"
/*
 * 
 */
int main(int argc, char** argv) {
    int num ,fact;
    printf ("Ingrese numero: "), scanf ("%d" , &num);
    fact=factorial(num);
    printf ("El factorial de %d es %d\n",num,fact);
    return (EXIT_SUCCESS);
}

