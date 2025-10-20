/*
 * EJERCICIO PROPUESTO 1
 * =====================
 * Dada la entrada para el array A: 9, 7, 1, 3, 5, 4, 8, 2
 * Realice una prueba de escritorio empleando los algoritmos de ordenación siguientes:
 * a) Método de la burbuja
 * b) Método de Inserción
 * c) Método de Selección
 * d) Método de Shell
 * e) Método de Quicksort
 *
 * Este programa implementa los 5 métodos de ordenación solicitados
 * y muestra paso a paso cómo cada algoritmo ordena el array dado.
 */

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 8; // Tamaño del array dado en el ejercicio

// Prototipos de funciones
void mostrarArray(int arr[], int n, string titulo);
void copiarArray(int origen[], int destino[], int n);

// Algoritmos de ordenación
void burbuja(int arr[], int n);
void insercion(int arr[], int n);
void seleccion(int arr[], int n);
void shell(int arr[], int n);
void quicksort(int arr[], int izq, int der);

int main() {
    // Array original del ejercicio: 9, 7, 1, 3, 5, 4, 8, 2
    int arrayOriginal[MAX] = {9, 7, 1, 3, 5, 4, 8, 2};
    int arrayTrabajo[MAX];
    
    cout << "\n";
    cout << "================================================================\n";
    cout << "         EJERCICIO 1: ALGORITMOS DE ORDENACION\n";
    cout << "================================================================\n";
    cout << "Array Original: 9, 7, 1, 3, 5, 4, 8, 2\n";
    cout << "================================================================\n\n";
    
    // =====================================================================
    // a) MÉTODO DE LA BURBUJA (BUBBLE SORT)
    // =====================================================================
    cout << "\n--- a) METODO DE LA BURBUJA (BUBBLE SORT) ---\n";
    cout << "Descripcion: Compara elementos adyacentes e intercambia si estan\n";
    cout << "             en orden incorrecto. El elemento mayor 'burbujea'\n";
    cout << "             hacia el final en cada iteracion.\n\n";
    
    copiarArray(arrayOriginal, arrayTrabajo, MAX);
    burbuja(arrayTrabajo, MAX);
    mostrarArray(arrayTrabajo, MAX, "Array ordenado con BURBUJA");
    
    // =====================================================================
    // b) MÉTODO DE INSERCIÓN (INSERTION SORT)
    // =====================================================================
    cout << "\n--- b) METODO DE INSERCION (INSERTION SORT) ---\n";
    cout << "Descripcion: Construye el array ordenado elemento por elemento,\n";
    cout << "             insertando cada nuevo elemento en su posicion correcta.\n\n";
    
    copiarArray(arrayOriginal, arrayTrabajo, MAX);
    insercion(arrayTrabajo, MAX);
    mostrarArray(arrayTrabajo, MAX, "Array ordenado con INSERCION");
    
    // =====================================================================
    // c) MÉTODO DE SELECCIÓN (SELECTION SORT)
    // =====================================================================
    cout << "\n--- c) METODO DE SELECCION (SELECTION SORT) ---\n";
    cout << "Descripcion: Busca el elemento minimo del array y lo coloca en\n";
    cout << "             la primera posicion, luego repite con los restantes.\n\n";
    
    copiarArray(arrayOriginal, arrayTrabajo, MAX);
    seleccion(arrayTrabajo, MAX);
    mostrarArray(arrayTrabajo, MAX, "Array ordenado con SELECCION");
    
    // =====================================================================
    // d) MÉTODO DE SHELL
    // =====================================================================
    cout << "\n--- d) METODO DE SHELL ---\n";
    cout << "Descripcion: Mejora del metodo de insercion. Compara elementos\n";
    cout << "             distantes y reduce progresivamente la distancia.\n\n";
    
    copiarArray(arrayOriginal, arrayTrabajo, MAX);
    shell(arrayTrabajo, MAX);
    mostrarArray(arrayTrabajo, MAX, "Array ordenado con SHELL");
    
    // =====================================================================
    // e) MÉTODO DE QUICKSORTs
    // =====================================================================
    cout << "\n--- e) METODO DE QUICKSORT ---\n";
    cout << "Descripcion: Algoritmo divide y venceras. Selecciona un pivote\n";
    cout << "             y particiona el array en menores y mayores al pivote.\n\n";
    
    copiarArray(arrayOriginal, arrayTrabajo, MAX);
    quicksort(arrayTrabajo, 0, MAX - 1);
    mostrarArray(arrayTrabajo, MAX, "Array ordenado con QUICKSORT");
    
    cout << "\n================================================================\n";
    cout << "              TODOS LOS METODOS COMPLETADOS\n";
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
    cout << titulo << ": ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;
}

