# Capítulo 8: Sobrecarga de Operadores

## 📚 Descripción

Este capítulo avanza en **Programación Orientada a Objetos** introduciendo la **sobrecarga de operadores**, una característica poderosa de C++ que permite usar operadores estándar (+, -, *, /, ==, <<, etc.) con objetos personalizados.

## 🎯 Objetivos de Aprendizaje

Al completar este capítulo, serás capaz de:

- ✅ Sobrecargar operadores aritméticos (+, -, *, /, %)
- ✅ Sobrecargar operadores relacionales (==, !=, <, >, <=, >=)
- ✅ Sobrecargar operadores unarios (-, !, ++, --)
- ✅ Sobrecargar operadores de flujo (<<, >>)
- ✅ Decidir entre **funciones miembro** vs **funciones friend**
- ✅ Implementar operadores de asignación (=, +=, -=, *=, /=)
- ✅ Gestionar memoria dinámica con operadores
- ✅ Crear **TADs completos** (Tipos Abstractos de Datos)

## 📂 Contenido del Capítulo

### 🔹 Introducción a Sobrecarga (01-05)

| Archivo | Tema | Conceptos Clave |
|---------|------|-----------------|
| `01_Complejo_Operator_1.cpp` | Sobrecarga básica con friend | Funciones friend, paso por valor |
| `02_Complejo_Operator_2.cpp` | Referencias constantes | `const &`, eficiencia, retorno directo |
| `03_Complejo_Operator_3.cpp` | Funciones miembro | Operador como método, `this` implícito |
| `04_Complejo_Operator_4.cpp` | Operadores múltiples | Binarios y unarios, conjugado |
| `05_Complejo_Operator_5.cpp` | Sobrecarga de << | Salida a stream, TAD completo |

**Progresión conceptual:**
```
01 → friend + valor
02 → friend + referencia constante  ✅ MÁS EFICIENTE
03 → función miembro
04 → unarios + binarios
05 → operador << para cout
```

### 🔹 Proyectos TAD Multi-Archivo (06-08)

#### 📦 Proyecto 1: TAD Entero
| Archivo | Descripción |
|---------|-------------|
| `06_entero.h` | Declaración del TAD Entero |
| `06_entero.cpp` | Implementación de operadores |
| `06_entero_main.cpp` | Programa de prueba |

**Operadores implementados:** `+`, `-`, `*`, `/`, `%`, `\|` (valor absoluto), `!` (divisores), `==`, `!=`, `<`, `>`, `<=`, `>=`

**Compilación:**
```bash
g++ -std=c++11 -Wall 06_entero.cpp 06_entero_main.cpp -o entero
./entero
```

#### 📦 Proyecto 2: TAD Racional (Fracciones)
| Archivo | Descripción |
|---------|-------------|
| `07_racional.h` | Declaración del TAD Racional |
| `07_racional.cpp` | Implementación con simplificación automática |
| `07_racional_main.cpp` | Programa de prueba |

**Características especiales:**
- ✅ Simplificación automática (MCD)
- ✅ Operadores: `+`, `-`, `*`, `/`, `==`, `!=`, `<`, `>`, `++`, `--`, `+=`, `-=`, `*=`, `/=`
- ✅ Entrada/salida: `<<`, `>>`
- ✅ Validación con `assert()`

**Compilación:**
```bash
g++ -std=c++11 -Wall 07_racional.cpp 07_racional_main.cpp -o racional
./racional
```

#### 📦 Proyecto 3: TAD Arreglo Dinámico
| Archivo | Descripción |
|---------|-------------|
| `08_arreglo_1.h` | Declaración del TAD Arreglo |
| `08_arreglo_1.cpp` | Implementación con memoria dinámica |
| `08_arreglo_1_main.cpp` | Programa de prueba |

**Características especiales:**
- ✅ Tamaño dinámico (con `new[]`)
- ✅ Regla de los Tres: Constructor de copia, operador=, destructor
- ✅ Operador `[]` con dos versiones (const y no-const)
- ✅ Gestión automática de memoria

**Compilación:**
```bash
g++ -std=c++11 -Wall 08_arreglo_1.cpp 08_arreglo_1_main.cpp -o arreglo
./arreglo
```

### 🔹 Ejercicios Propuestos (09-14)

