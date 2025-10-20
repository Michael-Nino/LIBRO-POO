/*
 * ============================================================================
 * EJERCICIO 4: Generar cadena repetida N veces
 * ============================================================================
 * 
 * ENUNCIADO:
 *   Programa cuya entrada sea una cadena S y un factor de multiplicación N.
 *   La función generaRepetida recibirá S y N como parámetros y generará
 *   la cadena S tantas veces como indique N.
 *   
 *   Ejemplo: S = "Hola que tal", N = 3
 *            Resultado: "Hola que tal Hola que tal Hola que tal"
 * 
 * OBJETIVO:
 *   - Concatenar cadenas múltiples veces
 *   - Trabajar con funciones que modifican cadenas
 *   - Usar strcat() o implementar concatenación manual
 *   - Validar límites de tamaño de buffer
 * 
 * CONCEPTOS CLAVE:
 *   - Concatenación de cadenas con strcat()
 *   - Control de tamaño de buffer
 *   - Bucles para repetición
 *   - Paso de parámetros a funciones
 * ============================================================================
 */

#include <iostream>
#include <cstring>   // Para strlen(), strcat(), strcpy()

using namespace std;

// =============================================================================
// CONSTANTES GLOBALES
// =============================================================================

// Tamaño máximo del buffer de salida
// Debe ser suficientemente grande para contener la cadena repetida
const int MAX_BUFFER = 2048;

// =============================================================================
// FUNCIONES AUXILIARES
// =============================================================================

/*
 * Función: generaRepetida
 * ------------------------
 * Genera una cadena resultado que contiene la cadena fuente repetida N veces
 * Las repeticiones están separadas por un espacio
 * 
 * Parámetros:
 *   fuente - cadena a repetir (entrada)
 *   resultado - buffer donde se guardará el resultado (salida)
 *   n - número de veces que se repetirá la cadena
 *   separador - carácter que separa cada repetición (por defecto ' ')
 * 
 * Retorna:
 *   bool - true si se completó exitosamente
 *          false si el buffer no es suficientemente grande
 * 
 * Ejemplo:
 *   char resultado[100];
 *   generaRepetida("Hola", resultado, 3, ' ');
 *   // resultado = "Hola Hola Hola"
 */
bool generaRepetida(const char fuente[], char resultado[], int n, char separador = ' ') {
    // Validar parámetros
    if (n <= 0) {
        // Si n es 0 o negativo, resultado es cadena vacía
        resultado[0] = '\0';
        return true;
    }
    
    // Calcular el tamaño necesario
    // Tamaño = longitud_fuente * n + (n-1) separadores + 1 para '\0'
    int longitudFuente = strlen(fuente);
    int tamanoNecesario = (longitudFuente * n) + (n - 1) + 1;
    
    // Verificar que el buffer sea suficientemente grande
    if (tamanoNecesario > MAX_BUFFER) {
        cerr << "⚠️  Error: El resultado excede el tamaño del buffer." << endl;
        cerr << "   Tamaño necesario: " << tamanoNecesario << " bytes" << endl;
        cerr << "   Tamaño disponible: " << MAX_BUFFER << " bytes" << endl;
        resultado[0] = '\0';
        return false;
    }
    
    // Inicializar el resultado como cadena vacía
    resultado[0] = '\0';
    
    // MÉTODO 1: Usando strcat() (concatenación de cadenas)
    // -----------------------------------------------------
    // strcat(destino, origen) concatena 'origen' al final de 'destino'
    
    for (int i = 0; i < n; i++) {
        // Concatenar la cadena fuente
        strcat(resultado, fuente);
        
        // Si no es la última repetición, agregar el separador
        if (i < n - 1) {
            // Para agregar un solo carácter, creamos una cadena de 2 caracteres
            char sep[2] = {separador, '\0'};
            strcat(resultado, sep);
        }
    }
    
    return true;
}

/*
 * Función: generaRepetidaManual
 * ------------------------------
 * Versión alternativa que implementa la concatenación manualmente
 * sin usar strcat(), para entender cómo funciona internamente
 * 
 * Parámetros:
 *   fuente - cadena a repetir
 *   resultado - buffer de salida
 *   n - número de repeticiones
 *   separador - carácter separador
 * 
 * Retorna:
 *   bool - true si fue exitoso, false si no cabe
 */
