// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Ejercicio Propuesto 4: Clase Polinomio con sobrecarga de operadores
 * 
 * OBJETIVO:
 * Implementar operaciones aritméticas con polinomios
 * 
 * CONCEPTOS PRACTICADOS:
 * - Arreglo de estructuras (monomio)
 * - Operadores aritméticos: +, -
 * - Operadores de asignación compuesta: +=, -=
 * - Gestión de términos semejantes (mismo exponente)
 * - Constructor de copia para manejo correcto de objetos
 * 
 * REPRESENTACIÓN:
 * Polinomio = suma de monomios (coeficiente * x^exponente)
 * Ejemplo: 3x² + 2x - 5
 */

#include <iostream>
#include <cmath>
using namespace std;

#define N 100  // Máximo número de términos

struct monomio {
    float coef;
    float exp;
    
    // se crea un termino independiente
    monomio() {
        coef = 0;
        exp = 0;
    }
};

class Polinomio {
private:
    monomio mons[N];
    int size;
    
public:
    Polinomio(float co = 0, float ex = 0);
    Polinomio(const Polinomio&);
    ~Polinomio() {}
    
    void add(const monomio&);
    void add(float co, float ex);
    int getSize() { return size; }
    
    // Polinomio + Polinomio
    Polinomio operator+(const Polinomio&);
    // Polinomio - Polinomio
    Polinomio operator-(const Polinomio&);
    // Polinomio += Polinomio
    Polinomio& operator+=(const Polinomio&);
    // Polinomio -= Polinomio
    Polinomio& operator-=(const Polinomio&);
    
    friend void print(const Polinomio& pol);
};

// Constructor
Polinomio::Polinomio(float co, float ex) {
    size = 0;
    if (co != 0) {
        mons[0].coef = co;
        mons[0].exp = ex;
        size = 1;
    }
}

// Constructor de copia
Polinomio::Polinomio(const Polinomio& p) {
    size = p.size;
    for (int i = 0; i < size; i++) {
        mons[i] = p.mons[i];
    }
}

// Agregar monomio
void Polinomio::add(const monomio& m) {
    if (size < N) {
        // Buscar si ya existe un termino con el mismo exponente
        for (int i = 0; i < size; i++) {
            if (mons[i].exp == m.exp) {
                mons[i].coef += m.coef;
                return;
            }
        }
        // Si no existe, agregar el nuevo monomio
        mons[size++] = m;
    }
}

void Polinomio::add(float co, float ex) {
    monomio m;
    m.coef = co;
    m.exp = ex;
    add(m);
}

// Suma de polinomios
Polinomio Polinomio::operator+(const Polinomio& p) {
    Polinomio resultado(*this);
    
    for (int i = 0; i < p.size; i++) {
        resultado.add(p.mons[i]);
    }
    
    return resultado;
}

// Resta de polinomios
Polinomio Polinomio::operator-(const Polinomio& p) {
    Polinomio resultado(*this);
    
    for (int i = 0; i < p.size; i++) {
        monomio m;
        m.coef = -p.mons[i].coef;
        m.exp = p.mons[i].exp;
        resultado.add(m);
    }
    
    return resultado;
}

// Suma y asignación
Polinomio& Polinomio::operator+=(const Polinomio& p) {
    *this = *this + p;
    return *this;
}

// Resta y asignación
Polinomio& Polinomio::operator-=(const Polinomio& p) {
    *this = *this - p;
    return *this;
}

// Función para imprimir el polinomio
void print(const Polinomio& pol) {
    if (pol.size == 0) {
        cout << "0";
        return;
    }
    
    for (int i = 0; i < pol.size; i++) {
        if (i > 0 && pol.mons[i].coef > 0)
            cout << " + ";
        else if (pol.mons[i].coef < 0)
            cout << " - ";
        
        float coef = fabs(pol.mons[i].coef);
        
        if (pol.mons[i].exp == 0) {
            cout << coef;
        } else if (pol.mons[i].exp == 1) {
            if (coef == 1)
                cout << "x";
            else
                cout << coef << "x";
        } else {
            if (coef == 1)
                cout << "x^" << pol.mons[i].exp;
            else
                cout << coef << "x^" << pol.mons[i].exp;
        }
    }
}

int main() {
    cout << "=== OPERACIONES CON POLINOMIOS ===" << endl << endl;
    
    // Crear polinomios: P1(x) = 3x^2 + 2x + 1
    Polinomio p1(3, 2);
    p1.add(2, 1);
    p1.add(1, 0);
    
    cout << "P1(x) = ";
    print(p1);
    cout << endl;
    
    // Crear P2(x) = 2x^2 + 4x + 3
    Polinomio p2(2, 2);
    p2.add(4, 1);
    p2.add(3, 0);
    
    cout << "P2(x) = ";
    print(p2);
    cout << endl << endl;
    
    // Suma de polinomios
    Polinomio p3 = p1 + p2;
    cout << "P3(x) = P1(x) + P2(x) = ";
    print(p3);
    cout << endl << endl;
    
    // Resta de polinomios
    Polinomio p4 = p1 - p2;
    cout << "P4(x) = P1(x) - P2(x) = ";
    print(p4);
    cout << endl << endl;
    
    // Operador +=
    Polinomio p5(1, 1);
    p5.add(1, 0);
    cout << "P5(x) = ";
    print(p5);
    cout << endl;
    
    p5 += p1;
    cout << "P5(x) += P1(x) = ";
    print(p5);
    cout << endl << endl;
    
    // Operador -=
    Polinomio p6(5, 2);
    p6.add(3, 1);
    cout << "P6(x) = ";
    print(p6);
    cout << endl;
    
    p6 -= p2;
    cout << "P6(x) -= P2(x) = ";
    print(p6);
    cout << endl;
    
    return 0;
}
