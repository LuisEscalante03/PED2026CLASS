#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <vector>

// Declaracion de Struct
struct DatosAlquiler
{
    float horas_alquiler[3];
    float costo_alquiler;
    int cod_alquiler;
    const float KPrecioHora = 3.0;
};

struct Cliente
{
    std::string nombre_completo;

    // Variable que anida
    struct DatosAlquiler datos_alquiler;

} cliente;

//Declaracion de vector
std::vector<Cliente> vector_cliente;

// Declaracion de funciones
void SolicitarDatos();
float CalcularCostoAlquiler(float cant_horas[], float precio_hora);
int GenerarCodigoAlquiler();
void DeterminarDescuento(int cod_alquiler);
void Imprimir();
int CalcularLongitudArreglo();

int main()
{
    std::cout << "Tamano en bytes de struct Cliente: " << sizeof(cliente) << "\n";

    SolicitarDatos();

    cliente.datos_alquiler.costo_alquiler =
        CalcularCostoAlquiler(cliente.datos_alquiler.horas_alquiler, cliente.datos_alquiler.KPrecioHora);
    cliente.datos_alquiler.cod_alquiler = GenerarCodigoAlquiler();

    //Almacenando en el vector
    vector_cliente.push_back(cliente);

    Imprimir();

    return 0;
}

void SolicitarDatos()
{
        std::cout << "Ingresa el nombre: ";
        std::getline(std::cin, cliente.nombre_completo);

        for (int j = 0; j < CalcularLongitudArreglo(); j++)
        {
            std::cout << "Ingresar horas de alquiler: ";
            std::cin >> cliente.datos_alquiler.horas_alquiler[j];
        }
}

float CalcularCostoAlquiler(float cant_horas[], float precio_hora)
{
    float total_horas_alquiler = 0;
    for (int i = 0; i < CalcularLongitudArreglo(); i++)
    {
        total_horas_alquiler += cant_horas[i];
    }

    return total_horas_alquiler * precio_hora;
}

int GenerarCodigoAlquiler()
{
    return rand() % 9999 + 1000;

    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<int> dist(1000, 9999);
    // return dist(gen);
}

void DeterminarDescuento(int cod_alquiler)
{
    /*  if (cod_alquiler % 2 == 0)
      {
          std::cout<<"Descuento del 10%";
      }else{
          std::cout<<"No tiene descuento";
      }
          */
    // Implementacion del operador ternario
    (cod_alquiler % 2 == 0) ? std::cout << "Descuento del 10% \n" : std::cout << "No tiene descuento \n";
}

void Imprimir()
{
    std::cout << "\n";
    std::cout << "\n ............Imprimiendo datos.................. \n";

    for (int i = 0; i < vector_cliente.size(); i++)
    {
        std::cout << "Nombre del cliente: " << vector_cliente[i].nombre_completo << "\n";
        std::cout << "Precio por hora: $" << vector_cliente[i].datos_alquiler.KPrecioHora << "\n";
        std::cout << "Detalles de horas de alquiler: \n";

        for (int j = 0; j < CalcularLongitudArreglo(); j++)
        {
            std::cout << " - Horas alquiler: " << vector_cliente[i].datos_alquiler.horas_alquiler[j] << "\n";
        }

        std::cout << "Costo de alquiler: $" << vector_cliente[i].datos_alquiler.costo_alquiler << "\n";
        std::cout << "Codigo de alquiler: " << vector_cliente[i].datos_alquiler.cod_alquiler << "\n";
        DeterminarDescuento(vector_cliente[i].datos_alquiler.cod_alquiler);
        std::cout << "\n";
    }
}

int CalcularLongitudArreglo()
{

    int longitud = 0;
    for (int i = 0; i < 3; i++)
    {
        longitud = sizeof(vector_cliente[i].datos_alquiler.horas_alquiler) / sizeof(float);
    }

    return longitud;
}