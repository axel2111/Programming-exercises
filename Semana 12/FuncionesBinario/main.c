/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 21 de junio de 2019, 07:20 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"
#include "FuncionesBin.h"
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archTxt , *archBin;
    archTxt=  fopen ("personal.csv", "r");
    archBin = fopen ("personal.bin", "rb");
    struct Persona persona ; 
    //crearArhivoBinario(archTxt , archBin);
    mostrarDatos(archBin);
    aumetarSueldo (archBin) ; 
    return (EXIT_SUCCESS);
}

