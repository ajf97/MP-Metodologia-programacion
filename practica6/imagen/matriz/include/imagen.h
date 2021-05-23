/**
@file
@brief Clase imagen blanco y negro.
*/

#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include "byte.h"
#include "lista.h"

/**
@brief Una imagen en blanco y negro. Cada píxel es un byte
*/
class Imagen{
private:
   byte **datos;///< datos de la imagen
   int nfilas; 			///< número de filas de la imagen
   int ncolumnas;		///< número de columnsa de la imagen
public:
/// Construye una imagen vacía (0 filas, 0 columnas)
   Imagen();

//funcion que libera memoria dinámica.
   void Destruir();
/**
@brief Construye una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen

Construye una imagen de tamaño @a filas x @a columnas y pone todos
sus elementos a 0.
*/
   Imagen(int filas, int columnas);


/**
@brief Crea una imagen negra de tamaño @a filas x @a columnas
@param filas 	número de filas de la imagen
@param columnas	número de columnas de la imagen

Dimensiona la imagen a tamaño @a filas x @a columnas y pone todos
sus elementos a 0.
*/
   void crear(int filas, int columnas);

/**
@brief Libera la memoria reservada en el vector de imagen

Libera la memoria reservada en el vetor de imagen y actualiza el numero
de filas y de columnas de la misma a 0.
*/
   ~Imagen();


/*Constructor de copia*/
   Imagen(const Imagen &copia);

/*Devuelve si la imagen está vacia o no.*/

   bool Vacia();

/**
@brief Devuelve el número de filas de las imagen
@return el número de filas de la imagen
*/

   int filas() const;


/**
@brief Devuelve el número de columnas de las imagen
@return el número de columnas de la imagen
*/
   int columnas() const;


/**
@brief Asigna el valor @a v a la posición (@a x,@a y) de la imagen
@param y 	fila de la imagen
@param x 	columna de la imagen
@param v 	valor a asignar

Asigna el valor @a v a la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x
del vector.
*/
   void set(int y, int x, byte v);


/**
@brief Devuelve el valor de la posición (@a x,@a y) de la imagen
@param y	 fila de la imagen
@param x	 columna de la imagen
@return el valor de la posición (@a x,@a y) de la imagen

Devuelve el valor de la posición (@a x,@a y) de la imagen. Dado que la imagen se guarda
como un vector, la posición (@a x,@a y) corresponde a la posición @a y * @c ncolumnas + @a x
del vector.
*/
   byte get(int y, int x) const;


/**
@brief Asigna el valor @a v a la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector
@param v 	valor a asignar

Asigna el valor @a v a la posición @a i de la imagen considerada como vector. La posición @a i
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la
fila y @c x representa la columna.
*/
   void setPos(int i, byte v);


/**
@brief Devuelve el valor de la posición @a i de la imagen considerada como vector
@param i 	posición de la imagen considerada como vector

Devuelve el valor de la posición @a i de la imagen considerada como vector. La posición @a i
corresponde con la posición @c y * @c ncolumnas + @c x de la imagen donde @c y representa la
fila y @c x representa la columna.
*/
   byte getPos(int i) const;


/**
@brief Carga una imagen desde un fichero
@param nombreFichero nombre del fichero que contiene la imagen
@retval true 	si ha tenido éxito en la lectura
@retval false 	si se ha producido algún error en la lectura

Lee desde disco los datos de la imagen llamada @a nombreFichero y la guarda en la memoria. La función debe asegurarse de que la imagen es de un tipo de imagen conocido y de que su tamaño es menor del tamaño máximo permitido (@c MAXDATOS).
*/
   bool leerImagen(const char nombreFichero[]);


/**
@brief Guarda una imagen desde un fichero
@param nombreFichero nombre del fichero que contiene la imagen
@param esBinario toma el valor @c true si el fichero se escribe en formato binario o @c false en caso contrario.
@retval true 	si ha tenido éxito en la escritura
@retval false 	si se ha producido algún error en la escritura
*/
   bool escribirImagen(const char nombreFichero[], bool esBinario);

/* Extraer plano k */
   Imagen plano (int k);

/*Devuelve si se ha realizado la conversión a asccii o no. */
   bool aArteASCII(const char grises[], char arteASCII[], int maxlong);


/*devuelve si se ha realizado la conversión a lista de arteascii o no.*/
	bool listaAArteASCII(const Lista celdas);


/*genera el nombre del fichero de salida a partir de una cadena de caracteres*/
   void FicheroSalida(const char c[], char i, char nfichero[]);

/* Sobrecarga del operador de asignación*/

   Imagen& operator=(const Imagen &otra_imagen);

/*Método que copia una imagen en otra*/
   void copiar(const Imagen &otra_imagen);


/*Concatena dos imagenes*/
Imagen operator+(const Imagen &otra_imagen) const;

};
#endif
