#include <string>
#include <fstream>
#include "lista.h"

using namespace std;

/// Construye una lista vacia (0 elementos)
Lista::Lista() : cabecera(0) {}
   

/**
* @brief Construye una lista a partir de un elemento
* @param valor el elemento a insertar en la lista
* 
* Construye una lista de tamaño 1 e inserta la datos @a valor 
*/
Lista::Lista(string valor){

	cabecera = new Celda;

	cabecera->datos = valor;
	cabecera->siguiente = 0;
}
	
/**
* @brief Elimina el contenido de la lista
*/
 void Lista::destruir(){

	while(!Vacia()){//si no esta vacia elimina por el principio de la lista
		Celda *p;

		if (cabecera !=0){
			p=cabecera;
			cabecera= cabecera->siguiente;
			delete p;
		}
	}
	delete cabecera;
	cabecera = 0;
}  

Lista::~Lista(){
	destruir();
}


Lista::Lista(const Lista &otra_lista){
	Copiar(otra_lista);
}


void Lista::Copiar(const Lista &otra_lista){
	Celda *nuevo, *anterior;
	cabecera = 0;

	for(Celda * p = otra_lista.cabecera; p != 0; p=p->siguiente){
		nuevo = new Celda;
		nuevo->datos = p->datos;
		nuevo->siguiente = 0;

		if(cabecera == 0)
			cabecera = nuevo;
		else
			anterior->siguiente = nuevo;

		anterior =  nuevo;
	}
}

//devueve true si la lista esta vacia y false si no lo está
bool Lista::Vacia(){
	return cabecera == 0;
}

/**
 * @brief inserta una nueva datos al final de la lista
 * @param cad elemento a insertar en la lista
 * 
 * Añade un nuevo elemento ( @a datos ) a la lista
 */
void Lista::insertar(string valor){
	
	Celda *nueva;
	Celda *p;

	if (Vacia()) //si esta vacia la lista añade al principio.
	{
		p = new Celda;
		p->datos = valor;
		p->siguiente = cabecera;
		cabecera = p;
	}
	else 		//si no está vacia añade al final de la lista
	{
		nueva = new Celda;
		nueva->datos = valor;
		nueva->siguiente = 0;

		p = cabecera;

		while(p->siguiente != 0)
		{
			p = p->siguiente;
		}
		p->siguiente = nueva;
	}
}

/**
 * @brief devuelve los datos de la posicion i-esima de la lista o la
datos vacia en caso de que el valor de i sea erroneo.
* @param pos indice del elemento dentro de la lista
* @return una datos si el indice @a pos se encuentra dentro de los margenes de 
* la lista, o una datos vacia en caso contrario
* 
*/
Celda * Lista::getCelda(int pos) const{
	Celda * p;
	p = cabecera;

	if (0 < pos && pos <= longitud() ) {
		for(int i = 1; i <= pos; i++)
			p= p->siguiente;
	}
	return p;
}

/**
 * @brief devuelve el numero de celdas que contiene la lista
 * @return el tamaño de la lista
 * 
 */
int Lista::longitud() const{
	int nceldas = 0;
	
	Celda *p;
	p=cabecera;

	while (p != 0){
		nceldas++;
		p= p->siguiente;
	}

	return nceldas;
}

/**
 * @brief Construye una lista de celdas enlazadas a partir de la informacion 
 * contenida en un fichero.
 * @param nombreFichero ruta del fichero de texto con el contenido de las datoss
 * a insertar en la lista
 * @retval true si ha tenido éxito en la lectura y el formato es el correcto
 * @retval false si se ha producido algún error en la lectura 
 * 
 * Lee desde disco los elementos almacenados en @a nombreFichero y los guarda 
 * en la lista. La función debe asegurarse de que la estructura sigue un patron 
 * determinado, y se ha de crear la lista con el numero de elementos que contenga. 
 */
bool Lista::leerLista(const char nombrefichero[]){
	ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
	    return false;
	}else{
		string grises;
		int lineas;
		getline(fin,grises); //la primera linea se ignora
		if (grises != "\0"){
			fin >> lineas; //leo el numero de datos de grises
			getline(fin,grises); //leer salto de linea
			bool vacio = false;
			for (int i = 0; (i < lineas)&&(!vacio); i++){
				getline(fin,grises); //leer cadena de caracteres
				if (grises == "\0"){
					vacio = true;
				}else{
					insertar(grises);
				}
			}
		}
		fin.close();
	}
	return true;
}


void Lista::Aniade_final(string cadena){

	Celda * nuevo;
	Celda * p;

	if(cabecera == 0)
		Aniade_principio(cadena);
	else{

		nuevo = new Celda;
		nuevo->datos = cadena;
		nuevo->siguiente = 0;

		p = cabecera;

		while(p->siguiente != 0){
			p = p->siguiente;
		}

		p->siguiente = nuevo;
	}

}


void Lista::Aniade_principio(string cadena){

	Celda *nuevo;

	nuevo = new Celda;
	nuevo->datos = cadena;
	nuevo->siguiente = cabecera;

	cabecera = nuevo;
}


Lista Lista::operator+(const Lista &otra_lista) const{

	Lista nueva(*this);
	Celda *p;

	for(p = otra_lista.cabecera; p != 0; p = p->siguiente)
		nueva.Aniade_final(p->datos);

	return nueva;
}


Lista& Lista::operator=(const Lista &otra_lista){

	if (&otra_lista != this){
		destruir();
		Copiar(otra_lista);
	}

	return *this;
}



