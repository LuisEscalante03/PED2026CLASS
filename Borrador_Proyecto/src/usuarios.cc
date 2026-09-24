#include <iostream>
#include "usuarios.h"

// Inicializar todas las posiciones en NULL
void iniciarTabla(Usuario *tabla[]) {
    for (int i = 0; i < TAMANO; i++) {
        tabla[i] = nullptr;
    }
}

// Función hash
int funcionHash(int codigo) {
    return codigo % TAMANO;
}

// Buscar usuario
Usuario *buscarUsuario(Usuario *tabla[], int codigo) {
    int posicion = funcionHash(codigo);

    Usuario *actual_nodo = tabla[posicion];

    while (actual_nodo != nullptr) {

        if (actual_nodo->codigo == codigo) {
            return actual_nodo;
        }

        actual_nodo = actual_nodo->siguiente;
    }

    return nullptr;
}


// Registrar usuario
void registrarUsuario(Usuario *tabla[], int codigo,std::string nombre) {

    // Primero verificar si ya existe
    if (buscarUsuario(tabla, codigo) != nullptr) {
        std::cout << "\nEse usuario ya existe.\n";
        return;
    }

    int posicion = funcionHash(codigo);
    Usuario *nuevo_nodo = new Usuario;

    nuevo_nodo->codigo = codigo;
    nuevo_nodo->nombre = nombre;
    nuevo_nodo->mensajes = nullptr;

    // Insertarlo en la tabla
    nuevo_nodo->siguiente = tabla[posicion];
    tabla[posicion] = nuevo_nodo;

    std::cout << "\nUsuario registrado correctamente.\n";
}


// Mostrar todos los usuarios
void mostrarUsuarios(Usuario *tabla[]) {
    std::cout << "\n===== USUARIOS =====\n";

    for (int i = 0; i < TAMANO; i++) {
        Usuario *actual_nodo = tabla[i];

        while (actual_nodo != nullptr) {

            std::cout << "Codigo: " << actual_nodo->codigo << " | Nombre: " << actual_nodo->nombre << std::endl;
            actual_nodo = actual_nodo->siguiente;
        }
    }
}

// Eliminar usuario
void eliminarUsuario(Usuario *tabla[], int codigo) {
    int posicion = funcionHash(codigo);

    Usuario *actual_nodo = tabla[posicion];
    Usuario *anterior_nodo = nullptr;


    while (actual_nodo != nullptr) {

        if (actual_nodo->codigo == codigo) {

            if (anterior_nodo == nullptr) {
                tabla[posicion] =
                actual_nodo->siguiente;
            }
            else {
                anterior_nodo->siguiente =
                actual_nodo->siguiente;
            }

            // Eliminar mensajes del usuario
            eliminarMensajes(
                actual_nodo->mensajes
            );

            delete actual_nodo;

            std::cout << "\nUsuario eliminado.\n";

            return;
        }

        anterior_nodo = actual_nodo;
        actual_nodo = actual_nodo->siguiente;

        actual_nodo = actual_nodo->siguiente;
    }

    std::cout << "\nUsuario no encontrado.\n";
}

// Mostrar la tabla hash
void mostrarTabla(Usuario *tabla[]) {

    std::cout << "\n===== TABLA HASH =====\n";

    for (int i = 0; i < TAMANO; i++) {
        std::cout << "[" << i << "] -> ";
        Usuario *actual_nodo = tabla[i];

        while (actual_nodo != nullptr) {
            std::cout << actual_nodo->nombre;
            actual_nodo = actual_nodo->siguiente;

            if (actual_nodo != nullptr) {
                std::cout << " -> ";
            }
        }

        std::cout << std::endl;
    }
}

// Liberar memoria
void eliminarTabla(Usuario *tabla[]) {
    for (int i = 0; i < TAMANO; i++) {
        Usuario *actual_nodo = tabla[i];

        while (actual_nodo != nullptr) {

            Usuario* eliminar_nodo = actual_nodo;

            actual_nodo = actual_nodo->siguiente;

            eliminarMensajes(
                eliminar_nodo->mensajes
            );


            delete eliminar_nodo;
        }


        tabla[i] = nullptr;
    }
}