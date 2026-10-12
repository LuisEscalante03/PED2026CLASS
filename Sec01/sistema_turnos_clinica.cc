#include <iostream>

// Clinica que necesita administrar los turnos de sus pacientes, uno a uno, cuando se llega al ultimo de la lista, el siguiente turno debe regresar nuevamente al primer paciente
//  se desea implementar una lista circular enlazada

struct Paciente
{
    std::string nombre;
    std::string apellido;
    float peso;
    float altura;
    Paciente *siguiente;
};

// Declaracion de funciones
void RegistrarPaciente(Paciente *&actual);

int main()
{

    Paciente *actual = nullptr;

    RegistrarPaciente(actual);

    return 0;
}

void RegistrarPaciente(Paciente *&actual)
{

    Paciente *nuevo_paciente = new Paciente();

    std::cout << "Ingrese el nombre: " << std::endl;
    std::cin >> nuevo_paciente->nombre;

    std::cout << "Ingrese el apellido: " << std::endl;
    std::cin >> nuevo_paciente->apellido;

    std::cout << "Ingrese el peso: " << std::endl;
    std::cin >> nuevo_paciente->peso;

    std::cout << "Ingrese la altura: " << std::endl;
    std::cin >> nuevo_paciente->altura;

    // Si la lista no está vacía, actualizamos el puntero anterior del primer nodo actual
    if (actual == nullptr)
    {
        nuevo_paciente->siguiente = nuevo_paciente;
        actual = nuevo_paciente;
    }
    else
    {
        Paciente *ultimo_paciente = actual;

        while (ultimo_paciente->siguiente != actual)
        {
            ultimo_paciente = ultimo_paciente->siguiente;
        }

        nuevo_paciente->siguiente = actual;
        ultimo_paciente->siguiente = nuevo_paciente;
    }
};
