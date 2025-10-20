/*
 * EJERCICIO PROPUESTO 2
 * =====================
 * Use los algoritmos de búsqueda para encontrar un elemento para el array
 * del problema anterior.
 * 
 * Array: 9, 7, 1, 3, 5, 4, 8, 2
 * 
 * Este programa implementa dos algoritmos de búsqueda:
 * a) Búsqueda Secuencial (Lineal)
 * b) Búsqueda Binaria (requiere array ordenado)
 * 
 * Se realizarán búsquedas de varios elementos tanto existentes como
 * no existentes para demostrar el funcionamiento de ambos algoritmos.
 */

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 8; // Tamaño del array

// Prototipos de funciones
void mostrarArray(int arr[], int n, string titulo);
void copiarArray(int origen[], int destino[], int n);
void ordenarArray(int arr[], int n);

// Algoritmos de búsqueda
int busquedaSecuencial(int arr[], int n, int clave);
int busquedaBinaria(int arr[], int n, int clave);
int busquedaBinariaRecursiva(int arr[], int izq, int der, int clave);

int main() {
    // Array original del ejercicio: 9, 7, 1, 3, 5, 4, 8, 2
    int arrayOriginal[MAX] = {9, 7, 1, 3, 5, 4, 8, 2};
    int arrayOrdenado[MAX];
    
    // Elementos a buscar (algunos existen, otros no)
    int elementosBuscar[] = {5, 9, 1, 10, 7, 15, 4, 0};
    int numBusquedas = 8;
    
    cout << "\n";
    cout << "================================================================\n";
    cout << "         EJERCICIO 2: ALGORITMOS DE BUSQUEDA\n";
    cout << "================================================================\n";
    mostrarArray(arrayOriginal, MAX, "Array Original");
    cout << "================================================================\n\n";
    
    // =====================================================================
    // PARTE A: BÚSQUEDA SECUENCIAL (LINEAL)
    // =====================================================================
    cout << "\n╔════════════════════════════════════════════════════════════════╗\n";
    cout << "║   a) BUSQUEDA SECUENCIAL (LINEAL)                             ║\n";
    cout << "╚════════════════════════════════════════════════════════════════╝\n";
    cout << "\nDescripcion:\n";
    cout << "- Recorre el array elemento por elemento desde el inicio\n";
    cout << "- Compara cada elemento con el valor buscado\n";
    cout << "- Se detiene cuando encuentra el elemento o llega al final\n";
    cout << "- NO requiere que el array este ordenado\n";
    cout << "- Complejidad: O(n)\n\n";
    
    mostrarArray(arrayOriginal, MAX, "Array a buscar (desordenado)");
    cout << "\n--- Realizando busquedas ---\n\n";
    
    for (int i = 0; i < numBusquedas; i++) {
        int clave = elementosBuscar[i];
        int resultado = busquedaSecuencial(arrayOriginal, MAX, clave);
        
        cout << "Buscar: " << setw(2) << clave << " -> ";
        if (resultado != -1) {
            cout << "✓ ENCONTRADO en indice " << resultado;
            cout << " (posicion " << (resultado + 1) << ")";
        } else {
            cout << "✗ NO ENCONTRADO";
        }
        cout << endl;
    }
    
    // =====================================================================
    // PARTE B: BÚSQUEDA BINARIA (VERSION ITERATIVA)
    // =====================================================================
    cout << "\n╔════════════════════════════════════════════════════════════════╗\n";
    cout << "║   b) BUSQUEDA BINARIA - Version Iterativa                     ║\n";
    cout << "╚════════════════════════════════════════════════════════════════╝\n";
    cout << "\nDescripcion:\n";
    cout << "- Divide el array por la mitad en cada iteracion\n";
    cout << "- Compara el elemento del medio con el valor buscado\n";
    cout << "- Descarta la mitad donde no puede estar el elemento\n";
    cout << "- REQUIERE que el array este ORDENADO\n";
    cout << "- Complejidad: O(log n)\n\n";
    
    // Ordenar el array para búsqueda binaria
    copiarArray(arrayOriginal, arrayOrdenado, MAX);
    ordenarArray(arrayOrdenado, MAX);
    
    mostrarArray(arrayOrdenado, MAX, "Array a buscar (ordenado)");
    cout << "\n--- Realizando busquedas ---\n\n";
    
    for (int i = 0; i < numBusquedas; i++) {
        int clave = elementosBuscar[i];
        int resultado = busquedaBinaria(arrayOrdenado, MAX, clave);
        
        cout << "Buscar: " << setw(2) << clave << " -> ";
        if (resultado != -1) {
            cout << "✓ ENCONTRADO en indice " << resultado;
            cout << " (posicion " << (resultado + 1) << ")";
        } else {
            cout << "✗ NO ENCONTRADO";
        }
        cout << endl;
    }
    
    // =====================================================================
    // PARTE C: BÚSQUEDA BINARIA (VERSION RECURSIVA)
    // =====================================================================
    cout << "\n╔════════════════════════════════════════════════════════════════╗\n";
    cout << "║   c) BUSQUEDA BINARIA - Version Recursiva                     ║\n";
    cout << "╚════════════════════════════════════════════════════════════════╝\n";
    cout << "\nDescripcion:\n";
    cout << "- Misma logica que la version iterativa\n";
    cout << "- Implementada usando recursion en lugar de bucles\n";
    cout << "- Cada llamada recursiva reduce el rango de busqueda\n";
    cout << "- REQUIERE que el array este ORDENADO\n";
    cout << "- Complejidad: O(log n)\n\n";
    
    mostrarArray(arrayOrdenado, MAX, "Array a buscar (ordenado)");
    cout << "\n--- Realizando busquedas ---\n\n";
    
    for (int i = 0; i < numBusquedas; i++) {
        int clave = elementosBuscar[i];
        int resultado = busquedaBinariaRecursiva(arrayOrdenado, 0, MAX - 1, clave);
        
        cout << "Buscar: " << setw(2) << clave << " -> ";
        if (resultado != -1) {
            cout << "✓ ENCONTRADO en indice " << resultado;
            cout << " (posicion " << (resultado + 1) << ")";
        } else {
            cout << "✗ NO ENCONTRADO";
        }
        cout << endl;
    }
    
    // =====================================================================
    // COMPARACIÓN DE RENDIMIENTO
    // =====================================================================
    cout << "\n╔════════════════════════════════════════════════════════════════╗\n";
    cout << "║   COMPARACION DE ALGORITMOS                                   ║\n";
    cout << "╚════════════════════════════════════════════════════════════════╝\n\n";
    
    cout << "┌──────────────────────┬─────────────┬─────────────┬──────────────┐\n";
    cout << "│ Algoritmo            │ Complejidad │ Requiere    │ Mejor para   │\n";
    cout << "│                      │             │ Ordenado    │              │\n";
    cout << "├──────────────────────┼─────────────┼─────────────┼──────────────┤\n";
    cout << "│ Busqueda Secuencial  │    O(n)     │     NO      │ Arrays       │\n";
    cout << "│                      │             │             │ pequeños     │\n";
    cout << "├──────────────────────┼─────────────┼─────────────┼──────────────┤\n";
    cout << "│ Busqueda Binaria     │  O(log n)   │     SI      │ Arrays       │\n";
    cout << "│ (Iterativa/Recursiva)│             │             │ grandes      │\n";
    cout << "└──────────────────────┴─────────────┴─────────────┴──────────────┘\n\n";
    
    cout << "================================================================\n";
    cout << "              TODAS LAS BUSQUEDAS COMPLETADAS\n";
    cout << "================================================================\n\n";
    
    return 0;
}

