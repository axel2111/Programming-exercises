/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "funcionProbar.h"
void fx (FILE *archNotas, double *notas){
    int a , b;
    while (1){
        fscanf (archNotas,"%d %d %lf" , &a , &b ,notas);
        if (feof(archNotas))break;
    }
}
