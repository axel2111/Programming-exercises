/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 14 de abril de 2019, 08:45 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    FILE *archTexto, *reporte ; 
    char c,d ; 
    int contLetras,longitudDePal=0, mayor = 0 , menor=10000; 
    int  contPal = 0 ;
    archTexto = fopen("Texto_v3.txt", "r");
    reporte = fopen("Reporte.txt", "w");
    
    if (archTexto == NULL){
        printf ("Error,el archivo Texto.txt no existe\n");
        exit(1);
    }
    if (reporte == NULL){
        printf ("Error,el archivo Reporte.txt no existe\n");
        exit(1);
    }
    
    contLetras = 0 ;
    while (1){
        c = fgetc(archTexto);
        if (feof(archTexto))break;
        if (c== ' ' || c== '\n'|| c=='\t' ){
            longitudDePal=contLetras;
            contLetras=0;
            if (mayor<longitudDePal){
                mayor = longitudDePal;
            }
            
            if (longitudDePal>=1){
                if (menor > longitudDePal){
                    menor = longitudDePal;
                }
                contPal++;
            }  
        }
        else{
            contLetras++;
        }
    }

    printf("\nLa palabra mas grande tiene %d letras\n" ,mayor);
    printf("La palabra mas pequenia tiene %d letras\n" ,menor);
    printf ("El texto tiene %d palabras\n" , contPal);
    fclose(archTexto);
    fclose(reporte);
    return (EXIT_SUCCESS);
}

