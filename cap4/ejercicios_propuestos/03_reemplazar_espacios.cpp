/*
 * ============================================================================
 * EJERCICIO 3: Reemplazar espacios por asteriscos
 * ============================================================================
 * 
 * ENUNCIADO:
 *   Programa que lea una cadena de caracteres y reemplace todos los
 *   caracteres espacio en blanco por el carácter *.
 *   Debe mostrarse la cadena ingresada y la cadena transformada.
 * 
 * OBJETIVO:
 *   - Modificar caracteres dentro de una cadena
 *   - Comparar caracteres
 *   - Mostrar cadenas antes y después de la transformación
 *   - Trabajar con arrays mutables
 * 
 * CONCEPTOS CLAVE:
 *   - Modificación in-place de cadenas
 *   - Comparación con ' ' (espacio)
 *   - Función isspace() para detectar espacios
 *   - Arrays de caracteres son mutables
 * ============================================================================
 */

#include <iostream>
#include <cstring>   // Para strlen(), strcpy()
#include <cctype>    // Para isspace()

using namespace std;

// =============================================================================
// FUNCIONES AUXILIARES
// =============================================================================

/*
 * Función: reemplazarEspacios
 * ----------------------------
 * Reemplaza todos los espacios en blanco por asteriscos en una cadena
 * 
 * Parámetros:
 *   cadena - array de caracteres a modificar (se modifica directamente)
 *   reemplazo - carácter que reemplazará los espacios (por defecto '*')
 * 
 * Retorna:
 *   int - número de espacios reemplazados
 * 
 * Nota:
 *   Esta función modifica la cadena original (paso por referencia)
 *   No crea una copia, sino que trabaja directamente sobre la cadena
 */
int reemplazarEspacios(char cadena[], char reemplazo = '*') {
    int contador = 0;  // Contar cuántos espacios se reemplazan
    
    // Recorrer cada carácter de la cadena
    // Nos detenemos al encontrar '\0' (fin de cadena)
    for (int i = 0; cadena[i] != '\0'; i++) {
        // Verificar si el carácter actual es un espacio
        if (cadena[i] == ' ') {
            // Reemplazar el espacio por el carácter de reemplazo
            cadena[i] = reemplazo;
            contador++;  // Incrementar contador
        }
    }
    
    return contador;  // Retornar cantidad de reemplazos realizados
}

/*
 * Función: reemplazarEspaciosIsspace
 * -----------------------------------
 * Versión alternativa que usa isspace()
 * Reemplaza todos los tipos de espacios en blanco (espacio, tab, newline, etc.)
 * 
 * Parámetros:
 *   cadena - array de caracteres a modificar
 *   reemplazo - carácter de reemplazo
 * 
 * Retorna:
 *   int - número de caracteres de espacio reemplazados
 * 
 * Nota:
 *   isspace() detecta: espacio ' ', tab '\t', newline '\n', etc.
 */
int reemplazarEspaciosIsspace(char cadena[], char reemplazo = '*') {
    int contador = 0;
    
    for (int i = 0; cadena[i] != '\0'; i++) {
        // isspace() retorna true para cualquier tipo de espacio en blanco
        if (isspace(cadena[i])) {
            cadena[i] = reemplazo;
            contador++;
        }
    }
    
    return contador;
}

/*
 * Función: contarEspacios
 * ------------------------
 * Cuenta el número de espacios en una cadena sin modificarla
 * 
 * Parámetro:
 *   cadena - cadena a analizar (no se modifica)
 * 
 * Retorna:
 *   int - número de espacios encontrados
 */
int contarEspacios(const char cadena[]) {
    int contador = 0;
    
    // const indica que no modificaremos la cadena
    // Es una buena práctica para funciones que solo leen
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == ' ') {
            contador++;
        }
    }
    
    return contador;
}

// =============================================================================
// FUNCIÓN PRINCIPAL
// =============================================================================

