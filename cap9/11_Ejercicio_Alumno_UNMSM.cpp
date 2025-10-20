// Ejercicio_Alumno_UNMSM.cpp
// EJERCICIO PROPUESTO 1
// Clase persona (nombre, edad, sexo, estado civil) y clase derivada
// alumno_unmsm con 5 cursos y promedio ponderado

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// Clase Base: Persona
class persona {
private:
    char nombre[50];
    int edad;
    char sexo; // 'M' o 'F'
    char estado_civil[20]; // Soltero, Casado, Divorciado, Viudo

public:
    // Constructores
    persona();
    persona(char nom[], int ed, char sex, char est[]);
    persona(const persona &p);
    
    // Funciones set
    void set_nombre(char nom[]);
    void set_edad(int ed);
    void set_sexo(char sex);
    void set_estado_civil(char est[]);
    
    // Funciones get
    char* get_nombre();
    int get_edad();
    char get_sexo();
    char* get_estado_civil();
    
    // Función print
    void print();
};

// Implementación de constructores de persona
persona::persona() {
    strcpy(nombre, "");
    edad = 0;
    sexo = 'M';
    strcpy(estado_civil, "Soltero");
}

persona::persona(char nom[], int ed, char sex, char est[]) {
    strcpy(nombre, nom);
    edad = ed;
    sexo = sex;
    strcpy(estado_civil, est);
}

persona::persona(const persona &p) {
    strcpy(nombre, p.nombre);
    edad = p.edad;
    sexo = p.sexo;
    strcpy(estado_civil, p.estado_civil);
}

// Implementación de funciones set
void persona::set_nombre(char nom[]) {
    strcpy(nombre, nom);
}

void persona::set_edad(int ed) {
    edad = ed;
}

void persona::set_sexo(char sex) {
    sexo = sex;
}

void persona::set_estado_civil(char est[]) {
    strcpy(estado_civil, est);
}

// Implementación de funciones get
char* persona::get_nombre() {
    return nombre;
}

int persona::get_edad() {
    return edad;
}

char persona::get_sexo() {
    return sexo;
}

char* persona::get_estado_civil() {
    return estado_civil;
}

// Implementación de print
void persona::print() {
    cout << "\n--- DATOS PERSONALES ---" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << " años" << endl;
    cout << "Sexo: " << (sexo == 'M' ? "Masculino" : "Femenino") << endl;
    cout << "Estado Civil: " << estado_civil << endl;
}

// Clase Derivada: alumno_unmsm
class alumno_unmsm : public persona {
private:
    char codigo[10];
    char nombres_cursos[5][50];
    float notas_curso[5];
    int peso[5]; // creditaje por curso

public:
    // Constructores
    alumno_unmsm();
    alumno_unmsm(char nom[], int ed, char sex, char est[], char cod[]);
    
    // Funciones set
    void set_codigo(char cod[]);
    void set_curso(int pos, char nombre_curso[], float nota, int creditos);
    
    // Funciones get
    char* get_codigo();
    void get_curso(int pos, char nombre_curso[], float &nota, int &creditos);
    
    // Función de cálculo
    float promedio_ponderado();
    
    // Función print
    void print();
};

// Implementación de constructores de alumno_unmsm
alumno_unmsm::alumno_unmsm() : persona() {
    strcpy(codigo, "");
    for (int i = 0; i < 5; i++) {
        strcpy(nombres_cursos[i], "");
        notas_curso[i] = 0.0;
        peso[i] = 0;
    }
}

alumno_unmsm::alumno_unmsm(char nom[], int ed, char sex, char est[], char cod[])
    : persona(nom, ed, sex, est) {
    strcpy(codigo, cod);
    for (int i = 0; i < 5; i++) {
        strcpy(nombres_cursos[i], "");
        notas_curso[i] = 0.0;
        peso[i] = 0;
    }
}

// Implementación de funciones set
void alumno_unmsm::set_codigo(char cod[]) {
    strcpy(codigo, cod);
}

void alumno_unmsm::set_curso(int pos, char nombre_curso[], float nota, int creditos) {
    if (pos >= 0 && pos < 5) {
        strcpy(nombres_cursos[pos], nombre_curso);
        notas_curso[pos] = nota;
        peso[pos] = creditos;
    }
}

// Implementación de funciones get
char* alumno_unmsm::get_codigo() {
    return codigo;
}

void alumno_unmsm::get_curso(int pos, char nombre_curso[], float &nota, int &creditos) {
    if (pos >= 0 && pos < 5) {
        strcpy(nombre_curso, nombres_cursos[pos]);
        nota = notas_curso[pos];
        creditos = peso[pos];
    }
}

// Cálculo del promedio ponderado
float alumno_unmsm::promedio_ponderado() {
    float suma_ponderada = 0.0;
    int suma_creditos = 0;
    
    for (int i = 0; i < 5; i++) {
        suma_ponderada += notas_curso[i] * peso[i];
        suma_creditos += peso[i];
    }
    
    if (suma_creditos == 0) return 0.0;
    return suma_ponderada / suma_creditos;
}

// Implementación de print para alumno_unmsm
void alumno_unmsm::print() {
    persona::print();
    cout << "\n--- DATOS ACADEMICOS ---" << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "\nCURSOS MATRICULADOS:" << endl;
    cout << setw(30) << left << "Curso" 
         << setw(10) << "Nota" 
         << setw(10) << "Creditos" << endl;
    cout << string(50, '-') << endl;
    
    for (int i = 0; i < 5; i++) {
        if (strlen(nombres_cursos[i]) > 0) {
            cout << setw(30) << left << nombres_cursos[i]
                 << setw(10) << notas_curso[i]
                 << setw(10) << peso[i] << endl;
        }
    }
    
    cout << string(50, '-') << endl;
    cout << "PROMEDIO PONDERADO: " << fixed << setprecision(2) 
         << promedio_ponderado() << endl;
}

// Programa principal
int main() {
    cout << "\n================================================" << endl;
    cout << "  EJERCICIO 1: ALUMNO UNMSM" << endl;
    cout << "================================================" << endl;
    
    // Crear objeto alumno_unmsm
    alumno_unmsm estudiante("Juan Carlos Perez Lopez", 20, 'M', "Soltero", "20241234");
    
    // Asignar cursos con notas y créditos
    estudiante.set_curso(0, "Algoritmos y Programacion", 18.5, 5);
    estudiante.set_curso(1, "Calculo Diferencial", 16.0, 4);
    estudiante.set_curso(2, "Fisica I", 17.5, 5);
    estudiante.set_curso(3, "Quimica General", 15.0, 4);
    estudiante.set_curso(4, "Geometria Analitica", 19.0, 3);
    
    // Mostrar datos completos
    estudiante.print();
    
    cout << "\n================================================" << endl;
    return 0;
}
