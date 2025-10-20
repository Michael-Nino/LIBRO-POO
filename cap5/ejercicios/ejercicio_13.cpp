/*
 * EJERCICIO 13: Posición del menor elemento de un array (recursivo)
 * 
 * Descripción:
 * Implementar una función que reciba como parámetros un arreglo y el tamaño
 * de este, y que en forma recursiva devuelva la posición del menor elemento
 * del array.
 * 
 * Algoritmo recursivo:
 * - Caso base: si solo hay un elemento, ese es el menor
 * - Caso recursivo: comparar el primer elemento con el menor del resto
 */

#include <iostream>
#include <iomanip>
using namespace std;

// Prototipos de funciones
int posicionMenor(int arr[], int n);
int posicionMenorRecursivo(int arr[], int n, int pos);
void leerArray(int arr[], int n);
void mostrarArray(int arr[], int n);

int main() {
    int n;
    
    cout << "========================================\n";
    cout << "  MENOR ELEMENTO (RECURSIVO)\n";
    cout << "========================================\n";
    
    cout << "\nIngrese el tamaño del arreglo: ";
    cin >> n;
    
    while(n <= 0 || n > 100) {
        cout << "Error: Tamaño invalido. Ingrese nuevamente: ";
        cin >> n;
    }
    
    int* arr = new int[n];
    
    // Leer el array
    leerArray(arr, n);
    
    // Mostrar el array
    cout << "\nArreglo ingresado:\n";
    mostrarArray(arr, n);
    
    // Encontrar la posición del menor elemento
    int posMenor = posicionMenor(arr, n);
    
    cout << "\n========================================\n";
    cout << "  RESULTADO\n";
    cout << "========================================\n";
    cout << "El elemento menor es: " << arr[posMenor] << endl;
    cout << "Se encuentra en la posicion: " << posMenor << endl;
    cout << "(Posicion 0 es la primera)\n";
    
    delete[] arr;
    return 0;
}

// Función wrapper para iniciar la recursión
int posicionMenor(int arr[], int n) {
    if(n <= 0) return -1;
    return posicionMenorRecursivo(arr, n, 0);
}

// Función recursiva que encuentra la posición del menor elemento
// pos: posición actual que estamos analizando
int posicionMenorRecursivo(int arr[], int n, int pos) {
    // Caso base: si llegamos al último elemento, esa es la posición del menor
    if(pos == n - 1) {
        return pos;
    }
    
    // Caso recursivo:
    // 1. Encontrar la posición del menor en el resto del array
    int posMenorResto = posicionMenorRecursivo(arr, n, pos + 1);
    
    // 2. Comparar el elemento actual con el menor del resto
    if(arr[pos] < arr[posMenorResto]) {
        return pos;  // El actual es menor
    } else {
        return posMenorResto;  // El menor está en el resto
    }
}

// Lee los elementos del array
void leerArray(int arr[], int n) {
    cout << "\nIngrese los " << n << " elementos del arreglo:\n";
    for(int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> arr[i];
    }
}

// Muestra los elementos del array
void mostrarArray(int arr[], int n) {
    cout << "[";
    for(int i = 0; i < n; i++) {
        cout << arr[i];
        if(i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}
