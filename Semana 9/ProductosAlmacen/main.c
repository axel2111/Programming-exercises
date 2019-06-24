/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 27 de mayo de 2019, 10:25 AM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_ARTICULO 300
#include "FuncionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    //para articulos; 
    int codArt[MAX_ARTICULO], stock[MAX_ARTICULO];     
    double precioU[MAX_ARTICULO], precioD[MAX_ARTICULO];
    int numArt= 0 ;
    
    reescribirArticulos(codArt,precioU,precioD,stock,&numArt);
    return (EXIT_SUCCESS);
}

