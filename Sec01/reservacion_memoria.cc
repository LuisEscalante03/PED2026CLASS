#include <iostream>

int main(){
    
    //Stack ya que es local y se libera automáticamente al salir del bloque
    char nombre [] = {'l', 'u', 'i', 's'};

    std::cout<<"Accediendo a posición 2 del arreglo: " << nombre[2] << "\n";

    //Acceder a direccion de memoria
    std::cout << "Dirección de memoria de la variable nombre: " << &nombre << "\n";

    //notacion de puntero
    std::cout << "Accediendo a la posición 2 del arreglo usando notación de puntero: " << *(nombre + 2) << "\n";

    return 0;
}