#include <iostream>
#include <string>

// Ejercicio consumo de energia kWh

struct Consumo
{
    float kwh;
    std::string nombre_mes;
};

void SolicitarDatos(Consumo *ptr);
void MostrarDatos(Consumo *ptr);

int main()
{
    int cant_meses;

    std::cout << "Ingrese la cantidad de meses a registrar: ";
    std::cin >> cant_meses;

    Consumo *ptr_consumo = new Consumo[cant_meses];

    for (int i = 0; i < cant_meses; i++)
    {
        SolicitarDatos(ptr_consumo + i);
    }

    for (int i = 0; i < cant_meses; i++)
    {
        std:: cout << "Direccion de arreglo: " << (ptr_consumo + i) << std::endl;
        MostrarDatos(ptr_consumo + i);
        
    }

    delete ptr_consumo;

    ptr_consumo = nullptr;

    return 0;
}

void SolicitarDatos(Consumo *ptr)
{
    std::cout << "Ingrese el nombre del mes: ";
    std::cin >> ptr->nombre_mes;

    std::cout << "Ingrese el consumo de energia en kWh: ";
    std::cin >> ptr->kwh;
}

void MostrarDatos(Consumo *ptr)
{
    std::cout << "Mes: " << ptr->nombre_mes << std::endl;
    std::cout << "Direccion de memoria de nombre_mes: " << &(ptr->nombre_mes) << std::endl;
    std::cout << "Consumo: " << ptr->kwh << " kWh" << std::endl;
    std::cout << "Direccion de memoria de kwh: " << &(ptr->kwh) << std::endl;
}