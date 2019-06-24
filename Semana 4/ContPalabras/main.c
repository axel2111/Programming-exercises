/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 15 de abril de 2019, 07:26 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archDatos ; 
    
    archDatos =  fopen("Texto.txt" , "r"); 
    
    if (archDatos == NULL){
        printf ("Error, el archivo Texto.txt no existe");
        exit (1);
    }
    char c ; 
    while (1){
        c=fgetchar(archDatos);
        putchar(c);
        if (feof(archDatos))break;
        
    }
    fclose(archDatos); 
    return (EXIT_SUCCESS);
}

