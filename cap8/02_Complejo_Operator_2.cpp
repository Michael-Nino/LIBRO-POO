// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Archivo: 02_Complejo_Operator_2.cpp
 * Propósito: PASO POR REFERENCIA y RETORNO DIRECTO en sobrecarga de operadores
 * 
 * MEJORAS RESPECTO A 01:
 * - Usa CONST REFERENCIA (&) en parámetros → Más eficiente (no copia objetos)
 * - RETORNO DIRECTO con constructor → Código más compacto
 * - DESTRUCTOR explícito → Gestión de recursos
 * 
 * VENTAJAS DE const Complejo&:
 * ✅ No copia el objeto (más rápido)
 * ✅ const protege los objetos originales
 * ✅ Funciona con objetos grandes sin penalización
 * 
 * COMPARACIÓN:
 * operator+(Complejo x, Complejo y)        ← 01: Copia objetos (2 copias)
 * operator+(const Complejo& x, const Complejo& y)  ← 02: Referencias (0 copias)
 */

#include <iostream>
using namespace std;

// ============ CLASE COMPLEJO CON REFERENCIAS ============
/*
 * Versión mejorada usando:
 * - Paso por referencia constante (const &)
 * - Retorno directo optimizado
 * - Destructor para limpieza
 */
class Complejo {
    float real;  // Parte real del número complejo
    float imag;  // Parte imaginaria del número complejo
    
public:
    // ============ CONSTRUCTORES ============
    
    Complejo() {}  // Constructor por defecto
    
    /*
     * Constructor con parámetros
     * Inicializa el complejo con valores específicos
     */
    Complejo(float, float);
    
    /*
     * print: Muestra el complejo en formato a + bi
     */
    void print();
    
    // ============ SOBRECARGA OPTIMIZADA CON REFERENCIAS ============
    /*
     * operator+ usando REFERENCIAS CONSTANTES
     * 
     * const Complejo& = Referencia constante
     * - & evita copiar el objeto (eficiencia)
     * - const protege el objeto original (seguridad)
     * 
     * VENTAJA: Para objetos grandes, evita copias costosas
     */
    friend Complejo operator+(const Complejo&, const Complejo&);
    
    /*
     * Destructor: Se llama automáticamente al destruir el objeto
     * Útil para liberar recursos si los hubiera
     */
    ~Complejo();
};

// ============ IMPLEMENTACIONES ============

/*
 * Constructor con parámetros
 * Crea un complejo de la forma: a + bi
 */
Complejo::Complejo(float a, float b) {
    real = a;  // Inicializa parte real
    imag = b;  // Inicializa parte imaginaria
}

/*
 * print: Imprime el número complejo
 * Formato: a + bi
 */
void Complejo::print() {
    cout << real << " + " << imag << "i " << endl;
}

// ============ SOBRECARGA DEL OPERADOR + ============
/*
 * VERSIÓN OPTIMIZADA con RETORNO DIRECTO
 * 
 * DIFERENCIA CON 01:
 * - 01: Crea z, asigna valores, retorna z (3 pasos)
 * - 02: Retorna directo con constructor (1 paso)
 * 
 * PROCESO:
 * 1. Suma las partes reales: x.real + y.real
 * 2. Suma las partes imaginarias: x.imag + y.imag
 * 3. Crea y retorna el complejo resultante directamente
 * 
 * VENTAJA: Más eficiente, menos líneas de código
 * 
 * Parámetros por REFERENCIA CONSTANTE:
 * - const: No puede modificar x ni y (seguridad)
 * - &: No copia los objetos (eficiencia)
 */
Complejo operator+(const Complejo& x, const Complejo& y) {
    // Retorna directamente un objeto temporal creado con el constructor
    // Esto es más eficiente que crear una variable, asignarla y retornarla
    return Complejo(x.real + y.real, x.imag + y.imag);
}

/*
 * Destructor: Limpia recursos
 * En este caso simple no hace nada, pero es buena práctica definirlo
 * Si tuviéramos memoria dinámica, aquí la liberaríamos
 */
Complejo::~Complejo() {
    // En este caso no hay recursos que liberar
    // Pero siempre es buena práctica tener un destructor
}

// ============ PROGRAMA PRINCIPAL ============
int main() {
    // ============ DECLARACIÓN DE OBJETOS ============
    /*
     * Creamos dos números complejos:
     * x = 1.0 + 3.0i
     * y = 2.0 + 1.0i
     */
    Complejo x(1.0, 3.0), y(2.0, 1.0);
    Complejo z;  // z sin inicializar, se usará para el resultado
    
    cout << "=== SOBRECARGA DE OPERADORES CON FRIEND ===" << endl;
    cout << "=== USANDO REFERENCIAS CONSTANTES ===" << endl << endl;
    
    // ============ MOSTRAR OPERANDOS ============
    cout << "Complejo 1: ";
    x.print();  // Muestra: 1 + 3i
    
    cout << "\nComplejo 2: ";
    y.print();  // Muestra: 2 + 1i
    
    // ============ OPERACIÓN DE SUMA ============
    /*
     * z = x + y;
     * 
     * Lo que ocurre internamente:
     * 1. Se llama a operator+(x, y)
     * 2. x e y se pasan por REFERENCIA (no se copian)
     * 3. Se calcula (1+2) + (3+1)i = 3 + 4i
     * 4. Se retorna el resultado directamente
     * 5. Se asigna a z
     * 
     * VENTAJA DE REFERENCIAS: Sin copias innecesarias
     */
    z = x + y;  // Llama a operator+(x, y)
    
    cout << "\nSuma (x + y): ";
    z.print();  // Muestra: 3 + 4i
    cout << endl;
    
    // ============ LLAMADAS EXPLÍCITAS AL DESTRUCTOR ============
    /*
     * NOTA: Normalmente NO se debe llamar al destructor explícitamente
     * El destructor se llama automáticamente cuando los objetos
     * salen de ámbito (al terminar main)
     * 
     * Esto es solo para demostración del concepto de destructores
     * En código real, confía en la destrucción automática
     */
    x.~Complejo();
    y.~Complejo();
    z.~Complejo();
    
    return 0;
}
