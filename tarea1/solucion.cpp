#include "constantes.h"
#include "solucion.h"
#include "logica.h"


#include <iostream>

using namespace std;

/*
* Implementar esta función.
* Dependiendo el estado del juego esta debe retornar:  

GANO_X: Si Ha ganado el jugador X
GANO_O: Si Ha ganado el jugador O
Epates: Si ya se llenaron todas las casillas y no hay ganador
JUEGO_EN_celdaRSO: Si el juego aún no se ha terminado.
*/
int GetEstado()
{
    /*
    Puedes acceder a las casillas del tablero mediante el arreglo de 
    dos dimensiones tablero.  

    Los índices Epiezan en cero, de modo que puedes acceder a la segunda fila, primera columna 
    de la siguiente manera:
    tablero[1][0]
    */
    
    char** tablero = GetTablero();
    int Ep = 0;
    
   
    
    // validacion vertical
    
    for(int colum = 0; colum < 3; ++colum ){
    	for(int hilera = 0; hilera < 1; ++hilera){
    		
    		if (tablero[hilera][colum] == tablero[hilera+ 1][colum]){
    			
    			if (tablero[hilera][colum] == tablero[hilera + 2][colum] ){
    				
    				if (tablero[hilera][colum] == 'X'){
    					
    					Ep = -1;
    					return GANO_X;
					}
					
					else if (tablero[hilera][colum] == 'O'){
						
						Ep = 1;
						return GANO_O;
					}
				}
    			
			}
		}
	}
	
	 // validaciones diagonales
	 
	 if ( ( (tablero[0][0] == tablero[1][1])  && (tablero[0][0] == tablero[2][2]) )  ||  ((tablero[0][1] == tablero[1][1])  && (tablero[2][0] == tablero[1][1]) ) ){
    			
    				
    	if (tablero[1][1] == 'X'){
    		
			Ep = -1;    					
    		return GANO_X;
		}
					
		else if (tablero[1][1] == 'O'){
			
			Ep = 1;	
			return GANO_O;
		}
    			
	}
    
    // validacion horizontal
    

    
    for(int hilera = 0; hilera < 3; ++hilera ){
    	for(int colum = 0; colum < 1; ++colum){
    		
    		if (tablero[hilera][colum] == tablero[hilera][colum + 1]){
    			
    			if (tablero[hilera][colum + 1] == tablero[hilera][colum + 2] ){
    				
    				if (tablero[hilera][colum] == 'X'){
    					
    					Ep = -1;
    					return GANO_X;
					}
					
					else if (tablero[hilera][colum] == 'O'){
						
						Ep = 1;
						return GANO_O;
					}
				}
    			
			}
		}
	}
	
	 
	
	
	
	if (Ep == 0){
		
		return EMPATE;
	}
    
    
    
    return JUEGO_EN_CURSO;
}
