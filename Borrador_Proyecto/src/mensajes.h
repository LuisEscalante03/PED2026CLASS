#ifndef MENSAJES_H
#define MENSAJES_H

#include <string>

// Struct para mensajes y Nodo de la lista enlazada
struct Mensaje {
    std::string usuario;
    std::string texto;
    Mensaje *siguiente;
};

// Agregar un mensaje
void agregarMensaje(Mensaje *&inicio, std::string usuario, std::string texto);

// Mostrar todos los mensajes
void mostrarMensajes(Mensaje *inicio);

// Eliminar toda la lista
void eliminarMensajes(Mensaje   *&inicio);

#endif