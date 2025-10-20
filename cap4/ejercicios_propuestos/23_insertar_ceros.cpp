/* EJERCICIO 23: Insertar "000" cada m caracteres */
#include <iostream>
#include <cstring>
using namespace std;

char* insertaCeros(char *s, char *z, int m) {
    static char resultado[1024];
    int j = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        resultado[j++] = s[i];
        
        // Cada m caracteres (sin contar espacios), insertar z
        if ((i + 1) % m == 0 && s[i+1] != '\0') {
            strcpy(resultado + j, z);
            j += strlen(z);
        }
    }
    resultado[j] = '\0';
    
    return resultado;
}

int main() {
    char s[256] = "Ejemplo de insertar ceros";
    char z[] = "000";
    int m = 4;
    
    cout << "=== INSERTAR CEROS ===" << endl;
    cout << "Cadena original: " << s << endl;
    cout << "Insertar: " << z << endl;
    cout << "Cada: " << m << " caracteres" << endl;
    
    char *resultado = insertaCeros(s, z, m);
    
    cout << "\nResultado: " << resultado << endl;
    
    return 0;
}
