/**
@file
@author DP
@date Marzo 2016
@brief Funciones de manejo de bytes

*/

#ifndef _BYTE_H_
#define	_BYTE_H_

#include <string>
#include <cstring>
using namespace std;

typedef unsigned char byte; ///< Un @c byte contiene el estado de 8 LEDs


void on(byte &b, int pos);                   //enciende el led pos del byte b


void off(byte &b, int pos); 		         //apaga el led pos del byte b


bool getbit(byte b, int pos);                 //consulta el estado de un led


string byteToString(byte b);         //devuelve un string correspondiente al estado de un led


void encender(byte &b);                   //enciende todos los led


void apagar(byte &b);                      //apaga todos los led


void asignar(byte &b, const bool v[]);    //enciende los led según la configuración de v


void volcar(byte b, bool v[]);              //asigna en v el estado de cada led


void encendidos(byte b, int posic[], int &cuantos); //devuelve en posic las posiciones encendidas y en cuantos el tamaño lógico


#endif

