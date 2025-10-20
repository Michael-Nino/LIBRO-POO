/*
 * EJERCICIO 5: Sistema de registro de infracciones de tránsito
 * 
 * Descripción:
 * La Policía Nacional lleva el registro de vehículos que cometen infracciones
 * de tránsito mensualmente. Se requiere un programa para:
 * 
 * a) Almacenar los datos de infracciones
 * b) Mostrar la información procesada
 * c) Mostrar vehículos de una determinada marca y cantidad
 * d) Determinar el vehículo con la multa más alta
 * 
 * Datos registrados:
 * - NroPlaca: 10 caracteres
 * - Marca: 15 caracteres
 * - Color: 15 caracteres
 * - FechaInfra: 12 caracteres
 * - Distrito: 25 caracteres
 * - MultaPagar: flotante
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int MAX_INFRACCIONES = 100;

// Estructura para representar una infracción de tránsito
struct Infraccion {
    char nroPlaca[11];        // Número de placa
    char marca[16];           // Marca del vehículo
    char color[16];           // Color del vehículo
    char fechaInfra[13];      // Fecha de la infracción
    char distrito[26];        // Distrito donde ocurrió
    float multaPagar;         // Monto de la multa
};

// Prototipos de funciones
void almacenarDatos(Infraccion infracciones[], int &n);
void leerInfraccion(Infraccion &inf);
void mostrarInformacion(const Infraccion infracciones[], int n);
void mostrarInfraccion(const Infraccion &inf, int numero);
void buscarPorMarca(const Infraccion infracciones[], int n, const char* marca);
int encontrarMultaMasAlta(const Infraccion infracciones[], int n);

int main() {
    Infraccion infracciones[MAX_INFRACCIONES];
    int numInfracciones = 0;
    int opcion;
    char marca[16];
    
    cout << "========================================\n";
    cout << "  REGISTRO DE INFRACCIONES DE TRANSITO\n";
    cout << "========================================\n";
    
    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Almacenar datos de infracciones\n";
        cout << "2. Mostrar toda la informacion\n";
        cout << "3. Buscar vehiculos por marca\n";
        cout << "4. Vehiculo con multa mas alta\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        
        switch(opcion) {
            case 1:
                almacenarDatos(infracciones, numInfracciones);
                break;
                
            case 2:
                if(numInfracciones == 0) {
                    cout << "\nNo hay infracciones registradas.\n";
                } else {
                    mostrarInformacion(infracciones, numInfracciones);
                }
                break;
                
            case 3:
                if(numInfracciones == 0) {
                    cout << "\nNo hay infracciones registradas.\n";
                } else {
                    cout << "\nIngrese la marca a buscar: ";
                    cin.getline(marca, 16);
                    buscarPorMarca(infracciones, numInfracciones, marca);
                }
                break;
                
            case 4:
                if(numInfracciones == 0) {
                    cout << "\nNo hay infracciones registradas.\n";
                } else {
                    int indice = encontrarMultaMasAlta(infracciones, numInfracciones);
                    cout << "\n=== VEHICULO CON MULTA MAS ALTA ===\n";
                    mostrarInfraccion(infracciones[indice], indice + 1);
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

// Almacena los datos de las infracciones
void almacenarDatos(Infraccion infracciones[], int &n) {
    int cantidad;
    
    cout << "\nCuantas infracciones desea registrar? ";
    cin >> cantidad;
    cin.ignore();
    
    if(n + cantidad > MAX_INFRACCIONES) {
        cout << "Error: Se excede el limite maximo.\n";
        cout << "Solo se pueden agregar " << (MAX_INFRACCIONES - n) 
             << " infracciones mas.\n";
        cantidad = MAX_INFRACCIONES - n;
    }
    
    for(int i = 0; i < cantidad; i++) {
        cout << "\n--- Infraccion #" << (n + 1) << " ---\n";
        leerInfraccion(infracciones[n]);
        n++;
    }
    
    cout << "\nDatos almacenados exitosamente!\n";
}

// Lee los datos de una infracción
void leerInfraccion(Infraccion &inf) {
    cout << "Numero de placa: ";
    cin.getline(inf.nroPlaca, 11);
    
    cout << "Marca del vehiculo: ";
    cin.getline(inf.marca, 16);
    
    cout << "Color: ";
    cin.getline(inf.color, 16);
    
    cout << "Fecha de la infraccion (dd/mm/aaaa): ";
    cin.getline(inf.fechaInfra, 13);
    
    cout << "Distrito: ";
    cin.getline(inf.distrito, 26);
    
    cout << "Monto de la multa: S/ ";
    cin >> inf.multaPagar;
    cin.ignore();
    
    // Validación del monto
    while(inf.multaPagar < 0) {
        cout << "Error: El monto no puede ser negativo.\n";
        cout << "Ingrese nuevamente el monto: S/ ";
        cin >> inf.multaPagar;
        cin.ignore();
    }
}

// Muestra toda la información de las infracciones
void mostrarInformacion(const Infraccion infracciones[], int n) {
    cout << "\n========================================\n";
    cout << "  LISTADO DE INFRACCIONES REGISTRADAS\n";
    cout << "========================================\n";
    
    for(int i = 0; i < n; i++) {
        mostrarInfraccion(infracciones[i], i + 1);
    }
    
    // Calcular total de multas
    float totalMultas = 0;
    for(int i = 0; i < n; i++) {
        totalMultas += infracciones[i].multaPagar;
    }
    
    cout << "\n========================================\n";
    cout << fixed << setprecision(2);
    cout << "Total de infracciones: " << n << endl;
    cout << "Total de multas: S/ " << totalMultas << endl;
}

// Muestra los datos de una infracción
void mostrarInfraccion(const Infraccion &inf, int numero) {
    cout << "\n--- Infraccion #" << numero << " ---\n";
    cout << "Placa:       " << inf.nroPlaca << endl;
    cout << "Marca:       " << inf.marca << endl;
    cout << "Color:       " << inf.color << endl;
    cout << "Fecha:       " << inf.fechaInfra << endl;
    cout << "Distrito:    " << inf.distrito << endl;
    cout << fixed << setprecision(2);
    cout << "Multa:       S/ " << inf.multaPagar << endl;
}

// Busca y muestra vehículos de una marca específica
void buscarPorMarca(const Infraccion infracciones[], int n, const char* marca) {
    int contador = 0;
    
    cout << "\n========================================\n";
    cout << "  VEHICULOS DE MARCA: " << marca << endl;
    cout << "========================================\n";
    
    for(int i = 0; i < n; i++) {
        // Comparación sin importar mayúsculas/minúsculas
        if(strcasecmp(infracciones[i].marca, marca) == 0) {
            mostrarInfraccion(infracciones[i], i + 1);
            contador++;
        }
    }
    
    cout << "\nTotal de vehiculos encontrados: " << contador << endl;
    
    if(contador == 0) {
        cout << "No se encontraron vehiculos de la marca " << marca << endl;
    }
}

// Encuentra el índice del vehículo con la multa más alta
int encontrarMultaMasAlta(const Infraccion infracciones[], int n) {
    int indiceMax = 0;
    float multaMax = infracciones[0].multaPagar;
    
    // Recorrer todas las infracciones para encontrar la multa más alta
    for(int i = 1; i < n; i++) {
        if(infracciones[i].multaPagar > multaMax) {
            multaMax = infracciones[i].multaPagar;
            indiceMax = i;
        }
    }
    
    return indiceMax;
}
