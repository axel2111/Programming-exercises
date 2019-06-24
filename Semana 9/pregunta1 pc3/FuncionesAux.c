/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesAux.h"
void leerArticulos(int *codArt,double *precioUnitario,double *precioDocena,int *stock,int *numArt){
    FILE *archArticulos ; 
    archArticulos = fopen("articulos.txt","r");
    if (archArticulos == NULL){
        printf ("Error el archivo articulos.txt no existe");
        exit (1);
    }
    int codigo,max,almacen;
    double pu , pd;
    while (1){
        fscanf (archArticulos,"%d %d %lf %lf %d" , &codigo ,&almacen, &pu,&pd,&max);
        if (feof(archArticulos))break;
        codArt [*numArt] = codigo;
        precioUnitario[*numArt] = pu;
        precioDocena[*numArt]=pd;
        stock[*numArt] = max;
        (*numArt)++;
    }
    fclose(archArticulos);
}
void reescribirArticulos(int *codArt,double *precioUnitario,double *precioDocena
                        ,int *stock,int numArt){
    FILE *archArticulosCorregido ; 
    archArticulosCorregido = fopen("articulos.txt","w");
    if (archArticulosCorregido == NULL){
        printf ("Error el archivo articulos.txt no existe");
        exit (1);
    }
    for (int i = 0 ; i < numArt-1;i++){
        for (int j= i+1 ; j<numArt;j++){
            if (codArt[i]>codArt[j]){
                cambiar(codArt,i,j);
                cambiar(stock,i,j);
                cambiarD(precioUnitario,i,j);
                cambiarD(precioDocena,i,j);   
            }
        }
    }
    for (int p = 0 ; p < numArt ; p++){
        fprintf (archArticulosCorregido,"%6d  %7.2lf  %7.2lf  %4d\n",codArt[p],
                            precioUnitario[p],precioDocena[p],stock[p]);
    }
}
void cambiar (int *arr,int i ,int j){
    int aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}
void cambiarD (double *arr,int i ,int j){
    double aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}

void montoGastado(double *gasto,int *codArt,double *precioUnitario,
        double *precioDocena,int *stock,int numArt,int *numC){
    int fecha[600] , hora[600] , dni[600];
    int numCompras = 0;
    leerCompras (fecha, hora ,dni , gasto,&numCompras,
                codArt,precioUnitario,precioDocena,stock,numArt);
    ordenarFechaYHora(fecha,hora,dni,gasto,numCompras);
    imprimirMontoGastado(fecha,hora,dni,gasto,numCompras);
    (*numC) = numCompras ; 
}

void leerCompras (int *fecha, int *hora ,int *dni ,double *gasto,int *numCompras,
        int *codArt,double *precioUnitario,double *precioDocena,int *stock,int numArt){
    FILE *archCompras ; 
    archCompras = fopen("compras.txt","r");
    if (archCompras == NULL){
        printf ("Error el archivo compras.txt no existe");
        exit (1);
    }
    
    int dd,mm,aa,h,m,s,dniAC,cod,cant;
    double total;
    char c ; 
    while (1){
        fscanf (archCompras,"%d/%d/%d %d:%d:%d %d",&dd,&mm,&aa,&h,&m,&s,&dniAC);
        if (feof(archCompras))break;
        fecha[*numCompras] = dd+mm*100+aa*10000;
        hora[*numCompras] = h*3600+m*60 +s ; 
        dni[*numCompras] = dniAC;
        total = 0 ;
        while (1){
            fscanf (archCompras,"%d %d",&cod,&cant);
            c = fgetc(archCompras);
            total += costo(cod,cant,codArt,precioUnitario,precioDocena,stock,numArt);
            if (c=='\n')break;
        }
        gasto[*numCompras] = total; 
        (*numCompras)++;
    }
}

