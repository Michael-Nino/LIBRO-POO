/*
 * EJERCICIO 11: Procesar palabras seleccionadas por el usuario
 * Construye cad2 solo con palabras elegidas de cad1
 */
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void procesa(char cad1[], char cad2[]) {
    char palabra[100];
    int j = 0, k = 0;
    cad2[0] = '\0';
    
    for (int i = 0; i <= strlen(cad1); i++) {
        if (cad1[i] != ' ' && cad1[i] != '\0') {
            palabra[j++] = cad1[i];
        } else if (j > 0) {
            palabra[j] = '\0';
            cout << "¿Tomar en cuenta <" << palabra << ">? (SI/NO): ";
            char respuesta[10];
            cin.getline(respuesta, 10);
            
            // Convertir a mayúsculas
            for (int m = 0; respuesta[m]; m++) respuesta[m] = toupper(respuesta[m]);
            
            if (strcmp(respuesta, "SI") == 0) {
                if (k > 0) cad2[k++] = ' ';
                strcpy(cad2 + k, palabra);
                k += j;
            }
            j = 0;
        }
    }
    cad2[k] = '\0';
}

int main() {
    char cad1[256], cad2[256];
    cout << "Ingrese cadena: ";
    cin.getline(cad1, 256);
    procesa(cad1, cad2);
    cout << "\nCadena construida: \"" << cad2 << "\"" << endl;
    return 0;
}
