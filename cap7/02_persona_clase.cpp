// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Programa: 02_persona_clase.cpp
 * Propósito: Demostrar el uso de CLASES con ENCAPSULAMIENTO y OPERADOR DE ÁMBITO
 * 
 * CONCEPTOS CLAVE:
 * - CLASS en lugar de STRUCT: Los miembros son PRIVADOS por defecto
 * - ENCAPSULAMIENTO: Los datos están protegidos (private), los métodos son públicos
 * - OPERADOR DE ÁMBITO (::): Permite definir métodos FUERA de la clase
 * - Separación de INTERFAZ (qué hace) e IMPLEMENTACIÓN (cómo lo hace)
 * 
 * DIFERENCIAS CON EL EJEMPLO ANTERIOR:
 * - Usa 'class' en lugar de 'struct'
 * - Los datos son 'private' (no accesibles directamente desde main)
 * - Los métodos se DECLARAN en la clase y se DEFINEN fuera con ::
 */

#include <iostream>
#include <cstring>  // Versión C++ de string.h
using namespace std;

// ============ DECLARACIÓN DE LA CLASE ============
class persona
{
private:
    // SECCIÓN PRIVADA: Solo accesible desde DENTRO de la clase
    // Esto protege los datos de modificaciones no controladas
    char nombre[40];  // Nombre de la persona (dato protegido)
    short edad;       // Edad de la persona (dato protegido)
    
public:
    // SECCIÓN PÚBLICA: Accesible desde CUALQUIER parte del programa
    // Estos son los métodos que permiten interactuar con el objeto
    
    void setDatos();  // Declaración del método para establecer datos
    void getDatos();  // Declaración del método para mostrar datos
};

// ============ DEFINICIÓN DE LOS MÉTODOS (fuera de la clase) ============

/*
 * OPERADOR DE ÁMBITO (::)
 * Sintaxis: NombreClase::nombreMetodo()
 * Indica que este método pertenece a la clase 'persona'
 * Permite acceder a los miembros privados de la clase
 */

void persona::setDatos()
{
    // Desde DENTRO de la clase, podemos acceder a los datos privados
    // Aquí leemos los datos directamente desde el teclado
    cout << "Ingrese nombre: ";
    cin.getline(nombre, 40);  // Accedemos al atributo privado 'nombre'
    cout << "Ingrese la edad: ";
    cin >> edad;               // Accedemos al atributo privado 'edad'
}

void persona::getDatos()
{
    // Este método también puede acceder a los datos privados
    // Muestra los valores almacenados en el objeto
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}

// ============ FUNCIÓN PRINCIPAL ============
int main()
{
    // Crear un OBJETO de tipo persona
    // A diferencia de struct, aquí NO podemos acceder directamente a nombre y edad
    // porque son PRIVATE. Debemos usar los métodos públicos.
    persona per;
    
    // Limpiar el buffer de entrada antes de usar getline
    // Esto evita problemas si hay un '\n' pendiente en el buffer
    cin.ignore();
    
    // Llamar a los métodos públicos para interactuar con el objeto
    per.setDatos();  // Establece los datos (única forma de modificarlos)
    per.getDatos();  // Muestra los datos (única forma de leerlos)
    
    cout << endl;
    return 0;
}

/*
 * NOTA IMPORTANTE:
 * En main() NO podemos hacer: per.nombre = "Juan";
 * porque 'nombre' es PRIVATE.
 * Esto es el ENCAPSULAMIENTO en acción: protege los datos y controla su acceso.
 */
