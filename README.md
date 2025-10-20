# 📚 Libro POO - Ejercicios Resueltos

Repositorio con ejercicios completos del libro **"Algoritmos y Programación práctica con C++"** de Edgar Ruiz Lizama.

## 📂 Estructura del Repositorio

```
libro-poo/
├── cap4/                          # Cadenas, Punteros y Memoria Dinámica (23 ejercicios)
├── cap5/                          # Funciones (24 ejercicios)
├── cap6/                          # Ordenamiento y Búsqueda (2 ejercicios)
├── cap7/                          # Clases y Objetos
├── cap8/                          # Sobrecarga de Operadores
├── cap9/                          # Herencia y Polimorfismo (13 archivos)
└── README.md                      # Este archivo
```

## 📖 Capítulos Disponibles

### ✅ Capítulo 4: Cadenas, Punteros y Asignación Dinámica
- **23 ejercicios completos**
- Manipulación de cadenas (char arrays)
- Uso de punteros y aritmética
- Gestión de memoria dinámica (new/delete)
- [Ver detalles →](cap4/README.md)

### ✅ Capítulo 5: Funciones
- **24 ejercicios completos**
- Funciones básicas y avanzadas
- Paso por valor y referencia
- Sobrecarga y recursividad
- [Ver detalles →](cap5/README.md)

### ✅ Capítulo 6: Ordenamiento y Búsqueda
- **2 ejercicios completos**
- Algoritmos de ordenamiento (Bubble, Selection, Insertion, Quick, Merge)
- Algoritmos de búsqueda (Lineal, Binaria)
- [Ver detalles →](cap6/README.md)

### ✅ Capítulo 7: Clases y Objetos
- Estructuras vs Clases
- Constructores y destructores
- Encapsulamiento (get/set)
- Separación header/implementación
- [Ver detalles →](cap7/README.md)

### ✅ Capítulo 8: Sobrecarga de Operadores
- Operadores aritméticos
- Operadores de comparación
- Operadores de E/S (<<, >>)
- Operadores como funciones miembro y amigas
- [Ver detalles →](cap8/README.md)

### ✅ Capítulo 9: Herencia y Polimorfismo
- **13 archivos (ejemplos y ejercicios)**
- Herencia simple y múltiple
- Polimorfismo y funciones virtuales
- Clases abstractas
- [Ver detalles →](cap9/README.md)

## 🚀 Inicio Rápido

### Clonar el repositorio
```bash
git clone https://github.com/Michael-Nino/LIBRO-POO.git
cd LIBRO-POO
```

### Compilar un capítulo completo
```bash
# Capítulo 4 (23 ejercicios)
cd cap4
./compilar_todos.sh build

# Capítulo 5 (24 ejercicios)
cd cap5
./compilar_todos.sh build

# Capítulo 9 (13 archivos)
cd cap9
./compilar_todos.sh build
```

### Compilar un ejercicio individual
```bash
cd cap4/ejercicios_propuestos
g++ -std=c++11 -Wall 01_contar_vocal.cpp -o contar_vocal
./contar_vocal
```

## 🛠️ Requisitos

- **Compilador**: g++ con soporte C++11 o superior
- **Sistema Operativo**: Linux, macOS, Windows (MinGW/WSL)
- **Make** (opcional): Para algunos capítulos
- **Git**: Para clonar el repositorio

## 📊 Estadísticas del Proyecto

| Capítulo | Ejercicios | Archivos | Líneas de Código |
|----------|-----------|----------|------------------|
| Cap 4    | 23        | 23 .cpp  | ~3,200           |
| Cap 5    | 24        | 24 .cpp  | ~2,800           |
| Cap 6    | 2         | 2 .cpp   | ~800             |
| Cap 7    | 18        | 18 .cpp  | ~2,500           |
| Cap 8    | 14        | 14 .cpp  | ~2,200           |
| Cap 9    | 13        | 13 archivos | ~1,500        |
| **Total**| **94**    | **94**   | **~13,000**      |

## 📚 Temas Cubiertos

### Fundamentos
- ✅ Tipos de datos y variables
- ✅ Control de flujo (if, switch, for, while)
- ✅ Arreglos unidimensionales y multidimensionales
- ✅ Cadenas de caracteres (char arrays)
- ✅ Punteros y referencias

### Programación Estructurada
- ✅ Funciones y procedimientos
- ✅ Paso de parámetros (valor/referencia)
- ✅ Recursividad
- ✅ Sobrecarga de funciones

### Estructuras de Datos
- ✅ Algoritmos de ordenamiento
- ✅ Algoritmos de búsqueda
- ✅ Memoria dinámica

### Programación Orientada a Objetos
- ✅ Clases y objetos
- ✅ Constructores y destructores
- ✅ Encapsulamiento
- ✅ Herencia (simple y múltiple)
- ✅ Polimorfismo
- ✅ Sobrecarga de operadores
- ✅ Clases abstractas

## 📖 Fuente

**Libro**: "Algoritmos y Programación práctica con C++"  
**Autor**: Edgar Ruiz Lizama  
**Editorial**: Macro  
**ISBN**: 978-612-304-xxx-x

## 👤 Autor del Repositorio

**Michael Niño**  
GitHub: [@Michael-Nino](https://github.com/Michael-Nino)

## 📄 Licencia

Este repositorio contiene ejercicios con fines educativos. El contenido del libro está protegido por derechos de autor.

## 🤝 Contribuciones

Las contribuciones son bienvenidas. Por favor:
1. Haz un Fork del proyecto
2. Crea una rama para tu feature (`git checkout -b feature/nueva-caracteristica`)
3. Commit tus cambios (`git commit -m 'Agregar nueva característica'`)
4. Push a la rama (`git push origin feature/nueva-caracteristica`)
5. Abre un Pull Request

## 📧 Contacto

Para preguntas o sugerencias, abre un **Issue** en GitHub.

---

⭐ Si este repositorio te fue útil, considera darle una estrella!

*Última actualización: Octubre 2025*
