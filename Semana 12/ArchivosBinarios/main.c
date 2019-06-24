/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 17 de junio de 2019, 11:41 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "ManejoDeArchivos.h"
/*
 * 
 */
int main(int argc, char** argv) {

    FILE *archTxt=abrirArchivo ("datos.txt", "r");
    FILE *archBin= abrirArchivo("datos.bin", "rb+");
    int num ;
/*

    while (1){
        fread(&num,sizeof(int),1,archBin);
        if (feof(archBin))break;
    }
    
*/
    int a[50] , n  , x , numReg ; 
    char op; 
    fseek(archBin,0,SEEK_END);
    numReg = ftell(archBin) / sizeof(int);
    fseek(archBin,0,SEEK_SET);
    for (int i = 0 ; i < numReg ; i++){
        fread(&a[i],sizeof(int),1,archBin);
        printf ("%4d) %8d\n" , i+1 ,a[i]);
    }
    while (1){
        printf ("Que dato quiere ver (0=FIN)"), scanf("%d", &n);
        if (n==0)break;
        if (n>numReg){
            printf ("Error, valor fuera de posicion\n"); 
            continue ; 
        }
        fseek(archBin,sizeof(int)*(n-1),SEEK_SET);
        fread(&x,sizeof(int),1,archBin);
        printf ("El dato es %d\n" , x );
        printf ("Desea modificarlo? (s/n)"), scanf ("\n%c",&op) ;
        if (op=='s'){
            printf ("Ingrese el nuevo valor ") , scanf("%d" , &x) ; 
            fseek(archBin,sizeof(int)*(n-1),SEEK_SET);
            fwrite(&x,sizeof(int),1,archBin);
            fseek(archBin,0,SEEK_SET);
            printf ("\n\n");
            for (int i = 0 ; i < numReg ; i++){
                fread(&num,sizeof(int) , 1 , archBin);
                printf ("%6d %8d\n " , i+1 , num);
            }
        }
        else{
            continue;
        }
    }
    fclose (archBin);
    return (EXIT_SUCCESS);
}

