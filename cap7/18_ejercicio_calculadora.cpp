// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Ejercicio Propuesto 4: Clase Calculadora
 * Implementación completa con memoria para almacenar resultados
 * 
 * CONCEPTOS PRACTICADOS:
 * - Arreglo como dato miembro (memoria[N])
 * - Manejo de múltiples operaciones (+, -, *, /)
 * - Almacenamiento de historial de resultados
 * - Validación de operación de división por cero
 * - Menú interactivo
 * - Gestión de memoria dinámica conceptual
 */

#include <iostream>
using namespace std;

const int N = 100;  // Máximo de valores en memoria

class Calculadora
{
private:
    float n1;           // primer operando
    float n2;           // segundo operando
    char op;            // operador
    float memoria[N];   // almacena los resultados de las operaciones
    int nmem;           // cantidad de valores almacenados en memoria
    
public:
    // Constructores
    Calculadora();                        // constructor por defecto
    Calculadora(float a, float b, char o); // constructor con parámetros
    
    // Destructor
    ~Calculadora();
    
    // Funciones de entrada
    void ingresar();    // ingresa los operandos y el operador
    
    // Funciones de cálculo
    void calcular();    // calcula, imprime y almacena el resultado de la operación
    
    // Funciones set/get
    void setn1(float a);    // asigna valor a n1
    void setn2(float b);    // asigna valor a n2
    void setop(char o);     // asigna valor a op
    float getn1();          // obtiene el valor de n1
    float getn2();          // obtiene el valor de n2
    char getop();           // obtiene el valor de op
    
    // Funciones de utilidad
    void operacion();       // imprime el tipo de operación realizada
    void limpiarMemoria();  // elimina los valores almacenados en memoria
    void mostrarMemoria();  // muestra todos los valores en memoria
    void mostrarInfo();     // muestra información actual de la calculadora
};

// Constructor por defecto
Calculadora::Calculadora()
{
    n1 = n2 = 0.0;
    op = '+';
    nmem = 0;
    cout << "Constructor por defecto - Calculadora creada" << endl;
}

// Constructor con parámetros
Calculadora::Calculadora(float a, float b, char o)
{
    n1 = a;
    n2 = b;
    op = o;
    nmem = 0;
    cout << "Constructor con parámetros - Calculadora creada con " << a << " " << o << " " << b << endl;
}

// Destructor
Calculadora::~Calculadora()
{
    cout << "Destructor - Calculadora destruida. Memoria limpiada." << endl;
}

// Ingresa los operandos y el operador
void Calculadora::ingresar()
{
    cout << "Ingrese el primer número: ";
    cin >> n1;
    cout << "Ingrese el operador (+, -, *, /): ";
    cin >> op;
    cout << "Ingrese el segundo número: ";
    cin >> n2;
}

// Calcula, imprime y almacena el resultado de la operación
void Calculadora::calcular()
{
    float resultado = 0;
    bool operacionValida = true;
    
    switch(op)
    {
        case '+':
            resultado = n1 + n2;
            break;
        case '-':
            resultado = n1 - n2;
            break;
        case '*':
            resultado = n1 * n2;
            break;
        case '/':
            if(n2 != 0)
                resultado = n1 / n2;
            else
            {
                cout << "Error: División por cero!" << endl;
                operacionValida = false;
            }
            break;
        default:
            cout << "Error: Operador no válido!" << endl;
            operacionValida = false;
    }
    
    if(operacionValida)
    {
        cout << "Resultado: " << n1 << " " << op << " " << n2 << " = " << resultado << endl;
        
        // Almacenar en memoria si hay espacio
        if(nmem < N)
        {
            memoria[nmem] = resultado;
            nmem++;
            cout << "Resultado almacenado en memoria (posición " << nmem-1 << ")" << endl;
        }
        else
        {
            cout << "Memoria llena! No se pudo almacenar el resultado." << endl;
        }
    }
}

// Funciones set/get
void Calculadora::setn1(float a) { n1 = a; }
void Calculadora::setn2(float b) { n2 = b; }
void Calculadora::setop(char o) { op = o; }
float Calculadora::getn1() { return n1; }
float Calculadora::getn2() { return n2; }
char Calculadora::getop() { return op; }

// Imprime el tipo de operación realizada
void Calculadora::operacion()
{
    string tipoOperacion;
    switch(op)
    {
        case '+': tipoOperacion = "Suma"; break;
        case '-': tipoOperacion = "Resta"; break;
        case '*': tipoOperacion = "Multiplicación"; break;
        case '/': tipoOperacion = "División"; break;
        default: tipoOperacion = "Operación desconocida"; break;
    }
    cout << "Tipo de operación: " << tipoOperacion << endl;
    calcular();
}

// Elimina los valores almacenados en memoria
void Calculadora::limpiarMemoria()
{
    nmem = 0;
    cout << "Memoria limpiada. Todos los valores eliminados." << endl;
}

// Muestra todos los valores en memoria
void Calculadora::mostrarMemoria()
{
    if(nmem == 0)
    {
        cout << "La memoria está vacía." << endl;
    }
    else
    {
        cout << "Valores en memoria (" << nmem << " elementos):" << endl;
        for(int i = 0; i < nmem; i++)
        {
            cout << "[" << i << "] = " << memoria[i] << endl;
        }
    }
}

// Muestra información actual de la calculadora
void Calculadora::mostrarInfo()
{
    cout << "=== ESTADO ACTUAL DE LA CALCULADORA ===" << endl;
    cout << "Operando 1: " << n1 << endl;
    cout << "Operador: " << op << endl;
    cout << "Operando 2: " << n2 << endl;
    cout << "Elementos en memoria: " << nmem << "/" << N << endl;
}

int main()
{
    cout << "=== PRUEBA DE CLASE CALCULADORA ===" << endl;
    
    // Constructor por defecto
    Calculadora calc1;
    calc1.mostrarInfo();
    
    // Constructor con parámetros
    cout << "\n--- Constructor con parámetros ---" << endl;
    Calculadora calc2(15.0, 3.0, '/');
    calc2.mostrarInfo();
    calc2.operacion();
    
    // Menú interactivo
    cout << "\n--- Menú interactivo ---" << endl;
    Calculadora calc;
    int opcion;
    
    do
    {
        cout << "\n=== MENU DE CALCULADORA ===" << endl;
        cout << "1. Ingresar nueva operación" << endl;
        cout << "2. Calcular con valores actuales" << endl;
        cout << "3. Mostrar información actual" << endl;
        cout << "4. Mostrar memoria" << endl;
        cout << "5. Limpiar memoria" << endl;
        cout << "6. Establecer valores manualmente" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;
        
        switch(opcion)
        {
            case 1:
                calc.ingresar();
                calc.operacion();
                break;
                
            case 2:
                calc.operacion();
                break;
                
            case 3:
                calc.mostrarInfo();
                break;
                
            case 4:
                calc.mostrarMemoria();
                break;
                
            case 5:
                calc.limpiarMemoria();
                break;
                
            case 6:
                {
                    float a, b;
                    char o;
                    cout << "Ingrese n1: ";
                    cin >> a;
                    cout << "Ingrese operador: ";
                    cin >> o;
                    cout << "Ingrese n2: ";
                    cin >> b;
                    calc.setn1(a);
                    calc.setop(o);
                    calc.setn2(b);
                    cout << "Valores establecidos." << endl;
                }
                break;
                
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
                
            default:
                cout << "Opción no válida." << endl;
        }
    } while(opcion != 0);
    
    cout << "\n=== FIN DEL PROGRAMA ===" << endl;
    return 0;
}