/**
 * Copia el contenido de un array a otro
 */
void copiarArray(int origen[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origen[i];
    }
}

// ========================================================================
// ALGORITMO 1: MÉTODO DE LA BURBUJA (BUBBLE SORT)
// ========================================================================
/**
 * Ordena un array usando el método de la burbuja
 * Complejidad: O(n²)
 * 
 * Funcionamiento:
 * - Recorre el array comparando pares de elementos adyacentes
 * - Si están en orden incorrecto, los intercambia
 * - Cada pasada coloca el elemento mayor al final
 * - Repite hasta que no haya intercambios
 */
void burbuja(int arr[], int n) {
    int aux, iteracion = 1;
    bool huboIntercambio;
    
    cout << "Paso a paso del ordenamiento:\n";
    
    // Bucle externo: controla el número de pasadas
    for (int i = 0; i < n - 1; i++) {
        huboIntercambio = false;
        
        // Bucle interno: compara elementos adyacentes
        for (int j = 0; j < n - i - 1; j++) {
            // Si el elemento actual es mayor que el siguiente, intercambiar
            if (arr[j] > arr[j + 1]) {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                huboIntercambio = true;
            }
        }
        
        // Mostrar el estado después de cada iteración
        cout << "Iteracion " << iteracion++ << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
        
        // Si no hubo intercambios, el array ya está ordenado
        if (!huboIntercambio) break;
    }
}

// ========================================================================
// ALGORITMO 2: MÉTODO DE INSERCIÓN (INSERTION SORT)
// ========================================================================
/**
 * Ordena un array usando el método de inserción
 * Complejidad: O(n²)
 * 
 * Funcionamiento:
 * - Divide el array en parte ordenada (izquierda) y no ordenada (derecha)
 * - Toma un elemento de la parte no ordenada
 * - Lo inserta en su posición correcta en la parte ordenada
 * - Desplaza los elementos mayores hacia la derecha
 */
void insercion(int arr[], int n) {
    int aux, j;
    
    cout << "Paso a paso del ordenamiento:\n";
    cout << "Inicial  : ";
    for (int k = 0; k < n; k++) cout << arr[k] << " ";
    cout << endl;
    
    // Comenzamos desde el segundo elemento (índice 1)
    for (int i = 1; i < n; i++) {
        aux = arr[i];  // Elemento a insertar
        j = i - 1;     // Posición del elemento anterior
        
        // Desplazar elementos mayores hacia la derecha
        while (j >= 0 && arr[j] > aux) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Insertar el elemento en su posición correcta
        arr[j + 1] = aux;
        
        // Mostrar el estado después de cada inserción
        cout << "Paso " << i << "    : ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << " (insertado: " << aux << ")" << endl;
    }
}

// ========================================================================
// ALGORITMO 3: MÉTODO DE SELECCIÓN (SELECTION SORT)
// ========================================================================
/**
 * Ordena un array usando el método de selección
 * Complejidad: O(n²)
 * 
 * Funcionamiento:
 * - Busca el elemento mínimo del array
 * - Lo intercambia con el primer elemento
 * - Busca el siguiente mínimo en el resto del array
 * - Lo intercambia con el segundo elemento
 * - Repite hasta ordenar todo el array
 */
