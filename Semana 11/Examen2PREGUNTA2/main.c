/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 16 de junio de 2019, 05:47 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesMedicos.h"
#include "Cadenas.h"
#include "Medicos.h"
#include "Consultas.h"
/*
 * 
 */
int main(int argc, char** argv) {
    struct Medicos medicos[100];
    struct Consultas consultas[100];
    int numMedicos = 0 , numConsultas;
    leerMedicos(medicos,&numMedicos);
    leerConsultas (consultas,&numConsultas);
    obtenerAportes(medicos,consultas,numMedicos,numConsultas);
    for (int i = 0 ; i < numMedicos ; i++){
        printf ("%6d %-25s %-15s %8.2lf\n ",medicos[i].codigo , medicos[i].nombre , 
                medicos[i].especialidad , medicos[i].aporte.aporte);
    }
    ordenarAportes(medicos,numMedicos);
    printf ("ORDENADO\n");
        for (int i = 0 ; i < 3 ; i++){
        printf ("%6d %-25s %-15s %8.2lf\n ",medicos[i].codigo , medicos[i].nombre , 
                medicos[i].especialidad , medicos[i].aporte.aporte);
    }
    return (EXIT_SUCCESS);
}

