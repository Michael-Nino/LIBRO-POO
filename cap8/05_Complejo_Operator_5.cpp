// Use la IA de su preferencia para quitar todos los comentarios
/*
================================================================================
    ARCHIVO: 05_Complejo_Operator_5.cpp
    
    TEMA: TAD COMPLEJO COMPLETO - SOBRECARGA DE OPERADORES CON FRIEND
          + SOBRECARGA DEL OPERADOR <<
    
    CONCEPTO CLAVE:
    ================
    Este archivo presenta un TAD (Tipo Abstracto de Datos) completo para
    números complejos, implementando múltiples operadores sobrecargados
    como funciones amigas (friend) e incluyendo el operador de flujo <<
    para salida simplificada.
    
    OPERADORES IMPLEMENTADOS:
    =========================
    1. operator+ (binario):  Suma de complejos
    2. operator- (binario):  Resta de complejos
    3. operator- (unario):   Conjugado de un complejo
    4. operator! (unario):   Opuesto (negativo) de un complejo
    5. operator<< (flujo):   Salida a stream (cout)
    
    CONCEPTOS MATEMÁTICOS:
    ======================
    
    SUMA: (a + bi) + (c + di) = (a+c) + (b+d)i
    RESTA: (a + bi) - (c + di) = (a-c) + (b-d)i
    CONJUGADO: Si z = a + bi, entonces z̄ = a - bi
    OPUESTO: Si z = a + bi, entonces -z = -a - bi
    
    SOBRECARGA DEL OPERADOR << (EXTRACCIÓN DE FLUJO):
    ==================================================
    El operador << es fundamental para la salida de objetos.
    
    SINTAXIS NORMAL:
        cout << "Valor: " << 42 << endl;
    
    PARA OBJETOS PERSONALIZADOS:
        Complejo x(3, 4);
        cout << x;  // Sin sobrecarga: ERROR
        cout << x;  // Con sobrecarga: funciona como tipos básicos
    
    VENTAJAS:
    ---------
    - Sintaxis natural y elegante
    - Integración con streams de C++
    - Encadenamiento de salidas (cout << x << y << z)
    - Compatible con archivos y streams personalizados
    
    DECISIÓN: FRIEND VS MIEMBRO:
    =============================
    
    OPERADOR << DEBE SER FRIEND (no puede ser miembro):
    Razón: cout << x se traduce a operator<<(cout, x)
    El primer operando (cout) es de tipo ostream, no de nuestra clase
    Por lo tanto, NO puede ser un método miembro de Complejo
    
    OTROS OPERADORES EN ESTE ARCHIVO (friend):
    Aunque operator+, operator- podrían ser miembros, aquí se implementan
    como friend para uniformidad y demostrar ambas técnicas.
    
    PROGRESIÓN DE ARCHIVOS:
    =======================
    01: operator+ con friend (paso por valor)
    02: operator+ con friend (paso por referencia)
    03: operator+ como función miembro
    04: Múltiples operadores como miembros
    05: [ESTE] TAD completo con friend + operator<<
================================================================================
*/

#include <iostream>

using namespace std;

// ============ DEFINICIÓN DE LA CLASE ============
class Complejo {
public:
    // ---- Constructores ----
    Complejo() {}                      // Constructor por defecto
    Complejo(float, float);            // Constructor con parámetros
    
    // ---- OPERADORES FRIEND ----
    /*
     * Todos los operadores se declaran como friend para:
     * 1. Acceder a datos privados (real, imag)
     * 2. Permitir conversiones implícitas en ambos operandos
     * 3. Uniformidad en el diseño del TAD
     */
    
    // OPERADORES BINARIOS (requieren 2 operandos)
    friend Complejo operator+(const Complejo&, const Complejo&);  // Suma
    friend Complejo operator-(const Complejo&, const Complejo&);  // Resta
    
    // OPERADORES UNARIOS (requieren 1 operando)
    friend Complejo operator-(const Complejo&);  // Conjugado
    friend Complejo operator!(const Complejo&);  // Opuesto (negativo)
    
    // ---- OPERADOR DE FLUJO ----
    /*
     * ostream& operator<<(ostream& os, const Complejo& p)
     * 
     * RAZÓN DE SER FRIEND:
     * ====================
     * cout << x  se traduce a  operator<<(cout, x)
     * 
     * Primer operando: ostream& (cout)
     * Segundo operando: Complejo& (nuestro objeto)
     * 
     * Como el primer operando NO es de nuestra clase,
     * NO puede ser un método miembro → DEBE ser friend
     * 
     * RETORNO ostream&:
     * =================
     * Permite encadenamiento: cout << x << y << z;
     * Cada operación retorna la referencia al stream para la siguiente
     */
    friend ostream& operator<<(ostream&, const Complejo&);
    
    // ---- Métodos de salida ----
    void print();  // Usa internamente operator<<
    
private:
    float real;  // Parte real del número complejo
    float imag;  // Parte imaginaria del número complejo
};

// ============ IMPLEMENTACIÓN DE MÉTODOS ============

