/*
 * ============================================================================
 * EJERCICIO 6: Intercambiar palabras en posiciones específicas
 * ============================================================================
 * ENUNCIADO: Función que reciba una cadena y dos enteros representando
 *            posiciones de dos palabras. Intercambiar esas palabras.
 * ============================================================================
 */

#include <iostream>
#include <cstring>

using namespace std;

// Extraer palabra en posición n (las palabras se cuentan desde 0)
void extraerPalabra(const char cadena[], int posicion, char palabra[]) {
    int palabraActual = 0;
    int j = 0;
    bool enPalabra = false;
    
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] != ' ' && !enPalabra) {
            enPalabra = true;
            if (palabraActual == posicion) {
                j = 0;
            }
        }
        
        if (enPalabra) {
            if (cadena[i] == ' ' || cadena[i+1] == '\0') {
                if (cadena[i] != ' ' && palabraActual == posicion) {
                    palabra[j++] = cadena[i];
                }
                palabra[j] = '\0';
                palabraActual++;
                enPalabra = false;
                if (palabraActual > posicion) break;
            } else if (palabraActual == posicion) {
                palabra[j++] = cadena[i];
            }
        }
    }
}

void intercambiarPalabras(char cadena[], int pos1, int pos2) {
    char palabra1[100], palabra2[100];
    char resultado[256] = "";
    
    // Extraer las dos palabras
    extraerPalabra(cadena, pos1, palabra1);
    extraerPalabra(cadena, pos2, palabra2);
    
    // Reconstruir la cadena con palabras intercambiadas
    int palabraActual = 0;
    int j = 0;
    bool enPalabra = false;
    
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] != ' ' && !enPalabra) {
            enPalabra = true;
            // Insertar palabra intercambiada
            if (palabraActual == pos1) {
                strcat(resultado, palabra2);
                j = strlen(resultado);
            } else if (palabraActual == pos2) {
                strcat(resultado, palabra1);
                j = strlen(resultado);
            }
        }
        
        if (enPalabra) {
            if (cadena[i] == ' ' || cadena[i+1] == '\0') {
                if (palabraActual != pos1 && palabraActual != pos2) {
                    resultado[j] = '\0';
                }
                palabraActual++;
                enPalabra = false;
                if (cadena[i] == ' ') {
                    resultado[j++] = ' ';
                    resultado[j] = '\0';
                }
            } else if (palabraActual != pos1 && palabraActual != pos2) {
                resultado[j++] = cadena[i];
            }
        }
    }
    
    strcpy(cadena, resultado);
}

int main() {
    char cadena[256];
    int pos1, pos2;
    
    cout << "=== INTERCAMBIAR PALABRAS ===" << endl;
    cout << "\nIngrese una cadena: ";
    cin.getline(cadena, 256);
    
    cout << "Posición de palabra 1 (desde 0): ";
    cin >> pos1;
    cout << "Posición de palabra 2 (desde 0): ";
    cin >> pos2;
    
    cout << "\nCadena original: " << cadena << endl;
    
    intercambiarPalabras(cadena, pos1, pos2);
    
    cout << "Cadena modificada: " << cadena << endl;
    
    return 0;
}
