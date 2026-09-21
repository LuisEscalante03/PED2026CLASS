#include <iostream>
#include <random>
#include <chrono>
#include <thread>

struct EstadisticarRed
{
    double enviado;
    double recibido;
};

struct AdaptadorRed
{
    std::string nombre;
    std::string direccion_ip;
    std::string tipo_conexion;
    EstadisticarRed stats;
};

// Declarar funciones
void ConsultarEstado(const AdaptadorRed &adaptador);
void RegistrarActividad(AdaptadorRed &adaptador, double envio,
                        double recepcion);
void RegistrarActividad(AdaptadorRed *adaptador, double envio,
                        double recepcion);

int main()
{
    AdaptadorRed wifi;
    wifi.nombre = "Wi-fi";
    wifi.direccion_ip = "192.168.1.100";
    wifi.tipo_conexion = "Inalambrico";
    wifi.stats.enviado = 0;
    wifi.stats.recibido = 0;

    // Generador de numero aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(5.0, 50.0);

    for (int i = 0; i <= 5; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));

        double kb_envio = dis(gen);
        double kb_recepcion = dis(gen);

        if (i % 2 == 0)
        {
            RegistrarActividad(wifi, kb_envio, kb_recepcion);
        }
        else
        {
            RegistrarActividad(&wifi, kb_envio, kb_recepcion);
        }   
    }

    std::cout << "Estado inicial:" << std::endl;
    ConsultarEstado(wifi);
    
    return 0;
}

void ConsultarEstado(const AdaptadorRed &adaptador)
{
    std::cout << "Nombre del adaptor: " << adaptador.nombre << std::endl;
    std::cout << "Direccion IP:" << adaptador.direccion_ip << std::endl;
    std::cout << "Tipo de conexion: " << adaptador.tipo_conexion << std::endl;
    std::cout << "Estadisticas de red: " << std::endl;
    std::cout << "Enviado:" << adaptador.stats.enviado << "KB" << std::endl;
    std::cout << "Recibido:" << adaptador.stats.recibido << "KB" << std::endl;
}

// Sobrecarga por referencia
// Modificar direntamente el adaptador recibido
void RegistrarActividad(AdaptadorRed &adaptador, double envio, double recepcion)
{
    adaptador.stats.enviado += envio;
    adaptador.stats.recibido += recepcion;
}

void RegistrarActividad(AdaptadorRed *adaptador, double envio, double recepcion)
{
    if (adaptador != nullptr)
    {
        return;
    }
    else
    {
        adaptador->stats.enviado += envio;
        adaptador->stats.enviado += recepcion;
    }
}