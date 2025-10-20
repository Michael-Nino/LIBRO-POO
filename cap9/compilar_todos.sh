#!/bin/bash#!/bin/bash



# compilar_todos.sh# compilar_todos.sh

# Script para compilar Y EJECUTAR todos los programas del Capítulo 9# Script para compilar # El 03 requiere entrada del usuario - proporcompilar_ejecutar "11_Ejercicio_Alumno_UNMSM.cpp" "ejercicio_alumno_unmsm" "" "9" "10"

# Compatible con cualquier sistema Linux/Mac con g++

# El 12 requiere entrada interactiva - proporcionar datos automáticamente

# Colores para mejor visualizaciónecho -e "${AZUL}[10/10]${RESET} ${AMARILLO}12_Ejercicio_Artista_Cantante.cpp${RESET}"

VERDE='\033[0;32m'TOTAL=$((TOTAL+1))

AZUL='\033[0;34m'if g++ -std=c++11 -o "bin/ejercicio_artista_cantante" "12_Ejercicio_Artista_Cantante.cpp" 2>/dev/null; then

AMARILLO='\033[1;33m'    SUCCESS=$((SUCCESS+1))

CIAN='\033[0;36m'    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"

MAGENTA='\033[0;35m'    echo -e "1\nShakira\n2 2 1977\nColombia\nF\nPop\n3\nHips Don't Lie\nWaka Waka\nLa Tortura\n3" | timeout 3 ./bin/ejercicio_artista_cantante 2>/dev/null || true

RESET='\033[0m'    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"

fi

# Obtener el directorio del script (para rutas relativas)

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"# El 13 también requiere entrada - proporcionar datos automáticamente

cd "$SCRIPT_DIR"echo -e "${AZUL}[11/10]${RESET} ${AMARILLO}13_Ejercicio_Nacimiento_Persona.cpp${RESET}"

TOTAL=$((TOTAL+1))

echo "=========================================="if g++ -std=c++11 -o "bin/ejercicio_nacimiento_persona" "13_Ejercicio_Nacimiento_Persona.cpp" 2>/dev/null; then

echo "COMPILANDO Y EJECUTANDO CAP 9"    SUCCESS=$((SUCCESS+1))

echo "Herencia y Polimorfismo"    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"

echo "=========================================="    echo -e "1\nGarcia\nJuan\n15 5 1990\n2" | timeout 3 ./bin/ejercicio_nacimiento_persona 2>/dev/null || true

echo ""    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"

fios automáticamente

# Crear directorio bin si no existeecho -e "${AZUL}[3/10]${RESET} ${AMARILLO}03_Herencia_Angulo_3.cpp${RESET}"

if [ ! -d "bin" ]; thenTOTAL=$((TOTAL+1))

    mkdir binif g++ -std=c++11 -o "bin/herencia_angulo_3" "03_Herencia_Angulo_3.cpp" -lm 2>/dev/null; then

fi    SUCCESS=$((SUCCESS+1))

    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"

# Contador de éxitos    echo -e "2\n45\n60" | timeout 3 ./bin/herencia_angulo_3 2>/dev/null || true

SUCCESS=0    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"

TOTAL=0fiTAR todos los programas del Capítulo 9

# Muestra los resultados de cada programa

# Función para compilar y ejecutar

compilar_ejecutar() {# Colores para mejor visualización

    local archivo=$1VERDE='\033[0;32m'

    local ejecutable=$2AZUL='\033[0;34m'

    local opciones=$3AMARILLO='\033[1;33m'

    local numero=$4CIAN='\033[0;36m'

    local total=$5MAGENTA='\033[0;35m'

    RESET='\033[0m'

    echo -e "${AZUL}[$numero/$total]${RESET} ${AMARILLO}$archivo${RESET}"

    TOTAL=$((TOTAL+1))echo "=========================================="

    echo "COMPILANDO Y EJECUTANDO CAP 9"

    if g++ -std=c++11 -o "bin/$ejecutable" "$archivo" $opciones 2>/dev/null; thenecho "Herencia y Polimorfismo"

        SUCCESS=$((SUCCESS+1))echo "=========================================="

        echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"echo ""

        ./bin/$ejecutable

        echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"# Crear directorio bin si no existe

    fiif [ ! -d "bin" ]; then

}    mkdir bin

fi

echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"

echo -e "${AMARILLO}│  EJEMPLOS DE HERENCIA BÁSICA        │${RESET}"# Contador de éxitos

echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"SUCCESS=0

