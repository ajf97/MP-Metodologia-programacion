/* Fichero fuente de implementación de las funciones
de cabecera*/

#include <iostream>
#include "byte.h"
using namespace std;


void on(byte &b, int pos)             //enciende el led pos del byte b
{	
	byte mask = 0b00000001 << pos;
	b = b | mask ;
}

void off(byte &b, int pos) 		   //apaga el led pos del byte b
{	
	byte mask = 0b00000001 << pos;
	mask = ~mask;
	b = b & mask;
}

bool getbit(byte b, int pos)           //consulta el estado de un led
{
	byte mask = 0b00000001 << pos;
	b = b & mask;

	if (b != 0)
		return true;
	else
		return false;
}

string byteToString(byte b)   //devuelve un string correspondiente al estado de un led
{
	string bloque;
	bool encendido;
	char cadena[8];

	for (int i = 0; i < 8 ; i++)
	{	
		encendido = getbit(b,7-i);

		if (encendido == true)
			cadena[i] = '1';
		else
			cadena[i] = '0';
	}

	bloque = cadena;
	return bloque;
}

void encender(byte &b)           //enciende todos los led
{
	b = 0b11111111;
}

void apagar(byte &b)             //apaga todos los led
{
	b = 0b0;
}

void asignar(byte &b, const bool v[])  //enciende los led según la configuración de v
{
	for (int i = 0; i < 8; i++)	
	{
		if (v[i] == true)
			on(b,7-i);
		else
			off(b,7-i);
	}
}

void volcar(byte b, bool v[])   //asigna en v el estado de cada led
{
	bool estado;

	for (int i = 0; i < 8; i++)
	{
		estado = getbit(b,7-i);

		if (estado == false)
			v[i] = false;
		else
			v[i] = true;
	}
}

void encendidos(byte b, int posic[], int &cuantos) //devuelve en posic las posiciones encendidas y en cuantos el tamaño lógico
{	
	bool encendido;
	int j = 0;
	cuantos = 0;


	for (int i = 0; i < 8; i++)
	{
		encendido = getbit(b,i);

		if (encendido == true)
		{
			posic[j] = i;
			cuantos++;
			j++;
		}
	}
}