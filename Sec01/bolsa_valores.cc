#include <iostream>
#include <string>
#include <random>

struct Accion{
    std::string simbolo; //AMZ
    std::string nombre_empresa; 
    float precio_compra;
    float precio_venta;
    float ultimo_precio;
};

float CalcularMargenGanancia(float precio_compra, float precio_venta);
//Sobrecarga
void CalcularFluctuacionAccion(Accion &accion);
void CalcularFluctuacionAccion(Accion *accion);

int main() {

    struct Accion accion;

    CalcularFluctuacionAccion(

}

float CalcularMargenGanancia(float precio_compra, float precio_venta){
    return (precio_venta - precio_compra) / precio_compra * 100;
}

void CalcularFluctuacionAccion(Accion &accion){
    //Generar valor aleatorio entre 10.0 y 500.0
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist_precio(10.0, 500.0);
    return dist_precio(gen);

    accion.precio_compra = dist_precio(gen);
}

void CalcularFluctuacionAccion(Accion *accion){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist_precio(10.0, 500.0);
    return dist_precio(gen);

    accion.precio_compra = dist_precio(gen);
}