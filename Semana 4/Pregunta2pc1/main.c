/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Axel
 *
 * Created on 15 de abril de 2019, 11:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {

    int setsJugador1 = 0, setsJugador2 = 0, jug1, jug2,
        ptj1,        // guarda el puntaje del juego actual para jugador 1
        ptj2,        // guarda el puntaje del juego actual para jugador 2
        ptj1Ant,        // guarda el puntaje del juego anterior para jugador 1
        ptj2Ant,        // guarda el puntaje del juego anterior para jugador 2
        saquePartida,       // guarda el saque del set actual
        saqueSet,        // guarda el saque de inicio de cada set
        ptjSaquejg1 = 0,        // puntos que el jg1 obtuvo cuando saco
        ptjSaquejg2 = 0,        // puntos que el jg2 obtuvo cuando saco
        numPartida,           // cuenta en que partida estamos en el set actual
        ganadorPartidaActual,
        ganador,
        contadorSaque = 0,
        setActual = 0;
    
    printf("Ingrese los jugadores y quien saca al inicio: \n");
    scanf("%d %d %d", &jug1, &jug2, &saqueSet); // 5 7 7
    
    while (! (setsJugador1 == 3 || setsJugador2 == 3)){   //sets
        setActual++;
        numPartida = 0;
        ptjSaquejg1 = 0;
        ptjSaquejg2 = 0;
        contadorSaque = 0;
        saquePartida = saqueSet;
/*
        saqueSet = saqueSet == jug1? jug2: jug1;
*/
        printf("\n\nIngrese el detalle en el puntaje del set %d: \n", setActual);
       
        while(1){ // partidas
            numPartida++; // Tarea: reemplazar por un booleano
            scanf("%d %d", &ptj1, &ptj2);    
            // Determinar el ganador de la partida actual
            if (numPartida != 1){
                if (ptj1Ant<ptj1){
                    ganadorPartidaActual = jug1 ; 
                }
                else if (ptj2Ant<ptj2){
                    ganadorPartidaActual = jug2 ;
                }
                else {
                    // lanzar error 
                }
            }
            else {
                
                if (ptj1 > ptj2){
                    ganadorPartidaActual = jug1;
                }
                else{
                    ganadorPartidaActual = jug2;
                }
                
            }
                    
            // acumulando el puntaje por saque
            if (saquePartida == jug1 && ganadorPartidaActual == jug1){
                ptjSaquejg1++;
            }
            else if (saquePartida == jug2 && ganadorPartidaActual == jug2){
                ptjSaquejg2++;
            }                   
            
            // evaluar si el set termina
            
            if (ptj1 + ptj2 >= 20 ){  // 11, 9
                if (fabs(ptj1-ptj2) == 2){
                    if (ptj1>ptj2){
                        setsJugador1++;
                    }
                    else{
                        setsJugador2++;
                    }
                    break;
                }
            }
            else{   //10 ,7
                if (ptj1 == 11 || ptj2 == 11){
                    if (ptj1>ptj2){
                        setsJugador1++;
                    }
                    else{
                        setsJugador2++;
                    }
                    break;
                }
            }           
            
            // Actualizar variables
            ptj1Ant = ptj1;
            ptj2Ant = ptj2;   
            contadorSaque++; 
            if (contadorSaque == 2){
                saquePartida =  saquePartida == jug1? jug2: jug1;
                contadorSaque = 0;
            }
        }
        printf("\nEl ganador del set %d es el jugador %d \n", setActual, ganadorPartidaActual);
        printf("El jugador %d hizo %d\n", jug1, ptj1);//11
        printf("El jugador %d hizo %d\n", jug2, ptj2);
        printf("El jugador %d hizo %d puntos en las jugadas que tuvo saque\n", jug1, ptjSaquejg1);
        printf("El jugador %d hizo %d puntos en las jugadas que tuvo saque\n", jug2, ptjSaquejg2);
        saqueSet = saqueSet == jug1? jug2: jug1;
    }
    
    if (setsJugador2 > setsJugador1){
        ganador = jug2;
    }
    else{
        ganador = jug1;
    }
    printf("\nRESUMEN DEL PARTIDO\n");
    printf("El ganador del partido es el jugador %d\n", ganador);
    printf ("El jugador %d gano %d sets\n" , jug1, setsJugador1);
    printf ("El jugador %d gano %d sets\n" , jug2, setsJugador2);
    
    return (EXIT_SUCCESS);
}

