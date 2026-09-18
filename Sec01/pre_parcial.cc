#include <iostream>
#include <string>

// Modelado del elemento
struct Elemento
{
    std::string codigo_elemento;
    std::string nombre_elemento;
    float longitud;
    float cargas[3];
    float capacidad_maxima;
    float factor_utilizacion;
    std::string estado_seguridad;
};

// Declaracion de funciones
void RegistrarElemento(Elemento &elemento);
float CalcularFactor(Elemento *elemento);
void DeterminarSeguridad(Elemento &elemento);

/*Esta funcion recorrer todos los elementos y determinael que tiene mayor factor de utilizacion,
ademas retorna un puntero al elemento original dentro del arreglo, retorna un puntero al elemento original
dentro del arreglo y no crea una copia del elemento*/
Elemento *ObtenerElementoCritico(Elemento elementos[], int cantidad);

// Simulacion de incremento de carga
void AumentarCargas(Elemento &elemento, float porcentaje);

// Genera un informe general mostrando todos los datos y contabiliza los estados
void GenerarInforme(Elemento elementos[], int cantidad);

int main()
{
    int cant_elementos;

    // Pedimos el dato en un rango donde 10 sea el maximo
    std::cout << "Ingrese la cantidad de elementos a registrar (1-10):";

    // Utilizamos un do while para validar la cantidad ingresada
    do
    {
        std::cin >> cant_elementos;

        // Evaluamos el ERROR (Si se equivoca, mostramos la alerta)
        if (cant_elementos <= 0 || cant_elementos > 10)
        {
            std::cout << " ERROR: Rango invalido. \n Ingrese un numero del 1 al 10: ";
        }
        // REPETIR MIENTRAS el error persista
    } while (cant_elementos <= 0 || cant_elementos > 10);

    // Reserva de memoria para el arreglo tipo struct
    Elemento *ptr_elemento = new Elemento[cant_elementos];

    // Utilizamos un solo bulce para recopilar y procesar la informacion
    for (int i = 0; i < cant_elementos; ++i)
    {
        std::cout << "\n=======================================\n";
        std::cout << "      PROCESANDO ELEMENTO # " << (i + 1) << "\n";
        std::cout << "=======================================\n";

        // Guardar elementos (Paso por referencia)
        RegistrarElemento(ptr_elemento[i]);

        // Calculo del factor de utilizacion (Paso por puntero)
        CalcularFactor(ptr_elemento + i);

        // Asiganacion de estado de seguridad(Paso por referencia)
        DeterminarSeguridad(ptr_elemento[i]);
    }

    // Buscamos el elemento con el mayor factor de utilizacion
    Elemento *ptr_critico = ObtenerElementoCritico(ptr_elemento, cant_elementos);

    // Imprimimos el reporte del elemento critico (usamos flecha -> por ser puntero)
    std::cout << "\n==================================================\n";
    std::cout << "       REPORTE: ELEMENTO MAS COMPROMETIDO         \n";
    std::cout << "==================================================\n";
    std::cout << "Codigo: \t" << ptr_critico->codigo_elemento << "\n";
    std::cout << "Nombre: \t" << ptr_critico->nombre_elemento << "\n";
    std::cout << "Longitud: \t" << ptr_critico->longitud << "\n";
    std::cout << "Carga [0]: \t" << ptr_critico->cargas[0] << "\n";
    std::cout << "Carga [1]: \t" << ptr_critico->cargas[1] << "\n";
    std::cout << "Carga [2]: \t" << ptr_critico->cargas[2] << "\n";
    std::cout << "Capacidad Max: \t" << ptr_critico->capacidad_maxima << "\n";
    std::cout << "Factor Util.: \t" << ptr_critico->factor_utilizacion << "\n";
    std::cout << "ESTADO: \t" << ptr_critico->estado_seguridad << "\n";

    // Simulacion de incremento de carga para el elemento critico
    std::cout << "\n==================================================\n";
    std::cout << "      SIMULACION DE INCREMENTO DE CARGA           \n";
    std::cout << "==================================================\n";

    float porcentaje_aumento = 0.0f;
    std::cout << "Ingrese el porcentaje de incremento (ej. 10 para 10%): ";
    std::cin >> porcentaje_aumento;

    // Aumentamos las cargas (paso por referencia, usamos * para desreferenciar)
    AumentarCargas(*ptr_critico, porcentaje_aumento);

    // Recalculamos el factor (paso por puntero, se manda directo)
    CalcularFactor(ptr_critico);

    // Recalculamos la seguridad (paso por referencia)
    DeterminarSeguridad(*ptr_critico);

    std::cout << "\n--- RESULTADOS ACTUALIZADOS TRAS EL INCREMENTO ---\n";
    std::cout << "Nuevas Cargas:\n";
    std::cout << "\tCarga [0]: \t" << ptr_critico->cargas[0] << "\n";
    std::cout << "\tCarga [1]: \t" << ptr_critico->cargas[1] << "\n";
    std::cout << "\tCarga [2]: \t" << ptr_critico->cargas[2] << "\n";
    std::cout << "Nuevo Factor Util.: \t" << ptr_critico->factor_utilizacion << "\n";
    std::cout << "Nuevo ESTADO: \t\t" << ptr_critico->estado_seguridad << "\n";

    // Generamos el informe final estadistico
    GenerarInforme(ptr_elemento, cant_elementos);

    // Liberacion de memoria como reserve con [] tambien libero con[]
    delete[] ptr_elemento;

    // Iniciarlizar a nulo el puntero
    ptr_elemento = nullptr;
    return 0;
}

