// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Ejercicio Propuesto 3: Clase CReal (Número Real)
 * Implementación completa con operaciones aritméticas
 * 
 * CONCEPTOS PRACTICADOS:
 * - Representación de números reales
 * - Separación de componentes (signo, parte entera, parte decimal)
 * - Operaciones aritméticas (suma, resta, multiplicación, división)
 * - Métodos que retornan objetos de la misma clase
 * - Uso de abs() para valor absoluto
 */

#define _USE_MATH_DEFINES  // Para constantes matemáticas
#include <iostream>
#include <cmath>
using namespace std;

class CReal
{
public:
    // Constructores
    CReal();                    // constructor por defecto
    CReal(double num);         // constructor con parámetro
    CReal(const CReal& r);     // constructor de copia
    
    // Funciones de utilidad
    void imprimir();           // imprime el real
    char getSigno();           // obtiene el signo del real (+ o -)
    void separar();            // separa los componentes del número real
    
    // Operaciones aritméticas
    CReal sumar(CReal a, CReal b);        // Sumar dos reales y devolver la suma
    CReal restar(CReal a, CReal b);       // Restar dos reales y devolver la resta
    CReal multiplicar(CReal a, CReal b);  // Multiplicar dos reales y devolver el producto
    CReal dividir(CReal a, CReal b);      // Dividir dos reales y devolver el cociente
    
    // Destructor
    ~CReal();
    
private:
    double num;  // dato miembro
};

// Constructor por defecto
CReal::CReal()
{
    num = 0.0;
    cout << "Constructor por defecto - CReal creado con valor 0" << endl;
}

// Constructor con parámetro
CReal::CReal(double num)
{
    this->num = num;
    cout << "Constructor con parámetro - CReal creado con valor " << num << endl;
}

// Constructor de copia
CReal::CReal(const CReal& r)
{
    num = r.num;
    cout << "Constructor de copia - CReal creado" << endl;
}

// Imprime el número real
void CReal::imprimir()
{
    cout << num;
}

// Obtiene el signo del real
char CReal::getSigno()
{
    return (num >= 0) ? '+' : '-';
}

// Separa los componentes de un numero real
// Por ejemplo: si num es -2.541, el signo es -, la parte entera es 2 y la parte decimal es 0.541
void CReal::separar()
{
    cout << "Separación de componentes para el número: ";
    imprimir();
    cout << endl;
    
    cout << "Signo: " << getSigno() << endl;
    
    double valorAbsoluto = abs(num);
    int parteEntera = (int)valorAbsoluto;
    double parteDecimal = valorAbsoluto - parteEntera;
    
    cout << "Parte entera: " << parteEntera << endl;
    cout << "Parte decimal: " << parteDecimal << endl;
}

// Suma dos números reales
CReal CReal::sumar(CReal a, CReal b)
{
    return CReal(a.num + b.num);
}

// Resta dos números reales
CReal CReal::restar(CReal a, CReal b)
{
    return CReal(a.num - b.num);
}

// Multiplica dos números reales
CReal CReal::multiplicar(CReal a, CReal b)
{
    return CReal(a.num * b.num);
}

// Divide dos números reales
CReal CReal::dividir(CReal a, CReal b)
{
    if(b.num != 0.0)
        return CReal(a.num / b.num);
    else
    {
        cout << "Error: División por cero!" << endl;
        return CReal(0);
    }
}

CReal::~CReal()
{
    cout << "Destructor - CReal destruido" << endl;
}

int main()
{
    cout << "=== PRUEBA DE CLASE CREAL ===" << endl;
    
    // Constructor por defecto
    CReal r1;
    cout << "r1 = ";
    r1.imprimir();
    cout << endl;
    
    // Constructor con parámetro
    cout << "\n--- Creando números reales ---" << endl;
    CReal r2(-2.541);
    CReal r3(10.75);
    
    cout << "r2 = ";
    r2.imprimir();
    cout << ", Signo: " << r2.getSigno() << endl;
    
    cout << "r3 = ";
    r3.imprimir();
    cout << ", Signo: " << r3.getSigno() << endl;
    
    // Separar componentes
    cout << "\n--- Separación de componentes ---" << endl;
    r2.separar();
    
    cout << "\n";
    r3.separar();
    
    // Operaciones aritméticas
    cout << "\n--- Operaciones aritméticas ---" << endl;
    CReal suma = r1.sumar(r2, r3);
    cout << "Suma: ";
    suma.imprimir();
    cout << endl;
    
    CReal resta = r1.restar(r3, r2);
    cout << "Resta: ";
    resta.imprimir();
    cout << endl;
    
    CReal producto = r1.multiplicar(r2, r3);
    cout << "Producto: ";
    producto.imprimir();
    cout << endl;
    
    CReal cociente = r1.dividir(r3, r2);
    cout << "Cociente: ";
    cociente.imprimir();
    cout << endl;
    
    // Constructor de copia
    cout << "\n--- Constructor de copia ---" << endl;
    CReal r4 = r2;
    cout << "r4 (copia de r2) = ";
    r4.imprimir();
    cout << endl;
    
    cout << "\n=== FIN DEL PROGRAMA ===" << endl;
    return 0;
}