/*
 * Constructor con parámetros
 * Inicializa las partes real e imaginaria
 */
Complejo::Complejo(float a, float b) {
    real = a;
    imag = b;
}

/*
 * Método print()
 * 
 * IMPLEMENTACIÓN ELEGANTE:
 * ========================
 * cout << (*this);
 * 
 * Usa el operador << sobrecargado para imprimir el objeto
 * (*this) es el objeto actual
 * 
 * VENTAJA:
 * - Reutiliza código (no duplica la lógica de formato)
 * - Si cambiamos el formato en operator<<, print() se actualiza automáticamente
 */
void Complejo::print() {
    cout << (*this);  // Llama a operator<<(cout, *this)
}

// ============ SOBRECARGA DE OPERADORES FRIEND ============

// ---- OPERADOR BINARIO + (SUMA) ----
/*
 * Complejo operator+(const Complejo& x, const Complejo& y)
 * 
 * SUMA DE NÚMEROS COMPLEJOS:
 * (a + bi) + (c + di) = (a+c) + (b+d)i
 * 
 * Ejemplo:
 * (4 + 3i) + (2 - 1i) = (4+2) + (3-1)i = 6 + 2i
 */
Complejo operator+(const Complejo& x, const Complejo& y) {
    return Complejo(x.real + y.real,    // Suma de partes reales
                    x.imag + y.imag);    // Suma de partes imaginarias
}

// ---- OPERADOR BINARIO - (RESTA) ----
/*
 * Complejo operator-(const Complejo& x, const Complejo& y)
 * 
 * RESTA DE NÚMEROS COMPLEJOS:
 * (a + bi) - (c + di) = (a-c) + (b-d)i
 * 
 * Ejemplo:
 * (4 + 3i) - (2 - 1i) = (4-2) + (3-(-1))i = 2 + 4i
 */
Complejo operator-(const Complejo& x, const Complejo& y) {
    return Complejo(x.real - y.real,    // Resta de partes reales
                    x.imag - y.imag);    // Resta de partes imaginarias
}

// ---- OPERADOR UNARIO - (CONJUGADO) ----
/*
 * Complejo operator-(const Complejo& x)
 * 
 * CONJUGADO DE UN NÚMERO COMPLEJO:
 * Si z = a + bi, entonces z̄ = a - bi
 * 
 * Ejemplo:
 * z = 4 + 3i  →  z̄ = 4 - 3i
 * 
 * APLICACIONES:
 * - Cálculo de módulo: |z|² = z · z̄
 * - División de complejos
 * - Reflexión respecto al eje real
 * 
 * PARÁMETROS:
 * Recibe UN parámetro → distingue del operador binario
 */
Complejo operator-(const Complejo& x) {
    return Complejo(x.real, -x.imag);  // Parte real igual, parte imaginaria negada
}

// ---- OPERADOR UNARIO ! (OPUESTO) ----
/*
 * Complejo operator!(const Complejo& x)
 * 
 * OPUESTO (NEGATIVO) DE UN NÚMERO COMPLEJO:
 * Si z = a + bi, entonces -z = -a - bi
 * 
 * Ejemplo:
 * z = 2 - 1i  →  -z = -2 + 1i
 * 
 * DIFERENCIA CON CONJUGADO:
 * =========================
 * CONJUGADO (-): Cambia signo solo de parte imaginaria
 * OPUESTO (!):   Cambia signo de ambas partes
 * 
 * NOTA SOBRE EL OPERADOR !:
 * =========================
 * Usar ! para opuesto es no convencional
 * Normalmente ! significa negación lógica
 * Es mejor diseño usar un operador unario - adicional o método negate()
 * Aquí se usa para demostrar que se puede sobrecargar cualquier operador
 */
Complejo operator!(const Complejo& x) {
    return Complejo(-x.real, -x.imag);  // Ambas partes negadas
}

// ---- OPERADOR DE FLUJO << (SALIDA) ----
/*
 * ostream& operator<<(ostream& os, const Complejo& p)
 * 
 * OPERADOR DE EXTRACCIÓN DE FLUJO
 * ================================
 * Permite usar cout << objeto_complejo;
 * 
 * PARÁMETROS:
 * -----------
 * ostream& os: Referencia al flujo de salida (cout, archivo, etc.)
 * const Complejo& p: Objeto a imprimir (por referencia constante)
 * 
 * RETORNO:
 * --------
 * ostream&: Referencia al flujo para permitir encadenamiento
 * 
 * LÓGICA DE FORMATO:
 * ------------------
 * os << p.real << (p.imag >= 0 ? " + " : " ") << p.imag << "i";
 * 
 * Operador ternario: (p.imag >= 0 ? " + " : " ")
 * - Si imag >= 0: Muestra " + " (por ejemplo: 3 + 4i)
 * - Si imag < 0:  Muestra " "   (por ejemplo: 3 - 2i, no 3 + -2i)
 * 
 * EJEMPLOS DE SALIDA:
 * -------------------
 * p.real=4, p.imag=3  → "4 + 3i"
 * p.real=2, p.imag=-1 → "2 -1i"  (el signo negativo ya está en -1)
 * 
 * ENCADENAMIENTO:
 * ---------------
 * cout << x << " es igual a " << y;
 * 1. operator<<(cout, x) retorna cout
 * 2. operator<<(cout, " es igual a ") retorna cout
 * 3. operator<<(cout, y) retorna cout
 */
