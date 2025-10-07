// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Programa: 09_alumno_gestion.cpp
 * Propósito: Sistema COMPLETO de gestión de alumnos con ARREGLO DE OBJETOS
 * 
 * CONCEPTOS CLAVE:
 * - ARREGLO DE OBJETOS: array[N] de tipo CAlumno
 * - CLASE CONTENEDORA: CAlumnos gestiona múltiples CAlumno
 * - OPERACIONES CRUD: Create (agrega), Read (listar/buscar), Delete (elimina)
 * - MENÚ INTERACTIVO: Usuario puede agregar, listar, buscar, eliminar alumnos
 * 
 * ARQUITECTURA:
 * 1. struct alumno: Datos básicos
 * 2. class CAlumno: Representa UN alumno
 * 3. class CAlumnos: Gestiona MÚLTIPLES alumnos
 * 4. main(): Interfaz de usuario con menú
 */

#include <iostream>
#include <cstdio>   // Para funciones C (no usado directamente aquí)
#include <cstdlib>  // Para funciones estándar (system, etc.)
#include <cstring>  // Para strcpy y manipulación de cadenas

const int N = 50;  // Máximo número de alumnos
using namespace std;

// ============ ESTRUCTURA DE DATOS ============
struct alumno
{
    int codigo;       // Código numérico del alumno
    char nombre[40];  // Nombre del alumno
    int notas[4];     // Arreglo de 4 notas
};

// ============ CLASE CAlumno (representa UN alumno) ============
class CAlumno
{
public:
    // ===== SETTERS =====
    void setCodigo(int cod);      // Asigna el código del alumno
    void setNombre(char nom[]);   // Asigna el nombre del alumno
    void setNotas();              // Solicita e ingresa las 4 notas
    
    // ===== GETTERS =====
    int getCodigo();              // Devuelve el código del alumno
    char* getNombre();            // Devuelve el nombre del alumno
    void getNotas();              // Muestra las 4 notas en pantalla
    
    // ===== LÓGICA DE NEGOCIO =====
    double promedio();            // Calcula y devuelve el promedio
    const char* estado();         // Devuelve "Aprobado" o "Desaprobado"
    
private:
    alumno a;  // Objeto del struct alumno (COMPOSICIÓN)
};

// ============ IMPLEMENTACIÓN DE CAlumno ============

/*
 * setCodigo: Asigna el código al alumno
 * Parámetro: cod = código numérico del alumno
 */
void CAlumno::setCodigo(int cod)
{
    a.codigo = cod;
}

/*
 * setNombre: Copia el nombre al alumno
 * Parámetro: nom = arreglo de caracteres con el nombre
 * Usa strcpy para copiar la cadena
 */
void CAlumno::setNombre(char nom[])
{
    strcpy(a.nombre, nom);  // Copia nom a a.nombre
}

/*
 * setNotas: Solicita e ingresa las 4 notas del alumno
 * Usa un bucle for para leer cada nota
 */
void CAlumno::setNotas()
{
    cout << "Ingrese cuatro notas: ";
    for(int i = 0; i < 4; i++)
    {
        cin >> a.notas[i];
    }
}

/*
 * getCodigo: Devuelve el código del alumno
 * Retorna: int con el código
 */
int CAlumno::getCodigo()
{
    return a.codigo;
}

/*
 * getNombre: Devuelve un puntero al nombre del alumno
 * Retorna: char* apuntando al arreglo a.nombre
 */
char* CAlumno::getNombre()
{
    return a.nombre;
}

/*
 * getNotas: Imprime las 4 notas del alumno
 */
void CAlumno::getNotas()
{
    cout << "Notas: ";
    for(int i = 0; i < 4; i++)
    {
        cout << a.notas[i] << " ";
    }
    cout << endl;
}

/*
 * promedio: Calcula el promedio de las 4 notas
 * Retorna: double con el promedio
 */
double CAlumno::promedio()
{
    int suma = 0;
    for(int i = 0; i < 4; i++)
    {
        suma += a.notas[i];
    }
    return suma / 4.0;  // División entre double para decimal
}

/*
 * estado: Determina si el alumno está aprobado o desaprobado
 * Retorna: const char* ("Aprobado" o "Desaprobado")
 * Criterio: Aprobado si promedio >= 10.5
 */
const char* CAlumno::estado()
{
    double prom = promedio();
    if(prom >= 10.5)
        return "Aprobado";
    else
        return "Desaprobado";
}