| Archivo | Ejercicio | Conceptos Practicados |
|---------|-----------|----------------------|
| `09_ejercicio_complejo_miembro.cpp` | Complejo (miembro) | Operadores como funciones miembro |
| `10_ejercicio_complejo_amigas.cpp` | Complejo (friend) | Operadores como funciones friend |
| `11_ejercicio_ascensor.cpp` | Ascensor | `++`, `--`, `==`, `!=` |
| `12_ejercicio_polinomio.cpp` | Polinomio | `+`, `-`, `+=`, `-=`, array de struct |
| `13_ejercicio_matriz.cpp` | Matriz | Operaciones matriciales, validación |
| `14_ejercicio_caja.cpp` | Caja 3D | Operadores con diferentes tipos |

## 🚀 Compilación y Ejecución

### Opción 1: Script Automático (Recomendado)
```bash
cd cap8
./compilar_todos.sh
```

Este script:
- ✅ Compila **todos** los programas (simples y multi-archivo)
- ✅ Ejecuta automáticamente con datos de prueba
- ✅ Muestra resultados con formato de colores
- ✅ Maneja proyectos complejos correctamente

### Opción 2: Compilación Individual

**Programas de un archivo:**
```bash
g++ -std=c++11 -Wall 01_Complejo_Operator_1.cpp -o bin/01_complejo
./bin/01_complejo
```

**Proyectos multi-archivo:**
```bash
# Entero
g++ -std=c++11 -Wall 06_entero.cpp 06_entero_main.cpp -o bin/entero
./bin/entero

# Racional
g++ -std=c++11 -Wall 07_racional.cpp 07_racional_main.cpp -o bin/racional
./bin/racional

# Arreglo
g++ -std=c++11 -Wall 08_arreglo_1.cpp 08_arreglo_1_main.cpp -o bin/arreglo
./bin/arreglo
```

### Opción 3: VS Code (Tasks)
El proyecto incluye tareas pre-configuradas:
- **Compilar Proyecto Entero (multi-archivo)**
- **Compilar Proyecto Racional (multi-archivo)**
- **Compilar Proyecto Arreglo (multi-archivo)**

## 🎓 Conceptos Clave Explicados

### 1️⃣ Funciones Miembro vs Friend

#### Función Miembro
```cpp
class Complejo {
public:
    // Recibe 1 parámetro (el objeto izquierdo es 'this')
    Complejo operator+(const Complejo& otro) {
        return Complejo(real + otro.real, imag + otro.imag);
    }
private:
    float real, imag;
};

// Uso: z = x + y;  → equivale a → z = x.operator+(y);
```

#### Función Friend
```cpp
class Complejo {
public:
    // Recibe 2 parámetros (ambos operandos)
    friend Complejo operator+(const Complejo& a, const Complejo& b) {
        return Complejo(a.real + b.real, a.imag + b.imag);
    }
private:
    float real, imag;
};

// Uso: z = x + y;  → equivale a → z = operator+(x, y);
```

**¿Cuándo usar cada uno?**

| Función Miembro | Función Friend |
|-----------------|----------------|
| Operadores unarios: `++`, `--`, `-` | Operadores simétricos: `+`, `*` |
| Operadores de asignación: `=`, `+=` | Conversiones implícitas del primer operando |
| Operador `[]`, `()`, `->` | Operadores de flujo: `<<`, `>>` |

### 2️⃣ Operadores Unarios

```cpp
class Complejo {
public:
    // Operador UNARIO (sin parámetros)
    Complejo operator-() {
        return Complejo(-real, -imag);  // Negativo
    }
    
    // Operador ! (uso no estándar)
    Complejo operator!() {
        return Complejo(real, -imag);  // Conjugado
    }
private:
    float real, imag;
};

// Uso:
Complejo z(3, 4);
Complejo negativo = -z;      // (-3, -4)
Complejo conjugado = !z;     // (3, -4)
```

### 3️⃣ Operadores de Incremento

```cpp
class Contador {
public:
    // Prefijo: ++x (retorna por referencia)
    Contador& operator++() {
        valor++;
        return *this;
    }
    
    // Posfijo: x++ (retorna copia)
    Contador operator++(int) {
        Contador temp = *this;
        valor++;
        return temp;
    }
private:
    int valor;
};
```

**Diferencia:**
- **Prefijo:** Incrementa y retorna el objeto ya modificado
- **Posfijo:** Guarda copia, incrementa, retorna la copia original

### 4️⃣ Operador de Flujo <<

```cpp
class Complejo {
    friend ostream& operator<<(ostream& os, const Complejo& c) {
        os << c.real;
        if(c.imag >= 0) os << " + ";
        else os << " - ";
        os << abs(c.imag) << "i";
        return os;  // Retorna ostream para encadenamiento
    }
private:
    float real, imag;
};

// Uso:
Complejo z(3, 4);
cout << z << endl;  // Muestra: 3 + 4i
cout << z << " es complejo" << endl;  // Encadenamiento
```

