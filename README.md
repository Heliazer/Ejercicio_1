# Advent of Code 2024 - Soluciones en C++

Este repositorio contiene las soluciones completas para los primeros días del Advent of Code 2024, implementadas en C++ con interfaces de consola atractivas.

## 📁 Archivos del Proyecto

### Día 1: Historian Hysteria
- `solucion.cpp` - Programa principal con ambos ejercicios
- `input.txt` - Datos de entrada (1000 pares de números)
- `ejercicio_1.txt` - Enunciado del problema

**Resultados:**
- Ejercicio 1 (Distancia total): 1,341,714
- Ejercicio 2 (Puntuación de similitud): 27,384,707

### Día 2: Red-Nosed Reports
- `dia2_solucion.cpp` - Análisis de reportes de reactor
- `input_ej2.txt` - Datos de entrada (1000 reportes)
- `ejercicio_2.txt` - Enunciado del problema

**Resultado:**
- Reportes seguros: 549 de 1000 totales (54.9%)

## 🚀 Compilación y Ejecución

### Requisitos
- Compilador C++ (g++ o clang++)
- C++11 o superior

### Compilar
```bash
# Día 1
g++ -o solucion solucion.cpp
./solucion

# Día 2
g++ -o dia2_solucion dia2_solucion.cpp
./dia2_solucion
```

## ✨ Características

- **Interfaz atractiva** con emojis y formato de consola profesional
- **Análisis detallado** paso a paso de los primeros elementos
- **Verificación automática** con ejemplos del problema
- **Código modular** y bien documentado
- **Manejo robusto de errores**

## 📊 Estructura de Archivos

```
├── solucion.cpp          # Día 1 - Programa principal
├── dia2_solucion.cpp     # Día 2 - Análisis de reactor
├── input.txt             # Datos del Día 1
├── input_ej2.txt         # Datos del Día 2
├── ejercicio_1.txt       # Enunciado Día 1
├── ejercicio_2.txt       # Enunciado Día 2
├── solucion_2.cpp        # Archivo base Día 2
├── solucion              # Ejecutable Día 1
├── dia2_solucion         # Ejecutable Día 2
└── README.md             # Este archivo
```

## 🎯 Soluciones Implementadas

### Día 1: Historian Hysteria
1. **Cálculo de Distancia Total**: Empareja el i-ésimo número más pequeño de cada lista y calcula la distancia absoluta total.
2. **Puntuación de Similitud**: Multiplica cada número de la lista izquierda por su frecuencia en la lista derecha.

### Día 2: Red-Nosed Reports
- **Análisis de Seguridad**: Verifica que los reportes cumplan las reglas de seguridad del reactor.
- **Reglas**: Los niveles deben ser todos crecientes O decrecientes, con diferencias entre 1 y 3.

## 🏆 Resultados

- ✅ **Día 1 Ejercicio 1**: 1,341,714
- ✅ **Día 1 Ejercicio 2**: 27,384,707  
- ✅ **Día 2**: 549 reportes seguros de 1000 (54.9%)

¡Navidad salvada! 🎄
