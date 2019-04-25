/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 19 de abril de 2019, 05:17 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archTexto,*archReporte ; 
    archTexto = fopen ("Texto.txt", "r") ; 
    archReporte = fopen ("reporte.txt", "w") ;
    if (archTexto==NULL){
        printf ("Error , el archivo texto.txt no pudo abrirse\n");
        exit(1);
    }
    if (archReporte==NULL){
        printf ("Error , el archivo reporte.txt no pudo abrirse\n");
        exit(1);
    }
    char cActual, cAnt; // guarda los caracteres; 
    int ultimaLetra, // Es una bandera para determinar si llegamos a la ultima letra
        contLetras=0,
        contEspacio=0,
        longitudPal;
    while (1){//EMPIEZA A LEER UNA PALABRA 
        longitudPal = 0 ;
        cActual= fgetc(archTexto);
        if (cActual == ' '|| cActual=='\t'||cActual== '\n'||cActual=='\377'){
            contEspacio++;
            longitudPal=contLetras;
            contLetras=0;
        }
        else {
            contLetras++;
        }
      
        
        if (longitudPal == 1){ // PARA PALABRAS DE UNA SOLA LETRA;
            if (cAnt>='a'&&cAnt<='z'){
                putchar(cAnt-32);
            }
            else{
                putchar(cAnt);
            }    
        }//PRIMERA LETRA
        else if ((contLetras == 2) ){
            if (cAnt>='a'&&cAnt<='z'){
                putchar(cAnt-32);
            }
            else{
                putchar(cAnt);
            }    
        } // ULTIMA LETRA
        else if ((cActual == ' '||cActual== '\t' || cActual == '\n'||cActual=='\377')&&(longitudPal>1)){
           
                 if (cAnt>='a'&&cAnt<='z'){
                    putchar(cAnt-32);
                }
                else{
                    putchar(cAnt);
                } 
              

        }
        
        else if (contEspacio>1){//contEspacio == 2;
            if(cAnt!=cActual){
                contEspacio = 0 ;
                putchar(cAnt);
            }

        }
        else{
            putchar(cAnt);
        }
       
        cAnt = cActual;
        if (feof(archTexto))break;
    }
    
    fclose(archReporte);
    fclose(archTexto);
    return (EXIT_SUCCESS);
}

