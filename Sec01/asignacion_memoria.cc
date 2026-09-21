#include <iostream>

int main(void) {
   
    //Reservando memoria
    int *p = new int;

    //Verifica la asignación de memoria
    if (p == nullptr){
        std::cout<<"Error de asignación de dir. de memoria";
        exit(1);
    }

    if (p != nullptr) {
        std::cout<<"Dirección de memoria asignada: " << p;
    } else {
        std::cout<<"Memoria liberada";
    }

    //Liberando memoria
    delete p; 

    p = nullptr; //Se asigna un valor nulo a p para evitar errores de acceso a memoria

    return 0;
}