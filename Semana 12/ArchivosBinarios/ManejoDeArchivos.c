/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "ManejoDeArchivos.h"
FILE *abrirArchivo (char *nombre,char * modo){
    FILE *arch ; 
    arch= fopen (nombre,modo);
    if (arch == NULL ){
        printf ("Error, el archivo %s no pudo abrirse" , nombre);
        exit (1);
    }
    return arch ; 
}