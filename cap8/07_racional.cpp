// Use la IA de su preferencia para quitar todos los comentarios
/*
================================================================================
    ARCHIVO: 07_racional.cpp
    
    TEMA: IMPLEMENTACIÓN DEL TAD RACIONAL (FRACCIONES)
    
    CONCEPTO CLAVE:
    ================
    Implementa todas las operaciones para números racionales (fracciones)
    manteniendo siempre la fracción simplificada automáticamente.
    
    OPERACIONES IMPLEMENTADAS:
    ==========================
    - 11 operadores aritméticos y relacionales
    - 5 operadores de asignación
    - 2 operadores de E/S
    - 2 constructores
    - Función de simplificación automática
    - Función MCD (Máximo Común Divisor)
================================================================================
*/

#include "07_racional.h"

// ============ OPERADORES ARITMÉTICOS ============

/*
 * Racional operator-() [UNARIO]
 * 
 * NEGACIÓN DE UN RACIONAL
 * =======================
 * Sintaxis: -r
 * 
 * Para a/b, el negativo es -a/b
 * 
 * Ejemplo:
 * r = 3/4  →  -r = -3/4
 * r = -2/5 →  -r = 2/5
 */
Racional Racional::operator-() {
    return Racional(-num, denom);  // Niega el numerador
}

/*
 * Racional operator+(const Racional& r1, const Racional& r2)
 * 
 * SUMA DE RACIONALES
 * ==================
 * Fórmula: a/b + c/d = (a*d + b*c) / (b*d)
 * 
 * Ejemplo:
 * 1/2 + 1/3 = (1*3 + 2*1) / (2*3) = (3 + 2) / 6 = 5/6
 * 
 * PROCESO:
 * 1. Calcula denominador común: dd = b * d
 * 2. Calcula numerador: nn = a*d + b*c
 * 3. Crea nuevo Racional (se simplifica automáticamente en constructor)
 */
Racional operator+(const Racional& r1, const Racional& r2) {
    int dd = r1.denom * r2.denom;           // Denominador común
    int nn = r1.num * r2.denom + r1.denom * r2.num;  // Numerador
    return Racional(nn, dd);  // Se simplifica automáticamente
}

/*
 * Racional operator-(const Racional& r1, const Racional& r2)
 * 
 * RESTA DE RACIONALES
 * ===================
 * Fórmula: a/b - c/d = (a*d - b*c) / (b*d)
 * 
 * Ejemplo:
 * 3/4 - 1/2 = (3*2 - 4*1) / (4*2) = (6 - 4) / 8 = 2/8 = 1/4
 * 
 * Nótese que 2/8 se simplifica automáticamente a 1/4
 */
Racional operator-(const Racional& r1, const Racional& r2) {
    int dd = r1.denom * r2.denom;           // Denominador común
    int nn = r1.num * r2.denom - r1.denom * r2.num;  // Numerador
    return Racional(nn, dd);  // Se simplifica automáticamente
}

/*
 * Racional operator*(const Racional& r1, const Racional& r2)
 * 
 * MULTIPLICACIÓN DE RACIONALES
 * ============================
 * Fórmula: a/b * c/d = (a*c) / (b*d)
 * 
 * Ejemplo:
 * 2/3 * 3/4 = (2*3) / (3*4) = 6/12 = 1/2
 * 
 * La multiplicación es más simple que suma/resta:
 * solo multiplicar numeradores y denominadores
 */
Racional operator*(const Racional& r1, const Racional& r2) {
    int dd = r1.denom * r2.denom;  // Producto de denominadores
    int nn = r1.num * r2.num;       // Producto de numeradores
    return Racional(nn, dd);  // Se simplifica automáticamente
}

/*
 * Racional operator/(const Racional& r1, const Racional& r2)
 * 
 * DIVISIÓN DE RACIONALES
 * ======================
 * Fórmula: (a/b) ÷ (c/d) = (a/b) * (d/c) = (a*d) / (b*c)
 * 
 * División = multiplicación por el recíproco
 * 
 * Ejemplo:
 * (1/2) ÷ (3/4) = (1/2) * (4/3) = (1*4) / (2*3) = 4/6 = 2/3
 * 
 * IMPORTANTE:
 * No verifica división por cero (c/d con c=0)
 * En código robusto debería verificarse r2.num != 0
 */