echo ""TOTAL=0



compilar_ejecutar "01_Herencia_Angulo_1.cpp" "herencia_angulo_1" "-lm" "1" "11"# Función para compilar y ejecutar

compilar_ejecutar "02_Herencia_Angulo_2.cpp" "herencia_angulo_2" "-lm" "2" "11"compilar_ejecutar() {

    local archivo=$1

# El 03 requiere entrada del usuario - proporcionar datos automáticamente    local ejecutable=$2

echo -e "${AZUL}[3/11]${RESET} ${AMARILLO}03_Herencia_Angulo_3.cpp${RESET}"    local opciones=$3

TOTAL=$((TOTAL+1))    local numero=$4

if g++ -std=c++11 -o "bin/herencia_angulo_3" "03_Herencia_Angulo_3.cpp" -lm 2>/dev/null; then    local total=$5

    SUCCESS=$((SUCCESS+1))    

    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"    echo -e "${AZUL}[$numero/$total]${RESET} ${AMARILLO}$archivo${RESET}"

    echo -e "2\n45\n60" | timeout 3 ./bin/herencia_angulo_3 2>/dev/null || true    TOTAL=$((TOTAL+1))

    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"    

fi    if g++ -o "bin/$ejecutable" "$archivo" $opciones 2>/dev/null; then

        SUCCESS=$((SUCCESS+1))

compilar_ejecutar "04_Herencia_Vehiculo.cpp" "herencia_vehiculo" "" "4" "11"        echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"

        ./bin/$ejecutable

echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"        echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"

echo -e "${AMARILLO}│  HERENCIA AVANZADA                  │${RESET}"    fi

echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"}

echo ""

echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"

compilar_ejecutar "05_Herencia_Punto3D.cpp" "herencia_punto3d" "-lm" "5" "11"echo -e "${AMARILLO}│  EJEMPLOS DE HERENCIA BÁSICA        │${RESET}"

compilar_ejecutar "06_Herencia_Empleado.cpp" "herencia_empleado" "" "6" "11"echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"

echo ""

echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"

echo -e "${AMARILLO}│  POLIMORFISMO                       │${RESET}"compilar_ejecutar "01_Herencia_Angulo_1.cpp" "herencia_angulo_1" "-lm" "1" "10"

echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"compilar_ejecutar "02_Herencia_Angulo_2.cpp" "herencia_angulo_2" "-lm" "2" "10"

echo ""

# El 03 requiere entrada del usuario, lo saltamos en auto-ejecución

compilar_ejecutar "07_Polimorfismo_Area.cpp" "polimorfismo_area" "-lm" "7" "11"echo -e "${AZUL}[3/10]${RESET} ${AMARILLO}03_Herencia_Angulo_3.cpp${RESET} ${MAGENTA}(requiere entrada interactiva - omitido)${RESET}"

TOTAL=$((TOTAL+1))

echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"if g++ -o "bin/herencia_angulo_3" "03_Herencia_Angulo_3.cpp" -lm 2>/dev/null; then

echo -e "${AMARILLO}│  PROYECTO PERSONA-ALUMNO            │${RESET}"    SUCCESS=$((SUCCESS+1))

echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"fi

echo ""echo ""



compilar_ejecutar "10_Persona_Alumno_Main.cpp" "persona_alumno" "-lm" "8" "11"compilar_ejecutar "04_Herencia_Vehiculo.cpp" "herencia_vehiculo" "" "4" "10"



echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"

echo -e "${AMARILLO}│  EJERCICIOS PROPUESTOS              │${RESET}"echo -e "${AMARILLO}│  HERENCIA AVANZADA                  │${RESET}"

echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"

echo ""echo ""



compilar_ejecutar "11_Ejercicio_Alumno_UNMSM.cpp" "ejercicio_alumno_unmsm" "" "9" "11"compilar_ejecutar "05_Herencia_Punto3D.cpp" "herencia_punto3d" "-lm" "5" "10"

compilar_ejecutar "06_Herencia_Empleado.cpp" "herencia_empleado" "" "6" "10"

# El 12 requiere entrada interactiva - proporcionar datos automáticamente

echo -e "${AZUL}[10/11]${RESET} ${AMARILLO}12_Ejercicio_Artista_Cantante.cpp${RESET}"echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"

TOTAL=$((TOTAL+1))echo -e "${AMARILLO}│  POLIMORFISMO                       │${RESET}"

if g++ -std=c++11 -o "bin/ejercicio_artista_cantante" "12_Ejercicio_Artista_Cantante.cpp" 2>/dev/null; thenecho -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"

    SUCCESS=$((SUCCESS+1))echo ""

    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"

    echo -e "1\nShakira\n2 2 1977\nColombia\nF\nPop\n3\nHips Don't Lie\nWaka Waka\nLa Tortura\n3" | timeout 3 ./bin/ejercicio_artista_cantante 2>/dev/null || truecompilar_ejecutar "07_Polimorfismo_Area.cpp" "polimorfismo_area" "-lm" "7" "10"

    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"

fiecho -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"

echo -e "${AMARILLO}│  PROYECTO PERSONA-ALUMNO            │${RESET}"

# El 13 también requiere entrada - proporcionar datos automáticamenteecho -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"

echo -e "${AZUL}[11/11]${RESET} ${AMARILLO}13_Ejercicio_Nacimiento_Persona.cpp${RESET}"echo ""

TOTAL=$((TOTAL+1))

if g++ -std=c++11 -o "bin/ejercicio_nacimiento_persona" "13_Ejercicio_Nacimiento_Persona.cpp" 2>/dev/null; thencompilar_ejecutar "10_Persona_Alumno_Main.cpp" "persona_alumno" "-lm" "8" "10"

    SUCCESS=$((SUCCESS+1))

    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}"echo -e "${AMARILLO}┌─────────────────────────────────────┐${RESET}"

    echo -e "1\nGarcia\nJuan\n15 5 1990\n2" | timeout 3 ./bin/ejercicio_nacimiento_persona 2>/dev/null || trueecho -e "${AMARILLO}│  EJERCICIOS PROPUESTOS              │${RESET}"

    echo -e "${CIAN}═══════════════════════════════════════════════════${RESET}\n"echo -e "${AMARILLO}└─────────────────────────────────────┘${RESET}"

