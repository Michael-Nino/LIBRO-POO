/*
 * EJERCICIO 2: Registro y promedio de alumno
 * 
 * Descripción:
 * Declarar la estructura Alumno(CodigoMat, Nombre, Nota1, Nota2, Nota3).
 * Escribir un programa que permita leer los datos de un alumno en la estructura
 * y luego imprima todos los datos del alumno y el promedio de sus notas.
 * 
 * Estructura de datos:
 * - CodigoMat: Código de matrícula del alumno (cadena)
 * - Nombre: Nombre completo del alumno (cadena)
 * - Nota1, Nota2, Nota3: Tres notas del alumno (float)
 * 
 * Funcionalidad:
 * - Lectura de datos del alumno
 * - Cálculo del promedio de las tres notas
 * - Impresión de todos los datos incluyendo el promedio
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

// Estructura para representar un alumno
struct Alumno {
    char codigoMat[15];   // Código de matrícula
    char nombre[50];      // Nombre completo
    float nota1;          // Primera nota
    float nota2;          // Segunda nota
    float nota3;          // Tercera nota
};

// Prototipos de funciones
void leerAlumno(Alumno &alumno);
float calcularPromedio(const Alumno &alumno);
void mostrarAlumno(const Alumno &alumno, float promedio);

int main() {
    Alumno estudiante;
    float promedio;
    
    cout << "========================================\n";
    cout << "   REGISTRO DE DATOS DE ALUMNO\n";
    cout << "========================================\n\n";
    
    // Leer datos del alumno
    leerAlumno(estudiante);
    
    // Calcular el promedio
    promedio = calcularPromedio(estudiante);
    
    // Mostrar los datos y el promedio
    cout << "\n========================================\n";
    cout << "   DATOS DEL ALUMNO\n";
    cout << "========================================\n";
    mostrarAlumno(estudiante, promedio);
    
    return 0;
}

// Lee los datos de un alumno desde el teclado
void leerAlumno(Alumno &alumno) {
    cout << "Ingrese el codigo de matricula: ";
    cin.getline(alumno.codigoMat, 15);
    
    cout << "Ingrese el nombre completo: ";
    cin.getline(alumno.nombre, 50);
    
    cout << "Ingrese la primera nota: ";
    cin >> alumno.nota1;
    
    cout << "Ingrese la segunda nota: ";
    cin >> alumno.nota2;
    
    cout << "Ingrese la tercera nota: ";
    cin >> alumno.nota3;
    
    // Validación de notas (0-20)
    while(alumno.nota1 < 0 || alumno.nota1 > 20 ||
          alumno.nota2 < 0 || alumno.nota2 > 20 ||
          alumno.nota3 < 0 || alumno.nota3 > 20) {
        cout << "\nError: Las notas deben estar entre 0 y 20.\n";
        cout << "Ingrese nuevamente las tres notas:\n";
        cout << "Nota 1: "; cin >> alumno.nota1;
        cout << "Nota 2: "; cin >> alumno.nota2;
        cout << "Nota 3: "; cin >> alumno.nota3;
    }
}

// Calcula el promedio de las tres notas del alumno
float calcularPromedio(const Alumno &alumno) {
    return (alumno.nota1 + alumno.nota2 + alumno.nota3) / 3.0;
}

// Muestra todos los datos del alumno y su promedio
void mostrarAlumno(const Alumno &alumno, float promedio) {
    cout << fixed << setprecision(2);
    
    cout << "\nCodigo de Matricula: " << alumno.codigoMat << endl;
    cout << "Nombre: " << alumno.nombre << endl;
    cout << "\nNotas:\n";
    cout << "  Nota 1: " << setw(6) << alumno.nota1 << endl;
    cout << "  Nota 2: " << setw(6) << alumno.nota2 << endl;
    cout << "  Nota 3: " << setw(6) << alumno.nota3 << endl;
    cout << "  ---------------------\n";
    cout << "  Promedio: " << setw(6) << promedio << endl;
    
    // Mostrar si aprobó o desaprobó
    if(promedio >= 10.5)
        cout << "\n  Estado: APROBADO\n";
    else
        cout << "\n  Estado: DESAPROBADO\n";
}
