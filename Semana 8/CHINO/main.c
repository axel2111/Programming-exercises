/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 20 de mayo de 2019, 03:32 PM
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    

    int fila ;
    int columna;
    int numeroBuscar ; 
    printf ("Ingrese la fila: ");
    scanf ("%d", &fila );
    
    printf ("Ingrese la columna: ");
    scanf ("%d", &columna );
    numeroBuscar = (fila)+(5*(columna-1));
    printf ("El numero encontrado es : %d\n" , numeroBuscar);

    return (EXIT_SUCCESS);
}

