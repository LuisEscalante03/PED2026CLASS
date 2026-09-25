#include <iostream>
#include <string>

#include "menu.h"
#include "mensajes.h"

void iniciarMenu() {

    // Lista general para usuarios anonimos
    Mensaje *chatGeneral = nullptr;

    int opcion;

    do {

        std::cout << "\n============================\n";
        std::cout << "       SALA DE CHAT\n";
        std::cout << "============================\n";

        std::cout << "1. Enviar mensaje\n";
        std::cout << "2. Mostrar chat anonimo\n";
        std::cout << "3. Salir\n";

        std::cout << "============================\n";

        std::cout << "Opcion: ";
        std::cin >> opcion;


        // =====================================
        // ENVIAR MENSAJE
        // =====================================

         switch (opcion) {
            case 1: {
                std::string nombre;
                std::string texto;

                std::cin.ignore();

                std::cout << "\nNombre anonimo: ";
                std::getline(std::cin, nombre);

                std::cout << "\nMensaje: ";
                std::getline(std::cin, texto);

                agregarMensaje(chatGeneral, nombre, texto);

                std::cout << "\nMensaje enviado.\n";
                    
                break;
            }

            // =====================================
            // MOSTRAR CHAT ANONIMO
            // =====================================
            case 2: {
                mostrarMensajes(chatGeneral);
                break;
            }

            // =====================================
            // SALIR
            // =====================================
            case 3: {
                std::cout << "\nFinalizando programa...\n";
                break;
            }

            default: {
                std::cout << "\nOpcion incorrecta.\n";
                break;
            }
        }
    } while (opcion != 3);

    // Liberar memoria
    eliminarMensajes(chatGeneral);
}