int main() {
    // -------------------------------------------------------------------------
    // DECLARACIÓN DE VARIABLES
    // -------------------------------------------------------------------------
    char cadenaOriginal[256];    // Cadena ingresada por el usuario
    char cadenaModificada[256];  // Copia para mostrar comparación
    
    // -------------------------------------------------------------------------
    // ENTRADA DE DATOS
    // -------------------------------------------------------------------------
    cout << "╔═══════════════════════════════════════════════════════════╗" << endl;
    cout << "║      REEMPLAZAR ESPACIOS POR ASTERISCOS                  ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
    
    cout << "Ingrese una cadena de texto: ";
    cin.getline(cadenaOriginal, 256);
    
    // -------------------------------------------------------------------------
    // VALIDACIÓN: Verificar que no sea una cadena vacía
    // -------------------------------------------------------------------------
    if (strlen(cadenaOriginal) == 0) {
        cout << "\n⚠️  Advertencia: La cadena está vacía." << endl;
        return 0;
    }
    
    // -------------------------------------------------------------------------
    // CREAR UNA COPIA PARA COMPARACIÓN
    // -------------------------------------------------------------------------
    // strcpy() copia una cadena a otra
    // Sintaxis: strcpy(destino, origen)
    // Copia todos los caracteres incluyendo '\0'
    strcpy(cadenaModificada, cadenaOriginal);
    
    // -------------------------------------------------------------------------
    // ANÁLISIS PREVIO
    // -------------------------------------------------------------------------
    int espaciosOriginales = contarEspacios(cadenaOriginal);
    
    cout << endl;
    cout << "📊 ANÁLISIS PREVIO:" << endl;
    cout << "   • Longitud total: " << strlen(cadenaOriginal) << " caracteres" << endl;
    cout << "   • Espacios encontrados: " << espaciosOriginales << endl;
    
    if (espaciosOriginales == 0) {
        cout << "\n✓ No hay espacios para reemplazar." << endl;
        return 0;
    }
    
    // -------------------------------------------------------------------------
    // PROCESAMIENTO: Reemplazar espacios
    // -------------------------------------------------------------------------
    // Reemplazamos espacios en la copia
    // La cadena original se mantiene para mostrar el "antes"
    int espaciosReemplazados = reemplazarEspacios(cadenaModificada, '*');
    
    // -------------------------------------------------------------------------
    // SALIDA DE RESULTADOS
    // -------------------------------------------------------------------------
    cout << endl;
    cout << "╔═══════════════════════════════════════════════════════════╗" << endl;
    cout << "║                      RESULTADO                           ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
    
    // Mostrar cadena original
    cout << "CADENA ORIGINAL:" << endl;
    cout << "\"" << cadenaOriginal << "\"" << endl;
    cout << endl;
    
    // Mostrar cadena transformada
    cout << "CADENA TRANSFORMADA:" << endl;
    cout << "\"" << cadenaModificada << "\"" << endl;
    cout << endl;
    
    // Mostrar estadísticas
    cout << "✓ Se reemplazaron " << espaciosReemplazados;
    if (espaciosReemplazados == 1) {
        cout << " espacio por '*'" << endl;
    } else {
        cout << " espacios por '*'" << endl;
    }
    
    // -------------------------------------------------------------------------
    // COMPARACIÓN VISUAL CARÁCTER POR CARÁCTER
    // -------------------------------------------------------------------------
    cout << endl;
    cout << "📝 COMPARACIÓN DETALLADA:" << endl;
    cout << "   Posición | Original | Transformada" << endl;
    cout << "   ---------|----------|-------------" << endl;
    
    for (int i = 0; i < strlen(cadenaOriginal); i++) {
        // Mostrar solo las posiciones donde hubo cambios
        if (cadenaOriginal[i] != cadenaModificada[i]) {
            cout << "      " << i << "     |    ";
            
            // Mostrar representación del espacio
            if (cadenaOriginal[i] == ' ') {
                cout << "' '";
            } else {
                cout << cadenaOriginal[i];
            }
            
            cout << "    |      '" << cadenaModificada[i] << "'" << endl;
        }
    }
    
    // -------------------------------------------------------------------------
    // DEMOSTRACIÓN DE DIFERENTES MÉTODOS
    // -------------------------------------------------------------------------
    cout << endl;
    cout << "╔═══════════════════════════════════════════════════════════╗" << endl;
    cout << "║            OTROS CARACTERES DE REEMPLAZO                 ║" << endl;
    cout << "╚═══════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
    
    // Crear copias para demostrar diferentes reemplazos
    char version2[256], version3[256], version4[256];
    strcpy(version2, cadenaOriginal);
    strcpy(version3, cadenaOriginal);
    strcpy(version4, cadenaOriginal);
    
    // Reemplazar con diferentes caracteres
    reemplazarEspacios(version2, '-');
    reemplazarEspacios(version3, '_');
    reemplazarEspacios(version4, '#');
    
    cout << "Con guiones (-):" << endl;
    cout << "\"" << version2 << "\"" << endl;
    cout << endl;
    
    cout << "Con guiones bajos (_):" << endl;
    cout << "\"" << version3 << "\"" << endl;
    cout << endl;
    
    cout << "Con numerales (#):" << endl;
    cout << "\"" << version4 << "\"" << endl;
    
    return 0;
}

