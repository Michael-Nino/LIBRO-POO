/*
 * EJERCICIO 20: Quitar espacios al inicio y final de una cadena (recursivo)
 * 
 * Descripción:
 * Escribir una función recursiva que reciba una cadena s y proceda a quitar
 * los espacios en blanco que contiene al inicio y al final de la cadena.
 * 
 * Por ejemplo:
 * Si la cadena s = "   cadena recursiva   "
 * La función devuelve "cadena recursiva"
 * 
 * Algoritmo:
 * 1. Eliminar espacios del inicio recursivamente
 * 2. Eliminar espacios del final recursivamente
 */

#include <iostream>
#include <cstring>
using namespace std;

// Prototipos de funciones
void quitarEspacios(char s[]);
void quitarEspaciosInicio(char s[]);
void quitarEspaciosFinal(char s[]);

int main() {
    char cadena[200];
    char continuar;
    
    cout << "========================================\n";
    cout << "  QUITAR ESPACIOS (RECURSIVO)\n";
    cout << "========================================\n";
    
    // Limpiar el buffer antes de la primera lectura
    cin.ignore();
    
    do {
        cout << "\nIngrese una cadena (puede tener espacios al inicio/final):\n";
        cout << "-> ";
        cin.getline(cadena, 200);
        
        cout << "\nCadena original: [" << cadena << "]" << endl;
        cout << "Longitud: " << strlen(cadena) << " caracteres\n";
        
        quitarEspacios(cadena);
        
        cout << "\nCadena procesada: [" << cadena << "]" << endl;
        cout << "Longitud: " << strlen(cadena) << " caracteres\n";
        
        cout << "\nDesea procesar otra cadena? (s/n): ";
        cin >> continuar;
        cin.ignore(); // Limpiar el buffer
        
    } while(continuar == 's' || continuar == 'S');
    
    cout << "\nPrograma finalizado.\n";
    return 0;
}

// Función principal que elimina espacios al inicio y al final
void quitarEspacios(char s[]) {
    quitarEspaciosInicio(s);
    quitarEspaciosFinal(s);
}

// Función recursiva que elimina espacios al inicio de la cadena
void quitarEspaciosInicio(char s[]) {
    // Caso base: si la cadena está vacía o no empieza con espacio, terminamos
    if(s[0] == '\0' || s[0] != ' ') {
        return;
    }
    
    // Caso recursivo: desplazar todos los caracteres una posición a la izquierda
    int i = 0;
    while(s[i] != '\0') {
        s[i] = s[i + 1];
        i++;
    }
    
    // Llamada recursiva para eliminar más espacios si es necesario
    quitarEspaciosInicio(s);
}

// Función recursiva que elimina espacios al final de la cadena
void quitarEspaciosFinal(char s[]) {
    int len = strlen(s);
    
    // Caso base: si la cadena está vacía o no termina con espacio, terminamos
    if(len == 0 || s[len - 1] != ' ') {
        return;
    }
    
    // Caso recursivo: eliminar el último carácter (que es un espacio)
    s[len - 1] = '\0';
    
    // Llamada recursiva para eliminar más espacios si es necesario
    quitarEspaciosFinal(s);
}
