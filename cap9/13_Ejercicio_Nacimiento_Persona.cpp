// Ejercicio_Nacimiento_Persona.cpp
// EJERCICIO PROPUESTO 3
// Clase base Nacimiento (fecha con validación) y clase derivada
// Persona (apellidos, nombres, edad calculada)

#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

// Clase Base: Nacimiento
class Nacimiento {
private:
    int dia, mes, anio;

public:
    // Pide al usuario la fecha de nacimiento
    void Leer();
    
    // Asigna los parámetros enviados a los datos miembros
    void SalvarFecha(int d, int m, int a);
    
    // Si fecha es correcta retorna verdadero,
    // en caso contrario escribe mensaje "Fecha incorrecta",
    // retorna falso y vuelve a pedir la fecha
    bool VerificarFecha();
    
    // Muestra la fecha de nacimiento en formato dd/mm/aa
    void Mostrar();
    
    // Si bisiesto retorna verdadero
    bool Bisiesto();
    
    // Retorna el año
    int getAnio();
};

// Implementación de Leer
void Nacimiento::Leer() {
    do {
        cout << "Ingrese dia: ";
        cin >> dia;
        cout << "Ingrese mes: ";
        cin >> mes;
        cout << "Ingrese anio: ";
        cin >> anio;
        
        if (!VerificarFecha()) {
            cout << "Fecha incorrecta. Intente nuevamente." << endl;
        }
    } while (!VerificarFecha());
}

// Implementación de SalvarFecha
void Nacimiento::SalvarFecha(int d, int m, int a) {
    dia = d;
    mes = m;
    anio = a;
}

// Implementación de VerificarFecha
bool Nacimiento::VerificarFecha() {
    // Verificar año válido (1900 - año actual)
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int anioActual = 1900 + ltm->tm_year;
    
    if (anio < 1900 || anio > anioActual) {
        return false;
    }
    
    // Verificar mes válido
    if (mes < 1 || mes > 12) {
        return false;
    }
    
    // Días por mes
    int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Ajustar febrero si es bisiesto
    if (Bisiesto()) {
        diasMes[2] = 29;
    }
    
    // Verificar día válido
    if (dia < 1 || dia > diasMes[mes]) {
        return false;
    }
    
    return true;
}

// Implementación de Mostrar
void Nacimiento::Mostrar() {
    cout << (dia < 10 ? "0" : "") << dia << "/"
         << (mes < 10 ? "0" : "") << mes << "/"
         << anio;
}

// Implementación de Bisiesto
bool Nacimiento::Bisiesto() {
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

// Implementación de getAnio
int Nacimiento::getAnio() {
    return anio;
}

// Clase Derivada: Persona
class Persona : public Nacimiento {
private:
    char Ape[25];
    char Nom[20];
    int Edad; // Se almacena la edad que cumplió o cumplirá este año

public:
    // Hace petición de apellidos y nombres y calcula la edad
    void Leer();
    
    // Muestra los datos de la persona
    void Mostrar();
    
    // Devuelve el nombre completo de la persona
    char* NombreCompleto();
};

// Implementación de Leer (Persona)
void Persona::Leer() {
    cout << "\n--- INGRESO DE DATOS PERSONALES ---" << endl;
    cout << "Apellidos: ";
    cin.ignore();
    cin.getline(Ape, 25);
    
    cout << "Nombres: ";
    cin.getline(Nom, 20);
    
    cout << "\nFecha de nacimiento:" << endl;
    Nacimiento::Leer();
    
    // Calcular edad
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int anioActual = 1900 + ltm->tm_year;
    
    Edad = anioActual - getAnio();
}

// Implementación de Mostrar (Persona)
void Persona::Mostrar() {
    cout << "\n--- DATOS DE LA PERSONA ---" << endl;
    cout << "Nombre completo: " << NombreCompleto() << endl;
    cout << "Fecha de nacimiento: ";
    Nacimiento::Mostrar();
    cout << endl;
    cout << "Edad: " << Edad << " años" << endl;
}

// Implementación de NombreCompleto
char* Persona::NombreCompleto() {
    static char nombreCompleto[50];
    strcpy(nombreCompleto, Nom);
    strcat(nombreCompleto, " ");
    strcat(nombreCompleto, Ape);
    return nombreCompleto;
}

// Programa principal
int main() {
    cout << "\n================================================" << endl;
    cout << "  EJERCICIO 3: NACIMIENTO Y PERSONA" << endl;
    cout << "================================================" << endl;
    
    // Ejemplo 1: Crear persona con ingreso manual
    Persona persona1;
    persona1.Leer();
    persona1.Mostrar();
    
    cout << "\n================================================" << endl;
    
    // Ejemplo 2: Crear otra persona
    cout << "\n\nDesea ingresar otra persona? (S/N): ";
    char opcion;
    cin >> opcion;
    
    if (opcion == 'S' || opcion == 's') {
        Persona persona2;
        persona2.Leer();
        persona2.Mostrar();
    }
    
    cout << "\n================================================" << endl;
    return 0;
}
