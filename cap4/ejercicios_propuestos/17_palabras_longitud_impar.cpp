/* EJERCICIO 17: Guardar solo palabras de longitud impar */
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void SuprimeImpares(char cad1[], char cad2[]) {
    char palabra[100];
    int j = 0, k = 0;
    cad2[0] = '\0';
    
    for (int i = 0; i <= strlen(cad1); i++) {
        if (!isspace(cad1[i]) && cad1[i] != '\0') {
            palabra[j++] = cad1[i];
        } else if (j > 0) {
            palabra[j] = '\0';
            if (j % 2 == 1) {  // Longitud impar
                if (k > 0) { cad2[k++] = ' '; }
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
    SuprimeImpares(cad1, cad2);
    cout << "Palabras impares: \"" << cad2 << "\"" << endl;
    return 0;
}
