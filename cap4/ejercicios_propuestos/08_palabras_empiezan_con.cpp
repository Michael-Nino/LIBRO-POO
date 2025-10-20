/*
 * ============================================================================
 * EJERCICIO 8: Palabras que empiezan con un carácter específico
 * ============================================================================
 * ENUNCIADO: Contar cuántas palabras empiezan con un carácter dado
 * ============================================================================
 */

#include <iostream>
#include <cctype>

using namespace std;

int contarPalabrasQueEmpiezanCon(const char cadena[], char caracter) {
    int contador = 0;
    bool enPalabra = false;
    char car = tolower(caracter);
    
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (!isspace(cadena[i])) {
            if (!enPalabra) {
                // Inicio de nueva palabra
                if (tolower(cadena[i]) == car) {
                    contador++;
                }
                enPalabra = true;
            }
        } else {
            enPalabra = false;
        }
    }
    
    return contador;
}

int main() {
    char cadena[256];
    char caracter;
    
    cout << "=== PALABRAS QUE EMPIEZAN CON... ===" << endl;
    cout << "\nIngrese una cadena: ";
    cin.getline(cadena, 256);
    
    cout << "Ingrese el carácter: ";
    cin >> caracter;
    
    int resultado = contarPalabrasQueEmpiezanCon(cadena, caracter);
    
    cout << "\nCadena: \"" << cadena << "\"" << endl;
    cout << "Palabras que empiezan con '" << caracter << "': " << resultado << endl;
    
    return 0;
}

/*
 * EJEMPLO:
 * Cadena: "Hola como estas hoy"
 * Carácter: 'h'
 * Resultado: 2 (Hola, hoy)
 */
