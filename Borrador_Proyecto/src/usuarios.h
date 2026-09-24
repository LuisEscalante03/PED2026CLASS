#ifndef USUARIOS_H
#define USUARIOS_H

#include <string>
#include "mensajes.h"

struct Usuario {
    int codigo;
    std::string nombre;
    // Primer mensaje del usuario
    Mensaje *mensajes;
    // Para manejar colisiones
    Usuario *siguiente;
};

// Tamaño de nuestra tabla hash
const int TAMANO = 10;

// Inicializar tabla
void iniciarTabla(Usuario *tabla[]);

// Función hash
int funcionHash(int codigo);

// Registrar usuario
void registrarUsuario(Usuario *tabla[], int codigo, std::string nombre);

// Buscar usuario
Usuario *buscarUsuario(Usuario *tabla[], int codigo);

// Mostrar usuarios
void mostrarUsuarios(Usuario *tabla[]);

// Eliminar usuario
void eliminarUsuario(Usuario *tabla[], int codigo);

// Mostrar tabla hash
void mostrarTabla(Usuario *tabla[]);

// Eliminar memoria
void eliminarTabla(Usuario *tabla[]);

#endif