#include <iostream>
#include "imagen.h"

using namespace std;


int main(int argc, char *argv[]){

  if(argc < 5){
    cerr << "Uso: "
        << " <Ejecutable> <Imagen1> <Imagen2> <ImagenSalida> <Bandera>"<<endl;
  }
  else{

    Imagen primera;
    Imagen segunda;
    Imagen destino;

    //Mensajes de error en los parámetros y lectura de las dos imágenes

    if(!primera.leerImagen(argv[1])){
      cerr << "Error leyendo imagen: " << argv[1] << endl;
      cerr << "Chequee la ruta del fichero, mayusuculas, o permisos" << endl;
  	  return 1;
    }

    if(!segunda.leerImagen(argv[2])){
      cerr << "Error leyendo imagen: " << argv[2] << endl;
      cerr << "Chequee la ruta del fichero, mayusuculas, o permisos" << endl;
      return 1;
    }


    if(argv[4][0] != 't' && argv[4][0] != 'b'){
      cerr << "Error en la bandera (flag): " << argv[4] << endl;
      cerr << "Introduza t para imagenes texto o b para imagenes binarias" << endl;
      return 1;
    }
    
    destino = primera + segunda;
    if(argv[4][0] == 't')
      destino.escribirImagen(argv[3],false);
    else
      destino.escribirImagen(argv[3],true);

    cout<<"Imagen creada correctamente "<< endl;
    cout<<"Compruebe el fichero: "<< argv[3] <<endl;

    return 0;
  }
}
