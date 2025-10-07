// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Programa: 03_persona_ambito.cpp
 * Propósito: Demostrar ÁMBITO y VIDA de objetos (local vs global)
 * 
 * CONCEPTOS CLAVE:
 * - OBJETO GLOBAL: Existe durante toda la ejecución del programa
 * - OBJETO LOCAL: Existe solo dentro de su bloque { }
 * - CONSTRUCTOR: Se ejecuta al crear el objeto
 * - DESTRUCTOR: Se ejecuta al destruir el objeto
 * - Observar CUÁNDO y DÓNDE se crean/destruyen los objetos
 */

#include <iostream>
#include <cstring>  // Versión C++ de string.h
using namespace std;

class persona
{
private:
    char nombre[40];
    short edad;
    
public:
    void setDatos();
    void getDatos();
};

void persona::setDatos()
{
    cout << "Ingrese nombre: ";
    cin.getline(nombre, 40);
    cout << "Ingrese la edad: ";
    cin >> edad;
}

void persona::getDatos()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}

// ============ FUNCIÓN PRINCIPAL ============
int main()
{
    persona per;  // OBJETO LOCAL: Se crea aquí, se destruye al terminar main()
    cin.ignore();
    per.setDatos();
    per.getDatos();
    
    cout << endl;
    return 0;
}

/*
 * NOTA SOBRE ÁMBITO:
 * - 'per' es local a main(): existe desde su declaración hasta el final de main()
 * - Si declaráramos persona per2 dentro de un bloque {}, se destruiría al salir del bloque
 * - Los objetos globales (fuera de funciones) existen durante todo el programa
 */
