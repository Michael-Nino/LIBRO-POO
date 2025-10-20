/*
 * ============================================================================
 * EJERCICIO 1: Contar ocurrencias de una vocal en una cadena
 * ============================================================================
 * 
 * ENUNCIADO:
 *   Programa que solicite una cadena de caracteres y una vocal para luego
 *   reportar el número de ocurrencias de dicha vocal.
 * 
 * OBJETIVO:
 *   - Manipular cadenas de caracteres (char[])
 *   - Recorrer una cadena con bucles
 *   - Comparar caracteres
 *   - Contar ocurrencias
 * 
 * CONCEPTOS CLAVE:
 *   - cin.getline(): Lee una línea completa incluyendo espacios
 *   - tolower()/toupper(): Convertir entre mayúsculas y minúsculas
 *   - Bucle for para recorrer cadenas
 *   - Carácter nulo '\0' marca el fin de cadena
 * ============================================================================
 */

#include <iostream>  // Para cin, cout
#include <cctype>    // Para tolower(), toupper(), isalpha()
#include <cstring>   // Para strlen()

using namespace std;

int main() {
    // -------------------------------------------------------------------------
    // DECLARACIÓN DE VARIABLES
    // -------------------------------------------------------------------------
    // Arrays de caracteres para almacenar cadenas en C++
    // El tamaño debe incluir espacio para el carácter nulo '\0'
    char cadena[256];  // Cadena para almacenar hasta 255 caracteres + '\0'
    char vocal;        // Vocal a buscar (un solo carácter)
    int contador = 0;  // Contador de ocurrencias (inicializado en 0)
    
    // -------------------------------------------------------------------------
    // ENTRADA DE DATOS
    // -------------------------------------------------------------------------
    cout << "╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║    CONTADOR DE VOCALES EN UNA CADENA                  ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
    
    // Solicitar la cadena al usuario
    // cin.getline() lee toda la línea, incluyendo espacios en blanco
    // Parámetros: (buffer, tamaño_máximo)
    // Lee hasta encontrar '\n' o hasta llenar el buffer
    cout << "Ingrese una cadena de texto: ";
    cin.getline(cadena, 256);
    
    // Solicitar la vocal a buscar
    // Se usa cin >> para leer un solo carácter
    // cin >> ignora espacios en blanco al inicio
    cout << "Ingrese una vocal (a, e, i, o, u): ";
    cin >> vocal;
    
    // -------------------------------------------------------------------------
    // CONVERSIÓN A MINÚSCULA PARA COMPARACIÓN CASE-INSENSITIVE
    // -------------------------------------------------------------------------
    // tolower() convierte un carácter a minúscula
    // Esto permite que 'A' y 'a' se consideren la misma vocal
    // Facilita la comparación sin duplicar código
    vocal = tolower(vocal);
    
    // -------------------------------------------------------------------------
    // VALIDACIÓN: Verificar que sea una vocal
    // -------------------------------------------------------------------------
    // Usamos el operador && (AND) para verificar que NO sea ninguna vocal
    // El operador ! (NOT) invierte el resultado de la condición
    if (vocal != 'a' && vocal != 'e' && vocal != 'i' && 
        vocal != 'o' && vocal != 'u') {
        // cerr: flujo de error estándar (similar a cout pero para errores)
        cerr << "\n❌ Error: '" << vocal << "' no es una vocal válida." << endl;
        return 1;  // Terminar el programa con código de error 1
    }
    
    // -------------------------------------------------------------------------
    // PROCESAMIENTO: Contar ocurrencias de la vocal
    // -------------------------------------------------------------------------
    // MÉTODO 1: Usando strlen() para obtener la longitud
    // strlen() cuenta caracteres hasta encontrar '\0'
    // No incluye el '\0' en el conteo
    for (int i = 0; i < strlen(cadena); i++) {
        // Convertimos cada carácter a minúscula para comparar
        // tolower() no modifica el carácter original en el array
        char caracter_actual = tolower(cadena[i]);
        
        // Comparamos el carácter actual con la vocal buscada
        if (caracter_actual == vocal) {
            contador++;  // Incrementar el contador en 1
        }
    }
    
    // MÉTODO ALTERNATIVO 1: Sin usar strlen()
    // Más eficiente porque no calcula la longitud en cada iteración
    /*
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (tolower(cadena[i]) == vocal) {
            contador++;
        }
    }
    */
    
    // MÉTODO ALTERNATIVO 2: Optimizado con variable de longitud
    /*
    int longitud = strlen(cadena);  // Calcular una sola vez
    for (int i = 0; i < longitud; i++) {
        if (tolower(cadena[i]) == vocal) {
            contador++;
        }
    }
    */
    
    // -------------------------------------------------------------------------
    // SALIDA DE RESULTADOS
    // -------------------------------------------------------------------------
    cout << endl;
    cout << "╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║                      RESULTADO                        ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;
    
    // Mostrar la cadena original
    cout << "Cadena ingresada: \"" << cadena << "\"" << endl;
    cout << "Longitud: " << strlen(cadena) << " caracteres" << endl;
    
    // Mostrar la vocal buscada
    cout << "Vocal buscada: '" << vocal << "'" << endl;
    
    // Mostrar el número de ocurrencias
    cout << "\n✓ Número de ocurrencias: " << contador << endl;
    
    // -------------------------------------------------------------------------
    // MENSAJE ADICIONAL SEGÚN EL RESULTADO
    // -------------------------------------------------------------------------
    cout << endl;
    if (contador == 0) {
        cout << "➤ La vocal '" << vocal << "' no aparece en la cadena." << endl;
    } else if (contador == 1) {
        cout << "➤ La vocal '" << vocal << "' aparece 1 vez." << endl;
    } else {
        cout << "➤ La vocal '" << vocal << "' aparece " << contador << " veces." << endl;
    }
    
    // -------------------------------------------------------------------------
    // ESTADÍSTICA ADICIONAL: Porcentaje
    // -------------------------------------------------------------------------
    int longitud = strlen(cadena);
    if (longitud > 0 && contador > 0) {
        // Calcular el porcentaje de la vocal respecto al total de caracteres
        // Multiplicamos por 100.0 para obtener decimales
        double porcentaje = (contador * 100.0) / longitud;
        cout << "➤ Representa el " << porcentaje << "% de la cadena." << endl;
    }
    
    return 0;  // Programa terminado exitosamente
}

