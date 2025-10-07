// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Programa: 01_persona_estructura.cpp
 * Propósito: Demostrar el uso de ESTRUCTURAS (struct) en C++ con métodos
 * 
 * CONCEPTOS CLAVE:
 * - Una struct puede contener datos Y funciones (métodos)
 * - En struct, todos los miembros son PÚBLICOS por defecto
 * - Es el primer paso hacia la Programación Orientada a Objetos
 * - Combina datos relacionados en una sola entidad
 */

#include <iostream>
#include <cstring>  // Versión C++ de string.h
using namespace std;

// Definición de la estructura persona
// En C++, las estructuras pueden tener métodos (no solo datos como en C)
struct persona
{
    // ============ DATOS MIEMBROS ============
    // Atributos que describen a una persona
    char nombre[40];  // Nombre de la persona (cadena de hasta 39 caracteres)
    short edad;       // Edad de la persona (número entero corto)
    
    // ============ FUNCIONES MIEMBROS (MÉTODOS) ============
    
    /*
     * setDatos: Establece los valores de nombre y edad
     * Parámetros:
     *   - nom[]: Cadena con el nombre a asignar
     *   - e: Edad a asignar
     * Nota: Este método MODIFICA el estado del objeto
     */
    void setDatos(char nom[], short e)
    {
        strcpy(nombre, nom);  // Copia el nombre recibido al atributo nombre
        edad = e;             // Asigna la edad recibida al atributo edad
    }
    
    /*
     * getDatos: Muestra los valores actuales de nombre y edad
     * Este método NO modifica el estado del objeto (solo lectura)
     * Imprime directamente en pantalla
     */
    void getDatos()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

// ============ FUNCIÓN PRINCIPAL ============
int main()
{
    // Variables temporales para almacenar los datos ingresados por el usuario
    char nom[40];   // Buffer para el nombre
    short ed;       // Variable para la edad
    
    // Solicitar datos al usuario
    cout << "Ingrese nombre: ";
    cin.getline(nom, 40);  // Lee una línea completa (permite espacios en el nombre)
    cout << "Ingrese la edad: ";
    cin >> ed;             // Lee un número entero
    
    // Crear una INSTANCIA (variable) del tipo persona
    // En struct, podemos acceder directamente a todos los miembros (son públicos)
    persona per;
    
    // Llamar al método setDatos para establecer los valores del objeto
    per.setDatos(nom, ed);
    
    // Llamar al método getDatos para mostrar los valores almacenados
    per.getDatos();
    
    cout << endl;
    return 0;
}
