/*
 * EJERCICIO 6: Sistema de gestión de biblioteca
 * 
 * Descripción:
 * Programa que recrea una Biblioteca con libros como objeto principal.
 * Implementa funciones para:
 * - Ingreso de material con datos (título, autor, editorial, etc.)
 * - Búsqueda de material por autor o título
 * - Impresión de lista completa o por autor
 * - Cálculo del valor del stock
 * 
 * La estructura Libro contiene:
 * - Código, título, autor, editorial
 * - Año de publicación, número de páginas
 * - Precio, cantidad en stock
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int MAX_LIBROS = 100;

// Estructura para representar un libro
struct Libro {
    char codigo[15];        // Código único del libro
    char titulo[80];        // Título del libro
    char autor[60];         // Nombre del autor
    char editorial[40];     // Editorial
    int yearPublic;         // Año de publicación
    int numPaginas;         // Número de páginas
    float precio;           // Precio unitario
    int stock;              // Cantidad en stock
};

// Prototipos de funciones
void ingresarMaterial(Libro biblioteca[], int &n);
void leerLibro(Libro &libro);
void buscarPorAutor(const Libro biblioteca[], int n);
void buscarPorTitulo(const Libro biblioteca[], int n);
void imprimirLista(const Libro biblioteca[], int n);
void imprimirListaPorAutor(const Libro biblioteca[], int n);
void mostrarLibro(const Libro &libro, int numero);
float calcularValorStock(const Libro biblioteca[], int n);

int main() {
    Libro biblioteca[MAX_LIBROS];
    int numLibros = 0;
    int opcion;
    
    cout << "========================================\n";
    cout << "  SISTEMA DE GESTION DE BIBLIOTECA\n";
    cout << "========================================\n";
    
    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Ingresar material\n";
        cout << "2. Buscar por autor\n";
        cout << "3. Buscar por titulo\n";
        cout << "4. Imprimir lista completa\n";
        cout << "5. Imprimir lista agrupada por autor\n";
        cout << "6. Ver valor total del stock\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        
        switch(opcion) {
            case 1:
                ingresarMaterial(biblioteca, numLibros);
                break;
                
            case 2:
                if(numLibros == 0)
                    cout << "\nNo hay libros registrados.\n";
                else
                    buscarPorAutor(biblioteca, numLibros);
                break;
                
            case 3:
                if(numLibros == 0)
                    cout << "\nNo hay libros registrados.\n";
                else
                    buscarPorTitulo(biblioteca, numLibros);
                break;
                
            case 4:
                if(numLibros == 0)
                    cout << "\nNo hay libros registrados.\n";
                else
                    imprimirLista(biblioteca, numLibros);
                break;
                
            case 5:
                if(numLibros == 0)
                    cout << "\nNo hay libros registrados.\n";
                else
                    imprimirListaPorAutor(biblioteca, numLibros);
                break;
                
            case 6:
                if(numLibros == 0)
                    cout << "\nNo hay libros registrados.\n";
                else {
                    float valorTotal = calcularValorStock(biblioteca, numLibros);
                    cout << fixed << setprecision(2);
                    cout << "\nValor total del stock: S/ " << valorTotal << endl;
                }
                break;
                
            case 0:
                cout << "\nSaliendo del sistema...\n";
                break;
                
            default:
                cout << "\nOpcion invalida!\n";
        }
    } while(opcion != 0);
    
    return 0;
}

// Ingresa nuevos libros a la biblioteca
void ingresarMaterial(Libro biblioteca[], int &n) {
    int cantidad;
    
    cout << "\nCuantos libros desea ingresar? ";
    cin >> cantidad;
    cin.ignore();
    
    if(n + cantidad > MAX_LIBROS) {
        cout << "Advertencia: Se excede el limite.\n";
        cout << "Solo se pueden agregar " << (MAX_LIBROS - n) << " libros.\n";
        cantidad = MAX_LIBROS - n;
    }
    
    for(int i = 0; i < cantidad; i++) {
        cout << "\n--- Libro #" << (n + 1) << " ---\n";
        leerLibro(biblioteca[n]);
        n++;
    }
    
    cout << "\nLibros ingresados exitosamente!\n";
}

// Lee los datos de un libro
void leerLibro(Libro &libro) {
    cout << "Codigo: ";
    cin.getline(libro.codigo, 15);
    
    cout << "Titulo: ";
    cin.getline(libro.titulo, 80);
    
    cout << "Autor: ";
    cin.getline(libro.autor, 60);
    
    cout << "Editorial: ";
    cin.getline(libro.editorial, 40);
    
    cout << "Año de publicacion: ";
    cin >> libro.yearPublic;
    
    cout << "Numero de paginas: ";
    cin >> libro.numPaginas;
    
    cout << "Precio: S/ ";
    cin >> libro.precio;
    
    cout << "Stock disponible: ";
    cin >> libro.stock;
    cin.ignore();
    
    // Validaciones
    while(libro.yearPublic < 1000 || libro.yearPublic > 2100) {
        cout << "Error: Año invalido. Ingrese nuevamente: ";
        cin >> libro.yearPublic;
    }
    
    while(libro.numPaginas <= 0) {
        cout << "Error: Numero de paginas debe ser positivo: ";
        cin >> libro.numPaginas;
    }
    
    while(libro.precio < 0) {
        cout << "Error: El precio no puede ser negativo: ";
        cin >> libro.precio;
    }
    
    while(libro.stock < 0) {
        cout << "Error: El stock no puede ser negativo: ";
        cin >> libro.stock;
    }
    cin.ignore();
}

// Busca libros por autor
void buscarPorAutor(const Libro biblioteca[], int n) {
    char autorBuscado[60];
    int encontrados = 0;
    
    cout << "\nIngrese el nombre del autor: ";
    cin.getline(autorBuscado, 60);
    
    cout << "\n========================================\n";
    cout << "  LIBROS DEL AUTOR: " << autorBuscado << endl;
    cout << "========================================\n";
    
    for(int i = 0; i < n; i++) {
        // Buscar coincidencias (sin importar mayúsculas/minúsculas)
        if(strcasestr(biblioteca[i].autor, autorBuscado) != NULL) {
            mostrarLibro(biblioteca[i], i + 1);
            encontrados++;
        }
    }
    
    if(encontrados == 0) {
        cout << "No se encontraron libros del autor especificado.\n";
    } else {
        cout << "\nTotal encontrados: " << encontrados << endl;
    }
}

// Busca libros por título
void buscarPorTitulo(const Libro biblioteca[], int n) {
    char tituloBuscado[80];
    int encontrados = 0;
    
    cout << "\nIngrese el titulo (o parte del titulo): ";
    cin.getline(tituloBuscado, 80);
    
    cout << "\n========================================\n";
    cout << "  RESULTADOS DE BUSQUEDA\n";
    cout << "========================================\n";
    
    for(int i = 0; i < n; i++) {
        if(strcasestr(biblioteca[i].titulo, tituloBuscado) != NULL) {
            mostrarLibro(biblioteca[i], i + 1);
            encontrados++;
        }
    }
    
    if(encontrados == 0) {
        cout << "No se encontraron libros con ese titulo.\n";
    } else {
        cout << "\nTotal encontrados: " << encontrados << endl;
    }
}

// Imprime la lista completa de libros
void imprimirLista(const Libro biblioteca[], int n) {
    cout << "\n========================================\n";
    cout << "  CATALOGO COMPLETO DE LA BIBLIOTECA\n";
    cout << "========================================\n";
    
    for(int i = 0; i < n; i++) {
        mostrarLibro(biblioteca[i], i + 1);
    }
    
    cout << "\nTotal de libros: " << n << endl;
}

// Imprime la lista agrupada por autor
void imprimirListaPorAutor(const Libro biblioteca[], int n) {
    // Crear lista de autores únicos
    char autores[MAX_LIBROS][60];
    int numAutores = 0;
    
    cout << "\n========================================\n";
    cout << "  CATALOGO POR AUTOR\n";
    cout << "========================================\n";
    
    // Encontrar autores únicos
    for(int i = 0; i < n; i++) {
        bool existe = false;
        for(int j = 0; j < numAutores; j++) {
            if(strcmp(biblioteca[i].autor, autores[j]) == 0) {
                existe = true;
                break;
            }
        }
        if(!existe) {
            strcpy(autores[numAutores], biblioteca[i].autor);
            numAutores++;
        }
    }
    
    // Mostrar libros agrupados por autor
    for(int i = 0; i < numAutores; i++) {
        cout << "\n--- AUTOR: " << autores[i] << " ---\n";
        int contador = 0;
        
        for(int j = 0; j < n; j++) {
            if(strcmp(biblioteca[j].autor, autores[i]) == 0) {
                cout << "  " << (contador + 1) << ". " << biblioteca[j].titulo;
                cout << " (" << biblioteca[j].yearPublic << ")\n";
                contador++;
            }
        }
    }
}

// Muestra los datos de un libro
void mostrarLibro(const Libro &libro, int numero) {
    cout << "\n--- Libro #" << numero << " ---\n";
    cout << "Codigo:      " << libro.codigo << endl;
    cout << "Titulo:      " << libro.titulo << endl;
    cout << "Autor:       " << libro.autor << endl;
    cout << "Editorial:   " << libro.editorial << endl;
    cout << "Año:         " << libro.yearPublic << endl;
    cout << "Paginas:     " << libro.numPaginas << endl;
    cout << fixed << setprecision(2);
    cout << "Precio:      S/ " << libro.precio << endl;
    cout << "Stock:       " << libro.stock << " unidades" << endl;
    cout << "Valor stock: S/ " << (libro.precio * libro.stock) << endl;
}

// Calcula el valor total del stock
float calcularValorStock(const Libro biblioteca[], int n) {
    float total = 0;
    
    for(int i = 0; i < n; i++) {
        total += biblioteca[i].precio * biblioteca[i].stock;
    }
    
    return total;
}