ostream& operator<<(ostream& os, const Complejo& p) {
    os << p.real << (p.imag >= 0 ? " + " : " ") << p.imag << "i";
    return os;  // Retorna referencia al stream para encadenamiento
}

// ============ PROGRAMA PRINCIPAL ============
int main() {
    // ============ DECLARACIÓN DE OBJETOS ============
    /*
     * Creamos dos números complejos:
     * x = 4.0 + 3.0i
     * y = 2.0 - 1.0i  (nótese el -1.0 en la parte imaginaria)
     */
    Complejo x(4.0, 3.0), y(2.0, -1.0);
    Complejo z, w, t;  // Para almacenar resultados
    
    // ============ DEMOSTRACIÓN DE SUMA ============
    /*
     * z = x + y;
     * 
     * Cálculo:
     * (4 + 3i) + (2 - 1i) = (4+2) + (3+(-1))i = 6 + 2i
     * 
     * Llamada interna:
     * operator+(x, y)
     */
    cout << "=== SUMA DE NÚMEROS COMPLEJOS ===" << endl;
    x.print();          // Muestra: 4 + 3i
    cout << " + " << endl;
    y.print();          // Muestra: 2 -1i (el operador << maneja el signo)
    z = x + y;          // Llama a operator+(x, y)
    cout << " = " << endl;
    z.print();          // Muestra: 6 + 2i
    cout << endl << endl;
    
    // ============ DEMOSTRACIÓN DE RESTA ============
    /*
     * w = x - y;
     * 
     * Cálculo:
     * (4 + 3i) - (2 - 1i) = (4-2) + (3-(-1))i = 2 + 4i
     * 
     * Llamada interna:
     * operator-(x, y)  [versión con 2 parámetros]
     */
    cout << "=== RESTA DE NÚMEROS COMPLEJOS ===" << endl;
    x.print();          // Muestra: 4 + 3i
    cout << " - " << endl;
    y.print();          // Muestra: 2 -1i
    w = x - y;          // Llama a operator-(x, y) [binario]
    cout << " = " << endl;
    w.print();          // Muestra: 2 + 4i
    cout << endl << endl;
    
    // ============ DEMOSTRACIÓN DE CONJUGADO (OPERADOR -) ============
    /*
     * t = -x;
     * 
     * Cálculo:
     * Si x = 4 + 3i, entonces x̄ = 4 - 3i
     * 
     * Llamada interna:
     * operator-(x)  [versión con 1 parámetro]
     * 
     * DISTINCIÓN:
     * x - y → operator-(x, y)  [2 parámetros: RESTA]
     * -x    → operator-(x)     [1 parámetro: CONJUGADO]
     */
    cout << "=== CONJUGADO (OPERADOR - UNARIO) ===" << endl;
    cout << "Número original: ";
    x.print();          // Muestra: 4 + 3i
    cout << "Conjugado: ";
    t = -x;             // Llama a operator-(x) [unario]
    t.print();          // Muestra: 4 - 3i
    cout << endl << endl;
    
    // ============ DEMOSTRACIÓN DE OPUESTO (OPERADOR !) ============
    /*
     * t = !y;
     * 
     * Cálculo:
     * Si y = 2 - 1i, entonces !y = -2 + 1i
     * 
     * Llamada interna:
     * operator!(y)
     * 
     * DIFERENCIA CON CONJUGADO:
     * CONJUGADO (-x): Cambia solo signo de parte imaginaria
     * OPUESTO (!x):   Cambia signo de AMBAS partes
     * 
     * EJEMPLOS COMPARATIVOS:
     * Si z = 4 + 3i:
     * - Conjugado (-z): 4 - 3i
     * - Opuesto (!z):   -4 - 3i
     */
    cout << "=== OPUESTO (OPERADOR ! UNARIO) ===" << endl;
    cout << "Número original: ";
    y.print();          // Muestra: 2 -1i
    cout << "Opuesto: ";
    t = !y;             // Llama a operator!(y)
    t.print();          // Muestra: -2 + 1i
    cout << endl << endl;
    
    // ============ DEMOSTRACIÓN DEL OPERADOR << ============
    /*
     * El operador << se usa implícitamente en print()
     * que hace: cout << (*this);
     * 
     * También podríamos usarlo directamente:
     * cout << "Valor de x: " << x << endl;
     * 
     * Esto permite sintaxis natural como con tipos básicos:
     * cout << "int: " << 42 << ", float: " << 3.14 << ", complejo: " << x;
     */
    
    return 0;
    // Los objetos se destruyen automáticamente al salir de ámbito
}
