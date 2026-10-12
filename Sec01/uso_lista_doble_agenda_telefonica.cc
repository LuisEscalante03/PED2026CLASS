#include <iostream>
#include <string>

struct Contacto
{
    std :: string nombre;
    std :: string numero_telefono;
};

struct Nodo
{
    Contacto contacto;
    Nodo *siguiente;
    Nodo *anterior;
};

// Puntero global
struct Nodo *lista = nullptr;

// Declaración de funciones
void InsertarInicio(struct Nodo **lista, Contacto c);
void EliminarFinal(struct Nodo **lista);
void Imprimir(struct Nodo *lista);

int main()
{
    Nodo *lista =nullptr;

    Contacto contacto1,contacto2; 
    contacto1.nombre = "Josue";
    contacto1.numero_telefono = "8788-2191";

    contacto2.nombre = "Oscar";
    contacto2.numero_telefono = "1886-9972";

    InsertarInicio(&lista, contacto1);
    InsertarInicio(&lista, contacto2);
    Imprimir(lista);
    EliminarFinal(&lista);
    Imprimir(lista);

    return 0;
}

// Insertar al inicio
void InsertarInicio(struct Nodo **lista, Contacto c)
{
    struct Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo-> contacto.nombre = c.nombre;
    nuevo_nodo-> contacto.numero_telefono = c.numero_telefono;
    nuevo_nodo->siguiente = *lista;
    nuevo_nodo->anterior = nullptr;

    // Si la lista no está vacía, actualizamos el puntero anterior del primer nodo actual
    if (*lista != nullptr)
    {
        (*lista)->anterior = nuevo_nodo;
    }

    // El nuevo nodo pasa a ser la cabeza de la lista
    *lista = nuevo_nodo;
}

// Eliminar el último nodo
void EliminarFinal(struct Nodo **lista)
{
    if (*lista == nullptr)
    {
        std::cout << "Lista vacia\n";
        return;
    }

    // Si solo hay un elemento
    if ((*lista)->siguiente == nullptr)
    {
        delete *lista;
        *lista = nullptr;
        return;
    }

    struct Nodo *temporal = *lista;
    while (temporal->siguiente != nullptr)
    {
        temporal = temporal->siguiente;
    }

    // Desconectamos el último nodo y lo borramos
    temporal->anterior->siguiente = nullptr;
    delete temporal; 
    temporal = nullptr;

}

// Imprimir la lista completa
void Imprimir(struct Nodo *lista)
{
    if (lista == nullptr)
    {
        std::cout << "Lista vacia\n";
        return;
    }

    struct Nodo *temporal = lista;
    while (temporal != nullptr)
    {
        std::cout << "Nombre: " << temporal->contacto.nombre
                  << "Numero: " << temporal->contacto.numero_telefono
                  << " | Dir: " << temporal
                  << " | Sig: " << temporal->siguiente
                  << " | Ant: " << temporal->anterior << "\n";
        temporal = temporal->siguiente;
    }
}