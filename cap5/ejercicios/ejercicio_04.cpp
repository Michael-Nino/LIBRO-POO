/*
 * EJERCICIO 4: Manejo de fechas
 * 
 * Descripción:
 * Definir una estructura Fecha(día, mes, año) y escribir un programa que permita
 * trabajar con objetos Fecha: lectura, escritura, comparación.
 * Asegurar que los objetos Fecha sean correctos en cuanto a día, mes y año.
 * Considerar años bisiestos.
 * 
 * Validaciones implementadas:
 * - Mes entre 1 y 12
 * - Días según el mes (considerando años bisiestos)
 * - Año válido (mayor a 1900)
 * 
 * Operaciones:
 * - Lectura y validación de fechas
 * - Comparación de fechas (anterior, posterior, igual)
 * - Cálculo de diferencia en días
 * - Verificación de año bisiesto
 */

#include <iostream>
#include <iomanip>
using namespace std;

// Estructura para representar una fecha
struct Fecha {
    int dia;
    int mes;
    int year;
};

// Prototipos de funciones
bool esBisiesto(int year);
int diasEnMes(int mes, int year);
bool esFechaValida(const Fecha &f);
void leerFecha(Fecha &f, const char* nombre);
void mostrarFecha(const Fecha &f);
int compararFechas(const Fecha &f1, const Fecha &f2);
int diasDesdeInicio(const Fecha &f);
int diferenciaEnDias(const Fecha &f1, const Fecha &f2);
void mostrarDiaSemana(const Fecha &f);

int main() {
    Fecha fecha1, fecha2;
    int opcion;
    
    cout << "========================================\n";
    cout << "   MANEJO DE FECHAS\n";
    cout << "========================================\n\n";
    
    // Leer dos fechas
    leerFecha(fecha1, "Fecha 1");
    leerFecha(fecha2, "Fecha 2");
    
    do {
        cout << "\n--- MENU DE OPERACIONES ---\n";
        cout << "1. Mostrar fechas\n";
        cout << "2. Comparar fechas\n";
        cout << "3. Calcular diferencia en dias\n";
        cout << "4. Verificar si el año es bisiesto\n";
        cout << "5. Ingresar nuevas fechas\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << "\nFecha 1: ";
                mostrarFecha(fecha1);
                cout << "Fecha 2: ";
                mostrarFecha(fecha2);
                break;
                
            case 2: {
                int comparacion = compararFechas(fecha1, fecha2);
                cout << "\nFecha 1: "; mostrarFecha(fecha1);
                cout << "Fecha 2: "; mostrarFecha(fecha2);
                
                if(comparacion < 0)
                    cout << "\nFecha 1 es ANTERIOR a Fecha 2\n";
                else if(comparacion > 0)
                    cout << "\nFecha 1 es POSTERIOR a Fecha 2\n";
                else
                    cout << "\nAmbas fechas son IGUALES\n";
                break;
            }
            
            case 3: {
                int diferencia = diferenciaEnDias(fecha1, fecha2);
                cout << "\nDiferencia entre las fechas: " 
                     << abs(diferencia) << " dias\n";
                break;
            }
            
            case 4:
                cout << "\nAño de Fecha 1 (" << fecha1.year << "): ";
                if(esBisiesto(fecha1.year))
                    cout << "Es BISIESTO\n";
                else
                    cout << "NO es bisiesto\n";
                    
                cout << "Año de Fecha 2 (" << fecha2.year << "): ";
                if(esBisiesto(fecha2.year))
                    cout << "Es BISIESTO\n";
                else
                    cout << "NO es bisiesto\n";
                break;
                
            case 5:
                leerFecha(fecha1, "Fecha 1");
                leerFecha(fecha2, "Fecha 2");
                break;
                
            case 0:
                cout << "\nSaliendo del programa...\n";
                break;
                
            default:
                cout << "\nOpcion invalida!\n";
        }
    } while(opcion != 0);
    
    return 0;
}

// Determina si un año es bisiesto
bool esBisiesto(int year) {
    // Un año es bisiesto si:
    // - Es divisible por 4 Y
    // - NO es divisible por 100, O es divisible por 400
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Retorna el número de días en un mes dado
int diasEnMes(int mes, int year) {
    // Días por mes: Ene=31, Feb=28/29, Mar=31, Abr=30, May=31, Jun=30
    //               Jul=31, Ago=31, Sep=30, Oct=31, Nov=30, Dic=31
    int dias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if(mes == 2 && esBisiesto(year))
        return 29;
    
    return dias[mes];
}

// Valida si una fecha es correcta
bool esFechaValida(const Fecha &f) {
    // Validar año
    if(f.year < 1900 || f.year > 2100)
        return false;
    
    // Validar mes
    if(f.mes < 1 || f.mes > 12)
        return false;
    
    // Validar día
    if(f.dia < 1 || f.dia > diasEnMes(f.mes, f.year))
        return false;
    
    return true;
}

// Lee una fecha validando los datos
void leerFecha(Fecha &f, const char* nombre) {
    cout << "\n--- " << nombre << " ---\n";
    
    do {
        cout << "Ingrese dia: ";
        cin >> f.dia;
        cout << "Ingrese mes: ";
        cin >> f.mes;
        cout << "Ingrese año: ";
        cin >> f.year;
        
        if(!esFechaValida(f)) {
            cout << "\nError: Fecha invalida. Intente nuevamente.\n";
        }
    } while(!esFechaValida(f));
}

// Muestra una fecha en formato dd/mm/aaaa
void mostrarFecha(const Fecha &f) {
    cout << setfill('0') << setw(2) << f.dia << "/"
         << setw(2) << f.mes << "/"
         << f.year << endl;
}

// Compara dos fechas: retorna <0 si f1<f2, 0 si f1==f2, >0 si f1>f2
int compararFechas(const Fecha &f1, const Fecha &f2) {
    if(f1.year != f2.year)
        return f1.year - f2.year;
    
    if(f1.mes != f2.mes)
        return f1.mes - f2.mes;
    
    return f1.dia - f2.dia;
}

// Calcula días transcurridos desde 01/01/1900
int diasDesdeInicio(const Fecha &f) {
    int dias = 0;
    
    // Sumar días por años completos
    for(int y = 1900; y < f.year; y++) {
        if(esBisiesto(y))
            dias += 366;
        else
            dias += 365;
    }
    
    // Sumar días por meses completos del año actual
    for(int m = 1; m < f.mes; m++) {
        dias += diasEnMes(m, f.year);
    }
    
    // Sumar los días del mes actual
    dias += f.dia;
    
    return dias;
}

// Calcula la diferencia en días entre dos fechas
int diferenciaEnDias(const Fecha &f1, const Fecha &f2) {
    return diasDesdeInicio(f1) - diasDesdeInicio(f2);
}
