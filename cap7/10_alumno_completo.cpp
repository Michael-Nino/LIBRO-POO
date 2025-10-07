// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Programa: 10_alumno_completo.cpp
 * Propósito: Sistema COMPLETO de gestión con OBJETO GLOBAL y FUNCIONES MODULARES
 * 
 * CONCEPTOS CLAVE:
 * - OBJETO GLOBAL: 'Industrial' existe durante todo el programa
 * - FUNCIONES MODULARES: agregar(), eliminar(), imprimir(), menu()
 * - CÓDIGO MÁS COMPACTO: Métodos inline donde es apropiado
 * - VALIDACIÓN: Verifica códigos duplicados y arreglo lleno
 * 
 * DIFERENCIA CON 09_alumno_gestion.cpp:
 * - Este usa un objeto GLOBAL (Industrial) accesible desde todas las funciones
 * - El anterior usaba objeto LOCAL en main() pasado a funciones
 * - Este es más modular con funciones separadas
 */

#include <iostream>
#include <cstdio>   // Para funciones C (no usado directamente)
#include <cstring>  // Para strcpy
using namespace std;

const int N = 50;  // Capacidad máxima de alumnos

// ============ ESTRUCTURA DE DATOS ============
struct alumno
{
    int codigo;
    char nombre[40];
    int notas[4];
};

// ============ CLASE CAlumno (representa UN alumno) ============
class CAlumno
{
public:
    void setCodigo(int cod);
    void setNombre(char nom[]);
    void setNotas();
    int getCodigo();
    char* getNombre();
    void getNotas();
    double promedio();
    const char* estado();
    
private:
    alumno a;
};

// ============ IMPLEMENTACIÓN DE CAlumno (versión compacta) ============

// Setters inline (una línea)
void CAlumno::setCodigo(int cod) { a.codigo = cod; }
void CAlumno::setNombre(char nom[]) { strcpy(a.nombre, nom); }

// Pide las 4 notas
void CAlumno::setNotas()
{
    cout << "Ingrese cuatro notas: ";
    for(int i = 0; i < 4; i++)
        cin >> a.notas[i];
}

// Getters inline
int CAlumno::getCodigo() { return a.codigo; }
char* CAlumno::getNombre() { return a.nombre; }

// Imprime las notas
void CAlumno::getNotas()
{
    for(int i = 0; i < 4; i++)
        cout << a.notas[i] << " ";
    cout << endl;
}

// Calcula el promedio
double CAlumno::promedio()
{
    int suma = 0;
    for(int i = 0; i < 4; i++)
        suma += a.notas[i];
    return suma / 4.0;
}

// Devuelve "Aprobado" o "Desaprobado" usando operador ternario
const char* CAlumno::estado()
{
    return (promedio() >= 10.5) ? "Aprobado" : "Desaprobado";
    // Equivale a: if(promedio() >= 10.5) return "Aprobado"; else return "Desaprobado";
}

// ============ CLASE CAlumnos (gestiona MÚLTIPLES alumnos) ============
class CAlumnos
{
public:
    CAlumnos() { indice = 0; }  // Constructor inline
    void setAlumno(int p, CAlumno actual) { array[p] = actual; }
    CAlumno getAlumno(int p) { return array[p]; }
    int getIndice() { return indice; }
    void agrega(CAlumno uno);   // Agrega alumno
    void elimina(int p);        // Elimina alumno en posición p
    int busca(int cod);         // Busca por código, retorna posición
    
private:
    CAlumno array[N];  // Arreglo de hasta N alumnos
    int indice;        // Número actual de alumnos
};

// ============ IMPLEMENTACIÓN DE CAlumnos ============

/*
 * agrega: Añade un alumno al arreglo
 * Nota: No verifica duplicados (eso se hace en la función agregar())
 */
void CAlumnos::agrega(CAlumno uno)
{
    if(indice < N)
    {
        array[indice] = uno;
        indice++;
    }
}

/*
 * elimina: Elimina alumno en posición p
 * Desplaza elementos posteriores hacia adelante
 */
void CAlumnos::elimina(int p)
{
    for(int i = p; i < indice - 1; i++)
        array[i] = array[i + 1];  // Desplaza
    indice--;
}

/*
 * busca: Busca alumno por código
 * Retorna: posición si encontrado, -1 si no
 */
int CAlumnos::busca(int cod)
{
    for(int i = 0; i < indice; i++)
        if(array[i].getCodigo() == cod)
            return i;
    return -1;  // No encontrado
}

// ============ OBJETO GLOBAL ============
/*
 * Industrial: Objeto GLOBAL de tipo CAlumnos
 * - Existe durante TODA la ejecución del programa
 * - Accesible desde TODAS las funciones
 * - Se crea al inicio del programa, se destruye al final
 * 
 * VENTAJA: No es necesario pasar el objeto como parámetro a las funciones
 * DESVENTAJA: Menos flexible (solo un objeto, no múltiples grupos)
 */
CAlumnos Industrial;

// ============ PROTOTIPOS DE FUNCIONES ============
void agregar();   // Función para agregar un alumno
void eliminar();  // Función para eliminar un alumno
void imprimir();  // Función para listar todos los alumnos
void menu();      // Función que muestra el menú principal

// ============ PROGRAMA PRINCIPAL ============
int main()
{
    menu();  // Llama al menú principal
    return 0;
}

// ============ IMPLEMENTACIÓN DE FUNCIONES ============

