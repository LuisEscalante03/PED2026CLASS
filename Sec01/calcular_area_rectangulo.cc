#include <iostream>

using namespace std;

// Declaración de funciones
void IngresarDatos();
void CalcularArea();
void MostrarResultado();

// Variables globales
double base, altura, area;

int main()
{
    IngresarDatos();
    CalcularArea();
    MostrarResultado();

    return 0;
}

void IngresarDatos()
{
    cout << "Ingrese la base del rectangulo: ";
    cin >> base;

    cout << "Ingrese la altura del rectangulo: ";
    cin >> altura;
}

void CalcularArea()
{
    area = base * altura;
}

void MostrarResultado()
{
    cout << "El area del rectangulo es: " << area << endl;
}