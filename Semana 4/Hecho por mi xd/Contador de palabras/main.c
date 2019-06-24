/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 18 de abril de 2019, 11:39 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archDatos ; 
    archDatos = fopen ("Texto.txt" , "r"); 
    if (archDatos == NULL) { // Validacion del archivo
        printf ("Error, el archivo Texto_v1.txt no pudo abrirse.\n");
        exit(1);
    }
    char c ; // Variable para leer los caracteres ; 
    int     contLetras = 0, // cuenta las letras de cada palabra ;
            grabLetras = 0, // graba las letras que tiene cada palabra;
            contPalabras = 0 , //cuenta la cantidad de palabras que hay en el texto; 
            mayor = 0 , menor =10000000,
            sumGrabLetras = 0 ;// suma la cantidad de letras que hay en cada palabra  
    double prom; 
    while (!feof(archDatos)){
        c= fgetc(archDatos);
        
        c = (c>='a' && c<='z')?c-32:c;
        putchar(c);
        
        if (c==' ' || c== '\n' || c=='\t'){
            grabLetras = contLetras;
            contLetras=0 ;
            
            if (grabLetras>0){//ENCUENTRA UNA PALABRA
                sumGrabLetras+=grabLetras;
                
                if (mayor <  grabLetras){
                    mayor = grabLetras;
                }
                
                if (menor >  grabLetras){
                    menor = grabLetras;
                }
                contPalabras++;
            }
        }
        
        else {
            contLetras++;
        }
    }
    prom = (double) sumGrabLetras / contPalabras ; 
    printf ("La palabra mas grande tiene %10d letras \n", mayor);
    printf ("La palabra mas pequenia tiene %10d letras \n", menor);
    printf ("El texto tiene %10d palabras\n", contPalabras);
    printf ("El promedio de letras es %10.2lf\n " , prom );
    fclose(archDatos); 
    
    return (EXIT_SUCCESS);
}

