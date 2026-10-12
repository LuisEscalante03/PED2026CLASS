#include <iostream>
#include <string>
#include <queue>
 
struct Documento {
    std::string nombre_archivo;
    int paginas;
    //Vertical/Horizontal
    std::string orientacion;
    //Blanco y negro/Color
    std::string modo_color;
    float tiempo;
};

//struct Documento SolicitarDatos();
//OTRA FORMA
struct Documento SolicitarDatos(Documento doc);
void Imprimir(std::queue<Documento> cola);

int main() {
    std::queue<Documento> cola;
    struct Documento documento_imprimir;
    //documento_imprimir = SolicitarDatos();
    //cola.push(documento_imprimir);

    char continuar;

    do
    {
        SolicitarDatos(documento_imprimir);
        //ALMACENAR DATOS EN LA COLA
        cola.push(documento_imprimir);  
        std::cout << "Deseas continuar imprimiendo? (s/n): ";
        std::cin >> continuar;
        std::cin.ignore(); // Limpiar el buffer de entrada  
    } while (continuar == 's' || continuar == 'S');
    
    Imprimir(cola);

    //Otra forma
    //SolicitarDatos(documento_imprimir); paso adentro de do while
    //Imprimir datos
    /*std::cout << "Imprimiendo documento en cola \n";
    std::cout << "Nombre del archivo: " << documento_imprimir.nombre_archivo << "\n";*/
    //Imprimir(documento_imprimir); paso adentro de do while

    //Almacenar los datos en la cola
    //cola.push(documento_imprimir);
    //cola.size();
    //Imprimir el primer valor de la cola
    //std::cout << "Elemento en la frente de la cola: " << cola.front().nombre_archivo << "\n";

    return 0;
}
//OTRA FORMA CON PARAMETRO
struct Documento SolicitarDatos(Documento doc){
//sin parametro
//struct Documento SolicitarDatos() {
    //Documento doc;
    std::cout << "Ingrese el nombre del archivo: ";
    std::getline(std::cin, doc.nombre_archivo);
    std::cout << "Ingrese el número de páginas: ";
    std::cin >> doc.paginas;
    std::cin.ignore(); // Limpiar el buffer de entrada
    std::cout << "Ingrese la orientación (Vertical/Horizontal): ";
    std::getline(std::cin, doc.orientacion);
    std::cout << "Ingrese el modo de color (Blanco y negro/Color): ";
    std::getline(std::cin, doc.modo_color);
    
    return doc;
} 
void Imprimir(std::queue<Documento> cola) {
   while (!cola.empty())
   {
    //IMPRIMIR FRENTE
    std::cout << "Imprimiendo documento en cola \n";
    std::cout << "Nombre del archivo: " << cola.front().nombre_archivo << "\n";
    std::cout << "Número de páginas: " << cola.front().paginas << "\n";
    std::cout << "Orientación: " << cola.front().orientacion << "\n";
    std::cout << "Modo de color: " << cola.front().modo_color << "\n";
    std::cout << "Tiempo de impresión: " << cola.front().tiempo << " segundos\n";
    //Desencolar pop()
    cola.pop(); // Eliminar el elemento impreso
   }
    
}
void CalcularTiempoImpresion(Documento doc) {
    // Lógica para calcular el tiempo de impresión
    doc.tiempo=doc.paginas *5.0;
}