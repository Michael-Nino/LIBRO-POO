// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Ejercicio Propuesto 3: Clase Ascensor con operadores unarios y relacionales
 * 
 * OBJETIVO:
 * Simular un ascensor con sobrecarga de operadores ++ (subir), -- (bajar),
 * == (igualdad), != (desigualdad)
 * 
 * CONCEPTOS PRACTICADOS:
 * - Operadores unarios: ++ y -- (prefijo y posfijo)
 * - Operadores relacionales: == y !=
 * - Validación de límites (no subir más allá del último piso)
 * - Retorno por referencia en operadores de asignación
 * 
 * DIFERENCIA PREFIJO/POSFIJO:
 * ++obj  → Prefijo: incrementa y retorna *this
 * obj++  → Posfijo: guarda copia, incrementa, retorna copia
 */

#include <iostream>
using namespace std;

class Ascensor {
private:
    int pisoActual;
    int numeroPisos;
    int capacidad; // capacidad en personas
    
public:
    // Constructor
    Ascensor(int pisos = 10, int cap = 8) {
        numeroPisos = pisos;
        capacidad = cap;
        pisoActual = 0; // inicia en planta baja
    }
    
    // Getters
    int getPisoActual() const { return pisoActual; }
    int getNumeroPisos() const { return numeroPisos; }
    int getCapacidad() const { return capacidad; }
    
    // Operador ++ prefijo (subir un piso)
    Ascensor& operator++() {
        if (pisoActual < numeroPisos - 1) {
            pisoActual++;
            cout << "Subiendo... Ahora en piso " << pisoActual << endl;
        } else {
            cout << "Ya esta en el ultimo piso!" << endl;
        }
        return *this;
    }
    
    // Operador ++ posfijo (subir un piso)
    Ascensor operator++(int) {
        Ascensor temp = *this;
        ++(*this);
        return temp;
    }
    
    // Operador -- prefijo (bajar un piso)
    Ascensor& operator--() {
        if (pisoActual > 0) {
            pisoActual--;
            cout << "Bajando... Ahora en piso " << pisoActual << endl;
        } else {
            cout << "Ya esta en la planta baja!" << endl;
        }
        return *this;
    }
    
    // Operador -- posfijo (bajar un piso)
    Ascensor operator--(int) {
        Ascensor temp = *this;
        --(*this);
        return temp;
    }
    
    // Operador == (igualdad)
    // Dos ascensores son iguales si tienen el mismo número de pisos y capacidad
    bool operator==(const Ascensor& otro) const {
        return (numeroPisos == otro.numeroPisos && 
                capacidad == otro.capacidad);
    }
    
    // Operador != (desigualdad)
    bool operator!=(const Ascensor& otro) const {
        return !(*this == otro);
    }
    
    // Método para mostrar información
    void mostrarInfo() const {
        cout << "Ascensor - Piso actual: " << pisoActual 
             << " | Total pisos: " << numeroPisos 
             << " | Capacidad: " << capacidad << " personas" << endl;
    }
};

int main() {
    cout << "=== SIMULADOR DE ASCENSORES ===" << endl << endl;
    
    // Crear dos ascensores
    Ascensor ascensor1(10, 8);  // 10 pisos, capacidad 8 personas
    Ascensor ascensor2(10, 8);  // 10 pisos, capacidad 8 personas
    Ascensor ascensor3(15, 10); // 15 pisos, capacidad 10 personas
    
    cout << "Estado inicial:" << endl;
    cout << "Ascensor 1: ";
    ascensor1.mostrarInfo();
    cout << "Ascensor 2: ";
    ascensor2.mostrarInfo();
    cout << "Ascensor 3: ";
    ascensor3.mostrarInfo();
    cout << endl;
    
    // Probar operador ==
    cout << "Comparando ascensores 1 y 2:" << endl;
    if (ascensor1 == ascensor2)
        cout << "Los ascensores 1 y 2 son IGUALES (mismo tipo)" << endl;
    else
        cout << "Los ascensores 1 y 2 son DIFERENTES" << endl;
    cout << endl;
    
    cout << "Comparando ascensores 1 y 3:" << endl;
    if (ascensor1 != ascensor3)
        cout << "Los ascensores 1 y 3 son DIFERENTES (distinto tipo)" << endl;
    else
        cout << "Los ascensores 1 y 3 son IGUALES" << endl;
    cout << endl;
    
    // Probar operador ++ (subir pisos)
    cout << "Moviendo ascensor 1:" << endl;
    ++ascensor1; // subir al piso 1
    ++ascensor1; // subir al piso 2
    ++ascensor1; // subir al piso 3
    ascensor1.mostrarInfo();
    cout << endl;
    
    // Probar operador -- (bajar pisos)
    cout << "Bajando ascensor 1:" << endl;
    --ascensor1; // bajar al piso 2
    --ascensor1; // bajar al piso 1
    ascensor1.mostrarInfo();
    cout << endl;
    
    // Intentar bajar más allá de la planta baja
    cout << "Intentando bajar mas alla de la planta baja:" << endl;
    --ascensor1; // bajar al piso 0
    --ascensor1; // intento de bajar del piso 0
    cout << endl;
    
    // Subir hasta el último piso
    cout << "Subiendo ascensor 3 hasta el ultimo piso:" << endl;
    for (int i = 0; i < 15; i++) {
        ++ascensor3;
    }
    ascensor3.mostrarInfo();
    
    return 0;
}