/*
 * agregar: Función para agregar un nuevo alumno
 * VALIDACIONES:
 * 1. Verifica que el código no esté duplicado
 * 2. Verifica que haya espacio en el arreglo
 * 
 * FLUJO:
 * 1. Pide datos al usuario
 * 2. Crea objeto alumno temporal
 * 3. Busca si el código ya existe
 * 4. Si no existe y hay espacio, lo agrega
 * 5. Muestra lista actualizada
 */
void agregar()
{
    // ===== ENTRADA DE DATOS =====
    int cod;
    char nom[40];
    
    cout << "\n--- Agregar Alumno ---" << endl;
    cout << "Ingrese codigo del alumno: ";
    cin >> cod;
    cout << "Ingrese Nombre del alumno: ";
    cin >> nom;
    
    // ===== CREAR OBJETO TEMPORAL =====
    CAlumno alum;
    alum.setCodigo(cod);
    alum.setNombre(nom);
    alum.setNotas();
    
    // ===== VALIDACIÓN 1: Verificar código duplicado =====
    int p = Industrial.busca(cod);
    if(p >= 0)  // Código ya existe
    {
        cout << "✗ ERROR: Codigo repetido! No se puede agregar." << endl;
    }
    else
    {
        // ===== VALIDACIÓN 2: Verificar espacio disponible =====
        if(Industrial.getIndice() == N)  // Arreglo lleno
        {
            cout << "✗ ERROR: Arreglo de alumnos lleno! No se puede agregar más." << endl;
        }
        else
        {
            // ===== AGREGAR Y MOSTRAR =====
            Industrial.agrega(alum);
            cout << "✓ Alumno agregado exitosamente!" << endl;
            imprimir();  // Muestra lista actualizada
        }
    }
}

/*
 * eliminar: Función para eliminar un alumno por código
 * FLUJO:
 * 1. Pide código al usuario
 * 2. Busca el alumno
 * 3. Si existe, lo elimina y muestra lista actualizada
 * 4. Si no existe, muestra mensaje de error
 */
void eliminar()
{
    int cod;
    cout << "\n--- Eliminar Alumno ---" << endl;
    cout << "Codigo a eliminar: ";
    cin >> cod;
    
    // Buscar el alumno
    int p = Industrial.busca(cod);
    
    if(p < 0)  // No encontrado
    {
        cout << "✗ ERROR: Codigo no existe! No se puede eliminar." << endl;
    }
    else  // Encontrado
    {
        cout << "→ Alumno encontrado en posicion " << p << endl;
        Industrial.elimina(p);  // Eliminar
        cout << "✓ Alumno eliminado exitosamente!" << endl;
        imprimir();  // Muestra lista actualizada
    }
}

/*
 * imprimir: Función para listar todos los alumnos registrados
 * Recorre el arreglo y muestra datos de cada alumno
 */
void imprimir()
{
    cout << "\n========== LISTADO DE ALUMNOS ==========" << endl;
    
    if(Industrial.getIndice() == 0)  // No hay alumnos
    {
        cout << "No hay alumnos registrados en Industrial." << endl;
    }
    else
    {
        // Recorrer y mostrar cada alumno
        for(int i = 0; i < Industrial.getIndice(); i++)
        {
            CAlumno a = Industrial.getAlumno(i);  // Obtener alumno i
            
            cout << "\n--- Alumno #" << (i+1) << " ---" << endl;
            cout << "Codigo: " << a.getCodigo() << endl;
            cout << "Nombre: " << a.getNombre() << endl;
            cout << "Promedio: " << a.promedio() << endl;
            cout << "Estado: " << a.estado() << endl;
        }
        cout << "\nTotal de alumnos: " << Industrial.getIndice() << endl;
    }
    cout << "========================================" << endl;
}

/*
 * menu: Función que muestra el menú principal
 * Bucle principal del programa
 * Permite seleccionar operación hasta que usuario elija salir (0)
 */
void menu()
{
    int opc;
    
    cout << "\n╔════════════════════════════════════════════╗" << endl;
    cout << "║  SISTEMA DE GESTION DE ALUMNOS - Industrial  ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    
    do
    {
        // Mostrar opciones
        cout << "\n========== MENU PRINCIPAL ==========" << endl;
        cout << "[1] Agregar alumno" << endl;
        cout << "[2] Eliminar alumno" << endl;
        cout << "[3] Listar alumnos" << endl;
        cout << "[0] Salir" << endl;
        cout << "====================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opc;
        
        // Procesar opción
        switch(opc)
        {
            case 1: 
                agregar(); 
                break;
                
            case 2: 
                eliminar(); 
                break;
                
            case 3: 
                imprimir(); 
                break;
                
            case 0:
                cout << "\n¡Gracias por usar el sistema! Hasta luego." << endl;
                break;
                
            default:
                cout << "\n✗ Opcion invalida. Intente de nuevo." << endl;
                break;
        }
    } while(opc != 0);  // Repetir hasta que usuario elija salir
    
    cout << "\n--- Fin del programa ---" << endl;
}

/*
 * COMPARACIÓN: Objeto Global vs Objeto Local
 * 
 * OBJETO GLOBAL (este programa):
 * + No necesita pasar como parámetro
 * + Código más simple
 * - Solo puede haber UNO en todo el programa
 * - Menos flexible
 * 
 * OBJETO LOCAL (programa anterior):
 * + Puede crear múltiples objetos
 * + Más flexible y modular
 * + Mejor encapsulamiento
 * - Requiere pasar como parámetro o usar referencia
 * 
 * MEJORAS POSIBLES:
 * - Modificar datos de un alumno existente
 * - Ordenar por código, nombre, o promedio
 * - Buscar por nombre (búsqueda parcial)
 * - Exportar/Importar desde archivo
 * - Estadísticas (promedio general, aprobados/desaprobados, etc.)
 */
