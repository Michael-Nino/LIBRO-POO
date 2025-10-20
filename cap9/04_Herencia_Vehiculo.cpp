#include <iostream>
using namespace std;

// Muestra el concepto de clase base y clase derivada
// Un auto es un vehiculo

// Clase base
class Vehiculo {
private:
    int Peso;
    int MaxVeloc;
    float Precio;
public:
    Vehiculo(int, int, float);
    ~Vehiculo() {}
    int getPeso();
    int getMaxVeloc();
    float getPrecio();
    void Print();
};

// Implementación de funciones miembro de la clase base
Vehiculo::Vehiculo(int pe, int maxV, float prec) {
    Peso = pe;
    MaxVeloc = maxV;
    Precio = prec;
}

int Vehiculo::getPeso() {
    return Peso;
}

int Vehiculo::getMaxVeloc() {
    return MaxVeloc;
}

float Vehiculo::getPrecio() {
    return Precio;
}

// Print para la clase base
void Vehiculo::Print() {
    cout << "\nPeso: " << Peso << " kg";
    cout << "\nVelocidad Maxima: " << MaxVeloc << " km/h";
    cout << "\nPrecio: " << Precio << " Dolares";
}

// Clase derivada Auto
class Auto : public Vehiculo {
private:
    int NumeroCilindros;
    int PotenciaCaballos;
    int Desplazamiento;
public:
    Auto() : Vehiculo(0, 0, 0.0) {}
    Auto(int, int, float, int, int, int);
    ~Auto() {}
    int getNumeroCilindros();
    int getPotenciaCaballos();
    int getDesplazamiento();
    void Print();
};

// Constructor para la clase derivada
Auto::Auto(int pe, int maxV, float prec, int NumCil, int PotCaba, int Despla) 
    : Vehiculo(pe, maxV, prec) {
    NumeroCilindros = NumCil;
    PotenciaCaballos = PotCaba;
    Desplazamiento = Despla;
}

int Auto::getNumeroCilindros() {
    return NumeroCilindros;
}

int Auto::getPotenciaCaballos() {
    return PotenciaCaballos;
}

int Auto::getDesplazamiento() {
    return Desplazamiento;
}

// Print para la clase derivada - heredando de la clase padre
void Auto::Print() {
    Vehiculo::Print(); // Llama al Print de la clase base
    cout << "\nNumero de Cilindros: " << NumeroCilindros;
    cout << "\nCaballos de Fuerza: " << PotenciaCaballos;
    cout << "\nDesplazamiento: " << Desplazamiento << " cm cubicos";
}

int main() { // Herencia_Vehiculo.cpp
    Vehiculo unVehiculo(4500, 120, 30000.00);
    cout << "\nUn Vehiculo: ";
    unVehiculo.Print();
    cout << endl << endl;
    
    Auto unAuto(1500, 180, 12000.00, 6, 120, 300);
    cout << "\nUn Auto: ";
    unAuto.Print();
    cout << endl << endl;
    
    return 0;
}
