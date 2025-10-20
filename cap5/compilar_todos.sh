#!/bin/bash

# Script para compilar todos los ejercicios del Capítulo 5
# Estructuras y Recursividad

echo "========================================"
echo "  COMPILANDO EJERCICIOS - CAPITULO 5"
echo "========================================"
echo ""

# Crear directorio para los ejecutables si no existe
mkdir -p bin

# Contador de éxitos y fallos
SUCCESS=0
FAILED=0

# Compilar cada ejercicio
for i in {01..24}; do
    FILE="ejercicio_${i}.cpp"
    OUTPUT="bin/ejercicio_${i}"
    
    if [ -f "$FILE" ]; then
        echo "Compilando $FILE..."
        
        # Compilar con g++
        if g++ -o "$OUTPUT" "$FILE" -lm -std=c++11 2>/dev/null; then
            echo "  ✓ $FILE compilado exitosamente"
            SUCCESS=$((SUCCESS + 1))
        else
            echo "  ✗ Error al compilar $FILE"
            FAILED=$((FAILED + 1))
        fi
    else
        echo "  ⚠ Archivo $FILE no encontrado"
        FAILED=$((FAILED + 1))
    fi
    echo ""
done

echo "========================================"
echo "  RESUMEN DE COMPILACION"
echo "========================================"
echo "Exitosos: $SUCCESS"
echo "Fallidos:  $FAILED"
echo ""

if [ $FAILED -eq 0 ]; then
    echo "✓ Todos los ejercicios compilaron correctamente"
    echo ""
    echo "Para ejecutar un ejercicio:"
    echo "  ./bin/ejercicio_XX"
    echo ""
    echo "Ejemplo:"
    echo "  ./bin/ejercicio_01"
else
    echo "⚠ Algunos ejercicios no compilaron correctamente"
fi

echo ""
echo "Los ejecutables estan en el directorio 'bin/'"
