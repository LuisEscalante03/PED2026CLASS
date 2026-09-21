/**
 * @file luis-escalante-00055726
 * @brief Parcial 1 - PED
 *
 * Sistema de GiftCard para consultar el saldo, recargar saldo, realizar una compra 
 * y mostrar un resumen.
 *
 * @author Luis Escalante
 * @date 2026-09-18
 */

 #include <iostream>

struct GiftCard{
    float Saldo;
    float TotalCompras;
    float TotalRecargas;
};

// Declaracion de funciones
void ConsultarSaldo(float Saldo);
void RecargarTarjeta(float &Saldo, float &MontoRecarga, float CantidadRecargar);
void RealizarCompra(float *Saldo, float *MontoCompras, float CantidadComprar);

int main(){

    GiftCard Tarjeta;

    Tarjeta.Saldo = 100.00;
    Tarjeta.TotalCompras = 0.00;
    Tarjeta.TotalRecargas = 0.00;

    int Opcion;
    float Cantidad;

    do {
        std::cout << "\n===== GIFT CARD RECARGABLE =====" << std::endl;
        std::cout << "1. Consultar el saldo" << std::endl;
        std::cout << "2. Recargar la tarjeta" << std::endl;
        std::cout << "3. Realizar una compra" << std::endl;
        std::cout << "4. Mostrar resumen" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> Opcion;

        switch (Opcion){
        case 1:
            std::cout << "\n--- CONSULTAR SALDO ---" << std::endl;
            ConsultarSaldo(Tarjeta.Saldo);

            break;

        case 2:     
            std::cout << "\n--- RECARGAR TARJETA ---" << std::endl;
            std::cout << "Ingrese la cantidad a recargar: $";
            std::cin >> Cantidad;

            RecargarTarjeta(Tarjeta.Saldo, Tarjeta.TotalRecargas, Cantidad);

            break;

        case 3:
            std::cout << "\n--- REALIZAR COMPRA ---" << std::endl;
            std::cout << "Ingrese la cantidad de la compra: $";
            std::cin >> Cantidad;

            RealizarCompra(&Tarjeta.Saldo, &Tarjeta.TotalCompras, Cantidad);

            break;

        case 4:
            std::cout << "\n--- RESUMEN DE LA GIFT CARD ---" << std::endl;
            std::cout << "Saldo disponible: $" << Tarjeta.Saldo << std::endl;
            std::cout << "Total recargado: $" << Tarjeta.TotalRecargas << std::endl;
            std::cout << "Total gastado: $" << Tarjeta.TotalCompras << std::endl;

            break;

        case 5:
            std::cout << "Gracias por usar la GiftCard, vuelva pronto." << std::endl;

            break;

        default:
            std::cout << "Opcion no valida." << std::endl;

            break;
        }

    } while (Opcion != 5);

    return 0;
}
//Funciones

void ConsultarSaldo(float Saldo){
    std::cout << "Saldo disponible: $" << Saldo << std::endl;
}

void RecargarTarjeta(float &Saldo, float &MontoRecarga, float CantidadRecargar){
    std::cout << "Su saldo es de: $" << Saldo << std::endl;

    if (CantidadRecargar <= 0){
        std::cout << "La cantidad a recargar debe ser mayor que $0.00" << std::endl;
        return;
    }

    Saldo += CantidadRecargar;
    MontoRecarga += CantidadRecargar;

    std::cout << "Se realizo la recarga correctamente." << std::endl;
    std::cout << "Nuevo saldo: $" << Saldo << std::endl;
}

void RealizarCompra(float *Saldo, float *MontoCompras, float CantidadComprar){
    if (CantidadComprar <= 0){
        std::cout << "La cantidad de la compra debe ser mayor que $0.00" << std::endl;
        return;
    }

    std::cout << "Saldo es de: $" << *Saldo << std::endl;

    if (CantidadComprar > *Saldo){
        std::cout << "Saldo insuficiente."<< std::endl;
        return;
    }

    *Saldo -= CantidadComprar;
    *MontoCompras += CantidadComprar;

    if (*Saldo < 0){
        *Saldo = 0;
    }

    std::cout << "Compra realizada correctamente." << std::endl;
    std::cout << "Su saldo es ahora de: $" << *Saldo << std::endl;
}