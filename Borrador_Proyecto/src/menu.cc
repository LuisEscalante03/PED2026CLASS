#include <iostream>
#include <string>

#include "menu.h"
#include "mensajes.h"
#include "usuarios.h"

void iniciarMenu() {

    // Lista general para usuarios anonimos
    Mensaje *chatGeneral = nullptr;

    // Tabla hash de usuarios
    Usuario *tabla[TAMANO];

    iniciarTabla(tabla);

    int opcion;

    do {

        std::cout << "\n============================\n";
        std::cout << "       SALA DE CHAT\n";
        std::cout << "============================\n";

        std::cout << "1. Enviar mensaje\n";
        std::cout << "2. Gestionar usuarios\n";
        std::cout << "3. Consultar historial\n";
        std::cout << "4. Mostrar chat anonimo\n";
        std::cout << "5. Salir\n";

        std::cout << "============================\n";

        std::cout << "Opcion: ";
        std::cin >> opcion;


        // =====================================
        // ENVIAR MENSAJE
        // =====================================

            switch (opcion) {
                case 1: {
                    int tipo;

                    std::cout << "\n1. Usuario anonimo\n";
                    std::cout << "2. Usuario registrado\n";

                    std::cout << "Opcion: ";
                    std::cin >> tipo;

                    std::cin.ignore();


                    // Usuario anonimo
                    if (tipo == 1) {

                        std::string nombre;
                        std::string texto;

                        std::cout << "\nNombre anonimo: ";
                        std::getline(std::cin, nombre);

                        std::cout << "Mensaje: ";
                        std::getline(std::cin, texto);

                        agregarMensaje(chatGeneral, nombre, texto);

                        std::cout << "\nMensaje enviado.\n";

                        mostrarMensajes(chatGeneral);
                    }


                    // Usuario registrado
                    else if (tipo == 2) {

                        int codigo;
                        std::string texto;

                        std::cout << "\nCodigo del usuario: ";
                        std::cin >> codigo;

                        std::cin.ignore();

                        Usuario *usuario_nodo = buscarUsuario(tabla, codigo);

                        if (usuario_nodo == nullptr) {
                            std::cout << "\nUsuario no encontrado.\n";
                        }
                        else {

                            std::cout << "\nUsuario: " << usuario_nodo->nombre << std::endl;

                            std::cout << "Mensaje: ";
                            std::getline(std::cin, texto);

                            agregarMensaje(usuario_nodo->mensajes, usuario_nodo->nombre, texto);

                            std::cout << "\nMensaje enviado.\n";
                        }
                    }
                    else {

                        std::cout << "\nOpcion incorrecta.\n";
                    }
                    break;
                }

            // =====================================
            // GESTIONAR USUARIOS
            // =====================================

            case 2: {
                int opcionUsuario;

                std::cout << "\n============================\n";
                std::cout << "    GESTION DE USUARIOS\n";
                std::cout << "============================\n";

                std::cout << "1. Registrar usuario\n";
                std::cout << "2. Buscar usuario\n";
                std::cout << "3. Mostrar usuarios\n";
                std::cout << "4. Eliminar usuario\n";
                std::cout << "5. Mostrar tabla hash\n";

                std::cout << "============================\n";

                std::cout << "Opcion: ";
                std::cin >> opcionUsuario;

                // Registrar usuario
                switch (opcionUsuario){
                    case 1: {
                        int codigo;
                        std::string nombre;

                        std::cout << "\nCodigo: ";
                        std::cin >> codigo;

                        std::cin.ignore();

                        std::cout << "Nombre: ";
                        std::getline(std::cin, nombre);

                        registrarUsuario(tabla, codigo, nombre);
                        break;
                    } 

                    // Buscar usuario
                    case 2: {
                        int codigo;

                        std::cout << "\nCodigo: ";
                        std::cin >> codigo;

                        Usuario *usuario_nodo = buscarUsuario(tabla, codigo);

                        if (usuario_nodo != nullptr) {

                            std::cout << "\nUsuario encontrado.\n";
                            std::cout << "Codigo: " << usuario_nodo->codigo << std::endl;
                            std::cout << "Nombre: " << usuario_nodo->nombre << std::endl;

                        }
                        else {
                            std::cout << "\nUsuario no encontrado.\n";
                        }
                        break;
                    }       

                    // Mostrar usuarios
                    case 3: {
                        mostrarUsuarios(tabla);
                        break;
                    }

                    // Eliminar usuario
                    case 4: {
                        int codigo;

                        std::cout << "\nCodigo del usuario: ";
                        std::cin >> codigo;

                        eliminarUsuario(tabla, codigo);
                        break;
                    }

                    // Mostrar tabla hash
                    case 5: {
                        mostrarTabla(tabla);
                        break;
                    }

                    default: {
                        std:: cout << "\nOpcion incorrecta.\n";
                        break;
                    }
                }
            
            break;
            }

            // =====================================
            // CONSULTAR HISTORIAL
            // =====================================
            case 3: {
                int codigo;

                std::cout << "\nCodigo del usuario: ";
                std::cin >> codigo;

                Usuario *usuario_nodo = buscarUsuario(tabla, codigo);

                if (usuario_nodo == nullptr) {
                    std::cout << "\nUsuario no encontrado.\n";

                }
                else {

                    std::cout << "\nHistorial de "<< usuario_nodo->nombre<< std::endl;

                    mostrarMensajes(usuario_nodo->mensajes);
                }
            break;
            }

            // =====================================
            // MOSTRAR CHAT ANONIMO
            // =====================================
            case 4: {
                mostrarMensajes(chatGeneral);
                break;
            }

            // =====================================
            // SALIR
            // =====================================
            case 5: {
                std::cout << "\nFinalizando programa...\n";
                break;
            }

            default: {
                std::cout << "\nOpcion incorrecta.\n";
                break;
            }
        }
    } while (opcion != 5);

    // Liberar memoria
    eliminarMensajes(chatGeneral);
    eliminarTabla(tabla);
}