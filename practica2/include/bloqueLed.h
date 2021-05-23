/**
@file
@author DP
@date Marzo 2016
@brief Funciones de manejo de bloqueLeds

*/

#ifndef _BLOQUELED_H_
#define	_BLOQUELED_H_

#include <string>
#include <cstring>
using namespace std;

typedef unsigned char bloqueLed; ///< Un @c bloqueLed contiene el estado de 8 LEDs


void on(bloqueLed &b, int pos);                   //enciende el led pos del bloqueLed b


void off(bloqueLed &b, int pos); 		         //apaga el led pos del bloqueLed b


bool get(bloqueLed b, int pos);                 //consulta el estado de un led


string bloqueLedToString(bloqueLed b);         //devuelve un string correspondiente al estado de un led


void encender(bloqueLed &b);                   //enciende todos los led


void apagar(bloqueLed &b);                      //apaga todos los led


void asignar(bloqueLed &b, const bool v[]);    //enciende los led según la configuración de v


void volcar(bloqueLed b, bool v[]);              //asigna en v el estado de cada led


void encendidos(bloqueLed b, int posic[], int &cuantos); //devuelve en posic las posiciones encendidas y en cuantos el tamaño lógico


#endif

