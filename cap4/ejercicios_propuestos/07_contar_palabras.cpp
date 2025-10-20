/*
 * ============================================================================
 * EJERCICIO 7: Contar palabras en una cadena
 * ============================================================================
 * ENUNCIADO: Solicitar una cadena y devolver el número de palabras
 * ============================================================================
 */

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int contarPalabras(const char cadena[]) {
    int contador = 0;
    bool enPalabra = false;
    
    for (int i = 0; cadena[i] != '\0'; i++) {
        // Si encontramos un carácter no espacio
        if (!isspace(cadena[i])) {
            if (!enPalabra) {
                contador++;  // Nueva palabra
                enPalabra = true;
            }
        } else {
            enPalabra = false;  // Fin de palabra
        }
    }
    
    return contador;
}

int main() {
    char cadena[256];
    
    cout << "=== CONTADOR DE PALABRAS ===" << endl;
    cout << "\nIngrese una cadena: ";
    cin.getline(cadena, 256);
    
    int numPalabras = contarPalabras(cadena);
    
    cout << "\nCadena: \"" << cadena << "\"" << endl;
    cout << "Número de palabras: " << numPalabras << endl;
    
    return 0;
}

/*
 * NOTAS:
 * - Una palabra es una secuencia de caracteres no espacios
 * - Los espacios múltiples se tratan correctamente
 * - isspace() detecta espacios, tabs, saltos de línea, etc.
 */
