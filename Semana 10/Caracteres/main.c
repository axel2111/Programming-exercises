/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 4 de junio de 2019, 02:36 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Archivos.h"
#include <string.h>
/*
 * 
 */
int main(int argc, char** argv) {
    
/*
 * char nombre[100];
    for (int i = 0 ; i < 4 ;i++){
        scanf ("%s" , nombre); 
        printf ("%d)  %-15s\n" ,i+1 ,nombre) ; 
    }
*/

/*
    scanf ("%s" , nombre);
*/
/*
    printf ("%s\n" , nombre);
    nombre[2] = '#';
    printf ("%s\n", nombre);
    printf ("nombre [2] = %s\n" , nombre);
*/
    char nombre[100] , *p;
    fgets (nombre, 100 , stdin);
    p = nombre ;  
    printf ("%s\n" , p);
    printf ("%s\n",p); 

    /*
    
    FILE *arch ; 
    arch = abrirArchivo ("notas.txt" , "r") ; 
    char nombre [100]; 
    while (1){
        fscanf (arch,"%s", nombre );
        if (feof (arch)) break; 
        printf ("%s\n" , nombre); 
    }
    
*/
    return (EXIT_SUCCESS);
}

