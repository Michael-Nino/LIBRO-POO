// Persona.h
// Proyecto que define la clase base CPersona
// Contiene datos personales y constructores

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <cstring>
using namespace std;

// Definición de la clase CPersona
class CPersona {
public:
    CPersona();
    CPersona(const char nom[], const char dn[], unsigned short e);
    CPersona(const CPersona &p);
    void Print();

private:
    char nombre[45];
    char dni[10];
    unsigned short edad;
};

// Constructor por defecto
CPersona::CPersona() {
    strcpy(nombre, "");
    strcpy(dni, "");
    edad = 0;
}

// Constructor con parámetros
CPersona::CPersona(const char nom[], const char dn[], unsigned short e) {
    strcpy(nombre, nom);
    strcpy(dni, dn);
    edad = e;
}

// Constructor de copia
CPersona::CPersona(const CPersona &p) {
    strcpy(nombre, p.nombre);
    strcpy(dni, p.dni);
    edad = p.edad;
}

// Función para imprimir datos
void CPersona::Print() {
    cout << "\nDatos de la persona:" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "DNI: " << dni << endl;
    cout << "Edad: " << edad << endl;
}

#endif // PERSONA_H
