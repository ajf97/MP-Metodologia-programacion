#include <iostream>
#include <fstream>
#include <cstring>
#include "pgm.h"
#include "imagen.h"
#include "lista.h"

using namespace std;

// Construye una imagen vacía (0 filas, 0 columnas)
Imagen::Imagen(){
	nfilas = 0;
	ncolumnas = 0;
	datos = 0;
}

// Construye una imagen NEGRA=TODO A 0? de tamaño filas x columnas
Imagen::Imagen(int filas, int columnas){
	datos = 0;
	crear(filas,columnas);
}

// Crea una imagen NEGRA? de tamaño filas x columnas
void Imagen::crear(int filas, int columnas){
	nfilas=filas;
	ncolumnas= columnas;
	int tamanio=(nfilas*ncolumnas)+nfilas+1;

    if (!Vacia())
        delete [] datos;

	datos = new byte [tamanio];

	for(int i = 0; i < tamanio; i++)
		datos[i] = 0;
}

Imagen::~Imagen(){
	
	if(!Vacia()){
		
		delete [] datos;
		datos = 0;
		nfilas = 0;
		ncolumnas = 0;
	}
}

Imagen::Imagen(const Imagen &copia){
	copiar(copia);
}



bool Imagen::Vacia(){
	return datos == 0;
}


// Devuelve el numero de filas de las imagen
int Imagen::filas() const{
	return nfilas;
} 

// Devuelve el numero de columnas de la imagen
int Imagen::columnas() const{
	return ncolumnas;
} 

// Asigna el valor v a la posicion (x,y) de la imagen
void Imagen::set(int y, int x, unsigned char v){
	datos[y*ncolumnas+x] = v;
}


// Devuelve el valor de la posicion (x,y) de la imagen
unsigned char Imagen::get(int y, int x) const {
	return datos[y*ncolumnas+x];
}

// Asigna el valor v a la posicion i de la imagen considerada como vector
void Imagen::setPos(int i, unsigned char v){
	datos[i] = v;
} 

// Devuelve el valor de la posicion i de la imagen considerada como vector
unsigned char Imagen::getPos(int i) const{
	return datos[i];
}


// Carga la imagen desde el fichero 
bool Imagen::leerImagen(const char fichero[]){
    int filas, columnas;
    TipoImagen tipo = infoPGM(fichero, filas, columnas);
    crear(filas,columnas);

    if (tipo == IMG_PGM_BINARIO){
		return leerPGMBinario(fichero, datos,nfilas,ncolumnas);
	}else{
        //return false;
        if (tipo == IMG_PGM_TEXTO){
            return leerPGMTexto(fichero, datos);
		}
	}
	return false;
}



// Guarda la imagen en fichero
bool Imagen::escribirImagen(const char fichero[], bool esBinario){
    
    if (esBinario)
		return escribirPGMBinario(fichero, datos, nfilas, ncolumnas);
    else
        return escribirPGMTexto(fichero, datos, nfilas, ncolumnas);
  
}
				
// Extraer plano k 		
Imagen Imagen::plano(int k){
    Imagen plano (nfilas, ncolumnas);
    for (int i=0; i < filas()*columnas(); i++){	
		if(getbit(getPos(i), k)){
			plano.setPos(i, 0x80); // 0b1000 0000
		}
		else{
			plano.setPos(i, 0);
		}
    }            
    return plano;
}


// Convertir a Arte ASCII 		
bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong ){
	int cardinal = strlen(grises);
	int contador_char = 0;
	  
	if (filas() * (columnas()+1) > maxlong){ // columnas +1 para tener en cuenta el \n
		return false;
	}

	for (int i=0; i < filas(); i++){
		for (int j=0; j < columnas(); j++){
			arteASCII[contador_char] = grises[(get(i, j) * cardinal) / 256];    
            //cout << ' ' << (get(i, j) * cardinal) / 256;
            contador_char ++;
		}
		//cout << endl;
		arteASCII[contador_char] = '\n';
		contador_char ++;          
	}
	arteASCII[contador_char] = '\0';  
	return true;       
}
//genera nombre de fichero de salida de imagen:
void Imagen::FicheroSalida(const char c[], char i, char nfichero[]){	
	char aux[4];

		int j = 0;
		int t=0;

		while(c[j] != '.'){
			nfichero[j]=c[j];
			j++;	
		}

		for(int z= j; c[z]!='\0'; z++){
			aux[t]= c[z];
			t++;
		}
			nfichero[j]=i;
			j++;
		for(int t=0; t<=4; t++){
			nfichero[j]=aux[t];
			j++;	
		}
}

