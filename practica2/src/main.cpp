#include <iostream>
#include "bloqueLed.h"

using namespace std;

int main()
{
    bloqueLed b;
    int posiciones[8];
    int size;
    bool inicial[] = {1,0,1,0,0,0,0,0};

    apagar(b);
    cout << "\nBloque apagado LEDs: ";
    cout << bloqueLedToString(b)<< endl;


    cout << "\nInicializo el bloque a partir de un vector de bool ";
    asignar(b,inicial);
    cout << bloqueLedToString(b)<< endl;
    cout << "\nAhora enciendo los LEDs 0, 1 y 2 con la funcion on \n";
    on(b,0);
    cout << bloqueLedToString(b)<< endl;
    on(b,1);
    cout << bloqueLedToString(b)<< endl;
    on(b,2);
    cout << bloqueLedToString(b)<< endl;

    cout << "\nLos LEDs encendidos estan en las posiciones: ";
    encendidos(b,posiciones, size);
    for(int i=0; i< size; i++)
        cout << posiciones[i] << ",";

    cout << endl;

    cout << "\nTodos encendidos: ";
    encender(b);
    cout << bloqueLedToString(b)<< endl;

    cout << "Todos apagados: ";
    apagar(b);
    cout << bloqueLedToString(b)<< endl;

    cout << "\nAhora la animacion\nEjemplo 1 \n";
    encender(b);
    cout << bloqueLedToString(b) << endl;

    for (int i = 0; i < 8; i++)
    {
        off(b,7-i);
        cout << bloqueLedToString(b) << endl;
        on(b,7-i);
    }

    cout << "\nAhora la animacion\nEjemplo 2\n";
    encender(b);
    cout << bloqueLedToString(b) << endl;


    int k = 7;
    int h = 0;

    while (k > h && h < k)
    {
        off(b,k);
        off(b,h);
        cout << bloqueLedToString(b) << endl;
        k--;
        h++;
    }

    k = 4;
    h = 3;

    while (k <= 7 && h >= 0)
    {
        on(b,k);
        on(b,h);
        cout << bloqueLedToString(b) << endl;
        k++;
        h--;
    }


}
