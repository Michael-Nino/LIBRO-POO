// Persona_Alumno_Main.cpp
// Programa principal que utiliza las clases CPersona y CAlumno
// Demuestra herencia y uso de constructores

#include <iostream>
#include "09_Alumno.h"
using namespace std;

int main() {
    cout << "\n========================================" << endl;
    cout << "PROYECTO: PERSONA Y ALUMNO" << endl;
    cout << "========================================" << endl;
    
    // Crear objeto de tipo CPersona
    CPersona unaPer("Luis Alberto", "45123698", 31);
    unaPer.Print();
    
    // Crear objeto de tipo CAlumno
    cout << "\n========================================" << endl;
    CAlumno unAlumno("Pedro Martin", "36001523", 17, "08BITAB6", "Prog.Industrial");
    unAlumno.Print();
    
    cout << "========================================" << endl;
    return 0;
}