// ========================================================================
// FUNCIONES AUXILIARES
// ========================================================================

/**
 * Muestra el contenido de un array con un título
 */
void mostrarArray(int arr[], int n, string titulo) {
    cout << titulo << ": [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;
}

/**
 * Copia el contenido de un array a otro
 */
void copiarArray(int origen[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origen[i];
    }
}

/**
 * Ordena un array usando el método de burbuja
 * (usado para preparar el array para búsqueda binaria)
 */
void ordenarArray(int arr[], int n) {
    int aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

// ========================================================================
// ALGORITMO 1: BÚSQUEDA SECUENCIAL (LINEAL)
// ========================================================================
/**
 * Realiza una búsqueda secuencial en un array
 * 
 * @param arr - Array donde buscar
 * @param n - Tamaño del array
 * @param clave - Elemento a buscar
 * @return Índice del elemento encontrado, o -1 si no existe
 * 
 * Complejidad: O(n)
 * - Mejor caso: O(1) - elemento en la primera posición
 * - Peor caso: O(n) - elemento al final o no existe
 * - Caso promedio: O(n/2) ≈ O(n)
 * 
 * Ventajas:
 * - Funciona con arrays desordenados
 * - Simple de implementar
 * - No requiere procesamiento previo
 * 
 * Desventajas:
 * - Lento para arrays grandes
 * - Siempre revisa todos los elementos en el peor caso
 */
int busquedaSecuencial(int arr[], int n, int clave) {
    int i = 0;
    
    // Recorrer el array hasta encontrar el elemento o llegar al final
    while (i < n && arr[i] != clave) {
        i++;
    }
    
    // Si llegamos al final sin encontrar, retornar -1
    // Si encontramos el elemento, retornar su índice
    return (i == n) ? -1 : i;
}

// ========================================================================
// ALGORITMO 2: BÚSQUEDA BINARIA - VERSION ITERATIVA
// ========================================================================
/**
 * Realiza una búsqueda binaria en un array ORDENADO (versión iterativa)
 * 
 * @param arr - Array ORDENADO donde buscar
 * @param n - Tamaño del array
 * @param clave - Elemento a buscar
 * @return Índice del elemento encontrado, o -1 si no existe
 * 
 * Complejidad: O(log n)
 * - Mejor caso: O(1) - elemento en el medio
 * - Peor caso: O(log n) - necesita todas las divisiones
 * - Caso promedio: O(log n)
 * 
 * Precondición: El array DEBE estar ordenado
 * 
 * Funcionamiento:
 * 1. Calcula el índice del medio
 * 2. Compara el elemento del medio con la clave
 * 3. Si son iguales, retorna el índice
 * 4. Si la clave es menor, busca en la mitad izquierda
 * 5. Si la clave es mayor, busca en la mitad derecha
 * 6. Repite hasta encontrar o agotar el rango
 */
int busquedaBinaria(int arr[], int n, int clave) {
    int izq = 0;        // Límite izquierdo del rango de búsqueda
    int der = n - 1;    // Límite derecho del rango de búsqueda
    int mitad;          // Índice del elemento del medio
    
    // Mientras el rango de búsqueda sea válido
    while (izq <= der) {
        // Calcular el índice del medio
        mitad = (izq + der) / 2;
        
        // Caso 1: Elemento del medio es menor que la clave
        // Buscar en la mitad derecha
        if (arr[mitad] < clave) {
            izq = mitad + 1;
        }
        // Caso 2: Elemento del medio es mayor que la clave
        // Buscar en la mitad izquierda
        else if (arr[mitad] > clave) {
            der = mitad - 1;
        }
        // Caso 3: Elemento encontrado
        else {
            return mitad;
        }
    }
    
    // Elemento no encontrado
    return -1;
}

// ========================================================================
// ALGORITMO 3: BÚSQUEDA BINARIA - VERSION RECURSIVA
// ========================================================================
/**
 * Realiza una búsqueda binaria en un array ORDENADO (versión recursiva)
 * 
 * @param arr - Array ORDENADO donde buscar
 * @param izq - Índice izquierdo del rango actual
 * @param der - Índice derecho del rango actual
 * @param clave - Elemento a buscar
 * @return Índice del elemento encontrado, o -1 si no existe
 * 
 * Complejidad: O(log n) - igual que la versión iterativa
 * 
 * Precondición: El array DEBE estar ordenado
 * 
 * Funcionamiento:
 * - Cada llamada recursiva reduce el rango de búsqueda a la mitad
 * - Caso base: cuando izq > der, el elemento no existe
 * - Caso recursivo: buscar en la mitad correspondiente
 * 
 * Ventajas de la versión recursiva:
 * - Código más elegante y fácil de entender
 * - Refleja claramente la naturaleza "divide y vencerás"
 * 
 * Desventajas de la versión recursiva:
 * - Usa más memoria (pila de llamadas)
 * - Puede causar stack overflow con arrays muy grandes
 */
int busquedaBinariaRecursiva(int arr[], int izq, int der, int clave) {
    // Caso base: rango inválido, elemento no encontrado
    if (izq > der) {
        return -1;
    }
    
    // Calcular el índice del medio
    int mitad = (izq + der) / 2;
    
    // Caso base: elemento encontrado
    if (arr[mitad] == clave) {
        return mitad;
    }
    
    // Caso recursivo 1: clave menor que el elemento del medio
    // Buscar en la mitad izquierda
    if (clave < arr[mitad]) {
        return busquedaBinariaRecursiva(arr, izq, mitad - 1, clave);
    }
    // Caso recursivo 2: clave mayor que el elemento del medio
    // Buscar en la mitad derecha
    else {
        return busquedaBinariaRecursiva(arr, mitad + 1, der, clave);
    }
}

// ========================================================================
// NOTAS ADICIONALES SOBRE LOS ALGORITMOS
// ========================================================================
/*
 * CUANDO USAR CADA ALGORITMO:
 * 
 * BUSQUEDA SECUENCIAL:
 * - Arrays pequeños (< 100 elementos)
 * - Arrays desordenados
 * - Cuando el costo de ordenar supera el beneficio
 * - Búsquedas poco frecuentes
 * 
 * BUSQUEDA BINARIA:
 * - Arrays grandes (> 100 elementos)
 * - Arrays ya ordenados o que se van a buscar múltiples veces
 * - Cuando se justifica el costo de ordenar
 * - Búsquedas frecuentes
 * 
 * EJEMPLO DE COMPARACION:
 * Para un array de 1,000,000 elementos:
 * - Búsqueda Secuencial: hasta 1,000,000 comparaciones
 * - Búsqueda Binaria: máximo 20 comparaciones (log₂ 1,000,000 ≈ 20)
 * 
 * ¡La diferencia es ENORME para arrays grandes!
 */
