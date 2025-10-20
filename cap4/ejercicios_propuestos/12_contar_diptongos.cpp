/*
 * EJERCICIO 12: Contar diptongos en una cadena
 * Diptongo: fuerte+débil, débil+fuerte, débil+débil
 */
#include <iostream>
#include <cctype>
using namespace std;

bool esVocalFuerte(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'o');
}

bool esVocalDebil(char c) {
    c = tolower(c);
    return (c == 'i' || c == 'u');
}

bool esVocal(char c) {
    return esVocalFuerte(c) || esVocalDebil(c);
}

int contarDiptongos(const char cadena[]) {
    int contador = 0;
    
    for (int i = 0; cadena[i] != '\0' && cadena[i+1] != '\0'; i++) {
        char c1 = cadena[i];
        char c2 = cadena[i+1];
        
        // Saltar h intermedia
        if (tolower(c2) == 'h' && cadena[i+2] != '\0') {
            c2 = cadena[i+2];
        }
        
        if (esVocal(c1) && esVocal(c2)) {
            // Casos de diptongo
            if ((esVocalFuerte(c1) && esVocalDebil(c2)) ||
                (esVocalDebil(c1) && esVocalFuerte(c2)) ||
                (esVocalDebil(c1) && esVocalDebil(c2))) {
                contador++;
            }
        }
    }
    
    return contador;
}

int main() {
    char cadena[256];
    cout << "=== CONTADOR DE DIPTONGOS ===" << endl;
    cout << "Ingrese cadena: ";
    cin.getline(cadena, 256);
    
    int diptongos = contarDiptongos(cadena);
    cout << "Número de diptongos: " << diptongos << endl;
    return 0;
}
