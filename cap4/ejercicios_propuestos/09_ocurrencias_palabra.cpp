/*
 * ============================================================================
 * EJERCICIO 9: Ocurrencias de palabra en oración
 * ============================================================================
 * ENUNCIADO: Contar cuántas veces aparece una palabra dentro de una oración
 * ============================================================================
 */

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// Convierte una cadena a minúsculas
void aMinusculas(char cadena[]) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        cadena[i] = tolower(cadena[i]);
    }
}

int contarOcurrenciasPalabra(const char oracion[], const char palabra[]) {
    char oracionTemp[256], palabraTemp[100];
    strcpy(oracionTemp, oracion);
    strcpy(palabraTemp, palabra);
    
    // Convertir ambas a minúsculas para comparación case-insensitive
    aMinusculas(oracionTemp);
    aMinusculas(palabraTemp);
    
    int contador = 0;
    int longitudPalabra = strlen(palabraTemp);
    char palabraActual[100];
    int j = 0;
    
    for (int i = 0; i <= strlen(oracionTemp); i++) {
        if (oracionTemp[i] != ' ' && oracionTemp[i] != '\0') {
            palabraActual[j++] = oracionTemp[i];
        } else {
            palabraActual[j] = '\0';
            if (strcmp(palabraActual, palabraTemp) == 0) {
                contador++;
            }
            j = 0;
        }
    }
    
    return contador;
}

int main() {
    char oracion[256], palabra[100];
    
    cout << "=== BUSCAR PALABRA EN ORACIÓN ===" << endl;
    cout << "\nIngrese la oración: ";
    cin.getline(oracion, 256);
    
    cout << "Ingrese la palabra a buscar: ";
    cin.getline(palabra, 100);
    
    int ocurrencias = contarOcurrenciasPalabra(oracion, palabra);
    
    cout << "\nOración: \"" << oracion << "\"" << endl;
    cout << "Palabra: \"" << palabra << "\"" << endl;
    cout << "Ocurrencias: " << ocurrencias << endl;
    
    return 0;
}

/*
 * EJEMPLO:
 * Oración: "la casa de la abuela es la mejor casa"
 * Palabra: "casa"
 * Resultado: 2
 */
