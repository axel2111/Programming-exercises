/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 6 de mayo de 2019, 02:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionProbar.h"
/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archNotas ; 
    archNotas = fopen ("Notas.txt","r");
    if (archNotas==NULL){
        printf ("error");
        exit (1);
    }
    double notas ; 
    fx(archNotas , &notas);
    printf ("%lf", notas);
    fclose (archNotas);
    return (EXIT_SUCCESS);
}