Racional operator/(const Racional& r1, const Racional& r2) {
    int dd = r2.num * r1.denom;    // Denominador: c * b
    int nn = r1.num * r2.denom;    // Numerador: a * d
    return Racional(nn, dd);  // Se simplifica automáticamente
}

// ============ OPERADORES DE COMPARACIÓN ============

/*
 * bool operator==(const Racional& r1, const Racional& r2)
 * 
 * IGUALDAD DE RACIONALES
 * ======================
 * Para comparar a/b == c/d, verificamos: a*d == b*c
 * 
 * Ejemplo:
 * 1/2 == 2/4?  →  1*4 == 2*2?  →  4 == 4  →  true
 * 
 * VENTAJA: Evita división de punto flotante
 * No necesitamos calcular 1/2 = 0.5 y 2/4 = 0.5
 */
bool operator==(const Racional& r1, const Racional& r2) {
    return (r1.num * r2.denom == r1.denom * r2.num) ? true : false;
}

/*
 * bool operator!=(const Racional& r1, const Racional& r2)
 * 
 * DESIGUALDAD DE RACIONALES
 * =========================
 * Para comparar a/b != c/d, verificamos: a*d != b*c
 * 
 * Ejemplo:
 * 1/2 != 1/3?  →  1*3 != 2*1?  →  3 != 2  →  true
 */
bool operator!=(const Racional& r1, const Racional& r2) {
    return (r1.num * r2.denom != r1.denom * r2.num) ? true : false;
}

/*
 * bool operator<(const Racional& r1, const Racional& r2)
 * 
 * MENOR QUE PARA RACIONALES
 * =========================
 * Para comparar a/b < c/d, verificamos: a*d < b*c
 * 
 * Ejemplo:
 * 1/3 < 1/2?  →  1*2 < 3*1?  →  2 < 3  →  true
 * 
 * IMPORTANTE: Asume denominadores positivos
 * (lo cual garantiza simplificar())
 */
bool operator<(const Racional& r1, const Racional& r2) {
    return (r1.num * r2.denom < r1.denom * r2.num) ? true : false;
}

/*
 * bool operator<=(const Racional& r1, const Racional& r2)
 * 
 * MENOR O IGUAL QUE
 * =================
 * Para comparar a/b <= c/d, verificamos: a*d <= b*c
 */
bool operator<=(const Racional& r1, const Racional& r2) {
    return (r1.num * r2.denom <= r1.denom * r2.num) ? true : false;
}

/*
 * bool operator>(const Racional& r1, const Racional& r2)
 * 
 * MAYOR QUE
 * =========
 * Para comparar a/b > c/d, verificamos: a*d > b*c
 * 
 * Ejemplo:
 * 3/4 > 1/2?  →  3*2 > 4*1?  →  6 > 4  →  true
 */
bool operator>(const Racional& r1, const Racional& r2) {
    return (r1.num * r2.denom > r1.denom * r2.num) ? true : false;
}

/*
 * bool operator>=(const Racional& r1, const Racional& r2)
 * 
 * MAYOR O IGUAL QUE
 * =================
 * Para comparar a/b >= c/d, verificamos: a*d >= b*c
 */
bool operator>=(const Racional& r1, const Racional& r2) {
    return (r1.num * r2.denom >= r1.denom * r2.num) ? true : false;
}

// ============ OPERADORES DE INCREMENTO/DECREMENTO ============

/*
 * Racional& operator++() [PREFIJO]
 * 
 * PRE-INCREMENTO
 * ==============
 * Sintaxis: ++r
 * Incrementa en 1 (suma 1/1)
 * 
 * Ejemplo:
 * r = 3/4  →  ++r  →  r = 3/4 + 1/1 = 7/4
 * 
 * IMPLEMENTACIÓN EFICIENTE:
 * En lugar de sumar 1/1, directamente: num = num + denom
 * Esto equivale a: a/b + 1 = a/b + b/b = (a+b)/b
 * 
 * RETORNO: Referencia al objeto incrementado
 */
