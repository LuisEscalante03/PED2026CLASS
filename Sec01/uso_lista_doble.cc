#include <iostream>

struct Datos
{
    int numero;
};

struct Nodo
{
    struct Datos datos;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};

//Declaracion de funciones
void InsertarInicio(struct Nodo **lista, int n);
void EliminarFinal(struct Nodo **lista);
void Imprimir(struct Nodo *lista);

int main() {
    //Memoria stack
    Nodo *lista = nullptr;

    InsertarInicio(&lista, 3);
    InsertarInicio(&lista, 44);
    Imprimir(lista);
    EliminarFinal(&lista);
    Imprimir(lista);
    return 0;
}

// Insertar al inicio
void InsertarInicio(struct Nodo **lista, int n)
{
    struct Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->datos.numero = n;
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

// Eliminar el primer nodo
void EliminarInicio(struct Nodo **lista)
{
    if (*lista == nullptr)
    {
        std::cout << "Lista vacia\n";
        return;
    }

    struct Nodo *temporal = *lista;
    *lista = (*lista)->siguiente;

    // Si todavía quedan elementos, actualizamos el puntero anterior
    if (*lista != nullptr)
    {
        (*lista)->anterior = nullptr;
    }

    delete temporal;
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
        std::cout << "Valor: " << temporal->datos.numero
                  << " | Dir: " << temporal
                  << " | Sig: " << temporal->siguiente
                  << " | Ant: " << temporal->anterior << "\n";
        temporal = temporal->siguiente;
    }
}
