/**
 * lee cualquier imagen indicada por el usuario y un fichero con cadenas 
 * de caracteres y crea ficheros de imagen transformadas, una por cadena
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include "imagen.h"
#include "lista.h"

using namespace std;


int main(int argc, char *argv[]){
    
  
    Imagen origen;
    Lista celdas;

    if(argc < 2){

    	cerr << "Uso: " 
    		<< "<Ejecutable> " << "<Fichero imagen> " << "<Fichero cadenas>" << endl;

    	return 1;
    }
    else
    {

	    // Leer la imagen desde fichero
	    if (!origen.leerImagen(argv[1])){
			cerr << "Error leyendo imagen " << argv[1] << endl;
			cerr << "Chequee la ruta del fichero, mayusuculas, o permisos" << endl;
		   return 1;
	    }
		
	
		celdas.leerLista(argv[2]);
		if(origen.listaAArteASCII(celdas)){
			cout << "Exito en la conversion." << endl;
			cout << "Chequee los ficheros asciiX.txt" << endl;
			cout << endl;
		}else{
			cerr << "La conversion no ha sido posible" << endl;
			cerr << endl;
		}

		return 0;
	}

}
