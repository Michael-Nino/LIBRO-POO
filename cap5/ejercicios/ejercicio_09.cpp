/*
 * EJERCICIO 9: Sistema de gestión de alumnos con funciones específicas
 * 
 * Descripción (2009-0):
 * Se define la estructura alumno con código, nombre, curso y array de notas.
 * 
 * Funciones implementadas:
 * - mayorPromedio: Encuentra el alumno con el mayor promedio e imprime sus datos.
 *   El promedio se obtiene eliminando la nota más baja.
 * - buscaAlumno: Busca un alumno según su código, si lo encuentra imprime sus datos,
 *   en caso contrario imprime mensaje respectivo.
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int N = 50;  // Máximo número de alumnos
const int NUM_NOTAS = 4;  // Número de notas por alumno

// Estructura alumno
struct Alumno {
    char codigo[10];
    char nombre[40];
    char curso[30];
    int notas[NUM_NOTAS];
};

// Prototipos de funciones
void leerAlumno(Alumno &a);
void leerGrupoAlumnos(Alumno a[], int &n);
void mostrarAlumno(const Alumno &a);
float calcularPromedioSinNotaBaja(const Alumno &a);
void mayorPromedio(Alumno a[], int n);
void buscaAlumno(Alumno a[], int n, char cod[]);

int main() {
    Alumno alumnos[N];
    int numAlumnos;
    int opcion;
    char codigoBuscar[10];
    
    cout << "========================================\n";
    cout << "  SISTEMA DE GESTION DE ALUMNOS\n";
    cout << "========================================\n\n";
    
    // Leer número de alumnos
    cout << "Ingrese el numero de alumnos (1-" << N << "): ";
    cin >> numAlumnos;
    cin.ignore();
    
    while(numAlumnos < 1 || numAlumnos > N) {
        cout << "Error. Ingrese un numero valido: ";
        cin >> numAlumnos;
        cin.ignore();
    }
    
    // Leer datos de los alumnos
    leerGrupoAlumnos(alumnos, numAlumnos);
    
    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Mostrar todos los alumnos\n";
        cout << "2. Buscar alumno por codigo\n";
        cout << "3. Encontrar alumno con mayor promedio\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        
        switch(opcion) {
            case 1:
                cout << "\n========================================\n";
                cout << "  LISTADO DE ALUMNOS\n";
                cout << "========================================\n";
                for(int i = 0; i < numAlumnos; i++) {
                    cout << "\n--- Alumno #" << (i + 1) << " ---\n";
                    mostrarAlumno(alumnos[i]);
                    float promedio = calcularPromedioSinNotaBaja(alumnos[i]);
                    cout << "Promedio (sin nota baja): " << fixed 
                         << setprecision(2) << promedio << endl;
                }
                break;
                
            case 2:
                cout << "\nIngrese el codigo del alumno a buscar: ";
                cin.getline(codigoBuscar, 10);
                buscaAlumno(alumnos, numAlumnos, codigoBuscar);
                break;
                
            case 3:
                mayorPromedio(alumnos, numAlumnos);
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

// Lee los datos de un alumno
void leerAlumno(Alumno &a) {
    cout << "Codigo: ";
    cin.getline(a.codigo, 10);
    
    cout << "Nombre: ";
    cin.getline(a.nombre, 40);
    
    cout << "Curso: ";
    cin.getline(a.curso, 30);
    
    cout << "Ingrese " << NUM_NOTAS << " notas:\n";
    for(int i = 0; i < NUM_NOTAS; i++) {
        cout << "  Nota " << (i + 1) << ": ";
        cin >> a.notas[i];
        
        while(a.notas[i] < 0 || a.notas[i] > 20) {
            cout << "  Error. Nota entre 0 y 20: ";
            cin >> a.notas[i];
        }
    }
    cin.ignore();
}

// Lee un grupo de alumnos
void leerGrupoAlumnos(Alumno a[], int &n) {
    cout << "\n=== INGRESO DE DATOS ===\n";
    for(int i = 0; i < n; i++) {
        cout << "\n--- Alumno #" << (i + 1) << " ---\n";
        leerAlumno(a[i]);
    }
}

// Muestra los datos de un alumno
void mostrarAlumno(const Alumno &a) {
    cout << "Codigo: " << a.codigo << endl;
    cout << "Nombre: " << a.nombre << endl;
    cout << "Curso:  " << a.curso << endl;
    cout << "Notas:  ";
    for(int i = 0; i < NUM_NOTAS; i++) {
        cout << a.notas[i];
        if(i < NUM_NOTAS - 1) cout << ", ";
    }
    cout << endl;
}

// Calcula el promedio eliminando la nota más baja
float calcularPromedioSinNotaBaja(const Alumno &a) {
    // Encontrar la nota más baja
    int notaBaja = a.notas[0];
    for(int i = 1; i < NUM_NOTAS; i++) {
        if(a.notas[i] < notaBaja) {
            notaBaja = a.notas[i];
        }
    }
    
    // Sumar todas las notas excepto la más baja
    int suma = 0;
    bool notaBajaEliminada = false;
    for(int i = 0; i < NUM_NOTAS; i++) {
        if(a.notas[i] == notaBaja && !notaBajaEliminada) {
            // Omitir la primera ocurrencia de la nota más baja
            notaBajaEliminada = true;
        } else {
            suma += a.notas[i];
        }
    }
    
    // Promedio de las 3 notas restantes
    return suma / (float)(NUM_NOTAS - 1);
}

// Encuentra el alumno con el mayor promedio (sin nota baja)
void mayorPromedio(Alumno a[], int n) {
    if(n == 0) {
        cout << "\nNo hay alumnos registrados.\n";
        return;
    }
    
    int indiceMejor = 0;
    float mejorPromedio = calcularPromedioSinNotaBaja(a[0]);
    
    // Buscar el mejor promedio
    for(int i = 1; i < n; i++) {
        float promedioActual = calcularPromedioSinNotaBaja(a[i]);
        if(promedioActual > mejorPromedio) {
            mejorPromedio = promedioActual;
            indiceMejor = i;
        }
    }
    
    // Mostrar el alumno con mejor promedio
    cout << "\n========================================\n";
    cout << "  ALUMNO CON MAYOR PROMEDIO\n";
    cout << "========================================\n";
    mostrarAlumno(a[indiceMejor]);
    cout << fixed << setprecision(2);
    cout << "Promedio (sin nota baja): " << mejorPromedio << endl;
}

// Busca un alumno por código
void buscaAlumno(Alumno a[], int n, char cod[]) {
    bool encontrado = false;
    
    for(int i = 0; i < n; i++) {
        if(strcmp(a[i].codigo, cod) == 0) {
            cout << "\n========================================\n";
            cout << "  ALUMNO ENCONTRADO\n";
            cout << "========================================\n";
            mostrarAlumno(a[i]);
            float promedio = calcularPromedioSinNotaBaja(a[i]);
            cout << fixed << setprecision(2);
            cout << "Promedio (sin nota baja): " << promedio << endl;
            encontrado = true;
            break;
        }
    }
    
    if(!encontrado) {
        cout << "\nAlumno con codigo '" << cod << "' NO encontrado.\n";
    }
}
