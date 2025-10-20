/*
 * EJERCICIO 15: Reemplazar subcadena por otra
 */
#include <iostream>
#include <cstring>
using namespace std;

void reemplazarSubcadena(char principal[], const char buscar[], const char reemplazo[]) {
    char resultado[512] = "";
    int lenBuscar = strlen(buscar);
    int i = 0;
    
    while (principal[i] != '\0') {
        // Verificar si coincide la subcadena
        bool coincide = true;
        for (int j = 0; j < lenBuscar; j++) {
            if (principal[i+j] != buscar[j]) {
                coincide = false;
                break;
            }
        }
        
        if (coincide) {
            strcat(resultado, reemplazo);
            i += lenBuscar;
        } else {
            int len = strlen(resultado);
            resultado[len] = principal[i];
            resultado[len+1] = '\0';
            i++;
        }
    }
    
    strcpy(principal, resultado);
}

int main() {
    char principal[512], buscar[100], reemplazo[100];
    
    cout << "Cadena principal: ";
    cin.getline(principal, 512);
    cout << "Subcadena a buscar: ";
    cin.getline(buscar, 100);
    cout << "Reemplazo: ";
    cin.getline(reemplazo, 100);
    
    cout << "\nOriginal: " << principal << endl;
    reemplazarSubcadena(principal, buscar, reemplazo);
    cout << "Resultado: " << principal << endl;
    
    return 0;
}