void seleccion(int arr[], int n) {
    int menor, posMin, aux;
    
    cout << "Paso a paso del ordenamiento:\n";
    
    // Bucle externo: recorre todo el array
    for (int i = 0; i < n - 1; i++) {
        menor = arr[i];  // Asumimos que el elemento actual es el menor
        posMin = i;      // Guardamos su posición
        
        // Bucle interno: busca el elemento mínimo en el resto del array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < menor) {
                menor = arr[j];
                posMin = j;
            }
        }
        
        // Intercambiar el elemento mínimo encontrado con el elemento en posición i
        if (posMin != i) {
            aux = arr[i];
            arr[i] = arr[posMin];
            arr[posMin] = aux;
        }
        
        // Mostrar el estado después de cada selección
        cout << "Paso " << (i + 1) << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << " (minimo: " << menor << ")" << endl;
    }
}

// ========================================================================
// ALGORITMO 4: MÉTODO DE SHELL
// ========================================================================
/**
 * Ordena un array usando el método de Shell
 * Complejidad: O(n log n) a O(n²) dependiendo de la secuencia de intervalos
 * 
 * Funcionamiento:
 * - Es una generalización del método de inserción
 * - Compara elementos separados por un intervalo (gap)
 * - El intervalo se reduce progresivamente hasta llegar a 1
 * - Cuando el intervalo es 1, es equivalente a inserción pero más eficiente
 */
void shell(int arr[], int n) {
    int intervalo, i, j, aux;
    int paso = 1;
    
    cout << "Paso a paso del ordenamiento:\n";
    
    // Calcular el intervalo inicial (n/2) y reducirlo en cada iteración
    for (intervalo = n / 2; intervalo > 0; intervalo /= 2) {
        cout << "\n--- Intervalo: " << intervalo << " ---\n";
        
        // Realizar inserción con el intervalo actual
        for (i = intervalo; i < n; i++) {
            aux = arr[i];
            
            // Desplazar elementos que son mayores que aux
            for (j = i; j >= intervalo && arr[j - intervalo] > aux; j -= intervalo) {
                arr[j] = arr[j - intervalo];
            }
            
            arr[j] = aux;
        }
        
        // Mostrar el estado después de procesar con este intervalo
        cout << "Resultado: ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

// ========================================================================
// ALGORITMO 5: MÉTODO DE QUICKSORT
// ========================================================================
/**
 * Ordena un array usando el método Quicksort (recursivo)
 * Complejidad: O(n log n) en promedio, O(n²) en el peor caso
 * 
 * Funcionamiento (Divide y Vencerás):
 * - Selecciona un elemento como pivote
 * - Particiona el array: menores a la izquierda, mayores a la derecha
 * - Aplica recursivamente el algoritmo a cada partición
 * - No necesita combinar los resultados (ordenamiento in-place)
 */
void quicksort(int arr[], int izq, int der) {
    int i, j, pivote, aux;
    
    // Caso base: si hay al menos 2 elementos
    if (izq < der) {
        // Elegir el pivote (elemento del medio)
        pivote = arr[(izq + der) / 2];
        
        i = izq;  // Índice que avanza desde la izquierda
        j = der;  // Índice que avanza desde la derecha
        
        // Partición: reorganizar elementos respecto al pivote
        do {
            // Buscar elemento mayor que el pivote desde la izquierda
            while (arr[i] < pivote) i++;
            
            // Buscar elemento menor que el pivote desde la derecha
            while (arr[j] > pivote) j--;
            
            // Si los índices no se han cruzado, intercambiar
            if (i <= j) {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
                i++;
                j--;
            }
        } while (i <= j);
        
        // Llamadas recursivas para ordenar las dos particiones
        if (izq < j) quicksort(arr, izq, j);     // Particionar subarray izquierdo
        if (i < der) quicksort(arr, i, der);     // Particionar subarray derecho
    }
}
