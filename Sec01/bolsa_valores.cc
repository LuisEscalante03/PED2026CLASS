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

}

float CalcularMargenGanancia(float precio_compra, float precio_venta){
    return precio_venta - precio_compra;
}

void CalcularFluctuacionAccion(Accion &accion){
    //Generar valor aleatorio entre 10.0 y 500.0
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distribucionPrecio(10.0, 500.0);

    accion.precio_compra = distribucionPrecio(gen);
}

void CalcularFluctuacionAccion(Accion *accion){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distribucionPrecio(10.0, 500.0);

    accion->precio_compra = distribucionPrecio(gen);
}