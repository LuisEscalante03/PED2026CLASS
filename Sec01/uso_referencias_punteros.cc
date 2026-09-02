#include <iostream>

//Sobrecarga
//Paso de valor (copia)
int Incrementar(int x);

//Paso de referencia
//int Incrementar(int &x);

//Paso de puntero
//int Incrementar(int *ptr_x);

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

    //Prueba de funcion incremento con paso de valor
    std::cout << "Paso por valor(copia): " << Incrementar(valor) << "\n";
    std::cout << "Detalle de valor: " << valor << "\n";
    

    return 0;
}

//Paso de valor (copia)
int Incrementar(int x) {
    x+=10;
    return x;
}

//Paso de referencia
//int Incrementar(int &x) {
//    x+=10;
//    return x;
//}
