# Capítulo 9: Herencia y Polimorfismo

## 📚 Descripción

Implementación de **13 ejemplos y ejercicios** sobre herencia, polimorfismo y programación orientada a objetos en C++.

## �� Estructura del Directorio

```
cap9/
├── compilar_todos.sh                    # Script de compilación automatizada
├── 01_Herencia_Angulo_1.cpp            # Herencia básica
├── 02_Herencia_Angulo_2.cpp            # Herencia con constructores
├── 03_Herencia_Angulo_3.cpp            # Herencia multinivel
├── 04_Herencia_Vehiculo.cpp            # Ejemplo de vehículos
├── 05_Herencia_Punto3D.cpp             # Punto 2D y Punto 3D
├── 06_Herencia_Empleado.cpp            # Jerarquía de empleados
├── 07_Polimorfismo_Area.cpp            # Polimorfismo con figuras
├── 08_Persona.h                        # Header clase base Persona
├── 09_Alumno.h                         # Header clase derivada Alumno
├── 10_Persona_Alumno_Main.cpp          # Programa principal
├── 11_Ejercicio_Alumno_UNMSM.cpp       # Ejercicio completo
├── 12_Ejercicio_Artista_Cantante.cpp   # Herencia múltiple
├── 13_Ejercicio_Nacimiento_Persona.cpp # Composición de objetos
└── README.md                           # Este archivo
```

## 🎯 Conceptos Cubiertos

### Herencia
- **Herencia simple**: Clase base y derivada
- **Herencia multinivel**: Cadena de herencia
- **Herencia múltiple**: Múltiples clases base
- **Modificadores de acceso**: public, protected, private
- **Constructores en herencia**: Inicialización de clases base
- **Funciones override**: Redefinición de métodos

### Polimorfismo
- **Funciones virtuales**: `virtual`
- **Funciones virtuales puras**: Clases abstractas
- **Polimorfismo en tiempo de ejecución**: Dynamic binding
- **Punteros a clases base**: Apuntando a objetos derivados

### Programación Orientada a Objetos
- **Encapsulamiento**: Ocultamiento de datos
- **Abstracción**: Clases abstractas
- **Composición**: Objetos dentro de objetos
- **Reutilización de código**: Ventajas de la herencia

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
g++ -std=c++11 -Wall 01_Herencia_Angulo_1.cpp -o herencia_angulo
./herencia_angulo
```

### Compilación con headers
```bash
# Para ejercicios con archivos .h
g++ -std=c++11 -Wall 10_Persona_Alumno_Main.cpp -o persona_alumno
./persona_alumno
```

## 📝 Lista de Ejercicios

| # | Archivo | Descripción |
|---|---------|-------------|
| 01 | Herencia_Angulo_1 | Introducción a herencia básica |
| 02 | Herencia_Angulo_2 | Herencia con constructores |
| 03 | Herencia_Angulo_3 | Herencia multinivel |
| 04 | Herencia_Vehiculo | Ejemplo con vehículos |
| 05 | Herencia_Punto3D | Extensión de Punto 2D a 3D |
| 06 | Herencia_Empleado | Jerarquía laboral |
| 07 | Polimorfismo_Area | Cálculo polimórfico de áreas |
| 08-09 | Persona + Alumno | Headers para POO |
| 10 | Persona_Alumno_Main | Uso de clases separadas |
| 11 | Alumno_UNMSM | Ejercicio completo de universidad |
| 12 | Artista_Cantante | Herencia múltiple |
| 13 | Nacimiento_Persona | Composición de clases |

## 🛠️ Requisitos

- **Compilador**: g++ con soporte C++11 o superior
- **Sistema Operativo**: Linux, macOS, Windows (con MinGW/WSL)
- **Bibliotecas**: Estándar de C++ (no se requieren externas)

## 📖 Fuente

**Libro**: "Algoritmos y Programación práctica con C++"  
**Autor**: Edgar Ruiz Lizama  
**Capítulo**: Práctica 9 - Herencia y Polimorfismo

---

*Última actualización: Octubre 2025*
