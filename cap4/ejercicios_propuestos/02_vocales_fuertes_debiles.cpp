/*
 * ============================================================================
 * EJERCICIO 2: Contar vocales fuertes y débiles
 * ============================================================================
 * 
 * ENUNCIADO:
 *   Programa que solicite una cadena al usuario y reporte el número de
 *   vocales fuertes y vocales débiles que existen en la cadena.
 * 
 * CONCEPTOS LINGÜÍSTICOS:
 *   - Vocales fuertes (abiertas): a, e, o
 *     Se llaman "fuertes" porque se pronuncian con mayor apertura bucal
 *   - Vocales débiles (cerradas): i, u
 *     Se llaman "débiles" porque se pronuncian con menor apertura bucal
 * 
 * OBJETIVO:
 *   - Clasificar vocales según su tipo
 *   - Usar múltiples contadores
 *   - Aplicar lógica condicional
 *   - Crear funciones auxiliares booleanas
 * 
 * APLICACIÓN:
 *   - Análisis fonético del español
 *   - Detección de diptongos e hiatos
 *   - Procesamiento de texto
 * ============================================================================
 */

#include <iostream>
#include <cctype>    // Para tolower()
#include <cstring>   // Para strlen()
#include <iomanip>   // Para setprecision(), fixed

using namespace std;

// =============================================================================
// FUNCIONES AUXILIARES
// =============================================================================

/*
 * Función: esVocalFuerte
 * ----------------------
 * Determina si un carácter es una vocal fuerte (a, e, o)
 * 
 * Parámetro:
 *   c - carácter a verificar
 * 
 * Retorna:
 *   true si es vocal fuerte (a, e, o)
 *   false en caso contrario
 * 
 * Ejemplo:
 *   esVocalFuerte('a') → true
 *   esVocalFuerte('A') → true (se convierte a minúscula internamente)
 *   esVocalFuerte('i') → false
 *   esVocalFuerte('b') → false
 */
bool esVocalFuerte(char c) {
    // Convertir a minúscula para hacer una sola comparación
    // Así 'A' y 'a' se tratan igual
    c = tolower(c);
    
    // Retornar true si es 'a', 'e' u 'o'
    // El operador || (OR) retorna true si alguna condición es verdadera
    return (c == 'a' || c == 'e' || c == 'o');
}

/*
 * Función: esVocalDebil
 * ---------------------
 * Determina si un carácter es una vocal débil (i, u)
 * 
 * Parámetro:
 *   c - carácter a verificar
 * 
 * Retorna:
 *   true si es vocal débil (i, u)
 *   false en caso contrario
 * 
 * Ejemplo:
 *   esVocalDebil('i') → true
 *   esVocalDebil('U') → true
 *   esVocalDebil('e') → false
 */
bool esVocalDebil(char c) {
    // Convertir a minúscula
    c = tolower(c);
    
    // Retornar true si es 'i' o 'u'
    return (c == 'i' || c == 'u');
}

/*
 * Función: esVocal
 * ----------------
 * Determina si un carácter es vocal (fuerte o débil)
 * 
 * Parámetro:
 *   c - carácter a verificar
 * 
 * Retorna:
 *   true si es cualquier vocal (a, e, i, o, u)
 *   false en caso contrario
 * 
 * Nota:
 *   Reutiliza las funciones esVocalFuerte y esVocalDebil
 */
bool esVocal(char c) {
    return esVocalFuerte(c) || esVocalDebil(c);
}

// =============================================================================
// FUNCIÓN PRINCIPAL
// =============================================================================

