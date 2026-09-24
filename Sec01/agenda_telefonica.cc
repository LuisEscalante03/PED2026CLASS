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
}; 

// Puntero global
struct Nodo *lista = nullptr;

// Declaración de funciones
void InsertarInicio(Contacto c);
void Imprimir ();
void EliminarInicio();
void InsertarFinal(Contacto c);
void EliminarFinal();

int main()
{
    Contacto contacto1, contacto2; 
    contacto1.nombre = "Luis";
    contacto1.numero_telefono = "68495815";

    contacto2.nombre = "Paola";
    contacto2.numero_telefono = "71360099";

    InsertarInicio(contacto1);
    InsertarFinal(contacto2);
    EliminarFinal();
    Imprimir();

    return 0;
};

void InsertarInicio(Contacto c)
{
    // Reserva de memoria
    struct Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->contacto.nombre = c.nombre ;
    nuevo_nodo->contacto.numero_telefono= c.numero_telefono;

    if (lista == nullptr)
    {
        lista = nuevo_nodo;
    }
    else
    {
        nuevo_nodo->siguiente = lista;
        lista = nuevo_nodo;
    }
};

void Imprimir()
{
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        while (temporal != nullptr)
        {
            std::cout << "Lista " << temporal->contacto.nombre << " Direccion " << temporal << " dir nodo siguiente " << temporal->siguiente << std::endl;
            temporal = temporal->siguiente;
        }
    }
    else
    {
        std::cout << "Lista vacia";
    }
};

// Eliminar el primer nodo
void EliminarInicio()
{
    if (lista == nullptr)
    {
        std::cout << "Lista vacia\n";
        return;
    }

    // Guardamos el nodo a eliminar
    struct Nodo *temporal = lista;
    // La lista avanza al siguiente       
    lista = lista->siguiente;    
    // Liberamos memoria de forma segura        
    delete temporal;                     
};

// Insertar al final
void InsertarFinal(Contacto c)
{
    struct Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->contacto.nombre = c.nombre ;
    nuevo_nodo->contacto.numero_telefono= c.numero_telefono;

    nuevo_nodo->siguiente = nullptr;

    // Si la lista está vacía, el nuevo nodo es el primero
    if (lista == nullptr)
    {
        lista = nuevo_nodo;
        return;
    }

    // Si no está vacía, buscamos el último nodo
    struct Nodo *temporal = lista;
    while (temporal->siguiente != nullptr)
    {
        temporal = temporal->siguiente;
    }

    // Conectamos el último nodo con el nuevo
    temporal->siguiente = nuevo_nodo;
};

//Eliminar al final
void EliminarFinal()
{
    if (lista == nullptr)
    {
        std::cout << "Lista vacia\n";
        return;
    }

    // Si solo hay un nodo, eliminamos la lista
    if (lista->siguiente == nullptr)
    {
        delete lista;
        lista = nullptr;
        return;
    }

    // Buscamos el penúltimo nodo
    struct Nodo *temporal = lista;
    while (temporal->siguiente->siguiente != nullptr)
    {
        temporal = temporal->siguiente;
    }

    // Guardamos el último nodo para eliminarlo
    struct Nodo *ultimo_nodo = temporal->siguiente;
    temporal->siguiente = nullptr; // Desconectamos el último nodo
    delete ultimo_nodo; // Liberamos memoria del último nodo
};
