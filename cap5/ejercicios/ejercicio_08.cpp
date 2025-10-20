/*
 * EJERCICIO 8: Registro de temperaturas semanales
 * 
 * Descripción:
 * Programa que declara las estructuras fecha, tiempo y clima.
 * La estructura clima contiene como campos la fecha, hora y temperatura
 * registrada en un determinado día.
 * 
 * Funciones implementadas:
 * - Leer datos de temperaturas registradas durante una semana
 * - Calcular el promedio de temperaturas de la semana
 * - Imprimir todas las temperaturas registradas
 */

#include <iostream>
#include <iomanip>
using namespace std;

const int DIAS_SEMANA = 7;

// Estructura para representar una fecha
struct Fecha {
    int dia;
    int mes;
    int year;
};

// Estructura para representar una hora
struct Tiempo {
    int hora;      // 0-23
    int minutos;   // 0-59
    int segundos;  // 0-59
};

// Estructura para representar un registro climático
struct Clima {
    Fecha fecha;
    Tiempo hora;
    float temperatura;  // En grados Celsius
};

// Prototipos de funciones
void leerClima(Clima &c, int dia);
void leerFecha(Fecha &f);
void leerTiempo(Tiempo &t);
void leerSemana(Clima semana[]);
void mostrarClima(const Clima &c);
void mostrarFecha(const Fecha &f);
void mostrarTiempo(const Tiempo &t);
void mostrarSemana(const Clima semana[]);
float calcularPromedioTemperatura(const Clima semana[]);
void encontrarTempExtremas(const Clima semana[], int &indiceMin, int &indiceMax);

int main() {
    Clima semana[DIAS_SEMANA];
    
    cout << "========================================\n";
    cout << "  REGISTRO DE TEMPERATURAS SEMANALES\n";
    cout << "========================================\n";
    
    // Leer datos de la semana
    leerSemana(semana);
    
    // Mostrar todos los registros
    cout << "\n========================================\n";
    cout << "  TEMPERATURAS REGISTRADAS\n";
    cout << "========================================\n";
    mostrarSemana(semana);
    
    // Calcular y mostrar promedio
    float promedio = calcularPromedioTemperatura(semana);
    cout << "\n========================================\n";
    cout << "  ESTADISTICAS\n";
    cout << "========================================\n";
    cout << fixed << setprecision(2);
    cout << "Temperatura promedio de la semana: " << promedio << " °C\n";
    
    // Encontrar temperaturas extremas
    int indiceMin, indiceMax;
    encontrarTempExtremas(semana, indiceMin, indiceMax);
    
    cout << "\nTemperatura MINIMA: " << semana[indiceMin].temperatura << " °C\n";
    cout << "Registrada el: ";
    mostrarFecha(semana[indiceMin].fecha);
    cout << " a las ";
    mostrarTiempo(semana[indiceMin].hora);
    cout << endl;
    
    cout << "\nTemperatura MAXIMA: " << semana[indiceMax].temperatura << " °C\n";
    cout << "Registrada el: ";
    mostrarFecha(semana[indiceMax].fecha);
    cout << " a las ";
    mostrarTiempo(semana[indiceMax].hora);
    cout << endl;
    
    return 0;
}

// Lee los datos climáticos de un día
void leerClima(Clima &c, int dia) {
    cout << "\n--- Dia " << dia << " ---\n";
    
    cout << "Fecha (dd mm aaaa): ";
    leerFecha(c.fecha);
    
    cout << "Hora (hh mm ss): ";
    leerTiempo(c.hora);
    
    cout << "Temperatura (°C): ";
    cin >> c.temperatura;
}

// Lee una fecha
void leerFecha(Fecha &f) {
    cin >> f.dia >> f.mes >> f.year;
}

// Lee una hora
void leerTiempo(Tiempo &t) {
    cin >> t.hora >> t.minutos >> t.segundos;
    
    // Validación básica
    while(t.hora < 0 || t.hora > 23 || 
          t.minutos < 0 || t.minutos > 59 ||
          t.segundos < 0 || t.segundos > 59) {
        cout << "Hora invalida. Ingrese nuevamente (hh mm ss): ";
        cin >> t.hora >> t.minutos >> t.segundos;
    }
}

// Lee los datos de toda la semana
void leerSemana(Clima semana[]) {
    for(int i = 0; i < DIAS_SEMANA; i++) {
        leerClima(semana[i], i + 1);
    }
}

// Muestra un registro climático
void mostrarClima(const Clima &c) {
    mostrarFecha(c.fecha);
    cout << " ";
    mostrarTiempo(c.hora);
    cout << " - Temperatura: " << fixed << setprecision(2) 
         << c.temperatura << " °C\n";
}

// Muestra una fecha
void mostrarFecha(const Fecha &f) {
    cout << setfill('0') << setw(2) << f.dia << "/"
         << setw(2) << f.mes << "/" << f.year;
}

// Muestra una hora
void mostrarTiempo(const Tiempo &t) {
    cout << setfill('0') << setw(2) << t.hora << ":"
         << setw(2) << t.minutos << ":" << setw(2) << t.segundos;
}

// Muestra todos los registros de la semana
void mostrarSemana(const Clima semana[]) {
    for(int i = 0; i < DIAS_SEMANA; i++) {
        cout << "\nDia " << (i + 1) << ": ";
        mostrarClima(semana[i]);
    }
}

// Calcula el promedio de temperaturas de la semana
float calcularPromedioTemperatura(const Clima semana[]) {
    float suma = 0;
    
    for(int i = 0; i < DIAS_SEMANA; i++) {
        suma += semana[i].temperatura;
    }
    
    return suma / DIAS_SEMANA;
}

// Encuentra las temperaturas mínima y máxima
void encontrarTempExtremas(const Clima semana[], int &indiceMin, int &indiceMax) {
    indiceMin = 0;
    indiceMax = 0;
    
    for(int i = 1; i < DIAS_SEMANA; i++) {
        if(semana[i].temperatura < semana[indiceMin].temperatura) {
            indiceMin = i;
        }
        if(semana[i].temperatura > semana[indiceMax].temperatura) {
            indiceMax = i;
        }
    }
}
