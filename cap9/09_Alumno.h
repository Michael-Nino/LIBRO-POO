// Alumno.h
// Proyecto que define la clase derivada CAlumno
// Hereda de CPersona y añade información académica

#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <cstring>
#include "08_Persona.h"

// Definición de la clase CAlumno
class CAlumno : public CPersona {
public:
    CAlumno();
    CAlumno(const char nom[], const char dn[], unsigned short e, const char cod[], const char cur[]);
    CAlumno(const CAlumno &a);
    float Promedio();
    void Print();

private:
    char codigo[10];
    char curso[30];
    short notas[4];
};

// Constructor por defecto
CAlumno::CAlumno() : CPersona() {
    strcpy(codigo, "");
    strcpy(curso, "");
    for (int i = 0; i < 4; i++)
        notas[i] = 0;
}

// Constructor con parámetros
CAlumno::CAlumno(const char nom[], const char dn[], unsigned short e, const char cod[], const char cur[]) 
    : CPersona(nom, dn, e) {
    strcpy(codigo, cod);
    strcpy(curso, cur);
    cout << "Ingrese 4 notas: ";
    for (int i = 0; i < 4; i++)
        cin >> notas[i];
}

// Constructor de copia
CAlumno::CAlumno(const CAlumno &a) : CPersona(a) {
    strcpy(codigo, a.codigo);
    strcpy(curso, a.curso);
    for (int i = 0; i < 4; i++)
        notas[i] = a.notas[i];
}

// Calcular promedio de notas
float CAlumno::Promedio() {
    float acum = 0;
    for (int i = 0; i < 4; i++)
        acum += notas[i];
    return acum / 4.0;
}

// Imprimir datos del alumno
void CAlumno::Print() {
    CPersona::Print();
    cout << "Codigo: " << codigo << endl;
    cout << "Curso: " << curso << endl;
    cout << "Notas: ";
    for (int i = 0; i < 4; i++)
        cout << notas[i] << " ";
    cout << endl;
    cout << "Promedio: " << Promedio() << endl << endl;
}

#endif // ALUMNO_H
