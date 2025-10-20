/* EJERCICIO 20: Palabra más larga */
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char* palabraMasLarga(char *oracion) {
    static char masLarga[100];
    char actual[100];
    int j = 0;
    int maxLen = 0;
    
    for (int i = 0; i <= strlen(oracion); i++) {
        if (!isspace(oracion[i]) && oracion[i] != '\0') {
            actual[j++] = oracion[i];
        } else if (j > 0) {
            actual[j] = '\0';
            if (j > maxLen) {
                maxLen = j;
                strcpy(masLarga, actual);
            }
            j = 0;
        }
    }
    
    return masLarga;
}

int main() {
    char oracion[256];
    cout << "Ingrese oración: ";
    cin.getline(oracion, 256);
    
    char* larga = palabraMasLarga(oracion);
    cout << "Palabra más larga: " << larga << endl;
    cout << "Longitud: " << strlen(larga) << endl;
    
    return 0;
}
