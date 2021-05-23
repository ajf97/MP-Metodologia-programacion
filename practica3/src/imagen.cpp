/* Implementación de los métodos de la clase imagen blanco y negro*/

#include <iostream>
#include "imagen.h"
#include "pgm.h"
#include "byte.h"
using namespace std;



Imagen::Imagen()
	{
		nfilas = 0;
		ncolumnas = 0;
	}


Imagen::Imagen(int filas, int columnas)
   {	
 	 crear(filas,columnas);
   }
   

void Imagen::crear(int filas, int columnas)
   {
   		int tamanio = filas * columnas;

   		for(int i = 0; i < tamanio; i++)
   			datos[i] = 0;

   		ncolumnas = columnas;
   		nfilas = filas;
   }
   

   int Imagen::filas()
   {
   	return nfilas;
   }

   

   int Imagen::columnas()
   {
   	return ncolumnas;
   }
   

	void Imagen::set(int y, int x, byte v)
   	{
   	 int i = y * ncolumnas + x;
   	 datos[i] = v;
    }
   
   
   byte Imagen::get(int y, int x)
   {
   	int i = y * ncolumnas + x;
   	return datos[i];
   }
   
   
   void Imagen::setPos(int i, byte v)
   {
   	datos[i] = v;
   }
   

   byte Imagen::getPos(int i)
   {
   	return datos[i];
   }


   bool Imagen::leerImagen(const char nombreFichero[])
   {
   	 bool lectura;
   	 int tamanio = nfilas * ncolumnas;
   	 bool tipo = infoPGM(nombreFichero,nfilas,ncolumnas);

   	 if(tipo && tamanio <= MAXPIXELS)
   	 {
   	 	lectura = leerPGMBinario(nombreFichero,datos,nfilas,ncolumnas);

   	 	if(lectura)
   	 		return true;
   	 	else
   	 		return false;
   	 }

   	 return false;
   }
   

   bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario)
   {
   	 bool escritura;

   	 if(esBinario)
   	 {
   	 	escritura = escribirPGMBinario(nombreFichero,datos,nfilas,ncolumnas);

   	 	if(escritura)
   	 		return true;
   	 	else
   	 		return false;
   	 }

   	 return false;
	}


   Imagen Imagen::plano(int k)
   {
      Imagen planobits;
      planobits.nfilas = nfilas;
      planobits.ncolumnas = ncolumnas;
      int tamanio = nfilas * ncolumnas;

      for(int j = 0; j < tamanio; j++)
      {
         if(getbit(datos[j],k) == true)
         {  
            apagar(planobits.datos[j]);
            on(planobits.datos[j],7);
         }
         else
            apagar(planobits.datos[j]);
         
      }

      return planobits;
   }

   bool Imagen::aArteASCII(const char grises[ ],char aArteASCII[ ],int maxlong)
   {
      int cardinal = 0;
      int fila = 0;
      int tamanio = nfilas * ncolumnas;
      char csalida;

      if(tamanio <= maxlong)
      {

         while(grises[cardinal] != '\0')
         {
            cardinal++;
         }

         for(int i = 0; i < tamanio && i < maxlong; i++)
         {  

            if(fila == ncolumnas-1)
            {
               aArteASCII[i] = '\n';
               fila = 0;
               
            }
            else
            {
               csalida = datos[i] * cardinal /256;
               aArteASCII[i] = grises[csalida];
               fila++;
            }
         }

         aArteASCII[tamanio+1] = '\0';
         return true;
      }
      else
         return false;

   }