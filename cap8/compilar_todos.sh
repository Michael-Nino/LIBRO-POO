#!/bin/bash
# Script para compilar y ejecutar todos los ejemplos del Capítulo 8
# Muestra los resultados de echo -e "${AZUL}[8/14]${RESET} ${AMARILLO}Proyecto Arreglo (multi-archivo)${RESET}"
TOTAL=$((TOTAL+1))
if g++ -std=c++11 -o bin/arreglo 08_arreglo_1.cpp 08_arreglo_1_main.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    # Proporcionar datos de entrada automáticamente: 7 enteros para enteros1 y 10 para enteros2
    echo -e "1 2 3 4 5 6 7 10 20 30 40 50 60 70 80 90 100" | timeout 3 ./bin/arreglo 2>/dev/null || true
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
figrama

# Colores para mejor visualización
VERDE='\033[0;32m'
AZUL='\033[0;34m'
AMARILLO='\033[1;33m'
CIAN='\033[0;36m'
MAGENTA='\033[0;35m'
RESET='\033[0m'

# Contador de archivos compilados
TOTAL=0
EXITOSOS=0

echo "=========================================="
echo "COMPILANDO Y EJECUTANDO CAP 8"
echo "=========================================="
echo ""

# Ejemplos de Complejo
echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"
echo -e "${AMARILLO}│  EJEMPLOS DE NÚMEROS COMPLEJOS      │${RESET}"
echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"
echo ""

echo -e "${AZUL}[1/14]${RESET} ${AMARILLO}01_Complejo_Operator_1.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -o bin/complejo1 01_Complejo_Operator_1.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/complejo1
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

echo -e "${AZUL}[2/14]${RESET} ${AMARILLO}02_Complejo_Operator_2.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -o bin/complejo2 02_Complejo_Operator_2.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/complejo2
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

echo -e "${AZUL}[3/14]${RESET} ${AMARILLO}03_Complejo_Operator_3.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -o bin/complejo3 03_Complejo_Operator_3.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/complejo3
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

echo -e "${AZUL}[4/14]${RESET} ${AMARILLO}04_Complejo_Operator_4.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -o bin/complejo4 04_Complejo_Operator_4.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/complejo4
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

echo -e "${AZUL}[5/14]${RESET} ${AMARILLO}05_Complejo_Operator_5.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -o bin/complejo5 05_Complejo_Operator_5.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/complejo5
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

# Clase Entero
echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"
echo -e "${AMARILLO}│  PROYECTO MULTI-ARCHIVO: ENTERO     │${RESET}"
echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"
echo ""

echo -e "${AZUL}[6/14]${RESET} ${AMARILLO}Proyecto Entero (multi-archivo)${RESET}"
TOTAL=$((TOTAL+1))
if g++ -o bin/entero 06_entero.cpp 06_entero_main.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/entero
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

# Clase Racional
echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"
echo -e "${AMARILLO}│  PROYECTO MULTI-ARCHIVO: RACIONAL   │${RESET}"
echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"
echo ""

echo -e "${AZUL}[7/14]${RESET} ${AMARILLO}Proyecto Racional (multi-archivo)${RESET}"
TOTAL=$((TOTAL+1))
if g++ -o bin/racional 07_racional.cpp 07_racional_main.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/racional
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

# Clase Arreglo
echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"
echo -e "${AMARILLO}│  PROYECTO MULTI-ARCHIVO: ARREGLO    │${RESET}"
echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"
echo ""

echo -e "${AZUL}[8/14]${RESET} ${AMARILLO}Proyecto Arreglo (multi-archivo)${RESET}"
TOTAL=$((TOTAL+1))
if g++ -o bin/arreglo 08_arreglo_1.cpp 08_arreglo_1_main.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/arreglo
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

# Ejercicios Propuestos
echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"
echo -e "${AMARILLO}│  EJERCICIOS PROPUESTOS              │${RESET}"
echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"
echo ""

echo -e "${AZUL}[9/14]${RESET} ${AMARILLO}09_ejercicio_complejo_miembro.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -o bin/ej1_complejo_miembro 09_ejercicio_complejo_miembro.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/ej1_complejo_miembro
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

echo -e "${AZUL}[10/14]${RESET} ${AMARILLO}10_ejercicio_complejo_amigas.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -o bin/ej2_complejo_amigas 10_ejercicio_complejo_amigas.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/ej2_complejo_amigas
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

echo -e "${AZUL}[11/14]${RESET} ${AMARILLO}11_ejercicio_ascensor.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -o bin/ej3_ascensor 11_ejercicio_ascensor.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/ej3_ascensor
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

echo -e "${AZUL}[12/14]${RESET} ${AMARILLO}12_ejercicio_polinomio.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -o bin/ej4_polinomio 12_ejercicio_polinomio.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/ej4_polinomio
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

echo -e "${AZUL}[13/14]${RESET} ${AMARILLO}13_ejercicio_matriz.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -o bin/ej5_matriz 13_ejercicio_matriz.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/ej5_matriz
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

echo -e "${AZUL}[14/14]${RESET} ${AMARILLO}14_ejercicio_caja.cpp${RESET}"
TOTAL=$((TOTAL+1))
if g++ -o bin/ej6_caja 14_ejercicio_caja.cpp 2>/dev/null; then
    EXITOSOS=$((EXITOSOS+1))
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"
    ./bin/ej6_caja
    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"
fi

echo ""
echo "=========================================="
echo "         RESUMEN FINAL"
echo "=========================================="
echo ""
echo -e "${VERDE}Programas compilados y ejecutados: ${EXITOSOS}/${TOTAL}${RESET}"
echo ""

if [ $EXITOSOS -eq $TOTAL ]; then
    echo -e "${VERDE}✓ ¡Todos los programas se ejecutaron correctamente!${RESET}"
else
    echo -e "${AMARILLO}⚠ Algunos programas tuvieron errores${RESET}"
fi
echo ""
echo "  ./bin/ej3_ascensor          - Simulación de ascensor"
echo "  ./bin/ej4_polinomio         - Operaciones con polinomios"
echo "  ./bin/ej5_matriz            - Operaciones con matrices"
echo "  ./bin/ej6_caja              - Sobrecarga para clase Caja"
echo ""
echo "======================================"
echo ""
