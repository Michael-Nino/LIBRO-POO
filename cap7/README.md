# Capítulo 7: Clases y Objetos Básicos

## 📚 Descripción

Este capítulo introduce los **fundamentos de la Programación Orientada a Objetos (POO)** en C++, cubriendo conceptos esenciales como clases, objetos, constructores, destructores, encapsulamiento y métodos.

## 🎯 Objetivos de Aprendizaje

Al completar este capítulo, serás capaz de:

- ✅ Comprender la diferencia entre `struct` y `class`
- ✅ Crear clases con datos privados y métodos públicos
- ✅ Implementar constructores (por defecto, parametrizados, de copia)
- ✅ Entender el uso de destructores
- ✅ Aplicar el concepto de **encapsulamiento**
- ✅ Usar **setters y getters** correctamente
- ✅ Organizar código en archivos `.h` y `.cpp` separados
- ✅ Gestionar arrays de objetos

## 📂 Contenido del Capítulo

### 🔹 Conceptos Básicos (01-04)

| Archivo | Tema | Conceptos Clave |
|---------|------|-----------------|
| `01_persona_estructura.cpp` | Struct con métodos | Diferencia struct/class, métodos básicos |
| `02_persona_clase.cpp` | Clase con encapsulamiento | Private/public, operador `::` |
| `03_persona_ambito.cpp` | Ámbito de objetos | Objetos locales vs globales, ciclo de vida |
| `04_circulo_setget.cpp` | Setters y Getters | Validación de datos, encapsulamiento |

### 🔹 Constructores y Destructores (05-07)

| Archivo | Tema | Conceptos Clave |
|---------|------|-----------------|
| `05_circulo_basico.cpp` | Métodos inline | Definición de métodos dentro de la clase |
| `06_circulo_constructores.cpp` | Tipos de constructores | Por defecto, parametrizado, de copia |
| `07_circulo_completo.cpp` | Constructor y destructor | Observar orden de creación/destrucción |

### 🔹 Gestión de Datos (08-10)

| Archivo | Tema | Conceptos Clave |
|---------|------|-----------------|
| `08_alumno_struct.cpp` | Clase con struct interno | Composición, lógica de negocio |
| `09_alumno_gestion.cpp` | Sistema CRUD completo | Array de objetos, búsqueda, eliminación |
| `10_alumno_completo.cpp` | Objeto global y funciones | Arquitectura modular, validaciones |

### 🔹 Proyecto Multi-Archivo (11-13)

| Archivo | Tema | Conceptos Clave |
|---------|------|-----------------|
| `11_time_header.h` | Archivo de cabecera | Guardas de inclusión, declaración |
| `12_time_implementacion.cpp` | Implementación | Definición de métodos, operador `::` |
| `13_time_main.cpp` | Programa principal | Uso del TAD, validación |

**Compilación del proyecto Time:**
```bash
g++ -std=c++11 -Wall 12_time_implementacion.cpp 13_time_main.cpp -o time
./time
```

### 🔹 Ejercicios Propuestos (14-18)

| Archivo | Ejercicio | Descripción |
|---------|-----------|-------------|
| `14_ejercicio_rectangulo.cpp` | Clase Rectángulo | Área, perímetro, constructores |
| `15_ejercicio_triangulo.cpp` | Clase Triángulo | Fórmula de Herón, validación |
| `16_ejercicio_punto3d.cpp` | Punto 3D | Distancia, punto medio |
| `17_ejercicio_creal.cpp` | Número Real | Operaciones, separación componentes |
| `18_ejercicio_calculadora.cpp` | Calculadora | Memoria, operaciones básicas |

## 🚀 Compilación y Ejecución

### Opción 1: Script Automático (Recomendado)
```bash
cd cap7
./compilar_todos.sh
```

Este script:
- ✅ Compila **todos** los programas automáticamente
- ✅ Ejecuta cada programa con datos de ejemplo
- ✅ Muestra resultados con colores
- ✅ Maneja proyectos multi-archivo correctamente

### Opción 2: Compilación Individual
```bash
# Programas de un solo archivo
g++ -std=c++11 -Wall 01_persona_estructura.cpp -o bin/01_persona_estructura
./bin/01_persona_estructura

# Proyecto multi-archivo (Time)
g++ -std=c++11 -Wall 12_time_implementacion.cpp 13_time_main.cpp -o bin/time
./bin/time
```

### Opción 3: VS Code (con tasks.json)
1. Abrir archivo `.cpp`
2. Presionar `Ctrl+Shift+B`
3. Seleccionar tarea de compilación

## 🎓 Conceptos Clave Explicados

### 1️⃣ Struct vs Class
```cpp
// STRUCT: Miembros públicos por defecto
struct Persona {
    char nombre[40];  // Público
    int edad;         // Público
};

// CLASS: Miembros privados por defecto
class Persona {
    char nombre[40];  // Privado
    int edad;         // Privado
public:
    void setDatos();  // Público
};
```

### 2️⃣ Constructores
```cpp
class Circulo {
public:
    Circulo();                    // Por defecto: Circulo c1;
    Circulo(float r);             // Parametrizado: Circulo c2(5.0);
    Circulo(const Circulo& c);    // De copia: Circulo c3 = c2;
private:
    float radio;
};
```

### 3️⃣ Encapsulamiento
```cpp
class Alumno {
private:
    float nota;  // Dato privado (protegido)
    
public:
    // Setter: Valida antes de asignar
    void setNota(float n) {
        if(n >= 0 && n <= 20)
            nota = n;
    }
    
    // Getter: Solo lectura
    float getNota() { return nota; }
};
```

### 4️⃣ Separación de Archivos
```
proyecto/
├── time.h              ← Declaración (interfaz)
├── time.cpp            ← Implementación
└── time_main.cpp       ← Uso (programa principal)
```

**Ventajas:**
- ✅ Reutilización de código
- ✅ Compilación modular
- ✅ Separación interfaz/implementación

## 📖 Puntos Clave del Capítulo

Consulta el archivo **`PUNTOS_CLAVE.txt`** para un resumen rápido de:
- Diferencias struct vs class
- Tipos de constructores
- Encapsulamiento y datos privados
- Operador de ámbito `::`
- Setters y getters
- Objetos locales vs globales

## 🔗 Recursos Adicionales

- **Libro de referencia:** *Algoritmos y Programación Práctica con C++*
- **Estándar usado:** C++11
- **Compilador recomendado:** g++ 7.0 o superior

## 💡 Notas Importantes

> **Eliminación de Comentarios:**  
> Todos los archivos incluyen comentarios educativos detallados. Si prefieres código sin comentarios para practicar, usa tu IA preferida con el comando al inicio de cada archivo:
> ```cpp
> // Use la IA de su preferencia para quitar todos los comentarios
> ```

## 📝 Ejercicios Sugeridos

1. Modifica `08_alumno_struct.cpp` para validar que las notas estén entre 0-20
2. Agrega un método `ordenar()` en `09_alumno_gestion.cpp` para ordenar por promedio
3. Implementa un método `modificar()` para editar datos de alumnos existentes
4. Crea una clase `Libro` similar a `Time` con separación de archivos

## 🤝 Contribuciones

Este material es educativo. Si encuentras errores o mejoras, siéntete libre de contribuir.

---

**📚 Siguiente:** [Capítulo 8 - Sobrecarga de Operadores](../cap8/README.md)

**🏠 Volver al:** [Índice Principal](../README.md)
