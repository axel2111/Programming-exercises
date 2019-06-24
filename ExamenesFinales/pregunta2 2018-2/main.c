/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 14 de junio de 2019, 04:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    int codigo[500],numMed=0;
    double tarifa[500];
    char *nombre[500] , *especialidad[500];
    //CONSULTAS
    int conMed[500] , numConsultas = 0 ;
    leerDatosMedico(codigo,tarifa,nombre,especialidad,&numMed);
    leerDatosConsulta(conMed,&numConsultas);
    mostrarReporte(codigo,tarifa,nombre,especialidad,numMed,conMed,numConsultas);
    return (EXIT_SUCCESS);
}

