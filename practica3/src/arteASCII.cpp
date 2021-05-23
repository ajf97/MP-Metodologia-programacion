/*Programa que lee una image y la convierte a Arte Ascii*/

#include <iostream>
#include <cstring>
#include "imagen.h"
using namespace std;


void lee_linea(char c[], int tamanio)
{
	do{
		cin.getline(c,tamanio);
	}while(c[0]=='\0');
}


int main()
{
	char grises[256];
	char arteASCII[500001];
	char nombre[100];
	
	Imagen origen;

	
	cout << "Introduce los caracteres para formar la imagen: ";
	lee_linea(grises,100);
	cout << "Introduce el directorio del archivo de la imagen: ";
	cin >> nombre;


	if (!origen.leerImagen(nombre)){
	   cerr << "Error en la lectura\n";
	   return 1;
    }

    
	
    cout << "\nLa imagen en arte ASCII es:\n";
    if(origen.aArteASCII(grises, arteASCII, 500001))
        cout << arteASCII;
    else
        cout << "La conversión no ha sido posible" << endl;  
	
    

}