void RegistrarElemento(Elemento &elemento)
{
    std::cout << "=============Registro de elemento:============= \n";

    std::cout << "\n Codigo: ";
    std::cin >> elemento.codigo_elemento;

    /*
     * ¿QUE DEBES HACER PARA AGREGAR GETLINE?
     * Debes usar std::cin.ignore() justo antes del getline.
     * Cuando usamos 'std::cin >> elemento.codigo_elemento', el usuario escribe
     * el codigo y presiona 'Enter' (\n). 'cin' lee el codigo pero deja el '\n'
     * guardado en el búfer de entrada. Si no lo limpiamos, getline leera ese '\n'
     * inmediatamente y se saltara el ingreso del nombre.
     */
    std::cin.ignore();

    std::cout << "\n Nombre: ";
    /*
     * ¿POR QUE USAR GETLINE?
     * Usamos std::getline para permitir que el usuario ingrese textos que
     * contengan espacios (por ejemplo: "Viga Principal"). Si usaramos
     * 'std::cin >>', este se detendria al encontrar el primer espacio
     * y solo guardaria "Viga", dejando "Principal" flotando en el buffer.
     */
    std::getline(std::cin, elemento.nombre_elemento);

    std::cout << "\nLongitud: ";
    std::cin >> elemento.longitud;

    std::cout << "----Ingreso de cargas ----\n";
    // Nos apoyamos de un for para recorrer el arreglo y guardar las cargas
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "\tCarga [" << i+1 << "]:";
        std::cin >> elemento.cargas[i];
    }

    std::cout << "Capacidad maxima (debe ser mayo a 0): ";
    do
    {
        std::cin >> elemento.capacidad_maxima;
        if (elemento.capacidad_maxima <= 0)
        {
            std::cout << "ERROR: La capacidad maxima debe ser mayor a 0 \n vuelve a ingresar la capacidad maxima: ";
        }

    } while (elemento.capacidad_maxima <= 0);
}
float CalcularFactor(Elemento *elemento)
{
    // Declaracion variable local las variables float necesitan del sufijo f
    float suma_cargas = 0.0f;
    for (int i = 0; i < 3; ++i)
    {
        // Accedemos mediante el puntero y calculamos las cargas
        suma_cargas += elemento->cargas[i];
    }
    // Calculamos el promedio y divimos entre 3.0 para asegurar que la division contemple decimales
    float promedio = suma_cargas / 3.0f;

    // Asignamos el valor dentro de la estructura siguiendo guia de google
    elemento->factor_utilizacion = promedio / elemento->capacidad_maxima;

    // retornamos la variable de forma limpia
    return elemento->factor_utilizacion;
}
void DeterminarSeguridad(Elemento &elemento)
{
    // Analiza el factor de utilizacion y establece el estado correspodiente y se guarda en el struc
    if (elemento.factor_utilizacion >= 0.00f && elemento.factor_utilizacion <= 0.50f)
    {
        elemento.estado_seguridad = "SEGURO";
    }
    else if (elemento.factor_utilizacion > 0.50f && elemento.factor_utilizacion <= 0.80f)
    {
        elemento.estado_seguridad = "PRECAUCION";
    }
    else if (elemento.factor_utilizacion > 0.80f && elemento.factor_utilizacion <= 1.00f)
    {
        elemento.estado_seguridad = "RIESGO";
    }
    else if (elemento.factor_utilizacion > 1.00f)
    {
        elemento.estado_seguridad = "SOBRECARGA";
    }
}
Elemento *ObtenerElementoCritico(Elemento elementos[], int cant_elementos)
{
    // Asumimos que el primer elemento es el más comprometido
    // Usamos el ampersand (&) para guardar su DIRECCIÓN DE MEMORIA, no una copia
    Elemento *ptr_critico = &elementos[0];

    // Recorremos desde el segundo elemento (índice 1) hasta el final
    for (int i = 1; i < cant_elementos; ++i)
    {
        // Comparamos el elemento actual contra nuestro 'ptr_critico'
        // elementos[i] usa punto (.) porque es el objeto directo del arreglo
        // ptr_critico usa flecha (->) porque es un puntero
        if (elementos[i].factor_utilizacion > ptr_critico->factor_utilizacion)
        {
            // Si encontramos uno peor, actualizamos el puntero
            // con la nueva dirección de memoria
            ptr_critico = &elementos[i];
        }
    }

    // 5. Retornamos la dirección de memoria del elemento más crítico
    return ptr_critico;
}
void AumentarCargas(Elemento &elemento, float porcentaje)
{
    // Nos apoyamos de un for para recorrer las 3 cargas y aplicar el aumento
    for (int i = 0; i < 3; ++i)
    {
        elemento.cargas[i] = elemento.cargas[i] * (1.0f + (porcentaje / 100.0f));
    }
}
void GenerarInforme(Elemento elementos[], int cantidad)
{
    // Declaracion de contadores locales
    int total_seguro = 0;
    int total_precaucion = 0;
    int total_riesgo = 0;
    int total_sobrecarga = 0;

    // Variable para acumular todos los factores
    float suma_factor_total = 0.0f;

    std::cout << "\n==================================================\n";
    std::cout << "             INFORME GENERAL DE ESTADO            \n";
    std::cout << "==================================================\n";

    // Utilizamos un for para recorrer todos los elementos
    for (int i = 0; i < cantidad; ++i)
    {
        // Calculamos la carga promedio al vuelo sumando las 3 cargas
        float suma_cargas = elementos[i].cargas[0] + elementos[i].cargas[1] + elementos[i].cargas[2];
        float carga_promedio = suma_cargas / 3.0f;

        std::cout << "\nElemento #" << (i + 1) << " | Codigo: " << elementos[i].codigo_elemento << "\n";
        std::cout << "Nombre: \t\t" << elementos[i].nombre_elemento << "\n";
        std::cout << "Carga Promedio: \t" << carga_promedio << "\n";
        std::cout << "Factor de Util.: \t" << elementos[i].factor_utilizacion << "\n";
        std::cout << "Estado de Seg.: \t" << elementos[i].estado_seguridad << "\n";

        // Contabilizamos a que estado pertenece cada elemento
        if (elementos[i].estado_seguridad == "SEGURO")
        {
            total_seguro++;
        }
        else if (elementos[i].estado_seguridad == "PRECAUCION")
        {
            total_precaucion++;
        }
        else if (elementos[i].estado_seguridad == "RIESGO")
        {
            total_riesgo++;
        }
        else if (elementos[i].estado_seguridad == "SOBRECARGA")
        {
            total_sobrecarga++;
        }

        // Sumamos el factor de utilizacion al total
        suma_factor_total += elementos[i].factor_utilizacion;
    }

    // Calculamos el promedio global dividiendo el total entre la cantidad
    float factor_promedio_estructura = suma_factor_total / static_cast<float>(cantidad);

    std::cout << "\n==================================================\n";
    std::cout << "               RESUMEN ESTADISTICO                \n";
    std::cout << "==================================================\n";
    std::cout << "Elementos SEGUROS: \t\t" << total_seguro << "\n";
    std::cout << "Elementos PRECAUCION: \t\t" << total_precaucion << "\n";
    std::cout << "Elementos RIESGO: \t\t" << total_riesgo << "\n";
    std::cout << "Elementos SOBRECARGA: \t\t" << total_sobrecarga << "\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "FACTOR PROMEDIO ESTRUCTURA: \t" << factor_promedio_estructura << "\n";
    std::cout << "==================================================\n";
}