/*
 * ============================================================================
 * EJEMPLO DE EJECUCIÓN 1:
 * ============================================================================
 * 
 * ╔═══════════════════════════════════════════════════════════╗
 * ║      REEMPLAZAR ESPACIOS POR ASTERISCOS                  ║
 * ╚═══════════════════════════════════════════════════════════╝
 * 
 * Ingrese una cadena de texto: Hola mundo desde C++
 * 
 * 📊 ANÁLISIS PREVIO:
 *    • Longitud total: 20 caracteres
 *    • Espacios encontrados: 3
 * 
 * ╔═══════════════════════════════════════════════════════════╗
 * ║                      RESULTADO                           ║
 * ╚═══════════════════════════════════════════════════════════╝
 * 
 * CADENA ORIGINAL:
 * "Hola mundo desde C++"
 * 
 * CADENA TRANSFORMADA:
 * "Hola*mundo*desde*C++"
 * 
 * ✓ Se reemplazaron 3 espacios por '*'
 * 
 * 📝 COMPARACIÓN DETALLADA:
 *    Posición | Original | Transformada
 *    ---------|----------|-------------
 *       4     |    ' '    |      '*'
 *       10    |    ' '    |      '*'
 *       16    |    ' '    |      '*'
 * 
 * ╔═══════════════════════════════════════════════════════════╗
 * ║            OTROS CARACTERES DE REEMPLAZO                 ║
 * ╚═══════════════════════════════════════════════════════════╝
 * 
 * Con guiones (-):
 * "Hola-mundo-desde-C++"
 * 
 * Con guiones bajos (_):
 * "Hola_mundo_desde_C++"
 * 
 * Con numerales (#):
 * "Hola#mundo#desde#C++"
 * 
 * ============================================================================
 * EJEMPLO DE EJECUCIÓN 2 (Sin espacios):
 * ============================================================================
 * 
 * Ingrese una cadena de texto: ProgramacionEnC++
 * 
 * 📊 ANÁLISIS PREVIO:
 *    • Longitud total: 17 caracteres
 *    • Espacios encontrados: 0
 * 
 * ✓ No hay espacios para reemplazar.
 * 
 * ============================================================================
 * NOTAS TÉCNICAS:
 * ============================================================================
 * 
 * 1. MODIFICACIÓN IN-PLACE:
 *    "In-place" significa modificar la estructura de datos original
 *    sin crear una copia. Ventajas:
 *    - Ahorra memoria (no duplicamos la cadena)
 *    - Más eficiente (no hay copia)
 *    
 *    Para preservar el original, usamos strcpy() para crear una copia
 * 
 * 2. PASO POR REFERENCIA vs PASO POR VALOR:
 *    
 *    En C++, los arrays SIEMPRE se pasan por referencia:
 *    void funcion(char arr[]) {
 *        arr[0] = 'X';  // Modifica el array original
 *    }
 *    
 *    Para evitar modificaciones, usamos const:
 *    void funcion(const char arr[]) {
 *        arr[0] = 'X';  // ❌ ERROR de compilación
 *    }
 * 
 * 3. STRCPY() - COPIA DE CADENAS:
 *    
 *    strcpy(destino, origen);
 *    
 *    Peligros:
 *    - No verifica el tamaño del destino
 *    - Puede causar buffer overflow si destino es pequeño
 *    
 *    Alternativa segura (C++):
 *    strncpy(destino, origen, tamaño_max);
 *    destino[tamaño_max - 1] = '\0';  // Asegurar terminación
 * 
 * 4. DIFERENCIA ENTRE ' ' Y isspace():
 *    
 *    ' ' (espacio simple):
 *    - Solo detecta el carácter espacio (ASCII 32)
 *    
 *    isspace():
 *    - Detecta: espacio ' ', tab '\t', newline '\n',
 *      carriage return '\r', form feed '\f', vertical tab '\v'
 * 
 * 5. PARÁMETROS POR DEFECTO:
 *    
 *    void funcion(int a, char c = '*') {
 *        // Si no se pasa 'c', usa '*' por defecto
 *    }
 *    
 *    funcion(5);      // Usa '*' por defecto
 *    funcion(5, '#'); // Usa '#'
 * 
 * 6. ALTERNATIVAS DE IMPLEMENTACIÓN:
 *    
 *    Método 1 - Con índice:
 *    for (int i = 0; cadena[i] != '\0'; i++)
 *    
 *    Método 2 - Con punteros:
 *    for (char* p = cadena; *p != '\0'; p++)
 *        if (*p == ' ') *p = '*';
 *    
 *    Método 3 - Con strlen():
 *    int len = strlen(cadena);
 *    for (int i = 0; i < len; i++)
 * 
 * 7. REEMPLAZO CON EXPRESIONES REGULARES (C++11):
 *    
 *    #include <regex>
 *    string texto = "Hola mundo";
 *    string resultado = regex_replace(texto, regex(" "), "*");
 * 
 * 8. CASOS ESPECIALES A CONSIDERAR:
 *    - Múltiples espacios consecutivos: "Hola  mundo"
 *    - Espacios al inicio o final: " Hola "
 *    - Solo espacios: "     "
 *    - Cadena vacía: ""
 *    - Sin espacios: "HolaMundo"
 * 
 * 9. EXTENSIONES POSIBLES:
 *    - Reemplazar solo el primer/último espacio
 *    - Reemplazar solo espacios múltiples
 *    - Eliminar espacios en lugar de reemplazar
 *    - Reemplazar con una cadena en lugar de un carácter
 *    - Contar palabras antes y después
 * 
 * 10. APLICACIONES PRÁCTICAS:
 *     - Formateo de nombres de archivo (espacios → guiones bajos)
 *     - URLs (espacios → %20 o +)
 *     - Procesamiento de texto
 *     - Limpieza de datos
 *     - Generación de identificadores
 * 
 * 11. COMPILACIÓN:
 *     g++ -std=c++11 -Wall -Wextra 03_reemplazar_espacios.cpp -o reemplazar
 *     ./reemplazar
 * ============================================================================
 */