double costo(int cod,int cant,int *codArt,double *precioUnitario,double *precioDocena,
                int *stock,int numArt){
    double costoProducto = 0 ;
    for (int i = 0 ;i < numArt ; i++){
        if (cod==codArt[i]){
            if (cant<=stock[i]){
                if (cant%12==0){
                    costoProducto=precioDocena[i] * cant ; 
                }
                else{
                    costoProducto = precioUnitario[i] * cant;
                }
                stock[i] = stock[i] - cant;
                return costoProducto;
            }
            else if (cant>stock[i]){
                if (stock[i]>=0){
                    if (cant%12==0){
                        costoProducto=precioDocena[i] * stock[i] ; 
                    }
                    else{
                        costoProducto = precioUnitario[i] * stock[i];
                    }
                    stock[i] =0;
                    return costoProducto;
                }
            }
            else return 0 ;
        }
    }
    return costoProducto;
}

void ordenarFechaYHora(int *fecha,int *hora,int *dni,double *gasto,int numCompras){
    for (int i = 0 ;i < numCompras-1;i++){
        for (int j= i+1 ; j < numCompras; j++){
            if (fecha[i] > fecha[j]
                    ||
                fecha[i] == fecha[j] && hora[i]>hora[j]){
                cambiar(fecha,i,j);
                cambiar(hora,i,j);
                cambiar(dni,i,j);
                cambiarD(gasto,i,j);
            }
        }
    }
}

void imprimirMontoGastado(int *fecha,int *hora,int *dni,double *gasto,int numCompras){
    FILE *archTotales ; 
    archTotales = fopen("con","w");
    if (archTotales == NULL){
        printf ("Error el archivo totales.txt no existe");
        exit (1);
    }
    int dd,mm,aa,h,m,s;
    for (int i = 0 ;i < numCompras ; i++){
        convertirFecha(fecha,i,&dd,&mm,&aa);
        convertirHora(hora,i,&h,&m,&s);
        fprintf (archTotales,"%3d) %02d/%02d/%02d %02d:%02d:%02d %9d %10.2lf\n",
                              i+1,  dd,  mm,  aa,   h,  m,   s, dni[i],gasto[i]);
    }
    estadisticaGastos(gasto,numCompras,archTotales);
    fclose(archTotales);
}
void convertirFecha(int *fecha,int i,int *dd,int *mm,int *aa){
    (*aa)=fecha[i]/10000;
    fecha[i]=fecha[i]%10000;
    (*mm)=fecha[i]/100;
    (*dd)=fecha[i]%100;
}
void convertirHora(int *hora,int i,int *h,int *m,int *s){
        (*h) = hora[i]/3600;
        hora[i] = hora[i]%3600;
        (*m) = hora[i]/60;
        (*s)=hora[i]%60;
}
void estadisticaGastos(double *gasto,int numC,FILE *archTotales){
    double promedio;
    double suma = 0 , mediana;
    double gastoOrdenado[500];
    ordenarGasto(gastoOrdenado,gasto,numC);
    int puntoMedio;
    for (int i = 0 ;i < numC ; i++){
        suma += gasto[i];
    }
    promedio = suma / numC;
    puntoMedio = (1 + numC)/2;
    if (numC%2==0){
        mediana = (gastoOrdenado[puntoMedio]+gastoOrdenado[puntoMedio-1])/2;
    }
    else{
        mediana = gastoOrdenado[puntoMedio-1];
    }
    fprintf (archTotales,"El promedio de gastos es: %8.2lf\n" , promedio);
    fprintf (archTotales,"La mediana es : %8.2lf\n" ,mediana );
}
void ordenarGasto(double *gastoOrdenado,double *gasto,int numC){
    for (int i = 0 ;i < numC; i++){
        gastoOrdenado[i] = gasto [i];
    }
    for (int p = 0 ; p <numC-1 ; p++){//325.23    6253
        for (int q = p +1 ; q < numC ; q++){
            if (gastoOrdenado[p]>gastoOrdenado[q]){
                cambiarD(gastoOrdenado,p,q);
            }
        }
    }
}