Racional& Racional::operator++() {
    num = num + denom;  // a/b + 1 = (a+b)/b
    return *this;
}

/*
 * Racional& operator--() [PREFIJO]
 * 
 * PRE-DECREMENTO
 * ==============
 * Sintaxis: --r
 * Decrementa en 1 (resta 1/1)
 * 
 * Ejemplo:
 * r = 7/4  →  --r  →  r = 7/4 - 1/1 = 3/4
 * 
 * IMPLEMENTACIÓN EFICIENTE:
 * num = num - denom  →  a/b - 1 = (a-b)/b
 */
Racional& Racional::operator--() {
    num = num - denom;  // a/b - 1 = (a-b)/b
    return *this;
}

// ============ OPERADORES DE ASIGNACIÓN ============

/*
 * Racional& operator=(const Racional& p)
 * 
 * ASIGNACIÓN SIMPLE
 * =================
 * Sintaxis: r1 = r2;
 * 
 * VERIFICACIÓN DE AUTO-ASIGNACIÓN:
 * if (*this != p) evita copiar si r = r
 * Esto previene trabajo innecesario
 * 
 * RETORNO: Referencia para permitir encadenamiento
 * r1 = r2 = r3;  →  r1 = (r2 = r3);
 */
Racional& Racional::operator=(const Racional& p) {
    if (*this != p) {  // Verifica que no sea auto-asignación
        num = p.num;
        denom = p.denom;
    }
    return *this;
}

/*
 * Racional& operator+=(const Racional& p)
 * 
 * SUMA Y ASIGNACIÓN
 * =================
 * Sintaxis: r1 += r2;
 * Equivale a: r1 = r1 + r2;
 * 
 * IMPLEMENTACIÓN:
 * Reutiliza operator+ ya implementado
 * *this + p llama al operator+ friend
 */
Racional& Racional::operator+=(const Racional& p) {
    *this = *this + p;  // Reutiliza operator+
    return *this;
}

/*
 * Racional& operator-=(const Racional& p)
 * 
 * RESTA Y ASIGNACIÓN
 * ==================
 * Sintaxis: r1 -= r2;
 * Equivale a: r1 = r1 - r2;
 */
Racional& Racional::operator-=(const Racional& p) {
    *this = *this - p;  // Reutiliza operator-
    return *this;
}

/*
 * Racional& operator*=(const Racional& p)
 * 
 * MULTIPLICACIÓN Y ASIGNACIÓN
 * ===========================
 * Sintaxis: r1 *= r2;
 * Equivale a: r1 = r1 * r2;
 */
Racional& Racional::operator*=(const Racional& p) {
    *this = *this * p;  // Reutiliza operator*
    return *this;
}

/*
 * Racional& operator/=(const Racional& p)
 * 
 * DIVISIÓN Y ASIGNACIÓN
 * =====================
 * Sintaxis: r1 /= r2;
 * Equivale a: r1 = r1 / r2;
 */
Racional& Racional::operator/=(const Racional& p) {
    *this = *this / p;  // Reutiliza operator/
    return *this;
}

// ============ CONSTRUCTORES ============

/*
 * Racional::Racional(int nu, int de)
 * 
 * CONSTRUCTOR CON PARÁMETROS
 * ==========================
 * Parámetros con valores por defecto (en .h): num=0, denom=1
 * 
 * IMPORTANTE: Llama a simplificar() al final
 * Esto garantiza que toda fracción esté simplificada
 * 
 * Ejemplos:
 * Racional()       → 0/1 = 0
 * Racional(5)      → 5/1 = 5
 * Racional(6, 8)   → simplifica a 3/4
 * Racional(-6, 8)  → simplifica a -3/4
 * Racional(6, -8)  → simplifica a -3/4
 */
Racional::Racional(int nu, int de) {
    num = nu;
    denom = de;
    simplificar();  // Simplifica automáticamente
}

/*
 * Racional::Racional(const Racional& r)
 * 
 * CONSTRUCTOR DE COPIA
 * ====================
 * Crea un nuevo racional copiando otro
 * 
 * NO llama a simplificar() porque r ya está simplificado
 * (todo racional se simplifica al construirse)
 */
