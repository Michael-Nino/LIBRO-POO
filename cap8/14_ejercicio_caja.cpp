// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Ejercicio Propuesto 6: Clase Caja con operadores aritméticos
 * 
 * OBJETIVO:
 * Implementar operaciones con objetos Caja (longitud, ancho, altura)
 * 
 * CONCEPTOS PRACTICADOS:
 * - Sobrecarga de operadores con diferentes tipos de parámetros
 * - Operadores friend para permitir operandos de diferentes tipos
 * - Operadores de incremento (prefijo y posfijo)
 * - Operaciones dimensionales (suma por dimensión, multiplicación escalar)
 * 
 * OPERACIONES:
 * - Caja + Caja: Suma dimensión por dimensión
 * - int + Caja: Añade constante a cada dimensión
 * - int * Caja: Multiplica cada dimensión por constante
 * - ++Caja: Incrementa cada dimensión en 1
 */

#include <iostream>
using namespace std;

class Caja {
    double longitud;
    double ancho, altura;
    
public:
    void set(int l, int w, int h) { 
        longitud = l; 
        ancho = w; 
        altura = h; 
    }
    
    void get() { 
        cout << "\nLongitud " << longitud 
             << ", Ancho " << ancho 
             << " Altura " << altura << endl; 
    }
    
    int volumen(void) { 
        return longitud * ancho * altura; 
    }
    
    friend Caja operator+(Caja a, Caja b); // Adiciona dos Cajas
    friend Caja operator+(int a, Caja b);   // Adiciona un constante a una Caja
    friend Caja operator*(int a, Caja b);   // Multiplica una Caja por un int
    
    Caja operator++();      // Incremento prefijo
    Caja operator++(int);   // Incremento posfijo
};

// Adiciona dos Cajas: suma dimensión por dimensión
Caja operator+(Caja a, Caja b) {
    Caja resultado;
    resultado.longitud = a.longitud + b.longitud;
    resultado.ancho = a.ancho + b.ancho;
    resultado.altura = a.altura + b.altura;
    return resultado;
}

// Adiciona una constante a cada dimensión de una Caja
Caja operator+(int a, Caja b) {
    Caja resultado;
    resultado.longitud = a + b.longitud;
    resultado.ancho = a + b.ancho;
    resultado.altura = a + b.altura;
    return resultado;
}

// Multiplica cada dimensión de una Caja por una constante
Caja operator*(int a, Caja b) {
    Caja resultado;
    resultado.longitud = a * b.longitud;
    resultado.ancho = a * b.ancho;
    resultado.altura = a * b.altura;
    return resultado;
}

// Incremento prefijo: incrementa cada dimensión en 1 y retorna la referencia
Caja Caja::operator++() {
    ++longitud;
    ++ancho;
    ++altura;
    return *this;
}

// Incremento posfijo: incrementa cada dimensión en 1 pero retorna el valor anterior
Caja Caja::operator++(int) {
    Caja temp = *this;
    longitud++;
    ancho++;
    altura++;
    return temp;
}

int main() {
    Caja pequena, mediana, grande;
    Caja temp;
    
    pequena.set(2, 4, 5);
    mediana.set(5, 6, 8);
    grande.set(8, 10, 12);
    
    cout << "*** CLASE CAJAS ****" << endl;
    
    cout << "\nPequena:";
    pequena.get();
    cout << "El volumen de pequena es " << pequena.volumen() << "\n";
    
    cout << "\nMediana:";
    mediana.get();
    cout << "El volumen de mediana es " << mediana.volumen() << "\n";
    
    cout << "\nGrande:";
    grande.get();
    cout << "El volumen de grande es " << grande.volumen() << "\n";
    
    temp = pequena + mediana;
    cout << "\npequena + mediana";
    temp.get();
    cout << "\nEl nuevo volumen es " << temp.volumen() << "\n";
    
    temp = 10 + pequena;
    cout << "\n10 + pequena";
    temp.get();
    cout << "El nuevo volumen es " << temp.volumen() << "\n";
    
    temp = 4 * grande;
    cout << "\n4 * grande";
    temp.get();
    cout << "El nuevo volumen es " << temp.volumen() << "\n";
    
    ++pequena;
    cout << "\nIncremento prefijo a pequena:";
    pequena.get();
    cout << "El volumen es " << pequena.volumen() << "\n";
    
    grande++;
    cout << "\nIncremento posfijo a grande";
    grande.get();
    cout << "El volumen es " << grande.volumen() << "\n";
    
    return 0;
}
