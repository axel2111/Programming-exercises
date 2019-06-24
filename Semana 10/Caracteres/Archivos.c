/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Archivos.h"
FILE *abrirArchivo (const char *nombArch ,const  char *modo){
    FILE *arch ; 
    arch = fopen (nombArch,modo); 
    if (arch==NULL){
        printf ("Error no existe el archivo %s \n" , nombArch);
        exit (1);
    }
    return arch ; 
}