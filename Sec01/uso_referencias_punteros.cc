#include <iostream>

//Sobrecarga
//Paso de valor (copia)
int IncrementarValor(int x);

//Paso de referencia
int IncrementarReferencia(int &x);

//Paso de puntero
int IncrementarPuntero(int *ptr_x);

int main() {

    int valor = 100;

    //Punteros
    int *ptr = &valor;

    //Modificar valor desde el ptr
    *ptr = 200;

    std::cout << "Detalle de valor: " << valor << "\n"; //200 porque se modifico desde el puntero
    std::cout << "Valor al que apunta el puntero: " << *ptr << "\n"; //200 porque se modifico desde el puntero
    std::cout << "Detalle de valor: " << valor << "\n"; //200 por que se modifico desde el puntero
    std::cout << "Dir. de memoria de valor: " << ptr << "\n"; // Dirección de memoria de valor
    std::cout << "Dir. de memoria de ptr: " << &ptr << "\n"; // Dirección de memoria de ptr
    std::cout << "\n";

    //Prueba de funcion incremento con paso de valor
    std::cout << "\n";
    std::cout << "Funcion incremento con paso de valor: " << "\n";
    std::cout << "Paso por valor(copia): " << IncrementarValor(valor) << "\n";
    std::cout << "Detalle de valor: " << valor << "\n";
    std::cout << "Detalle del valor desde el ptr: " << *ptr << "\n"; 

    //Prueba de funcion incremento con referencia
    std::cout << "\n";
    std::cout << "Funcion incremento con paso de referencia: " << "\n"; 
    std::cout << "Paso por referencia: " << IncrementarReferencia(valor) << "\n";
    std::cout << "Detalle de valor: " << valor << "\n";
    std::cout << "Detalle del valor desde el ptr: " << *ptr << "\n";

    //Prueba de funcion incremento con puntero
    std::cout << "\n";
    std::cout << "Funcion incremento con paso de puntero: " << "\n";
    std::cout << "Paso por puntero: " << IncrementarPuntero(ptr) << "\n";
    std::cout << "Paso por puntero con &valor: " << IncrementarPuntero(&valor) << "\n";
    std::cout << "Detalle de valor: " << valor << "\n";
    std::cout << "Detalle del valor desde el ptr: " << *ptr << "\n";

    return 0;
}

//Paso de valor (copia)
int IncrementarValor(int x) {
    x+=10;
    return x;
}

//Paso de referencia
int IncrementarReferencia(int &x) {
   x+=10;
   return x;
}

//Paso de puntero
int IncrementarPuntero(int *ptr_x) {
   *ptr_x += 10;
   return *ptr_x;
}
