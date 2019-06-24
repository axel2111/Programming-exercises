/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 20 de junio de 2019, 07:50 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archTxt = fopen ("datos.txt" , "r");
    FILE *archBin = fopen ("datos.bin" , "wb");
    int num;
    while (1){
        fscanf (archTxt, "%d" , &num);
        if (feof(archTxt))break;
        fwrite(&num,sizeof(int),1,archBin);
    }
    fclose (archTxt);
    fclose (archBin);
    return (EXIT_SUCCESS);
}

