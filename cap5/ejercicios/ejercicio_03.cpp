/*
 * EJERCICIO 3: Registro de grupo de alumnos
 * 
 * Descripción:
 * Modificar el programa del ejercicio 2 para que permita leer los datos
 * de un grupo de alumnos. El programa debe imprimir los datos de cada alumno
 * y su respectivo promedio de notas.
 * Se implementan funciones definidas por el usuario para realizar las tareas.
 * 
 * Mejoras respecto al ejercicio anterior:
 * - Manejo de múltiples alumnos usando arreglos
 * - Funciones modulares para cada tarea específica
 * - Estadísticas del grupo (promedio general, mejor alumno, etc.)
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int MAX_ALUMNOS = 50;  // Máximo número de alumnos

// Estructura para representar un alumno
struct Alumno {
    char codigoMat[15];   // Código de matrícula
    char nombre[50];      // Nombre completo
    float nota1;          // Primera nota
    float nota2;          // Segunda nota
    float nota3;          // Tercera nota
};

// Prototipos de funciones
int leerNumeroAlumnos();
void leerAlumno(Alumno &alumno, int numero);
void leerGrupoAlumnos(Alumno alumnos[], int n);
float calcularPromedio(const Alumno &alumno);
void mostrarAlumno(const Alumno &alumno, int numero, float promedio);
void mostrarGrupoAlumnos(const Alumno alumnos[], int n);
void mostrarEstadisticas(const Alumno alumnos[], int n);
int encontrarMejorAlumno(const Alumno alumnos[], int n);

int main() {
    Alumno grupo[MAX_ALUMNOS];
    int numAlumnos;
    
    cout << "========================================\n";
    cout << "   REGISTRO DE GRUPO DE ALUMNOS\n";
    cout << "========================================\n\n";
    
    // Leer número de alumnos
    numAlumnos = leerNumeroAlumnos();
    
    // Leer datos del grupo de alumnos
    leerGrupoAlumnos(grupo, numAlumnos);
    
    // Mostrar datos de todos los alumnos con sus promedios
    mostrarGrupoAlumnos(grupo, numAlumnos);
    
    // Mostrar estadísticas del grupo
    mostrarEstadisticas(grupo, numAlumnos);
    
    return 0;
}

// Lee y valida el número de alumnos
int leerNumeroAlumnos() {
    int n;
    cout << "Ingrese el numero de alumnos (1-" << MAX_ALUMNOS << "): ";
    cin >> n;
    cin.ignore(); // Limpiar buffer
    
    while(n < 1 || n > MAX_ALUMNOS) {
        cout << "Error: Numero invalido. Intente nuevamente: ";
        cin >> n;
        cin.ignore();
    }
    
    return n;
}

// Lee los datos de un alumno individual
void leerAlumno(Alumno &alumno, int numero) {
    cout << "\n--- Alumno #" << numero << " ---\n";
    
    cout << "Codigo de matricula: ";
    cin.getline(alumno.codigoMat, 15);
    
    cout << "Nombre completo: ";
    cin.getline(alumno.nombre, 50);
    
    cout << "Nota 1: ";
    cin >> alumno.nota1;
    
    cout << "Nota 2: ";
    cin >> alumno.nota2;
    
    cout << "Nota 3: ";
    cin >> alumno.nota3;
    cin.ignore(); // Limpiar buffer para próxima lectura
    
    // Validación de notas
    while(alumno.nota1 < 0 || alumno.nota1 > 20 ||
          alumno.nota2 < 0 || alumno.nota2 > 20 ||
          alumno.nota3 < 0 || alumno.nota3 > 20) {
        cout << "\nError: Notas deben estar entre 0 y 20.\n";
        cout << "Ingrese nuevamente:\n";
        cout << "Nota 1: "; cin >> alumno.nota1;
        cout << "Nota 2: "; cin >> alumno.nota2;
        cout << "Nota 3: "; cin >> alumno.nota3;
        cin.ignore();
    }
}

// Lee los datos de un grupo de alumnos
void leerGrupoAlumnos(Alumno alumnos[], int n) {
    cout << "\n=== INGRESO DE DATOS ===\n";
    for(int i = 0; i < n; i++) {
        leerAlumno(alumnos[i], i + 1);
    }
}

// Calcula el promedio de las tres notas
float calcularPromedio(const Alumno &alumno) {
    return (alumno.nota1 + alumno.nota2 + alumno.nota3) / 3.0;
}

// Muestra los datos de un alumno con su promedio
void mostrarAlumno(const Alumno &alumno, int numero, float promedio) {
    cout << fixed << setprecision(2);
    
    cout << "\n--- ALUMNO #" << numero << " ---\n";
    cout << "Codigo: " << alumno.codigoMat << endl;
    cout << "Nombre: " << alumno.nombre << endl;
    cout << "Notas: " << alumno.nota1 << " | " 
         << alumno.nota2 << " | " << alumno.nota3 << endl;
    cout << "Promedio: " << promedio;
    
    if(promedio >= 10.5)
        cout << " (APROBADO)\n";
    else
        cout << " (DESAPROBADO)\n";
}

// Muestra los datos de todos los alumnos
void mostrarGrupoAlumnos(const Alumno alumnos[], int n) {
    cout << "\n========================================\n";
    cout << "   DATOS DE LOS ALUMNOS\n";
    cout << "========================================\n";
    
    for(int i = 0; i < n; i++) {
        float promedio = calcularPromedio(alumnos[i]);
        mostrarAlumno(alumnos[i], i + 1, promedio);
    }
}

// Encuentra el índice del mejor alumno
int encontrarMejorAlumno(const Alumno alumnos[], int n) {
    int indiceMejor = 0;
    float mejorPromedio = calcularPromedio(alumnos[0]);
    
    for(int i = 1; i < n; i++) {
        float promedioActual = calcularPromedio(alumnos[i]);
        if(promedioActual > mejorPromedio) {
            mejorPromedio = promedioActual;
            indiceMejor = i;
        }
    }
    
    return indiceMejor;
}

// Muestra estadísticas del grupo
void mostrarEstadisticas(const Alumno alumnos[], int n) {
    cout << "\n========================================\n";
    cout << "   ESTADISTICAS DEL GRUPO\n";
    cout << "========================================\n";
    cout << fixed << setprecision(2);
    
    // Calcular promedio general del grupo
    float sumaPromedios = 0;
    int aprobados = 0, desaprobados = 0;
    
    for(int i = 0; i < n; i++) {
        float promedio = calcularPromedio(alumnos[i]);
        sumaPromedios += promedio;
        
        if(promedio >= 10.5)
            aprobados++;
        else
            desaprobados++;
    }
    
    float promedioGeneral = sumaPromedios / n;
    
    cout << "\nTotal de alumnos: " << n << endl;
    cout << "Aprobados: " << aprobados << endl;
    cout << "Desaprobados: " << desaprobados << endl;
    cout << "Promedio general del grupo: " << promedioGeneral << endl;
    
    // Mostrar mejor alumno
    int indiceMejor = encontrarMejorAlumno(alumnos, n);
    float mejorPromedio = calcularPromedio(alumnos[indiceMejor]);
    
    cout << "\nMejor alumno: " << alumnos[indiceMejor].nombre << endl;
    cout << "Promedio del mejor alumno: " << mejorPromedio << endl;
}
