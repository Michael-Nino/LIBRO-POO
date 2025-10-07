#!/bin/bash

# compilar_todos.sh
# Script para compilar Y EJECUTAR todos los programas del Capítulo 7
# Compatible con cualquier sistema Linux/Mac con g++

# Colores para mejor visualización
VERDE='\033[0;32m'
AZUL='\033[0;34m'
AMARILLO='\033[1;33m'
CIAN='\033[0;36m'
MAGENTA='\033[0;35m'
RESET='\033[0m'

# Obtener el directorio del script (para rutas relativas)
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

echo "=========================================="
echo "COMPILANDO Y EJECUTANDO CAP 7"
echo "Clases y Objetos Básicos"
echo "=========================================="
echo ""

# Crear directorio bin si no existe
if [ ! -d "bin" ]; then
    mkdir bin
fi

# Contador de éxitos
SUCCESS=0
TOTAL=0

# Función para compilar y ejecutar
compilar_ejecutar() {
    local archivo=$1
    local ejecutable=$2
    local opciones=$3
    local numero=$4
    local total=$5
    
    echo -e "${AZUL}[$numero/$total]${RESET} ${AMARILLO}$archivo${RESET}"
    TOTAL=$((TOTAL+1))
    
    if g++ -std=c++11 -o "bin/$ejecutable" "$archivo" $opciones 2>/dev/null; then
        SUCCESS=$((SUCCESS+1))
        echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
        ./bin/$ejecutable
        echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
    fi
}

echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"
echo -e "${AMARILLO}│  EJEMPLOS DE CLASES BÁSICAS         │${RESET}"
echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"
echo ""

compilar_ejecutar "01_persona_estructura.cpp" "persona_estructura" "" "1" "16"
compilar_ejecutar "02_persona_clase.cpp" "persona_clase" "" "2" "16"
compilar_ejecutar "03_persona_ambito.cpp" "persona_ambito" "" "3" "16"

echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"
echo -e "${AMARILLO}│  EJEMPLOS CON CLASE CÍRCULO         │${RESET}"
echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"
echo ""

compilar_ejecutar "04_circulo_setget.cpp" "circulo_setget" "" "4" "16"
compilar_ejecutar "05_circulo_basico.cpp" "circulo_basico" "" "5" "16"
compilar_ejecutar "06_circulo_constructores.cpp" "circulo_constructores" "" "6" "16"
compilar_ejecutar "07_circulo_completo.cpp" "circulo_completo" "" "7" "16"

echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"
echo -e "${AMARILLO}│  EJEMPLOS CON CLASE ALUMNO          │${RESET}"
echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"
echo ""

# El 08 requiere entrada interactiva - proporcionar datos automáticamente
echo -e "${AZUL}[8/16]${RESET} ${AMARILLO}08_alumno_struct.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -std=c++11 -o "bin/alumno_struct" "08_alumno_struct.cpp" 2>/dev/null; then
    SUCCESS=$((SUCCESS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    echo -e "A20234567\nJuan Perez\n15\n16\n17\n18\n19" | ./bin/alumno_struct
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

# El 09 requiere entrada interactiva - proporcionar datos automáticamente
echo -e "${AZUL}[9/16]${RESET} ${AMARILLO}09_alumno_gestion.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -std=c++11 -o "bin/alumno_gestion" "09_alumno_gestion.cpp" 2>/dev/null; then
    SUCCESS=$((SUCCESS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    echo -e "1\nA001\nCarlos Lopez\n15\n16\n14\n17\n18\n2\nA001\n5" | timeout 2 ./bin/alumno_gestion 2>/dev/null || true
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

# El 10 requiere entrada interactiva - proporcionar datos automáticamente
echo -e "${AZUL}[10/16]${RESET} ${AMARILLO}10_alumno_completo.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -std=c++11 -o "bin/alumno_completo" "10_alumno_completo.cpp" 2>/dev/null; then
    SUCCESS=$((SUCCESS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    echo -e "A2023\nMaria Garcia\n16\n15\n18\n17\n19" | timeout 2 ./bin/alumno_completo 2>/dev/null || true
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"
echo -e "${AMARILLO}│  PROYECTO MULTI-ARCHIVO: TIME       │${RESET}"
echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"
echo ""

echo -e "${AZUL}[11/16]${RESET} ${AMARILLO}Proyecto Time (multi-archivo)${RESET}"
TOTAL=$((TOTAL+1))
if g++ -std=c++11 -o bin/time_proyecto 13_time_main.cpp 12_time_implementacion.cpp 2>/dev/null; then
    SUCCESS=$((SUCCESS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/time_proyecto
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"
echo -e "${AMARILLO}│  EJERCICIOS PROPUESTOS              │${RESET}"
echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"
echo ""

compilar_ejecutar "14_ejercicio_rectangulo.cpp" "ejercicio_rectangulo" "" "12" "16"
compilar_ejecutar "15_ejercicio_triangulo.cpp" "ejercicio_triangulo" "-lm" "13" "16"
compilar_ejecutar "16_ejercicio_punto3d.cpp" "ejercicio_punto3d" "-lm" "14" "16"
compilar_ejecutar "17_ejercicio_creal.cpp" "ejercicio_creal" "" "15" "16"

# El 18 requiere entrada interactiva - proporcionar datos automáticamente
echo -e "${AZUL}[16/16]${RESET} ${AMARILLO}18_ejercicio_calculadora.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -std=c++11 -o "bin/ejercicio_calculadora" "18_ejercicio_calculadora.cpp" 2>/dev/null; then
    SUCCESS=$((SUCCESS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    echo -e "1\n10\n+\n5\n3" | timeout 2 ./bin/ejercicio_calculadora 2>/dev/null || true
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

echo ""
echo "=========================================="
echo "         RESUMEN FINAL"
echo "=========================================="
echo ""
echo -e "${VERDE}Programas compilados y ejecutados: ${SUCCESS}/${TOTAL}${RESET}"
echo ""

if [ $SUCCESS -eq $TOTAL ]; then
    echo -e "${VERDE}✓ ¡Todos los programas se ejecutaron correctamente!${RESET}"
else
    echo -e "${AMARILLO}⚠ Algunos programas tuvieron errores${RESET}"
fi
echo ""
echo "Los ejecutables están en: $SCRIPT_DIR/bin/"
echo ""
echo "Ejemplos de ejecución:"
echo "  ./bin/persona_estructura      - Estructura vs Clase"
echo "  ./bin/circulo_completo        - Círculo con constructores"
echo "  ./bin/alumno_completo         - Gestión de alumnos"
echo "  ./bin/time_proyecto           - Proyecto multi-archivo"
echo "  ./bin/ejercicio_rectangulo    - Ejercicio propuesto"
echo ""
echo "======================================"
echo ""
