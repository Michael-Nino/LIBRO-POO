/*
 * ============================================================================
 * EJERCICIO 5: Formato apellidos y nombre
 * ============================================================================
 * ENUNCIADO: Solicitar nombre, apellido paterno y apellido materno.
 *            Imprimir: Apellido paterno, apellido materno, nombre
 * ============================================================================
 */

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char nombre[100], apellidoPaterno[100], apellidoMaterno[100];
    
    cout << "=== FORMATO DE NOMBRE COMPLETO ===" << endl;
    cout << "\nIngrese su nombre: ";
    cin.getline(nombre, 100);
    
    cout << "Ingrese apellido paterno: ";
    cin.getline(apellidoPaterno, 100);
    
    cout << "Ingrese apellido materno: ";
    cin.getline(apellidoMaterno, 100);
    
    // Formato: Apellido Paterno, Apellido Materno, Nombre
    cout << "\n=== RESULTADO ===" << endl;
    cout << apellidoPaterno << ", " << apellidoMaterno << ", " << nombre << endl;
    
    return 0;
}

/*
 * EJEMPLO: 
 * Nombre: Juan Carlos
 * Apellido paterno: Pérez
 * Apellido materno: García
 * 
 * RESULTADO: Pérez, García, Juan Carlos
 */
