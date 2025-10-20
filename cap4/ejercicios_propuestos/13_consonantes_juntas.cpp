/*
 * EJERCICIO 13: Contar consonantes juntas
 */
#include <iostream>
#include <cctype>
using namespace std;

bool esVocal(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool esConsonante(char c) {
    return isalpha(c) && !esVocal(c);
}

int contarConsonantesJuntas(const char cadena[]) {
    int contador = 0;
    
    for (int i = 0; cadena[i] != '\0' && cadena[i+1] != '\0'; i++) {
        if (esConsonante(cadena[i]) && esConsonante(cadena[i+1])) {
            contador++;
        }
    }
    
    return contador;
}

int main() {
    char cadena[256];
    cout << "Ingrese cadena: ";
    cin.getline(cadena, 256);
    
    int resultado = contarConsonantesJuntas(cadena);
    cout << "Consonantes juntas: " << resultado << endl;
    return 0;
}
