/**
  * @file 
  * @brief Fichero con las definiciones para la E/S de imágenes PGM 
  *
  * Permite la E/S de archivos de tipos PGM
  *
  */

#include <fstream>
#include <iostream>
#include <string>
#include "pgm.h"
using namespace std;


TipoImagen LeerTipo(ifstream& f)
{
  char c1,c2;
  TipoImagen res= IMG_DESCONOCIDO;

  if (f) {
    f >> c1 >> c2;
    if (f && c1=='P')
      switch (c2) {
        case '5': res= IMG_PGM_BINARIO; break;
        case '2': res= IMG_PGM_TEXTO; break;
        default: res= IMG_DESCONOCIDO;
      }
  }
  return res;
}


// _____________________________________________________________________________

char SaltarSeparadores (ifstream& f)
{
  char c;
  do {
    c= f.get();
  } while (isspace(c));
  f.putback(c);
  return c;
}

// _____________________________________________________________________________

bool LeerCabecera (ifstream& f, int& filas, int& columnas)
{
    int maxvalor;

    while (SaltarSeparadores(f)=='#')
      f.ignore(10000,'\n');

    f >> columnas >> filas >> maxvalor;
    
    if (/*str &&*/ f && filas>0 && filas <5000 && columnas >0 && columnas<5000) {
        f.get(); // Saltamos separador
        return true;
    }
    else return false;
}

// _____________________________________________________________________________

TipoImagen infoPGM(const char nombre[], int& filas, int& columnas)
{
  TipoImagen tipo;
  filas=columnas=0;
  ifstream f(nombre);

  tipo=LeerTipo(f);
  if (tipo!=IMG_DESCONOCIDO)
    if (!LeerCabecera(f,filas,columnas)) {
      tipo=IMG_DESCONOCIDO;
    }

  return tipo;
}

// _____________________________________________________________________________

bool leerPGMBinario (const char nombre[], unsigned char datos[], int& filas, int& columnas)
{
  bool exito= false;
  filas=0;
  columnas=0;
  ifstream f(nombre);
  
  if (LeerTipo(f)==IMG_PGM_BINARIO)
    if (LeerCabecera (f, filas, columnas))
	if (f.read(reinterpret_cast<char *>(datos),filas*columnas))
	  exito= true;
  
  return exito;
}

// _____________________________________________________________________________

bool escribirPGMBinario (const char nombre[], const unsigned char datos[], int filas, int columnas)
{
  ofstream f(nombre);
  bool res= true;
  
  if (f) {
    f << "P5" << endl;
    f << columnas << ' ' << filas << endl;
    f << 255 << endl;
    f.write(reinterpret_cast<const char *>(datos),filas*columnas);
    if (!f) res=false;
  }
  return res;
}

//___________________________________________________________________________________________

bool leerPGMTexto(const char nombre[],unsigned char datos[])
{
   bool exito = false;
   int filas,columnas;
   int maxpixel;
   int tamanio;
   int pixel;
   string tipo;
   ifstream fentrada;

   fentrada.open(nombre);
   if(fentrada.fail()){
      cerr<<"no se ha podido leer el fichero"<<endl;
   }
   if(fentrada.is_open()){
     fentrada >> tipo;

     if(tipo == "P2")
     {
      fentrada >> columnas;
      fentrada >> filas;
      fentrada >> maxpixel; //255
      tamanio = filas * columnas;

      for (int i = 0; i < tamanio; i++)
      {
        fentrada >> pixel;
        datos[i] = pixel;
      }
    }
    exito = true;
    fentrada.close();
   }
  
    return exito;
  

}

//____________________________________________________________________________________________

bool escribirPGMTexto(const char nombre[], const unsigned char datos[], int filas, int columnas)
{
  ofstream fsalida;
  int tamanio = filas * columnas;
  int entero[tamanio];
  int cfilas = 0;
  bool res;
  int contador = 0;


  for(int i = 0; i < tamanio;i++)
    entero[i] = datos[i];
  


  fsalida.open(nombre);
  if(fsalida.fail()){
      cerr<<"no se ha podido escribir el fichero"<<endl;
      res=false;
  }
  if(fsalida.is_open()){

    fsalida << "P2" << endl;
    fsalida << columnas << ' ' << filas << endl;
    fsalida << 255 << endl;

    for(int i = 0; i < filas; i++)
    {
        for (int j=0; j<columnas; j++){
          if(cfilas == columnas)
          {
            fsalida << entero[contador] << '\n';
            cfilas = 0;
            contador++;
          }
          else
          {
            fsalida << entero[contador] << ' ';
            cfilas++;
            contador++;
          }
      }
    }
    res=true;
  } 
  fsalida.close();

  return res;
}