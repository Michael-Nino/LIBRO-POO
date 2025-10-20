# Capítulo 4: Cadenas, Punteros y Asignación Dinámica

## 📚 Descripción

Implementación completa de **23 ejercicios** sobre manipulación de cadenas de caracteres, uso de punteros y gestión de memoria dinámica en C++.

## 📂 Estructura del Directorio

```
cap4/
├── compilar_todos.sh           # Script de compilación automatizada
├── ejercicios_propuestos/      # 23 ejercicios implementados
│   ├── 01_contar_vocal.cpp
│   ├── 02_vocales_fuertes_debiles.cpp
│   ├── 03_reemplazar_espacios.cpp
│   ├── 04_cadena_repetida.cpp
│   ├── 05_formato_nombre.cpp
│   ├── 06_intercambiar_palabras.cpp
│   ├── 07_contar_palabras.cpp
│   ├── 08_palabras_empiezan_con.cpp
│   ├── 09_ocurrencias_palabra.cpp
│   ├── 10_encriptar_cadena.cpp
│   ├── 11_procesar_palabras.cpp
│   ├── 12_contar_diptongos.cpp
│   ├── 13_consonantes_juntas.cpp
│   ├── 14_palabras_longitud_n.cpp
│   ├── 15_reemplazar_subcadena.cpp
│   ├── 16_extraer_iniciales.cpp
│   ├── 17_palabras_longitud_impar.cpp
│   ├── 18_encontrar_hidroxidos.cpp
│   ├── 19_hidroxidos_punteros.cpp
│   ├── 20_palabra_mas_larga.cpp
│   ├── 21_intercambiar_palabras_largas.cpp
│   ├── 22_formar_plurales.cpp
│   └── 23_insertar_ceros.cpp
└── README.md                   # Este archivo
```

## 🎯 Conceptos Cubiertos

- **Cadenas de caracteres (char arrays)**
  - Declaración e inicialización
  - Funciones de `<cstring>`: strlen, strcpy, strcat, strcmp
  - Entrada/salida con cin.getline()
  
- **Punteros**
  - Aritmética de punteros
  - Paso por referencia
  - Relación puntero-arreglo
  
- **Memoria Dinámica**
  - Asignación con new/new[]
  - Liberación con delete/delete[]
  - Prevención de memory leaks

## 🚀 Uso Rápido

### Compilar todos los ejercicios
```bash
./compilar_todos.sh build
```

### Compilar y ejecutar
```bash
./compilar_todos.sh run
```

### Limpiar ejecutables
```bash
./compilar_todos.sh clean
```

### Compilación individual
```bash
g++ -std=c++11 -Wall ejercicios_propuestos/01_contar_vocal.cpp -o 01_contar_vocal
./01_contar_vocal
```

## 📝 Lista de Ejercicios

| # | Ejercicio | Descripción |
|---|-----------|-------------|
| 01 | Contar vocal | Cuenta ocurrencias de una vocal específica |
| 02 | Vocales fuertes/débiles | Clasifica vocales en fuertes y débiles |
| 03 | Reemplazar espacios | Sustituye espacios por otros caracteres |
| 04 | Cadena repetida | Repite una cadena N veces |
| 05 | Formato nombre | Formato: Apellido, Apellido, Nombre |
| 06 | Intercambiar palabras | Intercambia dos palabras en una frase |
| 07 | Contar palabras | Cuenta palabras en una cadena |
| 08 | Palabras empiezan con | Filtra palabras por letra inicial |
| 09 | Ocurrencias palabra | Cuenta repeticiones de una palabra |
| 10 | Encriptar cadena | Encripta vocales a números |
| 11 | Procesar palabras | Selecciona palabra N de una frase |
| 12 | Contar diptongos | Identifica diptongos en texto |
| 13 | Consonantes juntas | Encuentra 3+ consonantes consecutivas |
| 14 | Palabras longitud N | Filtra palabras por tamaño |
| 15 | Reemplazar subcadena | Buscar y reemplazar en texto |
| 16 | Extraer iniciales | Obtiene iniciales de nombre completo |
| 17 | Palabras longitud impar | Filtra palabras de tamaño impar |
| 18 | Encontrar hidróxidos | Detecta términos químicos OH |
| 19 | Hidróxidos (punteros) | Versión con punteros del anterior |
| 20 | Palabra más larga | Encuentra la palabra de mayor longitud |
| 21 | Intercambiar largas | Intercambia palabras más largas |
| 22 | Formar plurales | Convierte palabras a plural |
| 23 | Insertar ceros | Inserta "000" cada M caracteres |

## 🛠️ Requisitos

- **Compilador**: g++ con soporte C++11 o superior
- **Sistema Operativo**: Linux, macOS, Windows (con MinGW/WSL)
- **Bibliotecas**: Estándar de C++ (no se requieren externas)

## 📖 Fuente

**Libro**: "Algoritmos y Programación práctica con C++"  
**Autor**: Edgar Ruiz Lizama  
**Capítulo**: Práctica 4 - Cadenas, Punteros y Asignación Dinámica

---

*Última actualización: Octubre 2025*
