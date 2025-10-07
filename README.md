# 📚 Libro POO Básico - Programación Orientada a Objetos en C++

<div align="center">

![C++](https://img.shields.io/badge/C++-11-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![License](https://img.shields.io/badge/License-Educational-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-success?style=for-the-badge)

**Material educativo completo para aprender Programación Orientada a Objetos con C++**

[📖 Ver Capítulos](#-contenido) • [🚀 Inicio Rápido](#-inicio-rápido) • [💻 Compilación](#-compilación) • [🤝 Contribuir](#-contribuciones)

</div>

---

## 📋 Descripción

Este repositorio contiene material educativo estructurado para aprender **Programación Orientada a Objetos (POO)** usando C++. Incluye ejemplos prácticos, ejercicios resueltos y proyectos completos que cubren desde conceptos básicos hasta técnicas avanzadas.

### ✨ Características

- ✅ **+50 programas** de ejemplo completamente documentados
- ✅ **Comentarios educativos** detallados en cada archivo
- ✅ **Scripts de compilación** automáticos para cada capítulo
- ✅ **Proyectos multi-archivo** con estructura profesional
- ✅ **Ejercicios propuestos** con soluciones completas
- ✅ Compilable con **C++11** estándar
- ✅ Compatible con **Linux**, **Windows** y **macOS**

---

## 📚 Contenido

### [Capítulo 7: Clases y Objetos Básicos](cap7/README.md) 🔰

Fundamentos de POO en C++: clases, objetos, constructores, destructores y encapsulamiento.

**Temas cubiertos:**
- 📦 Diferencia entre `struct` y `class`
- 🔒 Encapsulamiento y modificadores de acceso
- 🏗️ Constructores (por defecto, parametrizado, de copia)
- 💥 Destructores y ciclo de vida de objetos
- 📂 Organización en archivos `.h` y `.cpp`
- 🗃️ Gestión de arrays de objetos

**Proyectos destacados:**
- `Time`: Sistema de hora con múltiples archivos
- `Alumno`: Sistema CRUD completo con búsqueda
- Ejercicios: Rectángulo, Triángulo, Punto3D, Calculadora

**📊 Estadísticas:** 19 archivos | 1500+ líneas de código

[📖 Ver documentación completa →](cap7/README.md)

---

### [Capítulo 8: Sobrecarga de Operadores](cap8/README.md) ⚡

Técnicas avanzadas: sobrecarga de operadores para crear tipos de datos intuitivos.

**Temas cubiertos:**
- ➕ Operadores aritméticos (+, -, *, /, %)
- ⚖️ Operadores relacionales (==, !=, <, >, <=, >=)
- 🔄 Operadores unarios (++, --, -, !)
- 📤 Operadores de flujo (<<, >>)
- 🎯 Decisión: funciones miembro vs friend
- 💾 Gestión de memoria dinámica
- 📦 TADs completos (Tipos Abstractos de Datos)

**Proyectos destacados:**
- `Complejo`: Números complejos (5 versiones evolutivas)
- `Racional`: Fracciones con simplificación automática
- `Arreglo`: Array dinámico con gestión de memoria
- Ejercicios: Matriz, Polinomio, Ascensor, Caja

**📊 Estadísticas:** 20 archivos | 2500+ líneas de código

[📖 Ver documentación completa →](cap8/README.md)

---

## 🚀 Inicio Rápido

### Prerrequisitos

```bash
# Linux/Ubuntu
sudo apt install g++ make

# macOS
xcode-select --install

# Windows (MinGW)
# Descargar desde: https://www.mingw-w64.org/
```

**Versión mínima:** g++ 7.0 o superior (con soporte C++11)

### Clonar el Repositorio

```bash
git clone https://github.com/Michael-Nino/LIBRO-POO.git
cd LIBRO-POO
```

### Estructura del Proyecto

```
LIBRO-POO/
├── README.md                    # Este archivo
├── .gitignore                   # Archivos ignorados por git
│
├── cap7/                        # Capítulo 7: Clases y Objetos
│   ├── README.md               # Documentación del capítulo
│   ├── PUNTOS_CLAVE.txt        # Resumen de conceptos
│   ├── compilar_todos.sh       # Script de compilación automática
│   ├── 01_persona_estructura.cpp
│   ├── 02_persona_clase.cpp
│   ├── ...
│   └── 18_ejercicio_calculadora.cpp
│
└── cap8/                        # Capítulo 8: Sobrecarga de Operadores
    ├── README.md               # Documentación del capítulo
    ├── PUNTOS_CLAVE.txt        # Resumen de conceptos
    ├── compilar_todos.sh       # Script de compilación automática
    ├── 01_Complejo_Operator_1.cpp
    ├── 06_entero.h             # Proyectos multi-archivo
    ├── 06_entero.cpp
    ├── 06_entero_main.cpp
    └── ...
```

---

## 💻 Compilación

### Opción 1: Script Automático (Recomendado) ⚡

Cada capítulo incluye un script que compila y ejecuta **todos** los programas:

```bash
# Capítulo 7
cd cap7
./compilar_todos.sh

# Capítulo 8
cd cap8
./compilar_todos.sh
```

**Características del script:**
- ✅ Compila automáticamente todos los programas
- ✅ Ejecuta con datos de ejemplo
- ✅ Muestra resultados con colores
- ✅ Maneja proyectos multi-archivo
- ✅ Rellena automáticamente programas interactivos

### Opción 2: Compilación Individual

```bash
# Programa de un solo archivo
g++ -std=c++11 -Wall nombre_archivo.cpp -o programa
./programa

# Proyecto multi-archivo (ejemplo: Time en cap7)
g++ -std=c++11 -Wall 12_time_implementacion.cpp 13_time_main.cpp -o time
./time

# Proyecto multi-archivo (ejemplo: Racional en cap8)
g++ -std=c++11 -Wall 07_racional.cpp 07_racional_main.cpp -o racional
./racional
```

### Opción 3: VS Code

Si usas **Visual Studio Code**:

1. Abre la carpeta del proyecto
2. Instala la extensión **C/C++** de Microsoft
3. Presiona `Ctrl+Shift+B` (Linux/Windows) o `Cmd+Shift+B` (macOS)
4. Selecciona la tarea de compilación

---

## 🎓 Filosofía Educativa

### Comentarios Didácticos

Todos los archivos incluyen **comentarios educativos extensos** que explican:

- 💡 **Qué hace** el código
- 🤔 **Por qué** se usa esa técnica
- 📖 **Conceptos teóricos** aplicados
- ⚠️ **Errores comunes** a evitar
- 🎯 **Mejores prácticas**

**Ejemplo:**

```cpp
// Use la IA de su preferencia para quitar todos los comentarios
/*
 * Constructor de copia:
 * - Se invoca al crear un objeto a partir de otro: Circulo c3(c2);
 * - Copia el valor del radio del objeto 'c' al nuevo objeto
 * - 'const' asegura que no modificamos el objeto original
 * - '&' pasa por referencia (más eficiente que copiar todo)
 */
Circulo::Circulo(const Circulo& c) {
    radio = c.radio;  // Copia el radio del objeto 'c'
}
```

### Progresión de Aprendizaje

Los capítulos están diseñados con **progresión incremental**:

1. **Conceptos básicos** → Ejemplos simples
2. **Aplicación práctica** → Proyectos pequeños
3. **Integración** → Proyectos multi-archivo
4. **Ejercicios** → Práctica autónoma

---

## 📖 Recursos Adicionales

### Archivos de Referencia

Cada capítulo incluye:

- **`README.md`**: Documentación completa del capítulo
- **`PUNTOS_CLAVE.txt`**: Resumen rápido de conceptos
- **`compilar_todos.sh`**: Script de compilación automática

### Libros de Referencia

- 📘 **Algoritmos y Programación Práctica con C++** - Ruiz et al.
- 📗 **C++ Como Programar** - Deitel & Deitel (4ta Edición)

### Recursos Online

- [cppreference.com](https://en.cppreference.com/) - Referencia completa de C++
- [learncpp.com](https://www.learncpp.com/) - Tutorial interactivo
- [cplusplus.com](https://cplusplus.com/) - Documentación y tutoriales

---

## 🔧 Herramientas Recomendadas

### IDEs / Editores

- **Visual Studio Code** (recomendado)
  - Extensión: C/C++ (Microsoft)
  - Extensión: C/C++ Themes
  
- **Code::Blocks** (alternativa)
- **CLion** (profesional)
- **Dev-C++** (simple)

### Compiladores

- **g++** (GNU Compiler Collection) - Linux/macOS
- **MinGW-w64** - Windows
- **Clang** - Alternativa moderna

---

## 💡 Cómo Usar Este Material

### Para Estudiantes

1. **Lee primero** el README.md del capítulo
2. **Revisa** PUNTOS_CLAVE.txt para conceptos importantes
3. **Estudia** los ejemplos en orden (01, 02, 03...)
4. **Compila y ejecuta** cada programa
5. **Modifica** el código para experimentar
6. **Resuelve** los ejercicios propuestos

### Para Profesores

- ✅ Material listo para usar en clase
- ✅ Progresión pedagógica estructurada
- ✅ Ejercicios con soluciones
- ✅ Scripts para demostración en vivo
- ✅ Comentarios que sirven como guía de clase

### Para Autodidactas

- ✅ Explicaciones detalladas en cada archivo
- ✅ No requiere libro físico (auto-contenido)
- ✅ Progresión de fácil a avanzado
- ✅ Ejercicios para practicar

---

## 🤝 Contribuciones

¡Las contribuciones son bienvenidas! Si encuentras:

- 🐛 **Errores** en el código
- 📝 **Mejoras** en documentación
- 💡 **Sugerencias** de ejercicios
- 🌍 **Traducciones**

Por favor:

1. Haz un **fork** del repositorio
2. Crea una **rama** para tu feature (`git checkout -b feature/mejora`)
3. **Commit** tus cambios (`git commit -m 'Agrega mejora'`)
4. **Push** a la rama (`git push origin feature/mejora`)
5. Abre un **Pull Request**

---

## 📜 Licencia

Este material es de uso **educativo**. Siéntete libre de:

- ✅ Usar en clases
- ✅ Compartir con estudiantes
- ✅ Modificar para tus necesidades
- ✅ Contribuir mejoras

**Por favor:** Mantén los créditos originales y comparte las mejoras con la comunidad.

---

## 👥 Autores

- **Michael Niño** - *Mantenedor principal* - [@Michael-Nino](https://github.com/Michael-Nino)

### Contribuidores

¡Gracias a todos los que han contribuido a este proyecto! 🙌

---

## 📞 Contacto

- **GitHub:** [@Michael-Nino](https://github.com/Michael-Nino)
- **Repositorio:** [LIBRO-POO](https://github.com/Michael-Nino/LIBRO-POO.git)
- **Issues:** [Reportar problema](https://github.com/Michael-Nino/LIBRO-POO/issues)

---

## 🗺️ Roadmap

### ✅ Completado
- [x] Capítulo 7: Clases y Objetos Básicos
- [x] Capítulo 8: Sobrecarga de Operadores
- [x] Comentarios educativos en todos los archivos
- [x] Scripts de compilación automáticos
- [x] Documentación completa (README)

### 🚧 En Progreso
- [ ] Capítulo 9: Herencia y Polimorfismo
- [ ] Tests unitarios
- [ ] Integración continua (CI/CD)

### 📅 Futuro
- [ ] Capítulo 10: Templates
- [ ] Capítulo 11: STL (Standard Template Library)
- [ ] Ejercicios interactivos online
- [ ] Videos explicativos

---

## ⭐ ¿Te Gusta Este Proyecto?

Si este material te ha sido útil:

- ⭐ Dale una **estrella** al repositorio
- 🔄 **Compártelo** con tus compañeros
- 💬 **Déjanos** tu feedback en Issues
- 🤝 **Contribuye** con mejoras

---

<div align="center">

**📚 Hecho con ❤️ para la comunidad educativa**

[⬆️ Volver arriba](#-libro-poo-básico---programación-orientada-a-objetos-en-c)

</div>
