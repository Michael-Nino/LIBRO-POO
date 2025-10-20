#!/usr/bin/env bash
#
# Script de compilación automática para los 23 ejercicios del Capítulo 4
# Uso: ./compilar_todos.sh [build|run|clean]
#

set -uo pipefail

# Colores para output
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Directorios
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC_DIR="$SCRIPT_DIR/ejercicios_propuestos"
BIN_DIR="$SCRIPT_DIR/bin"
DATA_DIR="$SCRIPT_DIR/data"

# Variables
TOTAL_EJERCICIOS=23
COMPILADOS=0
ERRORES=0

# Funciones auxiliares
msg() {
    echo -e "${GREEN}✓${NC} $*"
}

warn() {
    echo -e "${YELLOW}⚠${NC} $*"
}

error() {
    echo -e "${RED}✗${NC} $*" >&2
}

info() {
    echo -e "${BLUE}ℹ${NC} $*"
}

# Función para limpiar
clean() {
    echo "═══════════════════════════════════════════════════════════"
    echo "Limpiando archivos generados..."
    echo "═══════════════════════════════════════════════════════════"
    
    if [ -d "$BIN_DIR" ]; then
        rm -rf "$BIN_DIR"
        msg "Directorio bin/ eliminado"
    fi
    
    # Limpiar scripts temporales
    rm -f "$SRC_DIR"/*.sh
    
    msg "Limpieza completada"
}

# Función para compilar todos los ejercicios
build() {
    echo "═══════════════════════════════════════════════════════════"
    echo "       COMPILANDO 23 EJERCICIOS DEL CAPÍTULO 4"
    echo "═══════════════════════════════════════════════════════════"
    echo ""
    
    # Crear directorio bin si no existe
    mkdir -p "$BIN_DIR"
    
    # Compilar cada ejercicio
    for i in $(seq -f "%02g" 1 $TOTAL_EJERCICIOS); do
        # Buscar el archivo
        archivo=$(ls "$SRC_DIR"/${i}_*.cpp 2>/dev/null | head -1)
        
        if [ -z "$archivo" ]; then
            error "Ejercicio $i no encontrado"
            ((ERRORES++))
            continue
        fi
        
        nombre=$(basename "$archivo" .cpp)
        ejecutable="$BIN_DIR/$nombre"
        
        echo -n "[$i/$TOTAL_EJERCICIOS] Compilando $nombre... "
        
        # Compilar con g++
        if g++ -std=c++11 -Wall "$archivo" -o "$ejecutable" 2>&1 | grep -q "error:"; then
            echo -e "${RED}✗${NC}"
            ((ERRORES++))
            # Mostrar error detallado
            g++ -std=c++11 -Wall "$archivo" -o "$ejecutable"
        elif [ -f "$ejecutable" ]; then
            echo -e "${GREEN}✓${NC}"
            ((COMPILADOS++))
        else
            echo -e "${RED}✗${NC}"
            ((ERRORES++))
        fi
    done
    
    echo ""
    echo "═══════════════════════════════════════════════════════════"
    echo "RESUMEN DE COMPILACIÓN:"
    echo "  ✓ Exitosos: $COMPILADOS/$TOTAL_EJERCICIOS"
    [ $ERRORES -gt 0 ] && echo "  ✗ Errores: $ERRORES"
    echo "═══════════════════════════════════════════════════════════"
    echo ""
}

# Función para ejecutar todos los ejercicios
run_all() {
    echo "═══════════════════════════════════════════════════════════"
    echo "       EJECUTANDO EJERCICIOS COMPILADOS"
    echo "═══════════════════════════════════════════════════════════"
    echo ""
    
    # Crear directorio data para archivos de entrada
    mkdir -p "$DATA_DIR"
    
    ejecutados=0
    
    for ejecutable in "$BIN_DIR"/*; do
        [ -x "$ejecutable" ] || continue
        
        nombre=$(basename "$ejecutable")
        ((ejecutados++))
        
        echo "───────────────────────────────────────────────────────────"
        echo -e "${BLUE}[$ejecutados] Ejecutando: $nombre${NC}"
        echo "───────────────────────────────────────────────────────────"
        
        # Verificar si existe archivo de entrada
        entrada="$DATA_DIR/${nombre}.in"
        
        if [ -f "$entrada" ]; then
            info "Usando entrada desde: $entrada"
            timeout 5s "$ejecutable" < "$entrada" || warn "Tiempo de espera excedido o error en ejecución"
        else
            # Ejecutar sin entrada (algunos ejercicios son interactivos)
            warn "No hay archivo de entrada. Ejecutando sin entrada..."
            warn "Para pruebas automáticas, crea: $entrada"
            timeout 2s "$ejecutable" <<< "" || true
        fi
        
        echo ""
    done
    
    echo "═══════════════════════════════════════════════════════════"
    echo "  ✓ Se ejecutaron $ejecutados ejercicios"
    echo "═══════════════════════════════════════════════════════════"
    echo ""
    
    if [ $ejecutados -eq 0 ]; then
        warn "No hay ejecutables. Ejecuta primero: ./compilar_todos.sh build"
    fi
}

# Función de ayuda
usage() {
    cat << EOF
Uso: $0 [COMANDO]

COMANDOS:
    build   - Compila todos los 23 ejercicios
    run     - Compila y ejecuta todos los ejercicios
    clean   - Elimina archivos generados (bin/)
    help    - Muestra esta ayuda

EJEMPLOS:
    $0 build        # Solo compilar
    $0 run          # Compilar y ejecutar todo
    $0 clean        # Limpiar

NOTAS:
    - Los ejecutables se guardan en: bin/
    - Para entradas automáticas, crea archivos en: data/NOMBRE.in
    - Requiere g++ con soporte C++11

EOF
}

# Programa principal
main() {
    case "${1:-run}" in
        build)
            build
            ;;
        run)
            build
            [ $COMPILADOS -gt 0 ] && run_all
            ;;
        clean)
            clean
            ;;
        help|--help|-h)
            usage
            ;;
        *)
            error "Comando desconocido: $1"
            usage
            exit 1
            ;;
    esac
}

# Verificar que estamos en el directorio correcto
if [ ! -d "$SRC_DIR" ]; then
    error "No se encuentra el directorio: $SRC_DIR"
    error "Asegúrate de ejecutar este script desde el directorio cap4/"
    exit 1
fi

# Ejecutar programa principal
main "$@"