// ============ FUNCIÓN AUXILIAR ============

/*
 * listar: Muestra toda la información de un alumno
 * Parámetro: a = objeto CAlumno a mostrar
 * Esta función RECIBE UNA COPIA del objeto (pasa por valor)
 * Para mayor eficiencia, podría recibir una referencia: void listar(const CAlumno& a)
 */
void listar(CAlumno a)
{
    cout << "\n--- Datos del alumno ---" << endl;
    cout << "Codigo: " << a.getCodigo() << endl;
    cout << "Nombre: " << a.getNombre() << endl;
    a.getNotas();
    cout << "Promedio = " << a.promedio() << endl;
    cout << "Estado = " << a.estado() << endl;
    cout << "------------------------" << endl;
}

// ============ CLASE CAlumnos (gestiona MÚLTIPLES alumnos) ============
/*
 * CAlumnos: Contenedor de objetos CAlumno
 * - Almacena hasta N alumnos en un arreglo
 * - Proporciona métodos para agregar, eliminar, buscar alumnos
 * - Mantiene un índice del número actual de alumnos
 * 
 * PATRÓN: Esta es una clase CONTENEDOR o COLECCIÓN
 */
class CAlumnos
{
public:
    // ===== CONSTRUCTOR =====
    /*
     * Constructor: Inicializa el índice en 0
     * Al crear un objeto CAlumnos, no tiene alumnos registrados
     */
    CAlumnos() { indice = 0; }
    
    // ===== SETTERS/GETTERS =====
    /*
     * setAlumno: Coloca un alumno en una posición específica
     * Parámetros: p = posición, actual = objeto CAlumno
     */
    void setAlumno(int p, CAlumno actual) { array[p] = actual; }
    
    /*
     * getAlumno: Obtiene el alumno en una posición específica
     * Parámetro: p = posición
     * Retorna: CAlumno en esa posición
     */
    CAlumno getAlumno(int p) { return array[p]; }
    
    /*
     * getIndice: Devuelve cuántos alumnos hay registrados
     * Retorna: int con el número actual de alumnos
     */
    int getIndice() { return indice; }
    
    // ===== OPERACIONES CRUD =====
    void agrega(CAlumno uno);     // CREATE: Agrega un alumno al arreglo
    void elimina(int p);          // DELETE: Elimina un alumno en posición p
    int busca(int cod);           // READ: Busca alumno por código, retorna posición
    
private:
    CAlumno array[N];  // ARREGLO DE OBJETOS (hasta N alumnos)
    int indice;        // Contador de alumnos actuales (0 a N)
};

// ============ IMPLEMENTACIÓN DE CAlumnos ============

/*
 * agrega: Añade un nuevo alumno al arreglo
 * Parámetro: uno = objeto CAlumno a agregar
 * - Verifica que haya espacio (indice < N)
 * - Copia el objeto en la posición actual
 * - Incrementa el índice
 */
void CAlumnos::agrega(CAlumno uno)
{
    if(indice < N)  // Hay espacio disponible
    {
        array[indice] = uno;  // Asigna el alumno en la posición actual
        indice++;             // Incrementa contador
    }
    else
    {
        cout << "ERROR: Arreglo lleno, no se puede agregar más alumnos." << endl;
    }
}

/*
 * elimina: Elimina un alumno en una posición específica
 * Parámetro: p = posición del alumno a eliminar
 * Algoritmo:
 * 1. Desplaza todos los elementos posteriores una posición hacia adelante
 * 2. Decrementa el índice
 * Ejemplo: [A,B,C,D,E] elimina pos 2 → [A,B,D,E,_]
 */
void CAlumnos::elimina(int p)
{
    // Desplaza elementos hacia adelante
    for(int i = p; i < indice - 1; i++)
    {
        array[i] = array[i + 1];  // Copia el siguiente al actual
    }
    indice--;  // Decrementa el contador de alumnos
}

/*
 * busca: Busca un alumno por su código
 * Parámetro: cod = código del alumno a buscar
 * Retorna: 
 *   - Posición (0 a indice-1) si se encuentra
 *   - -1 si NO se encuentra
 * Algoritmo: Búsqueda lineal (recorre todo el arreglo)
 */
int CAlumnos::busca(int cod)
{
    for(int i = 0; i < indice; i++)
    {
        if(array[i].getCodigo() == cod)  // Compara código
            return i;  // Encontrado, retorna posición
    }
    return -1;  // No encontrado
}

