/*
 * EJERCICIO 17: Despiece de dinero (recursivo)
 * 
 * Descripción:
 * El arreglo monedas[] = {200, 100, 50, 20, 10, 5, 1} almacena la denominación
 * de monedas y/o billetes del sistema monetario.
 * 
 * Escribir una función recursiva con el prototipo:
 * int despiece(int monedas[], int n, int valor)
 * 
 * La función recibe una cantidad (entera) de dinero e imprime la cantidad
 * de billetes de cada denominación y el total de ellos.
 * 
 * Ejemplo:
 * Ingrese valor -> 257
 * 1 billete de 200
 * 0 billete de 100
 * 1 billete de 50
 * 0 billete de 20
 * 0 billete de 10
 * 1 billete de 5
 * 2 billete de 1
 * El despiece es de 5 billetes
 */

#include <iostream>
using namespace std;

// Array global con las denominaciones
int monedas[] = {200, 100, 50, 20, 10, 5, 1};
const int NUM_DENOMINACIONES = 7;

// Prototipos de funciones
int despiece(int monedas[], int n, int valor);
int despieceRecursivo(int monedas[], int n, int valor, int pos);

int main() {
    int valor;
    char continuar;
    
    cout << "========================================\n";
    cout << "  DESPIECE DE DINERO (RECURSIVO)\n";
    cout << "========================================\n";
    
    do {
        cout << "\nIngrese valor -> ";
        cin >> valor;
        
        while(valor < 0) {
            cout << "Error: El valor no puede ser negativo.\n";
            cout << "Ingrese valor -> ";
            cin >> valor;
        }
        
        int totalBilletes = despiece(monedas, NUM_DENOMINACIONES, valor);
        
        cout << "\nEl despiece es de " << totalBilletes << " billetes\n";
        
        cout << "\nDesea hacer otro despiece? (s/n): ";
        cin >> continuar;
        
    } while(continuar == 's' || continuar == 'S');
    
    cout << "\nPrograma finalizado.\n";
    return 0;
}

// Función wrapper que inicia la recursión
int despiece(int monedas[], int n, int valor) {
    cout << endl;
    return despieceRecursivo(monedas, n, valor, 0);
}

// Función recursiva para hacer el despiece
// pos: posición actual en el array de monedas
int despieceRecursivo(int monedas[], int n, int valor, int pos) {
    // Caso base: si ya procesamos todas las denominaciones o el valor es 0
    if(pos >= n || valor == 0) {
        return 0;
    }
    
    // Calcular cuántos billetes de esta denominación necesitamos
    int cantidadBilletes = valor / monedas[pos];
    
    // Imprimir la cantidad de billetes de esta denominación
    cout << cantidadBilletes << " billete(s) de " << monedas[pos] << endl;
    
    // Calcular el valor restante
    int valorRestante = valor % monedas[pos];
    
    // Caso recursivo: procesar las siguientes denominaciones
    int billetesRestantes = despieceRecursivo(monedas, n, valorRestante, pos + 1);
    
    // Retornar el total de billetes (los de esta denominación + los del resto)
    return cantidadBilletes + billetesRestantes;
}