// Convertir a Arte ASCII 		
bool Imagen::listaAArteASCII(const Lista celdas){
		
	//Llama al metodo aArteASCII(const char grises[], char arteASCII[], int maxlong)
	
	int longitud = celdas.longitud();	//calcula el numero de celdas de la lista. la longitud
	int tamanio = (nfilas * ncolumnas)+nfilas+1;
	bool exito= false;
	ofstream salida;
	char *arteASCII, *c;
	Celda *p;
	string cadena;
	char nombre_fichero[50];
	char fichero_inicio[] = "ascii.txt";
	char numero = '1';
	
	arteASCII = new char[tamanio];

	for(int i = 0; i < longitud; i++)
	{
		//genero el nombre del fichero de salida//
		FicheroSalida(fichero_inicio,numero,nombre_fichero);
		numero++;

		p = celdas.getCelda(i);
		cadena = p->datos;
		int tcadena= cadena.size();

		//paso contenido de la lista al vector c	
		c = new char [tcadena+1];

		for(int j = 0; j < tcadena; j++)
			c[j] = cadena[j];

		c[tcadena]='\0';


		if ( aArteASCII(c,arteASCII,tamanio))
		{	
			salida.open(nombre_fichero);
			
			if (salida.fail())
				exito = false;
			
			if(salida.is_open())
			{
				salida << arteASCII;
				delete [] c;
				c = 0;
			}
			
			salida.close();
		} 
		exito=true;
}
delete [] arteASCII;
arteASCII = 0;
return exito;
}

void Imagen::copiar(const Imagen &otra_imagen){
	
	nfilas = otra_imagen.filas();
	ncolumnas = otra_imagen.columnas();
	int tamanio = nfilas * ncolumnas;

	datos = new byte [tamanio];

	for(int i = 0; i < tamanio; i++)
		datos[i] = otra_imagen.getPos(i);
}


Imagen& Imagen::operator=(const Imagen &otra_imagen){
	if(&otra_imagen != this){
		delete [] datos;
		datos = 0;
		nfilas = 0;
		ncolumnas = 0;
		copiar(otra_imagen);
	}

	return *this;
}

Imagen Imagen::operator+(const Imagen &otra_imagen) const{
int filas= this->filas();
int columnas= this->columnas() + otra_imagen.columnas();
int t = 0, m=0, l=0;
		if( filas < otra_imagen.filas())
			filas= otra_imagen.filas();

		Imagen img_concat (filas,columnas);

		for(int i=0; i<filas; i++){
			
				for(int j=0; j< this->columnas(); j++){
					if(i<this->filas()){
						img_concat.setPos(t,this->getPos(l));
						t++;
						l++;
					}
					else{
						img_concat.setPos(t,0);
						t++;
					}
				}
			
				for(int k=this->columnas(); k< columnas; k++){
					if(i<otra_imagen.filas()){
						img_concat.setPos(t,otra_imagen.getPos(m));
						t++;
						m++;
					}
					else{
						img_concat.setPos(t,0);
						t++;
					}
				}
		}
return img_concat;
}

/*Imagen Imagen::operator+(const Imagen &otra_imagen) const{
int filas= this->filas();
int columnas= this->columnas() + otra_imagen.columnas();
int t = 0, m=0, l=0;


		if( filas < otra_imagen.filas() )
			filas= otra_imagen.filas();

		Imagen img_concat (filas,columnas);

		for(int i=0; i<filas; i++){

				for(int j=0; j< this->columnas(); j++){
					img_concat.setPos(t,this->getPos(l));
					t++;
					l++;
				}
			
				for(int k=this->columnas(); k< columnas; k++){
					img_concat.setPos(t,otra_imagen.getPos(m));
					t++;
					m++;
				}
		}


return img_concat;
}*/