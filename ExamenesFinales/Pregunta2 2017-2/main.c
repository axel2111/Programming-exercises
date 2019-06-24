/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 17 de junio de 2019, 04:38 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Cadenas.h"
/*
 * 
 */
int main(int argc, char** argv) {
/*
    FILE *arch = fopen ("datos.txt" , "r");
    FILE *archBin = fopen ("datos.bin" , "wb");
    char nombre[50]  , direccion[50]; 
    int dni  , fecha ,telefono;
    int i = 0 ;
    char espacio[5];
    while (1){
        fscanf (arch, "%d" , &dni );
        if (feof (arch ))break;
        fwrite(&dni,sizeof(char),1,archBin);
        leerCadena(espacio,5,arch);
        
        leerCadena(nombre,50,arch);
        
        fwrite(nombre,sizeof(char) , 1 ,archBin);
        
        leerCadena(direccion,50,arch);
        
        fwrite(direccion,sizeof(char) ,1 ,archBin);
        
        fscanf (arch, "%d" , &fecha);
        fwrite(&fecha , sizeof(int) ,1, archBin);
        
        fscanf (arch , "%d" , &telefono);
        fwrite(&telefono, sizeof(int) ,1 ,archBin);
        
    }
    
*/
    int numero1=3 ;
    printf ("%d" , 5%10);
    return (EXIT_SUCCESS);
}

