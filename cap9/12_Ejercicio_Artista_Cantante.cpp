// Ejercicio_Artista_Cantante.cpp
// EJERCICIO PROPUESTO 2
// Clase artista (nombre, fecha nacimiento, país, sexo) y clase derivada
// cantante (género musical, canciones, repertorio)

#include <iostream>
#include <cstring>
using namespace std;

// Estructura para fecha
struct fecha {
    int dia;
    int mes;
    int anio;
};

// Clase Base: artista
class artista {
private:
    char nombre[30];    // nombre del artista
    fecha fecnac;       // fecha de nacimiento del artista
    char paisnac[15];   // país de nacimiento del artista
    char sexo;          // sexo del artista

public:
    // Constructor
    artista(char n[30], fecha f, char p[15], char s);
    
    // Destructor
    ~artista();
    
    // Ingreso de los datos del artista
    void ingresar();
    
    // Impresión de los datos del artista
    void imprimir();
};

// Implementación del constructor de artista
artista::artista(char n[30], fecha f, char p[15], char s) {
    strcpy(nombre, n);
    fecnac = f;
    strcpy(paisnac, p);
    sexo = s;
}

// Implementación del destructor
artista::~artista() {
    // Destructor
}

// Implementación de ingresar
void artista::ingresar() {
    cout << "\n--- INGRESO DE DATOS DEL ARTISTA ---" << endl;
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(nombre, 30);
    
    cout << "Fecha de nacimiento (dd mm aaaa): ";
    cin >> fecnac.dia >> fecnac.mes >> fecnac.anio;
    
    cout << "Pais de nacimiento: ";
    cin.ignore();
    cin.getline(paisnac, 15);
    
    cout << "Sexo (M/F): ";
    cin >> sexo;
}

// Implementación de imprimir
void artista::imprimir() {
    cout << "\n--- DATOS DEL ARTISTA ---" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Fecha de nacimiento: " << fecnac.dia << "/" 
         << fecnac.mes << "/" << fecnac.anio << endl;
    cout << "Pais: " << paisnac << endl;
    cout << "Sexo: " << (sexo == 'M' ? "Masculino" : "Femenino") << endl;
}

// Clase Derivada: cantante
class cantante : public artista {
private:
    char genero[15];              // género musical del cantante
    char canciones[200][40];      // lista de canciones interpretadas
    int cantcanciones;            // cantidad de canciones

public:
    // Constructor
    cantante(char n[30], fecha f, char p[15], char s, char g[15]);
    
    // Destructor
    ~cantante();
    
    // Ingreso de los datos del cantante y sus canciones
    void ingresar();
    
    // Impresión de los datos del cantante
    void imprimir();
    
    // Devolución del género musical del cantante
    void getgenero(char g[15]);
    
    // Impresión de las canciones interpretadas por el cantante
    void repertorio();
};

// Implementación del constructor de cantante
cantante::cantante(char n[30], fecha f, char p[15], char s, char g[15])
    : artista(n, f, p, s) {
    strcpy(genero, g);
    cantcanciones = 0;
}

// Implementación del destructor
cantante::~cantante() {
    // Destructor
}

// Implementación de ingresar
void cantante::ingresar() {
    artista::ingresar();
    
    cout << "\n--- DATOS DEL CANTANTE ---" << endl;
    cout << "Genero musical: ";
    cin.ignore();
    cin.getline(genero, 15);
    
    cout << "Cantidad de canciones: ";
    cin >> cantcanciones;
    
    cout << "Ingrese los nombres de las canciones:" << endl;
    cin.ignore();
    for (int i = 0; i < cantcanciones; i++) {
        cout << "Cancion " << (i + 1) << ": ";
        cin.getline(canciones[i], 40);
    }
}

// Implementación de imprimir
void cantante::imprimir() {
    artista::imprimir();
    cout << "Genero musical: " << genero << endl;
    cout << "Cantidad de canciones: " << cantcanciones << endl;
}

// Implementación de getgenero
void cantante::getgenero(char g[15]) {
    strcpy(g, genero);
}

// Implementación de repertorio
void cantante::repertorio() {
    cout << "\n--- REPERTORIO ---" << endl;
    if (cantcanciones == 0) {
        cout << "No hay canciones registradas." << endl;
    } else {
        for (int i = 0; i < cantcanciones; i++) {
            cout << (i + 1) << ". " << canciones[i] << endl;
        }
    }
}

// Programa principal
int main() {
    cout << "\n================================================" << endl;
    cout << "  EJERCICIO 2: ARTISTA Y CANTANTE" << endl;
    cout << "================================================" << endl;
    
    // Crear objeto cantante con datos predefinidos
    fecha fnac = {4, 7, 1927};
    cantante artista1("Chabuca Granda", fnac, "Peru", 'F', "Musica criolla");
    
    // Agregar canciones manualmente (simulando ingreso)
    char cancion1[] = "La flor de la canela";
    char cancion2[] = "Fina estampa";
    char cancion3[] = "Jose Antonio";
    
    // Mostrar información del cantante
    artista1.imprimir();
    
    // Obtener y mostrar género
    char gen[15];
    artista1.getgenero(gen);
    cout << "\nGenero obtenido: " << gen << endl;
    
    cout << "\n================================================" << endl;
    
    // Ejemplo interactivo
    cout << "\n\nDesea ingresar un nuevo cantante? (S/N): ";
    char opcion;
    cin >> opcion;
    
    if (opcion == 'S' || opcion == 's') {
        fecha fnac2 = {1, 1, 1990};
        cantante artista2("", fnac2, "", 'M', "");
        artista2.ingresar();
        artista2.imprimir();
        artista2.repertorio();
    }
    
    cout << "\n================================================" << endl;
    return 0;
}
