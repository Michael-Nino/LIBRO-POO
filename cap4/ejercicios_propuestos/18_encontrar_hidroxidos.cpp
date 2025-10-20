/* EJERCICIO 18: Encontrar hidróxidos (terminan en OH) */
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int encuentraHidroxidos(char formu[], char hidrox[][50]) {
    char palabra[50];
    int j = 0, count = 0;
    
    for (int i = 0; i <= strlen(formu); i++) {
        if (formu[i] != ' ' && formu[i] != '\0') {
            palabra[j++] = formu[i];
        } else if (j > 0) {
            palabra[j] = '\0';
            int len = strlen(palabra);
            if (len >= 2 && palabra[len-2] == 'O' && palabra[len-1] == 'H') {
                strcpy(hidrox[count++], palabra);
            }
            j = 0;
        }
    }
    
    return count;
}

int main() {
    char formu[256];
    char hidrox[20][50];
    
    cout << "Ingrese fórmulas separadas por espacios: ";
    cin.getline(formu, 256);
    
    int n = encuentraHidroxidos(formu, hidrox);
    
    cout << "\nHidróxidos encontrados: " << n << endl;
    for (int i = 0; i < n; i++) {
        cout << hidrox[i] << " ";
    }
    cout << endl;
    
    return 0;
}
