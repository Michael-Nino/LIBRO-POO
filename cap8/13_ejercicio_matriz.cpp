// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Ejercicio Propuesto 5: Clase Matriz con operaciones matriciales
 * 
 * OBJETIVO:
 * Implementar operaciones algebraicas con matrices
 * 
 * CONCEPTOS PRACTICADOS:
 * - Arreglo bidimensional como dato miembro
 * - Operadores aritméticos: +, -, * (producto matricial)
 * - Operador de asignación: =
 * - Operadores relacionales: ==, !=
 * - Validación de dimensiones para operaciones matriciales
 * 
 * OPERACIONES MATRICIALES:
 * - Suma/Resta: Solo si tienen las mismas dimensiones
 * - Producto: (m×n) * (n×p) = (m×p) → columnas de A = filas de B
 */

#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 10  // Tamaño máximo de matriz

class Matriz {
private:
    int datos[MAX][MAX];
    int filas;
    int columnas;
    
public:
    // Constructor
    Matriz(int f = 3, int c = 3) {
        filas = (f > 0 && f <= MAX) ? f : 3;
        columnas = (c > 0 && c <= MAX) ? c : 3;
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                datos[i][j] = 0;
    }
    
    // Getters
    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }
    
    // Método para establecer un valor
    void setValor(int f, int c, int valor) {
        if (f >= 0 && f < filas && c >= 0 && c < columnas)
            datos[f][c] = valor;
    }
    
    // Método para obtener un valor
    int getValor(int f, int c) const {
        if (f >= 0 && f < filas && c >= 0 && c < columnas)
            return datos[f][c];
        return 0;
    }
    
    // Operador de asignación =
    Matriz& operator=(const Matriz& m) {
        if (this != &m) {
            filas = m.filas;
            columnas = m.columnas;
            for (int i = 0; i < filas; i++)
                for (int j = 0; j < columnas; j++)
                    datos[i][j] = m.datos[i][j];
        }
        return *this;
    }
    
    // Operador de suma +
    Matriz operator+(const Matriz& m) const {
        if (filas != m.filas || columnas != m.columnas) {
            cout << "Error: Las matrices deben tener las mismas dimensiones" << endl;
            return *this;
        }
        
        Matriz resultado(filas, columnas);
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                resultado.datos[i][j] = datos[i][j] + m.datos[i][j];
        
        return resultado;
    }
    
    // Operador de resta -
    Matriz operator-(const Matriz& m) const {
        if (filas != m.filas || columnas != m.columnas) {
            cout << "Error: Las matrices deben tener las mismas dimensiones" << endl;
            return *this;
        }
        
        Matriz resultado(filas, columnas);
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                resultado.datos[i][j] = datos[i][j] - m.datos[i][j];
        
        return resultado;
    }
    
    // Operador de multiplicación *
    Matriz operator*(const Matriz& m) const {
        if (columnas != m.filas) {
            cout << "Error: El numero de columnas de la primera matriz debe ser igual al numero de filas de la segunda" << endl;
            return *this;
        }
        
        Matriz resultado(filas, m.columnas);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < m.columnas; j++) {
                resultado.datos[i][j] = 0;
                for (int k = 0; k < columnas; k++)
                    resultado.datos[i][j] += datos[i][k] * m.datos[k][j];
            }
        }
        
        return resultado;
    }
    
    // Operador de igualdad ==
    bool operator==(const Matriz& m) const {
        if (filas != m.filas || columnas != m.columnas)
            return false;
        
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                if (datos[i][j] != m.datos[i][j])
                    return false;
        
        return true;
    }
    
    // Operador de desigualdad !=
    bool operator!=(const Matriz& m) const {
        return !(*this == m);
    }
    
    // Método para imprimir la matriz
    void imprimir() const {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++)
                cout << setw(6) << datos[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    cout << "=== OPERACIONES CON MATRICES ===" << endl << endl;
    
    // Crear matrices
    Matriz m1(3, 3), m2(3, 3), m3(3, 2);
    
    // Inicializar matriz 1
    cout << "Matriz M1 (3x3):" << endl;
    m1.setValor(0, 0, 1); m1.setValor(0, 1, 2); m1.setValor(0, 2, 3);
    m1.setValor(1, 0, 4); m1.setValor(1, 1, 5); m1.setValor(1, 2, 6);
    m1.setValor(2, 0, 7); m1.setValor(2, 1, 8); m1.setValor(2, 2, 9);
    m1.imprimir();
    cout << endl;
    
    // Inicializar matriz 2
    cout << "Matriz M2 (3x3):" << endl;
    m2.setValor(0, 0, 9); m2.setValor(0, 1, 8); m2.setValor(0, 2, 7);
    m2.setValor(1, 0, 6); m2.setValor(1, 1, 5); m2.setValor(1, 2, 4);
    m2.setValor(2, 0, 3); m2.setValor(2, 1, 2); m2.setValor(2, 2, 1);
    m2.imprimir();
    cout << endl;
    
    // Suma de matrices
    cout << "M1 + M2 =" << endl;
    Matriz suma = m1 + m2;
    suma.imprimir();
    cout << endl;
    
    // Resta de matrices
    cout << "M1 - M2 =" << endl;
    Matriz resta = m1 - m2;
    resta.imprimir();
    cout << endl;
    
    // Inicializar matriz 3 para multiplicación
    cout << "Matriz M3 (3x2):" << endl;
    m3.setValor(0, 0, 1); m3.setValor(0, 1, 2);
    m3.setValor(1, 0, 3); m3.setValor(1, 1, 4);
    m3.setValor(2, 0, 5); m3.setValor(2, 1, 6);
    m3.imprimir();
    cout << endl;
    
    // Multiplicación de matrices
    cout << "M1 * M3 =" << endl;
    Matriz producto = m1 * m3;
    producto.imprimir();
    cout << endl;
    
    // Comparación de matrices
    cout << "Comparando M1 y M2:" << endl;
    if (m1 == m2)
        cout << "M1 es IGUAL a M2" << endl;
    else
        cout << "M1 es DIFERENTE de M2" << endl;
    cout << endl;
    
    // Asignación
    cout << "Asignando M2 a M4:" << endl;
    Matriz m4 = m2;
    cout << "M4:" << endl;
    m4.imprimir();
    cout << endl;
    
    cout << "Comparando M2 y M4:" << endl;
    if (m2 == m4)
        cout << "M2 es IGUAL a M4" << endl;
    else
        cout << "M2 es DIFERENTE de M4" << endl;
    
    return 0;
}
