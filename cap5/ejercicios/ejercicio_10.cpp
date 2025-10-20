/*
 * EJERCICIO 10: Sistema de mapeo de profundidades marinas
 * 
 * Descripción:
 * La Marina del Perú desea levantar un mapa de las profundidades del mar peruano.
 * Se toman datos: coordenadas x, y de un punto, su profundidad asociada
 * y la fecha en que se realizó la medición.
 * 
 * Funciones implementadas:
 * a) Almacenar toda la información levantada
 * b) Imprimir toda la información levantada
 * c) Encontrar e imprimir los datos de la máxima y mínima profundidad registrados
 */

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_PUNTOS = 100;

// Estructura para representar una fecha
struct Fecha {
    int dia, mes, year;
};

// Estructura para los datos de medición
struct Datos {
    float x, y;         // Coordenadas del punto
    float prof;         // Profundidad en metros
    Fecha dia;          // Fecha de medición
};

// Prototipos de funciones
void almacenarInformacion(Datos datos[], int &n);
void leerDato(Datos &d, int numero);
void leerFecha(Fecha &f);
void imprimirInformacion(const Datos datos[], int n);
void mostrarDato(const Datos &d, int numero);
void mostrarFecha(const Fecha &f);
void encontrarExtremos(const Datos datos[], int n);

int main() {
    Datos mediciones[MAX_PUNTOS];
    int numMediciones = 0;
    int opcion;
    
    cout << "========================================\n";
    cout << "  MAPEO DE PROFUNDIDADES MARINAS\n";
    cout << "  Marina de Guerra del Peru\n";
    cout << "========================================\n";
    
    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Almacenar datos de mediciones\n";
        cout << "2. Imprimir toda la informacion\n";
        cout << "3. Encontrar profundidades extremas\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                almacenarInformacion(mediciones, numMediciones);
                break;
                
            case 2:
                if(numMediciones == 0) {
                    cout << "\nNo hay mediciones registradas.\n";
                } else {
                    imprimirInformacion(mediciones, numMediciones);
                }
                break;
                
            case 3:
                if(numMediciones == 0) {
                    cout << "\nNo hay mediciones registradas.\n";
                } else {
                    encontrarExtremos(mediciones, numMediciones);
                }
                break;
                
            case 0:
                cout << "\nSaliendo del programa...\n";
                break;
                
            default:
                cout << "\nOpcion invalida!\n";
        }
    } while(opcion != 0);
    
    return 0;
}

// Almacena la información de las mediciones
void almacenarInformacion(Datos datos[], int &n) {
    int cantidad;
    
    cout << "\nCuantas mediciones desea registrar? ";
    cin >> cantidad;
    
    if(n + cantidad > MAX_PUNTOS) {
        cout << "Advertencia: Se excede el limite.\n";
        cout << "Solo se pueden agregar " << (MAX_PUNTOS - n) << " mediciones.\n";
        cantidad = MAX_PUNTOS - n;
    }
    
    cout << "\n=== INGRESO DE DATOS ===\n";
    for(int i = 0; i < cantidad; i++) {
        leerDato(datos[n], n + 1);
        n++;
    }
    
    cout << "\nDatos almacenados exitosamente!\n";
}

// Lee los datos de una medición
void leerDato(Datos &d, int numero) {
    cout << "\n--- Punto #" << numero << " ---\n";
    
    cout << "Ingrese coordenadas x, y: ";
    cin >> d.x >> d.y;
    
    cout << "Ingrese profundidad asociada: ";
    cin >> d.prof;
    
    while(d.prof < 0) {
        cout << "Error: La profundidad no puede ser negativa.\n";
        cout << "Ingrese nuevamente: ";
        cin >> d.prof;
    }
    
    cout << "Fecha (dd mm aaaa): ";
    leerFecha(d.dia);
}

// Lee una fecha
void leerFecha(Fecha &f) {
    cin >> f.dia >> f.mes >> f.year;
    
    // Validación básica
    while(f.dia < 1 || f.dia > 31 || f.mes < 1 || f.mes > 12 || f.year < 2000) {
        cout << "Fecha invalida. Ingrese nuevamente (dd mm aaaa): ";
        cin >> f.dia >> f.mes >> f.year;
    }
}

// Imprime toda la información registrada
void imprimirInformacion(const Datos datos[], int n) {
    cout << "\n========================================\n";
    cout << "  IMPRESION DE DATOS\n";
    cout << "========================================\n";
    
    for(int i = 0; i < n; i++) {
        mostrarDato(datos[i], i + 1);
    }
}

// Muestra los datos de una medición
void mostrarDato(const Datos &d, int numero) {
    cout << fixed << setprecision(2);
    cout << "\nCoordenadas (x,y) del punto " << numero << ": " 
         << d.x << ", " << d.y << endl;
    cout << "Profundidad asociada: " << d.prof << " mts." << endl;
    cout << "Fecha: dd mm aaaa: ";
    mostrarFecha(d.dia);
    cout << endl;
}

// Muestra una fecha
void mostrarFecha(const Fecha &f) {
    cout << f.dia << "/" << f.mes << "/" << f.year;
}

// Encuentra y muestra las profundidades máxima y mínima
void encontrarExtremos(const Datos datos[], int n) {
    int indiceMin = 0, indiceMax = 0;
    
    // Buscar índices de profundidades extremas
    for(int i = 1; i < n; i++) {
        if(datos[i].prof < datos[indiceMin].prof) {
            indiceMin = i;
        }
        if(datos[i].prof > datos[indiceMax].prof) {
            indiceMax = i;
        }
    }
    
    cout << "\n========================================\n";
    cout << "  PROFUNDIDADES EXTREMAS\n";
    cout << "========================================\n";
    
    cout << "\n--- PROFUNDIDAD MINIMA ---\n";
    mostrarDato(datos[indiceMin], indiceMin + 1);
    
    cout << "\n--- PROFUNDIDAD MAXIMA ---\n";
    mostrarDato(datos[indiceMax], indiceMax + 1);
}