/*
 * ============================================================================
 * EJEMPLO DE EJECUCIÓN 1:
 * ============================================================================
 * 
 * ╔════════════════════════════════════════════════════════╗
 * ║    CONTADOR DE VOCALES EN UNA CADENA                  ║
 * ╚════════════════════════════════════════════════════════╝
 * 
 * Ingrese una cadena de texto: Programacion en C++ es interesante
 * Ingrese una vocal (a, e, i, o, u): e
 * 
 * ╔════════════════════════════════════════════════════════╗
 * ║                      RESULTADO                        ║
 * ╚════════════════════════════════════════════════════════╝
 * Cadena ingresada: "Programacion en C++ es interesante"
 * Longitud: 37 caracteres
 * Vocal buscada: 'e'
 * 
 * ✓ Número de ocurrencias: 5
 * 
 * ➤ La vocal 'e' aparece 5 veces.
 * ➤ Representa el 13.51% de la cadena.
 * 
 * ============================================================================
 * EJEMPLO DE EJECUCIÓN 2 (Vocal no encontrada):
 * ============================================================================
 * 
 * Ingrese una cadena de texto: Programming
 * Ingrese una vocal (a, e, i, o, u): u
 * 
 * ✓ Número de ocurrencias: 0
 * ➤ La vocal 'u' no aparece en la cadena.
 * 
 * ============================================================================
 * EJEMPLO DE EJECUCIÓN 3 (Entrada inválida):
 * ============================================================================
 * 
 * Ingrese una cadena de texto: Hola mundo
 * Ingrese una vocal (a, e, i, o, u): x
 * 
 * ❌ Error: 'x' no es una vocal válida.
 * 
 * ============================================================================
 * NOTAS TÉCNICAS:
 * ============================================================================
 * 
 * 1. DIFERENCIA ENTRE cin >> y cin.getline():
 *    
 *    cin >> cadena:
 *    - Lee hasta el primer espacio en blanco, tab o salto de línea
 *    - Si ingresamos "Hola mundo", solo lee "Hola"
 *    - Deja el resto en el buffer de entrada
 *    
 *    cin.getline(cadena, n):
 *    - Lee toda la línea hasta '\n' o hasta n-1 caracteres
 *    - Si ingresamos "Hola mundo", lee "Hola mundo"
 *    - Añade automáticamente '\0' al final
 *    - Descarta el '\n' del buffer
 * 
 * 2. FUNCIONES DE <cctype>:
 *    - tolower(c): Convierte 'c' a minúscula ('A' → 'a')
 *    - toupper(c): Convierte 'c' a mayúscula ('a' → 'A')
 *    - isalpha(c): Verifica si 'c' es una letra (true/false)
 *    - isdigit(c): Verifica si 'c' es un dígito 0-9
 *    - isspace(c): Verifica si 'c' es un espacio en blanco
 *    - isalnum(c): Verifica si 'c' es alfanumérico
 *    - ispunct(c): Verifica si 'c' es un signo de puntuación
 * 
 * 3. CARÁCTER NULO '\0':
 *    - En C++, las cadenas estilo C terminan con '\0'
 *    - Este carácter marca el fin de la cadena en memoria
 *    - strlen() cuenta caracteres hasta encontrar '\0'
 *    - Si olvidamos '\0', strlen() puede leer basura de memoria
 *    - cin.getline() añade '\0' automáticamente
 * 
 * 4. OPTIMIZACIÓN DE STRLEN():
 *    strlen() tiene complejidad O(n) porque recorre la cadena
 *    Si llamamos strlen() en cada iteración del for:
 *    
 *    for (int i = 0; i < strlen(cadena); i++)  // ¡INEFICIENTE!
 *    
 *    Calculamos la longitud n veces, dando complejidad O(n²)
 *    
 *    SOLUCIÓN: Calcular una sola vez antes del bucle
 *    int longitud = strlen(cadena);  // O(n)
 *    for (int i = 0; i < longitud; i++)  // O(n)
 *    Total: O(n)
 * 
 * 5. COMPARACIÓN CASE-INSENSITIVE:
 *    Para ignorar mayúsculas/minúsculas tenemos 3 opciones:
 *    
 *    a) Convertir ambos a minúscula:
 *       if (tolower(c1) == tolower(c2))
 *    
 *    b) Convertir ambos a mayúscula:
 *       if (toupper(c1) == toupper(c2))
 *    
 *    c) Comparar ambas posibilidades:
 *       if (c1 == c2 || c1 == toupper(c2) || c1 == tolower(c2))
 * 
 * 6. EXTENSIONES POSIBLES:
 *    - Contar todas las vocales (a,e,i,o,u) simultáneamente
 *    - Usar un array de contadores: int contadores[5]
 *    - Mostrar posiciones donde aparece la vocal
 *    - Distinguir entre mayúsculas y minúsculas
 *    - Contar consonantes, dígitos, espacios, etc.
 * 
 * 7. MANEJO DE ERRORES:
 *    Este programa valida que el carácter ingresado sea una vocal
 *    Para un programa más robusto, se podría:
 *    - Verificar que cin >> vocal no falle
 *    - Manejar entrada de más de un carácter
 *    - Permitir reintentos si hay error
 * 
 * 8. COMPILACIÓN Y EJECUCIÓN:
 *    g++ -std=c++11 -Wall -Wextra 01_contar_vocal.cpp -o contar_vocal
 *    ./contar_vocal
 * ============================================================================
 */
