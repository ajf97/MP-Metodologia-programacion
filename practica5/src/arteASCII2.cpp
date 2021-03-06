/**
 * lee cualquier imagen indicada por el usuario y un fichero con cadenas 
 * de caracteres y crea ficheros de imagen transformadas, una por cadena
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include "imagen.h"
#include "lista.h"

using namespace std;


const int MAXLONG = 100000;

void leelinea(char * s){

	do{
		cin.getline(s, MAXLONG);

	} while (s[0]=='\0');
}

int main(){
    char ficheroGrises[MAXLONG];
    char nombreImagen[MAXLONG];
    char ficheroImagen[MAXLONG];
    Imagen origen;
    Lista celdas;

	cout << "Introduzca nombre de la imagen: ";
	leelinea(nombreImagen);
	//Descomentar la linea siguiente para forzar a leer de la carpeta "imagenes"
	strcpy(ficheroImagen,"./imagenes/");
	strcat(ficheroImagen,nombreImagen);

    // Leer la imagen desde fichero
    if (!origen.leerImagen(ficheroImagen)){
		cerr << "Error leyendo imagen " << ficheroImagen << endl;
		cerr << "Chequee la ruta del fichero, mayusuculas, o permisos" << endl;
	   return 1;
    }
	
	cout << "Introduzca el nombre de fichero con el conjunto de caracteres para realizar la conversion: ";
	
	leelinea(ficheroGrises);
	celdas.leerLista(ficheroGrises);
	if(origen.listaAArteASCII(celdas)){
		cout << "Exito en la conversion." << endl;
		cout << "Chequee los ficheros asciiX.txt" << endl;
		cout << endl;
	}else{
		cerr << "La conversion no ha sido posible" << endl;
		cerr << endl;
	}

	celdas.destruir();
    origen.destruir();
	return 0;
}
