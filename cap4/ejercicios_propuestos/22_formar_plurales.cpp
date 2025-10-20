/* EJERCICIO 22: Formar plurales según reglas del español */
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool esVocal(char v) {
    v = tolower(v);
    return (v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u');
}

bool es_e_acentuada(char a) {
    return (a == 'é');
}

bool es_iu_acentuada(char iu) {
    return (iu == 'í' || iu == 'ú');
}

bool esConsonante(char ec) {
    return isalpha(ec) && !esVocal(ec);
}

void formarPlural(const char sing[], char plur[]) {
    int len = strlen(sing);
    strcpy(plur, sing);
    
    // Excepciones
    if (strcmp(sing, "papa") == 0 || strcmp(sing, "mama") == 0 || 
        strcmp(sing, "sofa") == 0) {
        strcat(plur, "s");
        return;
    }
    
    // Termina en vocal no acentuada o é
    char ultimo = sing[len-1];
    if (esVocal(ultimo) && ultimo != 'í' && ultimo != 'ú' && ultimo != 'á' && ultimo != 'ó') {
        strcat(plur, "s");
    }
    else if (es_e_acentuada(ultimo)) {
        strcat(plur, "s");
    }
    // Termina en consonante o í, ú acentuadas
    else if (esConsonante(ultimo) || es_iu_acentuada(ultimo)) {
        strcat(plur, "es");
    }
    else {
        strcat(plur, "s");
    }
}

void FormaPlural(char sing[], char plu[][50]) {
    char palabra[50];
    int j = 0, count = 0;
    
    for (int i = 0; i <= strlen(sing); i++) {
        if (sing[i] != ' ' && sing[i] != '\0') {
            palabra[j++] = sing[i];
        } else if (j > 0) {
            palabra[j] = '\0';
            formarPlural(palabra, plu[count]);
            cout << palabra << " -> " << plu[count] << endl;
            count++;
            j = 0;
        }
    }
}

int main() {
    char singular[] = "papa gato te colibri cama bar virtud sofa soledad cafe";
    char plurales[20][50];
    
    cout << "=== FORMAR PLURALES ===" << endl;
    FormaPlural(singular, plurales);
    
    return 0;
}
