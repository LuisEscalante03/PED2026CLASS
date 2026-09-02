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

}

float CalcularMargenGanancia(float precio_compra, float precio_venta){
    return (precio_venta - precio_compra) / precio_compra * 100;
}

void CalcularFluctuacionAccion(Accion &accion){
    //Generar valor aleatorio entre 10 y 500
    accion.ultimo_precio = 10 + (rand() % 500);
}