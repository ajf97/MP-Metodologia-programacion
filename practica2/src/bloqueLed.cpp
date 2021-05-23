/* Fichero fuente de implementación de las funciones
de cabecera*/

#include <iostream>
#include "bloqueLed.h"
using namespace std;


void on(bloqueLed &b, int pos)             //enciende el led pos del bloqueLed b
{	
	bloqueLed mask = 0b00000001 << pos;
	b = b | mask ;
}

void off(bloqueLed &b, int pos) 		   //apaga el led pos del bloqueLed b
{	
	bloqueLed mask = 0b00000001 << pos;
	mask = ~mask;
	b = b & mask;
}

bool get(bloqueLed b, int pos)           //consulta el estado de un led
{
	bloqueLed mask = 0b00000001 << pos;
	b = b & mask;

	if (b != 0)
		return true;
	else
		return false;
}

string bloqueLedToString(bloqueLed b)   //devuelve un string correspondiente al estado de un led
{
	string bloque;
	bool encendido;
	char cadena[8];

	for (int i = 0; i < 8 ; i++)
	{	
		encendido = get(b,7-i);

		if (encendido == true)
			cadena[i] = '1';
		else
			cadena[i] = '0';
	}

	bloque = cadena;
	return bloque;
}

void encender(bloqueLed &b)           //enciende todos los led
{
	b = 0b11111111;
}

void apagar(bloqueLed &b)             //apaga todos los led
{
	b = 0b0;
}

void asignar(bloqueLed &b, const bool v[])  //enciende los led según la configuración de v
{
	for (int i = 0; i < 8; i++)	
	{
		if (v[i] == true)
			on(b,7-i);
		else
			off(b,7-i);
	}
}

void volcar(bloqueLed b, bool v[])   //asigna en v el estado de cada led
{
	bool estado;

	for (int i = 0; i < 8; i++)
	{
		estado = get(b,7-i);

		if (estado == false)
			v[i] = false;
		else
			v[i] = true;
	}
}

void encendidos(bloqueLed b, int posic[], int &cuantos) //devuelve en posic las posiciones encendidas y en cuantos el tamaño lógico
{	
	bool encendido;
	int j = 0;
	cuantos = 0;


	for (int i = 0; i < 8; i++)
	{
		encendido = get(b,i);

		if (encendido == true)
		{
			posic[j] = i;
			cuantos++;
			j++;
		}
	}
}