// ============ PROGRAMA PRINCIPAL ============
int main()
{
    CAlumnos grupo;    // Objeto contenedor de alumnos
    CAlumno temp;      // Objeto temporal para crear alumnos
    int opcion, codigo;
    char nombre[40];
    
    // ===== MENÚ PRINCIPAL (bucle do-while) =====
    do
    {
        // Mostrar opciones
        cout << "\n========== MENU DE GESTION DE ALUMNOS ==========" << endl;
        cout << "1. Agregar alumno" << endl;
        cout << "2. Listar todos los alumnos" << endl;
        cout << "3. Buscar alumno por codigo" << endl;
        cout << "4. Eliminar alumno por codigo" << endl;
        cout << "0. Salir" << endl;
        cout << "================================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        // ===== PROCESAR OPCIÓN =====
        switch(opcion)
        {
            case 1:  // AGREGAR ALUMNO
                cout << "\n--- Agregar Nuevo Alumno ---" << endl;
                cout << "Ingrese codigo: ";
                cin >> codigo;
                cout << "Ingrese nombre: ";
                cin >> nombre;
                
                // Configurar datos del alumno temporal
                temp.setCodigo(codigo);
                temp.setNombre(nombre);
                temp.setNotas();
                
                // Agregar al grupo
                grupo.agrega(temp);
                cout << "✓ Alumno agregado exitosamente!" << endl;
                break;
                
            case 2:  // LISTAR TODOS LOS ALUMNOS
                cout << "\n--- Listado de Alumnos ---" << endl;
                if(grupo.getIndice() == 0)
                {
                    cout << "No hay alumnos registrados." << endl;
                }
                else
                {
                    // Recorrer y mostrar cada alumno
                    for(int i = 0; i < grupo.getIndice(); i++)
                    {
                        cout << "\nAlumno #" << (i+1) << ":" << endl;
                        listar(grupo.getAlumno(i));
                    }
                }
                break;
                
            case 3:  // BUSCAR ALUMNO POR CÓDIGO
                cout << "\n--- Buscar Alumno ---" << endl;
                cout << "Codigo a buscar: ";
                cin >> codigo;
                {
                    int pos = grupo.busca(codigo);  // Buscar en el arreglo
                    if(pos >= 0)  // Encontrado
                    {
                        cout << "✓ Alumno encontrado en posicion " << pos << ":" << endl;
                        listar(grupo.getAlumno(pos));
                    }
                    else  // No encontrado
                    {
                        cout << "✗ Alumno no encontrado." << endl;
                    }
                }
                break;
                
            case 4:  // ELIMINAR ALUMNO POR CÓDIGO
                cout << "\n--- Eliminar Alumno ---" << endl;
                cout << "Codigo a eliminar: ";
                cin >> codigo;
                {
                    int pos = grupo.busca(codigo);  // Buscar primero
                    if(pos != -1)  // Encontrado
                    {
                        grupo.elimina(pos);  // Eliminar
                        cout << "✓ Alumno eliminado exitosamente." << endl;
                    }
                    else  // No encontrado
                    {
                        cout << "✗ Alumno no encontrado." << endl;
                    }
                }
                break;
                
            case 0:  // SALIR
                cout << "\n¡Hasta luego!" << endl;
                break;
                
            default:  // OPCIÓN INVÁLIDA
                cout << "\n✗ Opcion invalida. Intente de nuevo." << endl;
                break;
        }
    } while(opcion != 0);  // Repetir mientras no sea 0 (Salir)
    
    return 0;
}

/*
 * FLUJO DEL PROGRAMA:
 * 1. Crear objeto 'grupo' de tipo CAlumnos (contenedor vacío)
 * 2. Mostrar menú en bucle
 * 3. Procesar opción:
 *    - Agregar: Crea alumno temporal y lo agrega al arreglo
 *    - Listar: Recorre el arreglo y muestra cada alumno
 *    - Buscar: Busca por código y muestra si existe
 *    - Eliminar: Busca por código y elimina si existe
 * 4. Repetir hasta que usuario elija opción 0 (Salir)
 * 
 * MEJORAS POSIBLES:
 * - Validar que el código no esté duplicado al agregar
 * - Modificar datos de un alumno existente
 * - Ordenar alumnos por código o promedio
 * - Guardar/cargar datos en archivo
 */