### 5️⃣ Gestión de Memoria Dinámica

**Regla de los Tres:**
```cpp
class Arreglo {
public:
    // 1. Constructor
    Arreglo(int tam) {
        tamano = tam;
        ptr = new int[tamano];  // Memoria dinámica
    }
    
    // 2. Constructor de copia (COPIA PROFUNDA)
    Arreglo(const Arreglo& otro) {
        tamano = otro.tamano;
        ptr = new int[tamano];  // Nueva memoria
        for(int i = 0; i < tamano; i++)
            ptr[i] = otro.ptr[i];  // Copia valores
    }
    
    // 3. Operador de asignación
    Arreglo& operator=(const Arreglo& otro) {
        if(this != &otro) {  // Evitar auto-asignación
            delete[] ptr;  // Libera memoria anterior
            tamano = otro.tamano;
            ptr = new int[tamano];
            for(int i = 0; i < tamano; i++)
                ptr[i] = otro.ptr[i];
        }
        return *this;
    }
    
    // 4. Destructor
    ~Arreglo() {
        delete[] ptr;  // Libera memoria
    }
private:
    int* ptr;
    int tamano;
};
```

## 📖 Puntos Clave del Capítulo

Consulta el archivo **`PUNTOS_CLAVE.txt`** para un resumen rápido de:
- Sintaxis de sobrecarga de operadores
- Diferencias miembro vs friend
- Operadores que no se pueden sobrecargar
- Retorno por referencia vs valor
- Gestión de memoria dinámica
- Operadores de flujo

## 📊 Tabla de Operadores Sobrecargables

| Categoría | Operadores |
|-----------|------------|
| **Aritméticos** | `+` `-` `*` `/` `%` |
| **Relacionales** | `==` `!=` `<` `>` `<=` `>=` |
| **Lógicos** | `&&` `\|\|` `!` |
| **Bit a bit** | `&` `\|` `^` `~` `<<` `>>` |
| **Asignación** | `=` `+=` `-=` `*=` `/=` `%=` `&=` `\|=` `^=` `<<=` `>>=` |
| **Incremento** | `++` `--` |
| **Acceso** | `[]` `->` `*` `&` |
| **Otros** | `()` `,` `new` `delete` |

**No sobrecargables:** `::`, `.`, `.*`, `?:`, `sizeof`, `typeid`

## 🔗 Matemática de Operaciones

### Números Complejos
```
z = a + bi

Suma:     (a+bi) + (c+di) = (a+c) + (b+d)i
Resta:    (a+bi) - (c+di) = (a-c) + (b-d)i
Producto: (a+bi) * (c+di) = (ac-bd) + (ad+bc)i
División: (a+bi) / (c+di) = [(ac+bd)/(c²+d²)] + [(bc-ad)/(c²+d²)]i
Conjugado: z̄ = a - bi
```

### Racionales (Fracciones)
```
Suma:     a/b + c/d = (ad + bc) / (bd)
Resta:    a/b - c/d = (ad - bc) / (bd)
Producto: a/b * c/d = (ac) / (bd)
División: a/b ÷ c/d = (ad) / (bc)
```

### Matrices
```
Suma: A + B (solo si m×n = p×q)
Producto: A(m×n) * B(n×p) = C(m×p)
```

## 💡 Notas Importantes

> **Eliminación de Comentarios:**  
> Todos los archivos incluyen comentarios educativos extensos. Para código sin comentarios:
> ```cpp
> // Use la IA de su preferencia para quitar todos los comentarios
> ```

> **Compilación C++11:**  
> Siempre usa `-std=c++11` para garantizar compatibilidad

## 📝 Ejercicios Sugeridos

1. Implementa el operador `*` para multiplicación de matrices
2. Agrega operador `^` para potencia de un número racional
3. Crea un TAD `Fecha` con operadores para sumar/restar días
4. Implementa un TAD `Conjunto` con operadores de unión e intersección
5. Modifica `Arreglo` para soportar arreglos 2D con `operator[][]`

## 🤝 Contribuciones

Este material es educativo. Si encuentras errores o mejoras, siéntete libre de contribuir.

---

**📚 Anterior:** [Capítulo 7 - Clases y Objetos](../cap7/README.md)

**📚 Siguiente:** [Capítulo 9 - Herencia y Polimorfismo](../cap9/README.md)

**🏠 Volver al:** [Índice Principal](../README.md)