bool generaRepetidaManual(const char fuente[], char resultado[], int n, char separador = ' ') {
    if (n <= 0) {
        resultado[0] = '\0';
        return true;
    }
    
    int longitudFuente = strlen(fuente);
    int tamanoNecesario = (longitudFuente * n) + (n - 1) + 1;
    
    if (tamanoNecesario > MAX_BUFFER) {
        resultado[0] = '\0';
        return false;
    }
    
    // Índice para escribir en resultado
    int pos = 0;
    
    // Repetir n veces
    for (int rep = 0; rep < n; rep++) {
        // Copiar cada carácter de fuente a resultado
        for (int i = 0; i < longitudFuente; i++) {
            resultado[pos] = fuente[i];
            pos++;
        }
        
        // Agregar separador si no es la última repetición
        if (rep < n - 1) {
            resultado[pos] = separador;
            pos++;
        }
    }
    
    // Agregar el carácter nulo al final
    resultado[pos] = '\0';
    
    return true;
}

/*
 * Función: generaRepetidaSinEspacios
 * -----------------------------------
 * Genera la cadena repetida sin separadores
 * 
 * Ejemplo:
 *   "ABC" repetido 3 veces → "ABCABCABC"
 */
bool generaRepetidaSinEspacios(const char fuente[], char resultado[], int n) {
    if (n <= 0) {
        resultado[0] = '\0';
        return true;
    }
    
    int longitudFuente = strlen(fuente);
    int tamanoNecesario = (longitudFuente * n) + 1;
    
    if (tamanoNecesario > MAX_BUFFER) {
        resultado[0] = '\0';
        return false;
    }
    
    resultado[0] = '\0';
    
    for (int i = 0; i < n; i++) {
        strcat(resultado, fuente);
    }
    
    return true;
}

// =============================================================================
// FUNCIÓN PRINCIPAL
// =============================================================================

int main() {
    // -------------------------------------------------------------------------
    // DECLARACIÓN DE VARIABLES
    // -------------------------------------------------------------------------
    char cadenaFuente[256];        // Cadena ingresada por el usuario
    char resultado[MAX_BUFFER];    // Buffer para almacenar el resultado
    int numeroRepeticiones;        // Cuántas veces repetir
    
    // -------------------------------------------------------------------------
    // ENTRADA DE DATOS
    // -------------------------------------------------------------------------
    cout << "╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║          GENERADOR DE CADENA REPETIDA                     ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
    
    // Solicitar la cadena
    cout << "Ingrese la cadena a repetir: ";
    cin.getline(cadenaFuente, 256);
    
    // Validar que no esté vacía
    if (strlen(cadenaFuente) == 0) {
        cout << "\n⚠️  Error: La cadena no puede estar vacía." << endl;
        return 1;
    }
    
    // Solicitar el número de repeticiones
    cout << "Ingrese el número de repeticiones (N): ";
    cin >> numeroRepeticiones;
    
    // -------------------------------------------------------------------------
    // VALIDACIÓN DEL NÚMERO DE REPETICIONES
    // -------------------------------------------------------------------------
    if (numeroRepeticiones < 0) {
        cout << "\n⚠️  Error: El número de repeticiones no puede ser negativo." << endl;
        return 1;
    }
    
    if (numeroRepeticiones == 0) {
        cout << "\n✓ Resultado: Cadena vacía (0 repeticiones)" << endl;
        return 0;
    }
    
    // Advertencia si es un número muy grande
    if (numeroRepeticiones > 100) {
        cout << "\n⚠️  Advertencia: Número de repeticiones muy grande (" 
             << numeroRepeticiones << ")" << endl;
        cout << "   El resultado puede ser muy largo." << endl;
        
        char continuar;
        cout << "   ¿Desea continuar? (s/n): ";
        cin >> continuar;
        
        if (continuar != 's' && continuar != 'S') {
            cout << "\n✗ Operación cancelada." << endl;
            return 0;
        }
    }
    
    // -------------------------------------------------------------------------
    // PROCESAMIENTO: Generar la cadena repetida
    // -------------------------------------------------------------------------
    cout << endl;
    cout << "⏳ Generando cadena repetida..." << endl;
    
    bool exito = generaRepetida(cadenaFuente, resultado, numeroRepeticiones, ' ');
    
    if (!exito) {
        cout << "\n✗ No se pudo generar la cadena repetida." << endl;
        cout << "   Intente con menos repeticiones o una cadena más corta." << endl;
        return 1;
    }
    
    // -------------------------------------------------------------------------
    // SALIDA DE RESULTADOS
    // -------------------------------------------------------------------------
    cout << endl;
    cout << "╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                      RESULTADO                            ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
    
    // Información de entrada
    cout << "📝 ENTRADA:" << endl;
    cout << "   • Cadena fuente: \"" << cadenaFuente << "\"" << endl;
    cout << "   • Longitud: " << strlen(cadenaFuente) << " caracteres" << endl;
    cout << "   • Repeticiones: " << numeroRepeticiones << endl;
    cout << endl;
    
    // Resultado
    cout << "✓ CADENA GENERADA:" << endl;
    cout << "\"" << resultado << "\"" << endl;
    cout << endl;
    
    // Estadísticas del resultado
    cout << "📊 ESTADÍSTICAS:" << endl;
    cout << "   • Longitud del resultado: " << strlen(resultado) << " caracteres" << endl;
    cout << "   • Tamaño usado del buffer: " << strlen(resultado) + 1 << " bytes" << endl;
    cout << "   • Tamaño disponible: " << MAX_BUFFER << " bytes" << endl;
    
    // Calcular porcentaje de uso del buffer
    double porcentajeUso = ((strlen(resultado) + 1) * 100.0) / MAX_BUFFER;
    cout << "   • Uso del buffer: " << porcentajeUso << "%" << endl;
    
    // -------------------------------------------------------------------------
    // DEMOSTRACIÓN CON DIFERENTES SEPARADORES
    // -------------------------------------------------------------------------
    cout << endl;
    cout << "╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║         VARIANTES CON DIFERENTES SEPARADORES              ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
    
    // Solo mostrar si hay pocas repeticiones (para no saturar la salida)
    if (numeroRepeticiones <= 5) {
        char variante[MAX_BUFFER];
        
        // Con guiones
        cout << "Con guiones (-):" << endl;
        generaRepetida(cadenaFuente, variante, numeroRepeticiones, '-');
        cout << "\"" << variante << "\"" << endl;
        cout << endl;
        
        // Con comas
        cout << "Con comas (,):" << endl;
        generaRepetida(cadenaFuente, variante, numeroRepeticiones, ',');
        cout << "\"" << variante << "\"" << endl;
        cout << endl;
        
        // Sin separadores
        cout << "Sin separadores:" << endl;
        generaRepetidaSinEspacios(cadenaFuente, variante, numeroRepeticiones);
        cout << "\"" << variante << "\"" << endl;
    }
    
    return 0;
}

