#include <iostream>
#include <fstream>
#include <cstring>
#include "imagen.h"
using namespace std;


void lee_linea(char c[], int tamanio)
{
	do{
		cin.getline(c,tamanio);
	}while(c[0]=='\0');
}

void FicheroSalida(const char c[], char i, char nfichero[])
{	
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

int main()
{
	
	char arteASCII[500001];
	char imagen_entrada[100];
	char grises[50];
	char salida[50];
	char nfichero[50];
	char cadenas[200];
	int ncadenas;
	char c = '1';
	

	ifstream fentrada;
	ofstream fsalida;
	Imagen origen;

	
	cout << "Imagen de entrada: ";
	cin.getline(imagen_entrada,100);
	cout << "Fichero de cadenas: ";
	cin.getline(grises,50);
	cout << "Fichero de salida: ";
	cin.getline(salida,50);



	if (!origen.leerImagen(imagen_entrada)){
	    	cerr << "Error en la lectura\n";
	    	return 1;
    	}


	fentrada.open(grises);
	if (fentrada.is_open())
	{
		fentrada.ignore(150,'\n');
		fentrada >> ncadenas;
		
		for(int i = 1; i <= ncadenas; i++)
		{	
			
			fentrada >> cadenas;
			FicheroSalida(salida,c,nfichero);
			c++;

			cout << "\nCreando fichero de salida: " << nfichero << "\n";
		    if(origen.aArteASCII(cadenas, arteASCII, 500001))
		    {
		    	fsalida.open(nfichero);
		        fsalida << arteASCII;
		        fsalida.close();
		    }
		    else
		        cout << "La conversión no ha sido posible" << endl; 
		}

		fentrada.close();
	}
	else
		cout << "Error en la lectura del fichero";
}