fiecho ""



echo ""compilar_ejecutar "11_Ejercicio_Alumno_UNMSM.cpp" "ejercicio_alumno_unmsm" "" "9" "10"

echo "=========================================="compilar_ejecutar "12_Ejercicio_Artista_Cantante.cpp" "ejercicio_artista_cantante" "" "10" "10"

echo "         RESUMEN FINAL"

echo "=========================================="# El 13 también requiere entrada

echo ""echo -e "${AZUL}[11/10]${RESET} ${AMARILLO}13_Ejercicio_Nacimiento_Persona.cpp${RESET} ${MAGENTA}(requiere entrada interactiva - omitido)${RESET}"

echo -e "${VERDE}Programas compilados y ejecutados: ${SUCCESS}/${TOTAL}${RESET}"TOTAL=$((TOTAL+1))

echo ""if g++ -o "bin/ejercicio_nacimiento_persona" "13_Ejercicio_Nacimiento_Persona.cpp" 2>/dev/null; then

    SUCCESS=$((SUCCESS+1))

if [ $SUCCESS -eq $TOTAL ]; thenfi

    echo -e "${VERDE}✓ ¡Todos los programas se ejecutaron correctamente!${RESET}"echo ""

else

    echo -e "${AMARILLO}⚠ Algunos programas tuvieron errores${RESET}"echo "=========================================="

fiecho "         RESUMEN FINAL"

echo ""echo "=========================================="

echo "Los ejecutables están en: $SCRIPT_DIR/bin/"echo ""

echo ""echo -e "${VERDE}Programas compilados y ejecutados: ${SUCCESS}/${TOTAL}${RESET}"

echo "Ejemplos de ejecución manual:"echo ""

echo "  ./bin/herencia_angulo_1             - Herencia básica"

echo "  ./bin/herencia_vehiculo             - Ejemplo vehículo"if [ $SUCCESS -eq $TOTAL ]; then

echo "  ./bin/polimorfismo_area             - Polimorfismo con áreas"    echo -e "${VERDE}✓ ¡Todos los programas se ejecutaron correctamente!${RESET}"

echo "  ./bin/persona_alumno                - Proyecto Persona-Alumno"else

echo "  ./bin/herencia_angulo_3             - Con entrada interactiva"    echo -e "${AMARILLO}⚠ Algunos programas fueron omitidos (requieren entrada interactiva)${RESET}"

echo "  ./bin/ejercicio_artista_cantante    - Con entrada interactiva"fi

echo "  ./bin/ejercicio_nacimiento_persona  - Con entrada interactiva"echo ""

echo ""
echo "======================================"
echo ""
