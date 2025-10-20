/*
 * ============================================================================
 * EJERCICIO 10: Encriptar cadena (vocales → dígitos)
 * ============================================================================
 * ENUNCIADO: Encriptar vocales: a→0, e→1, i→2, o→3, u→4 (minúsculas)
 *                              A→5, E→6, I→7, O→8, U→9 (mayúsculas)
 * ============================================================================
 */

#include <iostream>
#include <cstring>

using namespace std;

void encriptarCadena(char cadena[]) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        switch(cadena[i]) {
            // Vocales minúsculas
            case 'a': cadena[i] = '0'; break;
            case 'e': cadena[i] = '1'; break;
            case 'i': cadena[i] = '2'; break;
            case 'o': cadena[i] = '3'; break;
            case 'u': cadena[i] = '4'; break;
            // Vocales mayúsculas
            case 'A': cadena[i] = '5'; break;
            case 'E': cadena[i] = '6'; break;
            case 'I': cadena[i] = '7'; break;
            case 'O': cadena[i] = '8'; break;
            case 'U': cadena[i] = '9'; break;
        }
    }
}

int main() {
    char cadena[256];
    char original[256];
    
    cout << "=== ENCRIPTADOR DE VOCALES ===" << endl;
    cout << "\nReglas: a→0, e→1, i→2, o→3, u→4" << endl;
    cout << "        A→5, E→6, I→7, O→8, U→9" << endl;
    
    cout << "\nIngrese la cadena: ";
    cin.getline(cadena, 256);
    
    strcpy(original, cadena);
    encriptarCadena(cadena);
    
    cout << "\nOriginal:   \"" << original << "\"" << endl;
    cout << "Encriptada: \"" << cadena << "\"" << endl;
    
    return 0;
}

/*
 * EJEMPLO:
 * Entrada: "Te espero a las 6 en el LUGAR de siempre"
 * Salida:  "T1 1sp1r3 0 l0s 6 1n 1l L9G5R d1 s21mpr1"
 */
