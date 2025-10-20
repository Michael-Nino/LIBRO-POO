/* EJERCICIO 19: Hidróxidos con punteros */
#include <iostream>
#include <cstring>
using namespace std;

int encuentraHidroxidos(char *formu, char *hidrox[]) {
    char palabra[50];
    int j = 0, count = 0;
    
    for (int i = 0; i <= strlen(formu); i++) {
        if (formu[i] != ' ' && formu[i] != '\0') {
            palabra[j++] = formu[i];
        } else if (j > 0) {
            palabra[j] = '\0';
            int len = strlen(palabra);
            if (len >= 2 && palabra[len-2] == 'O' && palabra[len-1] == 'H') {
                hidrox[count] = new char[len+1];
                strcpy(hidrox[count], palabra);
                count++;
            }
            j = 0;
        }
    }
    
    return count;
}

int main() {
    char formu[256];
    char *hidrox[20];
    
    cout << "Ingrese fórmulas: ";
    cin.getline(formu, 256);
    
    int n = encuentraHidroxidos(formu, hidrox);
    
    cout << "Hidróxidos: ";
    for (int i = 0; i < n; i++) {
        cout << hidrox[i] << " ";
        delete[] hidrox[i];
    }
    cout << endl;
    
    return 0;
}
