/*
 * EJERCICIO 22: Contar dígitos pares en posiciones impares (recursivo)
 * 
 * Descripción:
 * Escribir una función recursiva que determine cuántos dígitos pares ocupan
 * posiciones impares (de izquierda a derecha) en un número natural.
 * 
 * Ejemplos:
 * - Para 3231: resultado es 0 (no hay dígitos pares en posiciones impares)
 *   Posiciones: 1(3) 2(2) 3(3) 4(1) - pos 1 y 3 son impares pero tienen 3 y 3
 * 
 * - Para 2233: resultado es 1 (el 2 en posición 1)
 *   Posiciones: 1(2*) 2(2) 3(3) 4(3)
 * 
 * - Para 22768: resultado es 2 (el 2 en pos 1 y el 6 en pos 3)
 *   Posiciones: 1(2*) 2(2) 3(6*) 4(8) 5(8)
 * 
 * Nota: Las posiciones se cuentan de izquierda a derecha empezando desde 1
 */

#include <iostream>
#include <cmath>
using namespace std;

// Prototipos de funciones
int contarDigitos(int n);
int contarParesEnPosImpares(int n);
int contarParesEnPosImparesRec(int n, int longitud, int posActual);

int main() {
    int numero;
    char continuar;
    
    cout << "========================================\n";
    cout << "  DIGITOS PARES EN POSICIONES IMPARES\n";
    cout << "  (RECURSIVO)\n";
    cout << "========================================\n";
    
    do {
        cout << "\nIngrese un numero natural: ";
        cin >> numero;
        
        while(numero < 0) {
            cout << "Error: Ingrese un numero no negativo: ";
            cin >> numero;
        }
        
        int resultado = contarParesEnPosImpares(numero);
        
        cout << "\nEl numero " << numero << " tiene " << resultado 
             << " digito(s) par(es) en posiciones impares.\n";
        
        cout << "\nDesea analizar otro numero? (s/n): ";
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

// Función wrapper que inicia la recursión
int contarParesEnPosImpares(int n) {
    int longitud = contarDigitos(n);
    return contarParesEnPosImparesRec(n, longitud, 1);
}

// Función recursiva que cuenta dígitos pares en posiciones impares
// n: número a analizar
// longitud: cantidad total de dígitos
// posActual: posición actual (de izquierda a derecha, empezando en 1)
int contarParesEnPosImparesRec(int n, int longitud, int posActual) {
    // Caso base: si no hay más dígitos, retornar 0
    if(n == 0 && posActual > longitud) {
        return 0;
    }
    
    // Calcular el divisor para extraer el dígito en la posición actual
    // Por ejemplo, para el número 22768 (longitud=5):
    // - Para posición 1: divisor = 10^4 = 10000, dígito = 22768/10000 = 2
    // - Para posición 2: divisor = 10^3 = 1000, dígito = 2276/1000 = 2
    int divisor = pow(10, longitud - posActual);
    
    if(divisor == 0) {
        return 0;
    }
    
    // Extraer el dígito en la posición actual
    int digito = n / divisor;
    
    // Eliminar el dígito extraído del número
    int restoNumero = n % divisor;
    
    // Contar si este dígito cumple la condición
    int cuenta = 0;
    if(posActual % 2 != 0 && digito % 2 == 0) {
        // La posición es impar Y el dígito es par
        cuenta = 1;
    }
    
    // Caso recursivo: sumar con el resultado del resto del número
    return cuenta + contarParesEnPosImparesRec(restoNumero, longitud, posActual + 1);
}
