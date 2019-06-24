/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 25 de abril de 2019, 10:16 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE *archTexto,*reporte ;
    archTexto = fopen("cuentos.txt", "r") ;
    reporte  = fopen ("reportes.txt" , "w");
    
    if (archTexto == NULL){
        printf ("Error, el archivo cuentos.txt no se a encontrado\n");
        exit (1); 
    }
    if (reporte == NULL){
        printf ("Error, el archivo reporte.txt no se a encontrado\n");
        exit (1); 
    }
    int vieneDeParrafo = 0 , estadistica = 0,numCod=0; // THIS IS A FLAG
    int codigo , n, espacios=0, longPalabra , contLetras, contPalabras ;
    int oraciones = 0 , parrafos = 0; 
    char c, cAnt  ; 
    n = fscanf (archTexto, "%d\n" , &codigo);
    while (1){// Read code
        
        if (feof(archTexto))break; 
        if (n==1){
            fprintf (reporte,"Alumno: %04d\tTITULO:" , codigo);
            vieneDeParrafo = 0;
            
        }
        if (vieneDeParrafo == 0){
            while (1){ // Read the TITTLE
                c= fgetc(archTexto);
                c=(c>='a'&&c<='z')?c-32:c;
                fprintf (reporte,"%c",c);
                vieneDeParrafo = 0 ; 
                oraciones = 0 ;
                parrafos = 0 ;
                longPalabra =0;
                contLetras = 0 ;
                contPalabras=0;
                if (c=='\n')break ;
            }
        }
        while ((c=fgetc(archTexto))!=EOF){// Read body 
            vieneDeParrafo =1 ;
            if (longPalabra >2){
                contPalabras ++;
                longPalabra = 0;
            }
            
            if (c==' '||c=='\t'){
                longPalabra= contLetras;
                contLetras = 0;
                espacios++;
                cAnt=c;
                continue;
            }
            else{
                contLetras++;
            }
            
            if (espacios>=1){
                if (cAnt!=c){
                    if (c!=' '){
                        fprintf (reporte," ");
                    }
                    espacios =0 ;
              
                }
            }
            fputc(c,reporte); 
            if(c=='.'){
                oraciones++;
                fputc('\n',reporte);
            }
            if (c=='\n'){
                parrafos++;
                n = fscanf (archTexto, "%d\n" , &codigo);
                if (n==1){
                    vieneDeParrafo = 0 ;
                }
                break;
            }
            cAnt= c;  
        }
        
        if (n==1||feof(archTexto)){
            fprintf (reporte,"ESTADISTICAS DEL CUENTO:\n");
            fprintf (reporte,"PALABRAS     ORACIONES     PARRAFOS     PROM.PALABRAS     PROM.ORACIONES\n");
            fprintf (reporte,"-------------------------------------------------------------------------\n");
            fprintf (reporte,"  %d            %d            %d             %.2lf             %.2lf\n",contPalabras,oraciones,parrafos,(double)contPalabras/oraciones,(double)oraciones/parrafos);
            fprintf (reporte,"===========================================================================\n\n");
        }
               
            
    }
    
    fclose (archTexto);
    fclose (reporte);
    return (EXIT_SUCCESS);
}