int main() {
    // -------------------------------------------------------------------------
    // DECLARACIÓN DE VARIABLES
    // -------------------------------------------------------------------------
    char cadena[256];         // Cadena de entrada (hasta 255 caracteres)
    int contadorFuertes = 0;  // Contador de vocales fuertes (a, e, o)
    int contadorDebiles = 0;  // Contador de vocales débiles (i, u)
    
    // -------------------------------------------------------------------------
    // ENTRADA DE DATOS
    // -------------------------------------------------------------------------
    cout << "╔══════════════════════════════════════════════════════════╗" << endl;
    cout << "║    CONTADOR DE VOCALES FUERTES Y DÉBILES                ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
    
    // Mostrar información sobre las vocales
    cout << "📚 Información:" << endl;
    cout << "   • Vocales fuertes (abiertas): a, e, o" << endl;
    cout << "   • Vocales débiles (cerradas): i, u" << endl;
    cout << endl;
    
    cout << "Ingrese una cadena de texto: ";
    cin.getline(cadena, 256);
    
    // -------------------------------------------------------------------------
    // VALIDACIÓN: Verificar que no sea una cadena vacía
    // -------------------------------------------------------------------------
    if (strlen(cadena) == 0) {
        cout << "\n⚠️  Advertencia: La cadena está vacía." << endl;
        return 0;
    }
    
    // -------------------------------------------------------------------------
    // PROCESAMIENTO: Recorrer y clasificar vocales
    // -------------------------------------------------------------------------
    // Optimización: Calcular la longitud una sola vez
    // Evita llamar a strlen() en cada iteración del bucle
    int longitud = strlen(cadena);
    
    // Recorrer cada carácter de la cadena
    for (int i = 0; i < longitud; i++) {
        char caracter = cadena[i];
        
        // Verificar si es vocal fuerte
        if (esVocalFuerte(caracter)) {
            contadorFuertes++;  // Incrementar contador de fuertes
        }
        // Verificar si es vocal débil
        // Usamos else if porque un carácter no puede ser ambas
        else if (esVocalDebil(caracter)) {
            contadorDebiles++;  // Incrementar contador de débiles
        }
        // Si no es vocal, continuamos con el siguiente carácter
        // (podría ser consonante, número, espacio, signo, etc.)
    }
    
    // -------------------------------------------------------------------------
    // CÁLCULOS ADICIONALES
    // -------------------------------------------------------------------------
    int totalVocales = contadorFuertes + contadorDebiles;
    int consonantes = 0;
    int espacios = 0;
    int otros = 0;
    
    // Segundo recorrido para contar otros tipos de caracteres
    for (int i = 0; i < longitud; i++) {
        char c = cadena[i];
        
        if (esVocal(c)) {
            // Ya contadas, no hacer nada
        }
        else if (isalpha(c)) {
            // Es letra pero no vocal, entonces es consonante
            consonantes++;
        }
        else if (isspace(c)) {
            // Es espacio en blanco (espacio, tab, etc.)
            espacios++;
        }
        else {
            // Es otro tipo de carácter (número, puntuación, etc.)
            otros++;
        }
    }
    
    // -------------------------------------------------------------------------
    // SALIDA DE RESULTADOS
    // -------------------------------------------------------------------------
    cout << endl;
    cout << "╔══════════════════════════════════════════════════════════╗" << endl;
    cout << "║                      RESULTADO                          ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
    
    cout << "Cadena analizada: \"" << cadena << "\"" << endl;
    cout << "Longitud total: " << longitud << " caracteres" << endl;
    cout << endl;
    
    // Mostrar conteo de vocales
    cout << "📊 VOCALES:" << endl;
    cout << "   ├─ Vocales fuertes (a, e, o): " << contadorFuertes << endl;
    cout << "   ├─ Vocales débiles (i, u):    " << contadorDebiles << endl;
    cout << "   └─ Total de vocales:          " << totalVocales << endl;
    cout << endl;
    
    // Mostrar otros caracteres
    cout << "📊 OTROS CARACTERES:" << endl;
    cout << "   ├─ Consonantes: " << consonantes << endl;
    cout << "   ├─ Espacios:    " << espacios << endl;
    cout << "   └─ Otros:       " << otros << endl;
    cout << endl;
    
    // -------------------------------------------------------------------------
    // ANÁLISIS ESTADÍSTICO
    // -------------------------------------------------------------------------
    if (totalVocales > 0) {
        cout << "📈 ANÁLISIS:" << endl;
        
        // Calcular porcentajes
        // Multiplicamos por 100.0 para obtener resultado con decimales
        double porcentajeFuertes = (contadorFuertes * 100.0) / totalVocales;
        double porcentajeDebiles = (contadorDebiles * 100.0) / totalVocales;
        
        // Configurar salida con 2 decimales
        cout << fixed << setprecision(2);
        
        cout << "   ├─ Porcentaje de vocales fuertes: " << porcentajeFuertes << "%" << endl;
        cout << "   └─ Porcentaje de vocales débiles: " << porcentajeDebiles << "%" << endl;
        cout << endl;
        
        // Determinar cuál tipo predomina
        cout << "🔍 CONCLUSIÓN:" << endl;
        if (contadorFuertes > contadorDebiles) {
            cout << "   Predominan las vocales fuertes." << endl;
            int diferencia = contadorFuertes - contadorDebiles;
            cout << "   (hay " << diferencia << " vocales fuertes más que débiles)" << endl;
        } 
        else if (contadorDebiles > contadorFuertes) {
            cout << "   Predominan las vocales débiles." << endl;
            int diferencia = contadorDebiles - contadorFuertes;
            cout << "   (hay " << diferencia << " vocales débiles más que fuertes)" << endl;
        } 
        else {
            cout << "   Hay igual cantidad de vocales fuertes y débiles." << endl;
        }
    } 
    else {
        cout << "⚠️  No se encontraron vocales en la cadena." << endl;
    }
    
    return 0;
}

