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
    FILE *archTxt, *archBin;
    archTxt = fopen("personal.csv", "r");
    archBin = fopen("personal.bin", "rb+");
    struct Persona persona;
    int registro;
    //crearArhivoBinario(archTxt , archBin);
    mostrarDatos(archBin);
    /*
        while (1) {
            printf("\nIngrese numero de registro: "), scanf("%d", &registro);
            if (registro == 0)break;
            modificaRegistro(registro, archBin);
            mostrarDatos(archBin);
        }
     */
    printf("AUMENTO DE SUELDO DEL 50%% \n");
    aumetarSueldo(archBin);
    mostrarDatos(archBin);
    fclose(archTxt);
    fclose(archBin);

    return (EXIT_SUCCESS);
}

