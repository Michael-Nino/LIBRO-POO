/* EJERCICIO 16: Extraer iniciales de palabras */
#include <iostream>
#include <cctype>
using namespace std;

void iniciales(char* p, char* q) {
    int j = 0;
    bool nuevaPalabra = true;
    
    for (int i = 0; p[i] != '\0'; i++) {
        if (!isspace(p[i])) {
            if (nuevaPalabra) {
                q[j++] = tolower(p[i]);
                nuevaPalabra = false;
            }
        } else {
            nuevaPalabra = true;
        }
    }
    q[j] = '\0';
}

int main() {
    char p[256], q[100];
    cout << "Ingrese cadena: ";
    cin.getline(p, 256);
    iniciales(p, q);
    cout << "Iniciales: " << q << endl;
    return 0;
}
