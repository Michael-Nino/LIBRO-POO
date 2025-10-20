/* EJERCICIO 21: Intercambiar palabras más largas entre dos cadenas */
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void encontrarMasLarga(char *cad, char *larga, int &pos) {
    char actual[100];
    int j = 0, maxLen = 0, currentPos = 0, wordPos = 0;
    
    for (int i = 0; i <= strlen(cad); i++) {
        if (!isspace(cad[i]) && cad[i] != '\0') {
            actual[j++] = cad[i];
        } else if (j > 0) {
            actual[j] = '\0';
            if (j > maxLen) {
                maxLen = j;
                strcpy(larga, actual);
                pos = wordPos;
            }
            j = 0;
            wordPos++;
        }
    }
}

void reemplazarPalabra(char *cad, int pos, const char *nueva) {
    char resultado[256] = "";
    char palabra[100];
    int j = 0, wordCount = 0;
    
    for (int i = 0; i <= strlen(cad); i++) {
        if (!isspace(cad[i]) && cad[i] != '\0') {
            palabra[j++] = cad[i];
        } else if (j > 0) {
            palabra[j] = '\0';
            if (wordCount == pos) {
                strcat(resultado, nueva);
            } else {
                strcat(resultado, palabra);
            }
            if (cad[i] == ' ') strcat(resultado, " ");
            j = 0;
            wordCount++;
        }
    }
    strcpy(cad, resultado);
}

void intercambiarLargas(char *cad1, char *cad2) {
    char larga1[100], larga2[100];
    int pos1, pos2;
    
    encontrarMasLarga(cad1, larga1, pos1);
    encontrarMasLarga(cad2, larga2, pos2);
    
    reemplazarPalabra(cad1, pos1, larga2);
    reemplazarPalabra(cad2, pos2, larga1);
}

int main() {
    char cad1[256], cad2[256];
    
    cout << "=== INTERCAMBIAR PALABRAS MÁS LARGAS ===" << endl;
    cout << "Cadena 1: ";
    cin.getline(cad1, 256);
    cout << "Cadena 2: ";
    cin.getline(cad2, 256);
    
    cout << "\nANTES:" << endl;
    cout << "Cadena 1: " << cad1 << endl;
    cout << "Cadena 2: " << cad2 << endl;
    
    intercambiarLargas(cad1, cad2);
    
    cout << "\nDESPUÉS:" << endl;
    cout << "Cadena 1: " << cad1 << endl;
    cout << "Cadena 2: " << cad2 << endl;
    
    return 0;
}