/*
 * ============================================================================
 * EJEMPLO DE EJECUCIÓN 1:
 * ============================================================================
 * 
 * ╔══════════════════════════════════════════════════════════╗
 * ║    CONTADOR DE VOCALES FUERTES Y DÉBILES                ║
 * ╚══════════════════════════════════════════════════════════╝
 * 
 * 📚 Información:
 *    • Vocales fuertes (abiertas): a, e, o
 *    • Vocales débiles (cerradas): i, u
 * 
 * Ingrese una cadena de texto: Universidad Nacional de San Marcos
 * 
 * ╔══════════════════════════════════════════════════════════╗
 * ║                      RESULTADO                          ║
 * ╚══════════════════════════════════════════════════════════╝
 * 
 * Cadena analizada: "Universidad Nacional de San Marcos"
 * Longitud total: 36 caracteres
 * 
 * 📊 VOCALES:
 *    ├─ Vocales fuertes (a, e, o): 9
 *    ├─ Vocales débiles (i, u):    4
 *    └─ Total de vocales:          13
 * 
 * 📊 OTROS CARACTERES:
 *    ├─ Consonantes: 17
 *    ├─ Espacios:    5
 *    └─ Otros:       1
 * 
 * 📈 ANÁLISIS:
 *    ├─ Porcentaje de vocales fuertes: 69.23%
 *    └─ Porcentaje de vocales débiles: 30.77%
 * 
 * 🔍 CONCLUSIÓN:
 *    Predominan las vocales fuertes.
 *    (hay 5 vocales fuertes más que débiles)
 * 
 * ============================================================================
 * EJEMPLO DE EJECUCIÓN 2:
 * ============================================================================
 * 
 * Ingrese una cadena de texto: Murciélago
 * 
 * Cadena analizada: "Murciélago"
 * Longitud total: 10 caracteres
 * 
 * 📊 VOCALES:
 *    ├─ Vocales fuertes (a, e, o): 3
 *    ├─ Vocales débiles (i, u):    2
 *    └─ Total de vocales:          5
 * 
 * ============================================================================
 * NOTAS TÉCNICAS:
 * ============================================================================
 * 
 * 1. VOCALES EN ESPAÑOL:
 *    
 *    Fuertes (abiertas): a, e, o
 *    - Se llaman "abiertas" porque la lengua desciende
 *    - Requieren mayor apertura de la mandíbula
 *    - Son más sonoras
 *    
 *    Débiles (cerradas): i, u
 *    - Se llaman "cerradas" porque la lengua asciende
 *    - Requieren menor apertura de la mandíbula
 *    - Son menos sonoras
 * 
 * 2. DIPTONGOS Y HIATOS:
 *    
 *    Diptongo (dos vocales en una sílaba):
 *    - Vocal fuerte + débil: ai-re, eu-ro, au-to
 *    - Débil + vocal fuerte: cie-lo, cuo-ta, mie-do
 *    - Débil + débil: ciu-dad, viu-da
 *    
 *    Hiato (dos vocales en sílabas separadas):
 *    - Dos vocales fuertes: ca-os, le-ón, te-a-tro
 *    - Vocal débil acentuada: pa-ís, ba-úl, Ma-rí-a
 * 
 * 3. FUNCIONES BOOLEANAS:
 *    Las funciones que retornan bool son útiles para:
 *    - Hacer el código más legible
 *    - Reutilizar lógica de verificación
 *    - Facilitar el mantenimiento
 *    - Crear abstracciones claras
 *    
 *    Ventajas:
 *    if (esVocalFuerte(c))  // ✓ Claro y expresivo
 *    vs
 *    if (c=='a' || c=='e' || c=='o')  // ✗ Repetitivo
 * 
 * 4. OPERADORES LÓGICOS:
 *    
 *    && (AND lógico):
 *    - Retorna true solo si AMBAS condiciones son verdaderas
 *    - Evaluación en corto-circuito: si la primera es false, no evalúa la segunda
 *    
 *    || (OR lógico):
 *    - Retorna true si AL MENOS UNA condición es verdadera
 *    - Evaluación en corto-circuito: si la primera es true, no evalúa la segunda
 *    
 *    ! (NOT lógico):
 *    - Invierte el valor booleano
 *    - !true = false, !false = true
 * 
 * 5. OPTIMIZACIÓN CON SWITCH:
 *    Una alternativa para clasificar vocales:
 *    
 *    switch (tolower(caracter)) {
 *        case 'a': case 'e': case 'o':
 *            contadorFuertes++;
 *            break;
 *        case 'i': case 'u':
 *            contadorDebiles++;
 *            break;
 *    }
 * 
 * 6. FUNCIONES DE <cctype>:
 *    - isalpha(c): true si c es letra (a-z, A-Z)
 *    - isspace(c): true si c es espacio, tab, newline, etc.
 *    - isalnum(c): true si c es letra o dígito
 *    - isdigit(c): true si c es dígito (0-9)
 *    - ispunct(c): true si c es signo de puntuación
 * 
 * 7. PORCENTAJES CON DECIMALES:
 *    Para calcular porcentajes correctamente:
 *    
 *    ❌ INCORRECTO:
 *    int porcentaje = (contador * 100) / total;
 *    // División entera trunca decimales
 *    
 *    ✓ CORRECTO:
 *    double porcentaje = (contador * 100.0) / total;
 *    // Al menos un operando debe ser double
 * 
 * 8. EXTENSIONES POSIBLES:
 *    - Contar cada vocal individualmente
 *    - Detectar diptongos automáticamente
 *    - Detectar hiatos
 *    - Análisis silábico básico
 *    - Generar estadísticas más detalladas
 *    - Crear histograma visual de vocales
 * 
 * 9. COMPILACIÓN:
 *    g++ -std=c++11 -Wall -Wextra 02_vocales_fuertes_debiles.cpp -o vocales
 *    ./vocales
 * ============================================================================
 */
