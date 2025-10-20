// Herencia_Empleado.cpp
// Herencia múltiple: Empleado, Asalariado, Estudiante, Practicante
// Demuestra el uso de herencia múltiple en C++

#include <iostream>
using namespace std;

// Clase Base Empleado
class Empleado {
private:
    int edad;
public:
    Empleado(int n) : edad(n) {}
    void setedad(int n) { edad = n; }
    int getedad() { return edad; }
};

// Clase Asalariado que hereda de Empleado
class Asalariado : public Empleado {
private:
    float salario;
public:
    Asalariado(float sal = 0, int n = 0);
    void setsalario(float n) { salario = n; }
    float getsalario() { return salario; }
};

Asalariado::Asalariado(float sal, int n) : Empleado(n) {
    salario = sal;
}

// Clase Estudiante
class Estudiante {
private:
    int ident;
    int grado;
    int edad;
public:
    Estudiante(int n1, int n2, int n3) {
        ident = n1;
        grado = n2;
        edad = n3;
    }
    void setident(int n) { ident = n; }
    int getident() { return ident; }
    void setgrado(int n) { grado = n; }
    int getgrado() { return grado; }
    void setedad(int n) { edad = n; }
    int getedad() { return edad; }
};

// Clase Practicante con herencia múltiple
class Practicante : public Estudiante, public Asalariado {
public:
    Practicante(int n1, int n2, int n3, float sal) :
        Estudiante(n1, n2, n3), Asalariado(sal) {}
    void print();
};

void Practicante::print() {
    cout << "ident   : " << getident() << endl;
    cout << "edad    : " << Estudiante::getedad() << endl;
    cout << "grado   : " << getgrado() << endl;
    cout << "salario : " << getsalario() << endl;
}

int main() {
    cout << "\nHerencia Multiple - Practicante" << endl;
    cout << "--------------------------------" << endl;
    
    Practicante Pedro(2001, 5, 25, 1200);
    Pedro.print();
    
    cout << endl;
    return 0;
}
