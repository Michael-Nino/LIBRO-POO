/*
 * EJERCICIO 21: Comparar si dos números son iguales (recursivo)
 * 
 * Descripción (2011-1):
 * Escribir el código de la función recursiva cuyo prototipo es:
 * bool iguales(int x, int y);
 * 
 * Los parámetros x e y reciben dos números enteros positivos (inclusive cero)
 * que tienen la misma cantidad de dígitos. La función devuelve true si dichos
 * números son iguales y false en caso contrario.
 * 
 * Ejemplos:
 * - iguales(12345, 12345) = true
 * - iguales(12345, 12346) = false
 * - iguales(0, 0) = true
 * 
 * Algoritmo recursivo:
 * Comparar dígito por dígito desde el menos significativo
 */

#include <iostream>
using namespace std;

// Prototipos de funciones
bool iguales(int x, int y);
int contarDigitos(int n);

int main() {
    int num1, num2;
    char continuar;
    
    cout << "========================================\n";
    cout << "  COMPARAR NUMEROS (RECURSIVO)\n";
    cout << "========================================\n";
    
    do {
        cout << "\nIngrese el primer numero (>= 0): ";
        cin >> num1;
        
        while(num1 < 0) {
            cout << "Error: Ingrese un numero no negativo: ";
            cin >> num1;
        }
        
        cout << "Ingrese el segundo numero (>= 0): ";
        cin >> num2;
        
        while(num2 < 0) {
            cout << "Error: Ingrese un numero no negativo: ";
            cin >> num2;
        }
        
        // Verificar que tengan la misma cantidad de dígitos
        if(contarDigitos(num1) != contarDigitos(num2)) {
            cout << "\nADVERTENCIA: Los numeros no tienen la misma cantidad de digitos.\n";
            cout << num1 << " tiene " << contarDigitos(num1) << " digito(s)\n";
            cout << num2 << " tiene " << contarDigitos(num2) << " digito(s)\n";
        }
        
        bool sonIguales = iguales(num1, num2);
        
        cout << "\nResultado: Los numeros " << num1 << " y " << num2;
        if(sonIguales) {
            cout << " SON IGUALES\n";
        } else {
            cout << " NO son iguales\n";
        }
        
        cout << "\nDesea comparar otros numeros? (s/n): ";
        cin >> continuar;
        
    } while(continuar == 's' || continuar == 'S');
    
    cout << "\nPrograma finalizado.\n";
    return 0;
}

// Función auxiliar para contar dígitos
int contarDigitos(int n) {
    if(n == 0) return 1;
    int count = 0;
    while(n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

// Función recursiva que compara si dos números son iguales
bool iguales(int x, int y) {
    // Caso base: si ambos son 0, son iguales
    if(x == 0 && y == 0) {
        return true;
    }
    
    // Caso base: si uno es 0 y el otro no, no son iguales
    if(x == 0 || y == 0) {
        return false;
    }
    
    // Comparar los últimos dígitos
    int ultimoDigitoX = x % 10;
    int ultimoDigitoY = y % 10;
    
    // Si los últimos dígitos son diferentes, no son iguales
    if(ultimoDigitoX != ultimoDigitoY) {
        return false;
    }
    
    // Caso recursivo: si los últimos dígitos son iguales,
    // comparar el resto de los números
    return iguales(x / 10, y / 10);
}
