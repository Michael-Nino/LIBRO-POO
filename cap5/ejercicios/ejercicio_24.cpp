/*
 * EJERCICIO 24: Dígitos pares en posiciones impares - Versión alternativa
 * 
 * NOTA: Este ejercicio es una versión mejorada del ejercicio 22 con mejor
 * explicación y ejemplos adicionales.
 * 
 * Descripción:
 * Escribir una función recursiva que determine cuántos dígitos pares ocupan
 * posiciones impares (de izquierda a derecha) en un número natural.
 * 
 * Posiciones (de izquierda a derecha, empezando en 1):
 * - Para 3231: pos 1→3, pos 2→2, pos 3→3, pos 4→1
 *   Dígitos pares en pos impares: ninguno → Resultado: 0
 * 
 * - Para 2233: pos 1→2(par✓), pos 2→2, pos 3→3, pos 4→3
 *   Dígitos pares en pos impares: 2 en pos 1 → Resultado: 1
 * 
 * - Para 22768: pos 1→2(par✓), pos 2→2, pos 3→6(par✓), pos 4→6, pos 5→8
 *   Dígitos pares en pos impares: 2 en pos 1, 6 en pos 3 → Resultado: 2
 * 
 * - Para 2468: pos 1→2(par✓), pos 2→4, pos 3→6(par✓), pos 4→8
 *   Dígitos pares en pos impares: 2 en pos 1, 6 en pos 3 → Resultado: 2
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Prototipos de funciones
int contarDigitos(int n);
int digitoEnPosicion(int n, int pos, int longitud);
int contarParesEnPosImpares(int n);
int contarParesEnPosImparesRec(int n, int longitud, int pos);
void mostrarAnalisisDetallado(int n);

int main() {
    int numero;
    char continuar;
    
    cout << "========================================\n";
    cout << "  DIGITOS PARES EN POSICIONES IMPARES\n";
    cout << "  Version mejorada con analisis\n";
    cout << "========================================\n";
    
    do {
        cout << "\nIngrese un numero natural: ";
        cin >> numero;
        
        while(numero < 0) {
            cout << "Error: Ingrese un numero no negativo: ";
            cin >> numero;
        }
        
        // Mostrar análisis detallado
        mostrarAnalisisDetallado(numero);
        
        // Calcular resultado
        int resultado = contarParesEnPosImpares(numero);
        
        cout << "\n========================================\n";
        cout << "RESULTADO: " << resultado << " digito(s) par(es) en posiciones impares\n";
        cout << "========================================\n";
        
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

// Extrae el dígito en una posición específica (1-indexed, de izq a der)
int digitoEnPosicion(int n, int pos, int longitud) {
    int divisor = pow(10, longitud - pos);
    return (n / divisor) % 10;
}

// Muestra un análisis detallado del número
void mostrarAnalisisDetallado(int n) {
    int longitud = contarDigitos(n);
    
    cout << "\n--- ANALISIS DEL NUMERO " << n << " ---\n";
    cout << "Longitud: " << longitud << " digitos\n\n";
    cout << "Pos | Digito | Pos Impar? | Digito Par? | Cuenta?\n";
    cout << "----+--------+------------+-------------+---------\n";
    
    for(int pos = 1; pos <= longitud; pos++) {
        int digito = digitoEnPosicion(n, pos, longitud);
        bool posImpar = (pos % 2 != 0);
        bool digitoPar = (digito % 2 == 0);
        bool cuenta = posImpar && digitoPar;
        
        cout << setw(3) << pos << " | "
             << setw(6) << digito << " | "
             << setw(10) << (posImpar ? "SI" : "NO") << " | "
             << setw(11) << (digitoPar ? "SI" : "NO") << " | "
             << setw(7) << (cuenta ? "SI ✓" : "NO") << "\n";
    }
}

// Función wrapper que inicia la recursión
int contarParesEnPosImpares(int n) {
    int longitud = contarDigitos(n);
    return contarParesEnPosImparesRec(n, longitud, 1);
}

// Función recursiva que cuenta dígitos pares en posiciones impares
int contarParesEnPosImparesRec(int n, int longitud, int pos) {
    // Caso base: si hemos procesado todas las posiciones
    if(pos > longitud) {
        return 0;
    }
    
    // Extraer el dígito en la posición actual
    int digito = digitoEnPosicion(n, pos, longitud);
    
    // Verificar si cumple la condición
    int cuenta = 0;
    if(pos % 2 != 0 && digito % 2 == 0) {
        // La posición es impar Y el dígito es par
        cuenta = 1;
    }
    
    // Caso recursivo: sumar con el resultado de las siguientes posiciones
    return cuenta + contarParesEnPosImparesRec(n, longitud, pos + 1);
}
