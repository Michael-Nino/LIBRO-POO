/*
 * EJERCICIO 7: Operaciones con puntos en el plano cartesiano
 * 
 * Descripción:
 * Programa que representa puntos del plano cartesiano p1, p2 y p3 como structs
 * y utiliza funciones para calcular:
 * - Longitud del segmento que une dos puntos
 * - Pendiente de la recta formada por dos puntos
 * - Área del triángulo formado por tres puntos
 * 
 * Fórmulas utilizadas:
 * - Distancia: d = sqrt((x2-x1)² + (y2-y1)²)
 * - Pendiente: m = (y2-y1)/(x2-x1)
 * - Área triángulo: A = |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)| / 2
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Estructura para representar un punto en el plano
struct Punto {
    float x;  // Coordenada x
    float y;  // Coordenada y
};

// Prototipos de funciones
void leerPunto(Punto &p, const char* nombre);
void mostrarPunto(const Punto &p, const char* nombre);
float distancia(const Punto &p1, const Punto &p2);
float pendiente(const Punto &p1, const Punto &p2);
float areaTriangulo(const Punto &p1, const Punto &p2, const Punto &p3);
bool sonColineales(const Punto &p1, const Punto &p2, const Punto &p3);

int main() {
    Punto p1, p2, p3;
    int opcion;
    
    cout << "========================================\n";
    cout << "  OPERACIONES CON PUNTOS EN EL PLANO\n";
    cout << "========================================\n\n";
    
    // Leer los tres puntos
    leerPunto(p1, "P1");
    leerPunto(p2, "P2");
    leerPunto(p3, "P3");
    
    do {
        cout << "\n--- MENU DE OPERACIONES ---\n";
        cout << "1. Mostrar puntos\n";
        cout << "2. Distancia entre P1 y P2\n";
        cout << "3. Distancia entre P2 y P3\n";
        cout << "4. Distancia entre P1 y P3\n";
        cout << "5. Pendiente de la recta P1-P2\n";
        cout << "6. Pendiente de la recta P2-P3\n";
        cout << "7. Area del triangulo P1-P2-P3\n";
        cout << "8. Ingresar nuevos puntos\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        cout << fixed << setprecision(4);
        
        switch(opcion) {
            case 1:
                cout << "\n--- PUNTOS INGRESADOS ---\n";
                mostrarPunto(p1, "P1");
                mostrarPunto(p2, "P2");
                mostrarPunto(p3, "P3");
                break;
                
            case 2:
                cout << "\nDistancia P1-P2 = " << distancia(p1, p2) << " unidades\n";
                break;
                
            case 3:
                cout << "\nDistancia P2-P3 = " << distancia(p2, p3) << " unidades\n";
                break;
                
            case 4:
                cout << "\nDistancia P1-P3 = " << distancia(p1, p3) << " unidades\n";
                break;
                
            case 5:
                if(p2.x == p1.x) {
                    cout << "\nLa recta P1-P2 es VERTICAL (pendiente indefinida)\n";
                } else {
                    cout << "\nPendiente de la recta P1-P2 = " 
                         << pendiente(p1, p2) << "\n";
                }
                break;
                
            case 6:
                if(p3.x == p2.x) {
                    cout << "\nLa recta P2-P3 es VERTICAL (pendiente indefinida)\n";
                } else {
                    cout << "\nPendiente de la recta P2-P3 = " 
                         << pendiente(p2, p3) << "\n";
                }
                break;
                
            case 7:
                if(sonColineales(p1, p2, p3)) {
                    cout << "\nLos puntos son COLINEALES.\n";
                    cout << "No forman un triangulo (area = 0)\n";
                } else {
                    float area = areaTriangulo(p1, p2, p3);
                    cout << "\nArea del triangulo P1-P2-P3 = " 
                         << area << " unidades cuadradas\n";
                }
                break;
                
            case 8:
                leerPunto(p1, "P1");
                leerPunto(p2, "P2");
                leerPunto(p3, "P3");
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

// Lee un punto desde el teclado
void leerPunto(Punto &p, const char* nombre) {
    cout << "\nIngrese las coordenadas del punto " << nombre << ":\n";
    cout << "  x: ";
    cin >> p.x;
    cout << "  y: ";
    cin >> p.y;
}

// Muestra un punto en formato (x, y)
void mostrarPunto(const Punto &p, const char* nombre) {
    cout << nombre << " = (" << p.x << ", " << p.y << ")\n";
}

// Calcula la distancia euclidiana entre dos puntos
// Fórmula: d = sqrt((x2-x1)² + (y2-y1)²)
float distancia(const Punto &p1, const Punto &p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

// Calcula la pendiente de la recta que pasa por dos puntos
// Fórmula: m = (y2-y1) / (x2-x1)
// Precondición: p2.x != p1.x (no debe ser recta vertical)
float pendiente(const Punto &p1, const Punto &p2) {
    return (p2.y - p1.y) / (p2.x - p1.x);
}

// Calcula el área del triángulo formado por tres puntos
// Fórmula: A = |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)| / 2
float areaTriangulo(const Punto &p1, const Punto &p2, const Punto &p3) {
    float area = abs(p1.x * (p2.y - p3.y) + 
                     p2.x * (p3.y - p1.y) + 
                     p3.x * (p1.y - p2.y)) / 2.0;
    return area;
}

// Verifica si tres puntos son colineales
bool sonColineales(const Punto &p1, const Punto &p2, const Punto &p3) {
    // Tres puntos son colineales si el área del triángulo es 0
    float area = areaTriangulo(p1, p2, p3);
    return area < 0.0001; // Tolerancia para errores de punto flotante
}
