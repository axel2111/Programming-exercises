/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 27 de mayo de 2019, 02:28 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_PERSONAS 100
#include "FuncionesAux.h"
/*
 * 
 */
int main(int argc, char** argv) {
    int dni[MAX_PERSONAS] , dia[MAX_PERSONAS],mes[MAX_PERSONAS],anio[MAX_PERSONAS];
    int fecha[MAX_PERSONAS];
    int edad[MAX_PERSONAS] , diasCump[MAX_PERSONAS];
    int numPersonas = 0 ; 
    
    leerDatos (dni,dia,mes,anio,fecha,&numPersonas);
    ordenarCumpleanos(dni,dia,mes,anio,fecha,numPersonas);
    int dd ,mm ,aa ,fechaInt ; 
    int valida=0;
    printf ("Ingrese una fecha de cumpleanios: ") , scanf ("%d/%d/%d" , &dd,&mm,&aa);
    fechaInt = dd+mm*100+aa*10000;
    valida = validarFecha(dd,mm,aa);
    if (valida == 0){
        printf ("La fecha ingresada es incorrecta\n");
        exit(0);
    }
    else{
        generarReporte(edad,diasCump,dni,dia,mes,anio,dd,mm,aa,numPersonas);
    }

    imprimirDatos(dni,dia,mes,anio,numPersonas);

    return (EXIT_SUCCESS);
}

