/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void modificaArreglo(int *a,int nd){ 
    a[3] = 1456; 
    a[8] = 12311111; 
}
void imprimeArreglo (int *a,int nd){ 
    for (int i = 0 ; i < nd ; i++){
        scanf ("%d" , &a[i]);
        printf ("%8d\n" , a[i]); 
    }

}
