#include <iostream>
using namespace std;

// Estructura para almacenar la información de la Gift Card
struct GiftCard {
    float saldo;
    float totalCompras;
    float totalRecargas;
};

// Función por valor
void ConsultarSaldo(float saldo) {
    cout << "Saldo disponible: $" << saldo << endl;
}

// Función por referencia
void RecargarTarjeta(float &saldo, float &montoRecarga,
                     float cantidadRecargar) {
    if (cantidadRecargar <= 0) {
        cout << "Error: la cantidad a recargar debe ser mayor que $0.00."
             << endl;
        return;
    }

    cout << "Saldo antes de la recarga: $" << saldo << endl;

    saldo += cantidadRecargar;
    montoRecarga += cantidadRecargar;

    cout << "Recarga realizada correctamente." << endl;
    cout << "Saldo despues de la recarga: $" << saldo << endl;
}

// Función por puntero
void RealizarCompra(float *saldo, float *montoCompras,
                    float cantidadComprar) {
    if (cantidadComprar <= 0) {
        cout << "Error: la cantidad de compra debe ser mayor que $0.00."
             << endl;
        return;
    }

    cout << "Saldo antes de la compra: $" << *saldo << endl;

    if (cantidadComprar > *saldo) {
        cout << "Error: no hay suficiente saldo para realizar la compra."
             << endl;
        return;
    }

    *saldo -= cantidadComprar;
    *montoCompras += cantidadComprar;

    if (*saldo < 0) {
        *saldo = 0;
    }

    cout << "Compra realizada correctamente." << endl;
    cout << "Saldo despues de la compra: $" << *saldo << endl;
}

int main() {
    GiftCard tarjeta;

    // Valores iniciales
    tarjeta.saldo = 100.00;
    tarjeta.totalCompras = 0.00;
    tarjeta.totalRecargas = 0.00;

    int opcion;
    float cantidad;

    do {
        cout << "\n===== GIFT CARD RECARGABLE =====" << endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Recargar tarjeta" << endl;
        cout << "3. Realizar compra" << endl;
        cout << "4. Mostrar resumen" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "\n--- CONSULTAR SALDO ---" << endl;
            ConsultarSaldo(tarjeta.saldo);

        } else if (opcion == 2) {
            cout << "\n--- RECARGAR TARJETA ---" << endl;
            cout << "Ingrese la cantidad a recargar: $";
            cin >> cantidad;

            RecargarTarjeta(
                tarjeta.saldo,
                tarjeta.totalRecargas,
                cantidad
            );

        } else if (opcion == 3) {
            cout << "\n--- REALIZAR COMPRA ---" << endl;
            cout << "Ingrese la cantidad de la compra: $";
            cin >> cantidad;

            RealizarCompra(
                &tarjeta.saldo,
                &tarjeta.totalCompras,
                cantidad
            );

        } else if (opcion == 4) {
            cout << "\n--- RESUMEN DE LA GIFT CARD ---" << endl;
            cout << "Saldo disponible: $" << tarjeta.saldo << endl;
            cout << "Total recargado: $" << tarjeta.totalRecargas << endl;
            cout << "Total gastado: $" << tarjeta.totalCompras << endl;

        } else if (opcion == 5) {
            cout << "\nGracias por utilizar la Gift Card." << endl;

        } else {
            cout << "\nError: opcion no valida." << endl;
        }

    } while (opcion != 5);

    return 0;
}