/*
 * ============================================================================
 * EJEMPLO DE EJECUCIÓN 1:
 * ============================================================================
 * 
 * ╔════════════════════════════════════════════════════════════╗
 * ║          GENERADOR DE CADENA REPETIDA                     ║
 * ╚════════════════════════════════════════════════════════════╝
 * 
 * Ingrese la cadena a repetir: Hola que tal
 * Ingrese el número de repeticiones (N): 3
 * 
 * ⏳ Generando cadena repetida...
 * 
 * ╔════════════════════════════════════════════════════════════╗
 * ║                      RESULTADO                            ║
 * ╚════════════════════════════════════════════════════════════╝
 * 
 * 📝 ENTRADA:
 *    • Cadena fuente: "Hola que tal"
 *    • Longitud: 12 caracteres
 *    • Repeticiones: 3
 * 
 * ✓ CADENA GENERADA:
 * "Hola que tal Hola que tal Hola que tal"
 * 
 * 📊 ESTADÍSTICAS:
 *    • Longitud del resultado: 38 caracteres
 *    • Tamaño usado del buffer: 39 bytes
 *    • Tamaño disponible: 2048 bytes
 *    • Uso del buffer: 1.90%
 * 
 * ╔════════════════════════════════════════════════════════════╗
 * ║         VARIANTES CON DIFERENTES SEPARADORES              ║
 * ╚════════════════════════════════════════════════════════════╝
 * 
 * Con guiones (-):
 * "Hola que tal-Hola que tal-Hola que tal"
 * 
 * Con comas (,):
 * "Hola que tal,Hola que tal,Hola que tal"
 * 
 * Sin separadores:
 * "Hola que talHola que talHola que tal"
 * 
 * ============================================================================
 * EJEMPLO DE EJECUCIÓN 2 (Muchas repeticiones):
 * ============================================================================
 * 
 * Ingrese la cadena a repetir: ABC
 * Ingrese el número de repeticiones (N): 10
 * 
 * ✓ CADENA GENERADA:
 * "ABC ABC ABC ABC ABC ABC ABC ABC ABC ABC"
 * 
 * 📊 ESTADÍSTICAS:
 *    • Longitud del resultado: 39 caracteres
 *    • Uso del buffer: 1.95%
 * 
 * ============================================================================
 * NOTAS TÉCNICAS:
 * ============================================================================
 * 
 * 1. STRCAT() - CONCATENACIÓN DE CADENAS:
 *    
 *    strcat(destino, origen);
 *    
 *    Funcionamiento:
 *    - Busca el '\0' en destino
 *    - Copia origen a partir de esa posición
 *    - Añade '\0' al final
 *    
 *    Complejidad: O(n + m) donde n = longitud de destino, m = longitud de origen
 *    
 *    PELIGROS:
 *    - No verifica el tamaño del buffer destino
 *    - Puede causar buffer overflow
 *    - Puede sobrescribir memoria adyacente
 * 
 * 2. ALTERNATIVA SEGURA: strncat()
 *    
 *    strncat(destino, origen, n);
 *    
 *    Concatena máximo n caracteres de origen a destino
 *    Siempre añade '\0' al final
 *    
 *    Ejemplo:
 *    char destino[10] = "Hola";
 *    strncat(destino, " mundo!", 5);  // Añade solo " mund"
 * 
 * 3. CÁLCULO DE TAMAÑO NECESARIO:
 *    
 *    Para repetir cadena S, n veces, con separadores:
 *    
 *    Tamaño = longitud(S) × n + (n - 1) + 1
 *             ^^^^^^^^^^^^^^^   ^^^^^^^   ^
 *             contenido        separadores '\0'
 *    
 *    Ejemplo: "ABC" repetido 3 veces con espacios
 *    Tamaño = 3 × 3 + (3 - 1) + 1 = 9 + 2 + 1 = 12
 *    Resultado: "ABC ABC ABC\0" (12 bytes)
 * 
 * 4. BUFFER OVERFLOW:
 *    
 *    Es uno de los errores más peligrosos en C/C++
 *    Ocurre cuando escribimos más allá del tamaño del array
 *    
 *    Consecuencias:
 *    - Corrupción de datos
 *    - Comportamiento impredecible
 *    - Vulnerabilidades de seguridad
 *    - Crashes del programa
 *    
 *    Prevención:
 *    - Siempre verificar tamaños antes de copiar/concatenar
 *    - Usar versiones seguras: strncpy(), strncat()
 *    - Usar std::string en C++ moderno (recomendado)
 * 
 * 5. COMPARACIÓN: strcat() VS IMPLEMENTACIÓN MANUAL:
 *    
 *    strcat():
 *    ✓ Más conciso
 *    ✓ Estándar de C
 *    ✗ Debe buscar '\0' cada vez (ineficiente para muchas concatenaciones)
 *    
 *    Manual (con índice):
 *    ✓ Más eficiente (no busca '\0' repetidamente)
 *    ✓ Control total del proceso
 *    ✗ Más código
 *    ✗ Mayor probabilidad de errores
 * 
 * 6. OPTIMIZACIÓN PARA MÚLTIPLES CONCATENACIONES:
 *    
 *    Si vamos a hacer muchas concatenaciones, es mejor
 *    mantener un puntero a la posición actual:
 *    
 *    char* pos = resultado;
 *    for (int i = 0; i < n; i++) {
 *        strcpy(pos, fuente);
 *        pos += strlen(fuente);  // Avanzar el puntero
 *        if (i < n - 1) {
 *            *pos++ = ' ';  // Añadir separador
 *        }
 *    }
 *    *pos = '\0';  // Terminar la cadena
 * 
 * 7. ALTERNATIVA MODERNA CON std::string:
 *    
 *    #include <string>
 *    
 *    string generaRepetida(const string& s, int n) {
 *        string resultado;
 *        for (int i = 0; i < n; i++) {
 *            resultado += s;
 *            if (i < n - 1) resultado += " ";
 *        }
 *        return resultado;
 *    }
 *    
 *    Ventajas:
 *    - Manejo automático de memoria
 *    - Sin riesgo de buffer overflow
 *    - Más seguro y fácil de usar
 * 
 * 8. CASOS DE USO PRÁCTICOS:
 *    - Generar patrones de texto
 *    - Crear separadores visuales ("=" * 50)
 *    - Rellenar espacios ("*" * n)
 *    - Duplicar datos para pruebas
 *    - Generar cadenas de caracteres repetidos
 * 
 * 9. EXTENSIONES POSIBLES:
 *    - Permitir diferentes separadores entre repeticiones
 *    - Alternar entre mayúsculas y minúsculas
 *    - Numerar cada repetición: "1.Hola 2.Hola 3.Hola"
 *    - Invertir la cadena en repeticiones pares
 *    - Agregar prefijo/sufijo a cada repetición
 * 
 * 10. COMPILACIÓN:
 *     g++ -std=c++11 -Wall -Wextra 04_cadena_repetida.cpp -o repetida
 *     ./repetida
 * ============================================================================
 */
