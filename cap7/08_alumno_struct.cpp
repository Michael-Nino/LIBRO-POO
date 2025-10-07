// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Programa: 08_alumno_struct.cpp
 * Propósito: Demostrar una CLASE que contiene un STRUCT como dato miembro
 * 
 * CONCEPTOS CLAVE:
 * - COMPOSICIÓN: Una clase puede tener un struct (o clase) como dato miembro
 * - ENCAPSULAMIENTO: El struct 'alumno' está dentro de CAlumno y es privado
 * - SETTERS/GETTERS: Métodos para modificar/obtener datos del struct interno
 * - LÓGICA DE NEGOCIO: Métodos como promedio() y estado() procesan los datos
 * 
 * ESTRUCTURA:
 * - struct alumno: Contiene datos básicos (código, nombre, notas)
 * - class CAlumno: Envuelve el struct y proporciona métodos
 */

#include <iostream>
#include <cstdio>  // Para funciones C (aunque aquí no se usa directamente)
using namespace std;

// ============ ESTRUCTURA DE DATOS ============
/*
 * struct alumno: Almacena información básica de un alumno
 * - Es un tipo de dato compuesto (agrupa varios datos relacionados)
 * - En C++, struct es similar a class pero sus miembros son públicos por defecto
 */
struct alumno
{
    char codigo[10];  // Código del alumno (ej: "2024001")
    char nombre[40];  // Nombre completo
    int notas[4];     // Arreglo de 4 notas
};

// ============ CLASE QUE GESTIONA AL ALUMNO ============
class CAlumno
{
public:
    // ===== MÉTODOS SETTERS (para ingresar datos) =====
    
    /*
     * setCodigo: Solicita e ingresa el código del alumno
     * Usa cin.getline() para leer cadenas con espacios
     */
    void setCodigo()
    {
        cout << "Ingrese codigo del alumno: ";
        cin.getline(a.codigo, 10);  // Lee hasta 9 caracteres + '\0'
    }
    
    /*
     * setNombre: Solicita e ingresa el nombre del alumno
     */
    void setNombre()
    {
        cout << "Ingrese Nombre del alumno: ";
        cin.getline(a.nombre, 40);  // Lee hasta 39 caracteres + '\0'
    }
    
    /*
     * setNotas: Solicita e ingresa las 4 notas del alumno
     * Usa un bucle for para leer cada nota
     */
    void setNotas()
    {
        cout << "Ingrese cuatro notas: ";
        for(int i = 0; i < 4; i++)
        {
            cin >> a.notas[i];  // Lee cada nota (entero)
        }
    }
    
    // ===== MÉTODOS GETTERS (para obtener datos) =====
    
    /*
     * getCodigo: Devuelve un puntero al código del alumno
     * Retorna: char* apuntando al arreglo a.codigo
     */
    char* getCodigo()
    {
        return a.codigo;  // Devuelve dirección del primer elemento
    }
    
    /*
     * getNombre: Devuelve un puntero al nombre del alumno
     * Retorna: char* apuntando al arreglo a.nombre
     */
    char* getNombre()
    {
        return a.nombre;
    }
    
    /*
     * getNotas: Imprime las 4 notas del alumno
     * No retorna valor, solo muestra en pantalla
     */
    void getNotas()
    {
        for(int i = 0; i < 4; i++)
        {
            cout << a.notas[i] << " ";
        }
        cout << endl;
    }
    
    // ===== MÉTODOS DE LÓGICA DE NEGOCIO =====
    
    /*
     * promedio: Calcula y devuelve el promedio de las 4 notas
     * Retorna: double (promedio de notas)
     * Suma las 4 notas y divide entre 4.0 (para obtener decimal)
     */
    double promedio()
    {
        int suma = 0;
        for(int i = 0; i < 4; i++)
        {
            suma += a.notas[i];  // Acumula las notas
        }
        return suma / 4.0;  // División entre double para resultado decimal
    }
    
    /*
     * estado: Determina si el alumno está aprobado o desaprobado
     * Retorna: const char* ("Aprobado" o "Desaprobado")
     * Criterio: Aprobado si promedio >= 10.5
     */
    const char* estado()
    {
        if(promedio() >= 10.5)  // Llama al método promedio()
            return "Aprobado";
        else
            return "Desaprobado";
    }
    
private:
    // ===== DATO PRIVADO =====
    alumno a;  // Objeto del struct alumno (COMPOSICIÓN)
               // Es PRIVADO: solo accesible por métodos de CAlumno
};

// ============ PROGRAMA PRINCIPAL ============
int main()
{
    CAlumno al;  // Crear objeto de la clase CAlumno
    
    // ===== ENTRADA DE DATOS =====
    cin.ignore();  // Limpiar buffer (importante antes de getline)
                   // Previene problemas si hubo un cin >> anterior
    
    al.setCodigo();  // Pide y guarda el código
    al.setNombre();  // Pide y guarda el nombre
    al.setNotas();   // Pide y guarda las 4 notas
    
    // ===== SALIDA DE DATOS =====
    cout << "\nDatos del alumno:" << endl;
    cout << "Codigo: " << al.getCodigo() << endl;  // Muestra código
    cout << "Nombre: " << al.getNombre() << endl;  // Muestra nombre
    cout << "Notas: ";
    al.getNotas();  // Muestra las 4 notas
    
    // ===== CÁLCULOS Y RESULTADOS =====
    double prom = al.promedio();  // Calcula promedio
    cout << "Promedio = " << prom << endl;
    cout << "Estado: " << al.estado() << endl;  // Muestra si aprobó o no
    
    return 0;
}

/*
 * VENTAJAS DE ESTA ARQUITECTURA:
 * 1. ENCAPSULAMIENTO: Los datos del alumno están protegidos (privados)
 * 2. COMPOSICIÓN: La clase usa un struct como dato miembro
 * 3. COHESIÓN: Toda la lógica relacionada con el alumno está en CAlumno
 * 4. FACILIDAD DE USO: main() solo llama métodos, no manipula datos directamente
 * 
 * MEJORA POSIBLE:
 * - Agregar validación en setNotas() (ej: notas entre 0-20)
 * - Usar std::string en lugar de char[] para mayor seguridad
 */
