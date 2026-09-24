#include <iostream>
#include "mensajes.h"

void agregarMensaje(Mensaje *&inicio, std::string usuario, std::string texto) {

    // Crear un nodo nuevo
    Mensaje *nuevo_nodo = new Mensaje;

    nuevo_nodo->usuario = usuario;
    nuevo_nodo->texto = texto;
    nuevo_nodo->siguiente = nullptr;

    // Si la lista está vacía
    if (inicio == nullptr) {
        inicio = nuevo_nodo;
    }
    else {

        // Buscar el último nodo
        Mensaje *actual_nodo = inicio;

        while (actual_nodo->siguiente != nullptr) {
            actual_nodo = actual_nodo->siguiente;
        }

        // Conectar el nuevo mensaje
        actual_nodo->siguiente = nuevo_nodo;
    }
}


void mostrarMensajes(Mensaje *inicio) {

    if (inicio == nullptr) {
        std::cout << "\nNo hay mensajes.\n";
        return;
    }

    Mensaje *actual_nodo = inicio;

    std::cout << "\n===== HISTORIAL =====\n";

    while (actual_nodo != nullptr) {
        std::cout << actual_nodo->usuario << ": " << actual_nodo->texto << std::endl;
        actual_nodo = actual_nodo->siguiente;
    }
}


void eliminarMensajes(Mensaje *&inicio) {

    Mensaje *actual_nodo;

    while (inicio != nullptr) {

        actual_nodo = inicio;

        inicio = inicio->siguiente;

        delete actual_nodo;
    }
}