Racional::Racional(const Racional& r) {
    num = r.num;
    denom = r.denom;
}

// ============ MÉTODOS DE ENTRADA/SALIDA ============

/*
 * void print()
 * 
 * MÉTODO DE IMPRESIÓN
 * ===================
 * Usa internamente operator<<
 * cout << *this llama a operator<<(cout, *this)
 * 
 * VENTAJA: Reutiliza código del operator<<
 */
void Racional::print() {
    cout << *this;  // Llama a operator<<
}

/*
 * ostream& operator<<(ostream& os, const Racional& r)
 * 
 * OPERADOR DE SALIDA
 * ==================
 * Sintaxis: cout << racional;
 * 
 * FORMATO: numerador/denominador
 * Ejemplo: 3/4, -2/5, 7/1
 * 
 * RETORNO: Referencia al stream para encadenamiento
 * cout << r1 << " + " << r2;
 */
ostream& operator<<(ostream& os, const Racional& r) {
    os << r.num << "/" << r.denom;
    return os;  // Permite encadenamiento
}

/*
 * istream& operator>>(istream& is, Racional& r)
 * 
 * OPERADOR DE ENTRADA
 * ===================
 * Sintaxis: cin >> racional;
 * 
 * FORMATO ESPERADO: numerador denominador
 * Usuario ingresa: 3 4  (para 3/4)
 * 
 * IMPORTANTE: No simplifica automáticamente
 * Si el usuario ingresa 6 8, quedará como 6/8
 * (debería llamar a r.simplificar() al final en código robusto)
 */
istream& operator>>(istream& is, Racional& r) {
    is >> r.num >> r.denom;
    return is;  // Permite encadenamiento
}

// ============ MÉTODO PRIVADO DE SIMPLIFICACIÓN ============

/*
 * void simplificar()
 * 
 * SIMPLIFICA LA FRACCIÓN A SU FORMA MÁS REDUCIDA
 * ==============================================
 * 
 * PASOS:
 * 1. Si numerador es 0, retorna (0/n = 0 ya está simplificado)
 * 2. Si denominador es negativo, mueve el signo al numerador
 * 3. Calcula MCD del numerador y denominador
 * 4. Divide ambos por el MCD
 * 
 * EJEMPLOS:
 * 6/8   → MCD(6,8)=2  → 3/4
 * -6/8  → MCD(6,8)=2  → -3/4
 * 6/-8  → 1º: -6/8, 2º: MCD=2 → -3/4
 * 0/5   → 0/5 (retorna inmediatamente)
 * 
 * INVARIANTE: Después de simplificar, denom > 0
 * El signo siempre está en el numerador
 */
void Racional::simplificar() {
    // Caso especial: numerador cero
    if (!num)  // if (num == 0)
        return;
    
    // Normalizar: signo siempre en numerador
    if (denom < 0) {
        num = -num;
        denom = -denom;
    }
    
    // Calcular MCD y simplificar
    int d = mcd(num, denom);
    num = num / d;
    denom = denom / d;
}

// ============ FUNCIÓN AUXILIAR GLOBAL ============

/*
 * int mcd(int x, int y)
 * 
 * MÁXIMO COMÚN DIVISOR (Algoritmo de Euclides)
 * =============================================
 * 
 * ALGORITMO RECURSIVO:
 * 1. Si x < y, intercambiar: mcd(x,y) = mcd(y,x)
 * 2. Si y divide a x (x % y == 0), entonces MCD = y
 * 3. Sino, mcd(x,y) = mcd(y, x%y)
 * 
 * EJEMPLOS:
 * mcd(8, 6) → mcd(6, 8) → mcd(8, 6) → mcd(6, 2) → mcd(2, 0) → 2
 * mcd(12, 8) → mcd(8, 4) → mcd(4, 0) → 4
 * 
 * COMPLEJIDAD: O(log min(x,y))
 * Muy eficiente incluso para números grandes
 */
int mcd(int x, int y) {
    if (x < y)
        return mcd(y, x);  // Asegura x >= y
    if (x % y == 0)
        return y;          // Caso base: y divide a x
    else
        return mcd(y, x % y);  // Recursión con resto
}
