/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 24 de mayo de 2019, 04:04 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"


/*
 * 
 */
int main(int argc, char** argv) {
    int codArt[500] , stock[500];
    double precioUnitario[500], precioDocena[500];
    int numArt= 0 ,numC = 0 ;
    double gasto[500];
    leerArticulos(codArt,precioUnitario,precioDocena,stock,&numArt);
    reescribirArticulos(codArt,precioUnitario,precioDocena,stock,numArt);
    montoGastado(gasto,codArt,precioUnitario,precioDocena,stock,numArt,&numC);

    return (EXIT_SUCCESS);
}

