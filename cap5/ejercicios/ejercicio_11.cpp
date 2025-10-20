/*
 * EJERCICIO 11: Promedio de kilómetros de autos de marca del más antiguo
 * 
 * Descripción (2003-1):
 * Programa que permite ingresar en un arreglo de estructuras los datos de
 * 100 automóviles: marca, color, año de fabricación y cantidad de kilómetros
 * recorridos.
 * 
 * Objetivo:
 * Calcular e imprimir el promedio de kilómetros recorridos de aquellos autos
 * que tengan la misma marca del auto más antiguo.
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int MAX_AUTOS = 100;

// Estructura para representar un automóvil
struct Automovil {
    char marca[20];
    char color[15];
    int yearFabric;
    float kmRecorridos;
};

// Prototipos de funciones
void leerAuto(Automovil &a, int numero);
void ingresarAutos(Automovil autos[], int &n);
void mostrarAuto(const Automovil &a, int numero);
void mostrarTodosAutos(const Automovil autos[], int n);
int encontrarAutoMasAntiguo(const Automovil autos[], int n);
float calcularPromedioKmPorMarca(const Automovil autos[], int n, const char* marca);
void procesarResultados(const Automovil autos[], int n);

int main() {
    Automovil autos[MAX_AUTOS];
    int numAutos;
    
    cout << "========================================\n";
    cout << "  REGISTRO DE AUTOMOVILES\n";
    cout << "========================================\n\n";
    
    // Ingresar datos de los autos
    ingresarAutos(autos, numAutos);
    
    // Mostrar todos los autos
    mostrarTodosAutos(autos, numAutos);
    
    // Procesar y mostrar resultados
    procesarResultados(autos, numAutos);
    
    return 0;
}

// Lee los datos de un automóvil
void leerAuto(Automovil &a, int numero) {
    cout << "\n--- Automovil #" << numero << " ---\n";
    
    cout << "Marca: ";
    cin.getline(a.marca, 20);
    
    cout << "Color: ";
    cin.getline(a.color, 15);
    
    cout << "Año de fabricacion: ";
    cin >> a.yearFabric;
    
    while(a.yearFabric < 1900 || a.yearFabric > 2025) {
        cout << "Año invalido. Ingrese nuevamente: ";
        cin >> a.yearFabric;
    }
    
    cout << "Kilometros recorridos: ";
    cin >> a.kmRecorridos;
    cin.ignore();
    
    while(a.kmRecorridos < 0) {
        cout << "Los km no pueden ser negativos. Ingrese nuevamente: ";
        cin >> a.kmRecorridos;
        cin.ignore();
    }
}

// Ingresa los datos de varios autos
void ingresarAutos(Automovil autos[], int &n) {
    cout << "Ingrese el numero de automoviles (1-" << MAX_AUTOS << "): ";
    cin >> n;
    cin.ignore();
    
    while(n < 1 || n > MAX_AUTOS) {
        cout << "Error. Ingrese un numero valido: ";
        cin >> n;
        cin.ignore();
    }
    
    cout << "\n=== INGRESO DE DATOS ===\n";
    for(int i = 0; i < n; i++) {
        leerAuto(autos[i], i + 1);
    }
}

// Muestra los datos de un auto
void mostrarAuto(const Automovil &a, int numero) {
    cout << "\n--- Auto #" << numero << " ---\n";
    cout << "Marca:       " << a.marca << endl;
    cout << "Color:       " << a.color << endl;
    cout << "Año:         " << a.yearFabric << endl;
    cout << fixed << setprecision(2);
    cout << "Kilometros:  " << a.kmRecorridos << " km" << endl;
}

// Muestra todos los autos
void mostrarTodosAutos(const Automovil autos[], int n) {
    cout << "\n========================================\n";
    cout << "  LISTADO DE AUTOMOVILES\n";
    cout << "========================================\n";
    
    for(int i = 0; i < n; i++) {
        mostrarAuto(autos[i], i + 1);
    }
}

// Encuentra el índice del auto más antiguo
int encontrarAutoMasAntiguo(const Automovil autos[], int n) {
    int indiceMasAntiguo = 0;
    int yearMasAntiguo = autos[0].yearFabric;
    
    for(int i = 1; i < n; i++) {
        if(autos[i].yearFabric < yearMasAntiguo) {
            yearMasAntiguo = autos[i].yearFabric;
            indiceMasAntiguo = i;
        }
    }
    
    return indiceMasAntiguo;
}

// Calcula el promedio de km de autos de una marca específica
float calcularPromedioKmPorMarca(const Automovil autos[], int n, const char* marca) {
    float sumaKm = 0;
    int contador = 0;
    
    // Sumar los km de todos los autos de la marca especificada
    for(int i = 0; i < n; i++) {
        if(strcasecmp(autos[i].marca, marca) == 0) {
            sumaKm += autos[i].kmRecorridos;
            contador++;
        }
    }
    
    // Calcular promedio
    if(contador > 0) {
        return sumaKm / contador;
    } else {
        return 0;
    }
}

// Procesa y muestra los resultados
void procesarResultados(const Automovil autos[], int n) {
    cout << "\n========================================\n";
    cout << "  RESULTADOS DEL ANALISIS\n";
    cout << "========================================\n";
    
    // Encontrar el auto más antiguo
    int indiceAntiguo = encontrarAutoMasAntiguo(autos, n);
    
    cout << "\n--- AUTO MAS ANTIGUO ---\n";
    mostrarAuto(autos[indiceAntiguo], indiceAntiguo + 1);
    
    // Calcular promedio de km de autos de la misma marca
    const char* marcaAntigua = autos[indiceAntiguo].marca;
    float promedioKm = calcularPromedioKmPorMarca(autos, n, marcaAntigua);
    
    cout << "\n--- ANALISIS POR MARCA ---\n";
    cout << "Marca del auto mas antiguo: " << marcaAntigua << endl;
    cout << fixed << setprecision(2);
    cout << "Promedio de km recorridos de autos marca '" << marcaAntigua 
         << "': " << promedioKm << " km\n";
    
    // Contar cuántos autos tienen esa marca
    int contadorMarca = 0;
    for(int i = 0; i < n; i++) {
        if(strcasecmp(autos[i].marca, marcaAntigua) == 0) {
            contadorMarca++;
        }
    }
    cout << "Cantidad de autos de marca '" << marcaAntigua << "': " 
         << contadorMarca << endl;
}
