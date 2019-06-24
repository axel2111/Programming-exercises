/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
#include <string.h>
#include "FuncionesDinamica.h"
char *leerCadenaExacta(FILE *arch){
    char aux[500] , *cad;
    
    leerCadena(aux,500,arch);
    if (feof(arch)) return NULL;
    cad = (char*)malloc (sizeof(char)*(strlen(aux)+1));
    strcpy(cad,aux);
    return cad ; 
}