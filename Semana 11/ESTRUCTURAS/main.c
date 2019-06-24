/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 14 de junio de 2019, 06:29 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Nombre.h"
#include "FuncionesAux.h"
#include "Consultas.h"
/*
 * 
 */
int main(int argc, char** argv) {
    struct Nombre nombre;
    struct Consultas consultas;
    int numDatos  = 0 , numConsultas = 0 ; 
    leerDatos (&nombre,&numDatos);
    obtenerConsultas(&consultas,&numConsultas);
    obtenerAportes(&nombre,consultas,numDatos,numConsultas);
    
    for (int i = 0 ;i < numDatos  ; i++){
        printf ("%6d %-30s %-15s %7.2lf\n" , nombre.codigo[i] ,nombre.nombre[i] ,
                nombre.especialidad[i], nombre.aporte[i]);
    }
    return (EXIT_SUCCESS);
}

