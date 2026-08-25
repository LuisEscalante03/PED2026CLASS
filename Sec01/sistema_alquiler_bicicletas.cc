#include <iostream>
#include <string>
#include <cstdlib>
#include <random>

using namespace std;

//Struct Cliente
struct Cliente
{
    string nombre;
    int edad;
    int a_nac;
    string num_telefono;
};

//Struct DatosAlquiler
struct DatosAlquiler
{
    const double kCostoAlquiler = 3;
    int horas_alquiler[3];
    double costo_total;
    int numero_aleatorio;
};

// Declaración de funciones
void SolicitarDatos();
double CalcularCostoAlquiler(int horas_alquiler[3], double kCostoAlquiler);
int GenerarAleatorio();
void DeterminarDescuento();
void ImprimirDatos(double costo_total);
int DeterminarLongitudArreglo();

//Variables struct globales
struct Cliente cliente_global;
struct DatosAlquiler datos_alquiler_global;

int main()
{
    SolicitarDatos();
    CalcularCostoAlquiler(datos_alquiler_global.horas_alquiler, datos_alquiler_global.kCostoAlquiler);
    GenerarAleatorio();
    DeterminarDescuento();
    ImprimirDatos(datos_alquiler_global.costo_total);

    return 0;
}

void SolicitarDatos()
{
    
    cout << "Ingrese su nombre completo: ";
    getline(cin, cliente_global.nombre);

    cout << "Ingresar la cantidad de horas de alquiler para cada bicicleta (3 bicicletas):" << endl;
    for (int i = 0; i < DeterminarLongitudArreglo(); i++)
    {
        cout << "Bicicleta " << i + 1 << ": ";
        cin >> datos_alquiler_global.horas_alquiler[i];
    }
}

double CalcularCostoAlquiler(int horas_alquiler[3], double kCostoAlquiler)
{

    datos_alquiler_global.costo_total = 0;
    for (int i = 0; i < DeterminarLongitudArreglo(); i++)
    {
        datos_alquiler_global.costo_total += horas_alquiler[i] * kCostoAlquiler;
    }
    return datos_alquiler_global.costo_total;
}

int GenerarAleatorio()
{
    int randomNum = rand() % 9999 + 1000;
    return randomNum;
    // random_device rd;
    // mt19937 gen(rd());
    // uniform_int_distribution<> dist(1000, 9999);
    // return dist(gen);
}

void DeterminarDescuento()
{
    datos_alquiler_global.numero_aleatorio = GenerarAleatorio();

    if (datos_alquiler_global.numero_aleatorio % 2 == 0)
    {
        cout << "Aplica para el descuento del 10%" << endl;
        datos_alquiler_global.costo_total -= datos_alquiler_global.costo_total * 0.10;
    }
    else
    {
        cout << "No aplica para ningun descuento" << endl;
    }
}

void ImprimirDatos(double costo_total)
{
    cout << "Factura: " << endl;
    cout << "Nombre del cliente: " << cliente_global.nombre << endl;
    cout << "Horas de alquiler: ";
    for (int i = 0; i < DeterminarLongitudArreglo(); i++)
    {
        cout << datos_alquiler_global.horas_alquiler[i] << " ";
    }
    cout << endl;
    cout << "Costo total del alquiler: $" << datos_alquiler_global.costo_total << endl;
    cout << "Número aleatorio generado: " << datos_alquiler_global.numero_aleatorio << endl;
}

int DeterminarLongitudArreglo()
{

    int longitud = 0;

    longitud = sizeof(datos_alquiler_global.horas_alquiler) / sizeof(int);

    return longitud;
}