#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <map>

using namespace std;

// Función para leer los datos del archivo
pair<vector<int>, vector<int>> leerDatos(const string& nombreArchivo) {
    vector<int> listaIzquierda, listaDerecha;
    ifstream archivo(nombreArchivo);
    string linea;
    
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
        return make_pair(listaIzquierda, listaDerecha);
    }
    
    // Leer la primera línea para determinar el formato
    if (getline(archivo, linea)) {
        // Si la línea contiene "INPUT", es el formato con encabezado
        if (linea.find("INPUT") != string::npos) {
            // Saltar las líneas de separación
            getline(archivo, linea); // ########################
            getline(archivo, linea); // ########################
        } else {
            // Es el formato directo, volver al inicio del archivo
            archivo.clear();
            archivo.seekg(0, ios::beg);
        }
    }
    
    // Leer los pares de números
    int contador = 0;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue; // Saltar líneas vacías
        
        istringstream iss(linea);
        int izquierda, derecha;
        if (iss >> izquierda >> derecha) {
            listaIzquierda.push_back(izquierda);
            listaDerecha.push_back(derecha);
            contador++;
        }
    }
    
    cout << "Archivo leído: " << nombreArchivo << " - " << contador << " pares encontrados" << endl;
    
    return make_pair(listaIzquierda, listaDerecha);
}

// Función para calcular la distancia total entre las dos listas
long long calcularDistanciaTotal(const vector<int>& lista1, const vector<int>& lista2, bool mostrarProceso = false) {
    // Crear copias de las listas para ordenarlas
    vector<int> lista1Ordenada = lista1;
    vector<int> lista2Ordenada = lista2;
    
    // Ordenar ambas listas
    sort(lista1Ordenada.begin(), lista1Ordenada.end());
    sort(lista2Ordenada.begin(), lista2Ordenada.end());
    
    // Mostrar proceso si se solicita
    if (mostrarProceso) {
        cout << "\n=== PROCESO DE LOS PRIMEROS 10 NÚMEROS ===" << endl;
        cout << "Lista izquierda ordenada: ";
        for (int i = 0; i < min(10, (int)lista1Ordenada.size()); i++) {
            cout << lista1Ordenada[i] << " ";
        }
        cout << endl;
        
        cout << "Lista derecha ordenada:   ";
        for (int i = 0; i < min(10, (int)lista2Ordenada.size()); i++) {
            cout << lista2Ordenada[i] << " ";
        }
        cout << endl << endl;
        
        cout << "Emparejamiento y distancias:" << endl;
        cout << "Posición | Izquierda | Derecha | Distancia" << endl;
        cout << "---------|-----------|---------|----------" << endl;
    }
    
    // Calcular la distancia total
    long long distanciaTotal = 0;
    for (size_t i = 0; i < lista1Ordenada.size(); i++) {
        int distancia = abs(lista1Ordenada[i] - lista2Ordenada[i]);
        distanciaTotal += distancia;
        
        // Mostrar proceso para los primeros 10
        if (mostrarProceso && i < 10) {
            cout << "   " << (i+1) << "     |   " << lista1Ordenada[i] 
                 << "   |   " << lista2Ordenada[i] << "   |    " << distancia << endl;
        }
    }
    
    if (mostrarProceso) {
        cout << "---------|-----------|---------|----------" << endl;
        cout << "Total de los primeros 10: " << endl;
        long long subtotal = 0;
        for (int i = 0; i < min(10, (int)lista1Ordenada.size()); i++) {
            subtotal += abs(lista1Ordenada[i] - lista2Ordenada[i]);
        }
        cout << "Subtotal primeros 10: " << subtotal << endl;
        cout << "=========================================" << endl;
    }
    
    return distanciaTotal;
}

// Función para calcular la puntuación de similitud entre las dos listas
long long calcularSimilitud(const vector<int>& listaIzquierda, const vector<int>& listaDerecha, bool mostrarProceso = false) {
    // Crear un mapa de frecuencias para la lista derecha
    map<int, int> frecuencias;
    for (int num : listaDerecha) {
        frecuencias[num]++;
    }
    
    long long puntuacionSimilitud = 0;
    
    if (mostrarProceso) {
        cout << "\n=== CÁLCULO DE PUNTUACIÓN DE SIMILITUD ===" << endl;
        cout << "Proceso para los primeros 10 números:" << endl;
        cout << "Número | Frecuencia | Cálculo | Subtotal" << endl;
        cout << "-------|------------|---------|---------" << endl;
    }
    
    // Calcular la puntuación para cada número en la lista izquierda
    for (size_t i = 0; i < listaIzquierda.size(); i++) {
        int numero = listaIzquierda[i];
        int frecuencia = frecuencias[numero];
        long long contribucion = numero * frecuencia;
        puntuacionSimilitud += contribucion;
        
        // Mostrar proceso para los primeros 10
        if (mostrarProceso && i < 10) {
            cout << "  " << numero << "   |     " << frecuencia << "      | " 
                 << numero << "×" << frecuencia << " = " << contribucion << " |   " << puntuacionSimilitud << endl;
        }
    }
    
    if (mostrarProceso) {
        cout << "-------|------------|---------|---------" << endl;
        cout << "Puntuación total de similitud: " << puntuacionSimilitud << endl;
        cout << "=======================================" << endl;
    }
    
    return puntuacionSimilitud;
}

void mostrarEncabezado() {
    cout << "╔══════════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                    ADVENT OF CODE - DÍA 1: HISTORIAN HYSTERIA                ║" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "║  El Jefe Historiador ha desaparecido y necesitamos reconciliar las listas    ║" << endl;
    cout << "║  de IDs de ubicación históricamente significativas que encontraron.          ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
}

void mostrarSeparador() {
    cout << "────────────────────────────────────────────────────────────────────────────────" << endl;
}

int main() {
    try {
        mostrarEncabezado();
        
        // Leer los datos del archivo input.txt
        pair<vector<int>, vector<int>> datos = leerDatos("input.txt");
        vector<int> listaIzquierda = datos.first;
        vector<int> listaDerecha = datos.second;
        
        cout << "📊 INFORMACIÓN DE LOS DATOS:" << endl;
        cout << "   • Número de elementos en cada lista: " << listaIzquierda.size() << endl;
        cout << "   • Archivo procesado: input.txt" << endl;
        cout << endl;
        
        // Mostrar los primeros 10 números originales
        cout << "🔍 PRIMEROS 10 NÚMEROS ORIGINALES:" << endl;
        cout << "   Lista izquierda: ";
        for (int i = 0; i < min(10, (int)listaIzquierda.size()); i++) {
            cout << listaIzquierda[i] << " ";
        }
        cout << endl;
        
        cout << "   Lista derecha:   ";
        for (int i = 0; i < min(10, (int)listaDerecha.size()); i++) {
            cout << listaDerecha[i] << " ";
        }
        cout << endl << endl;
        
        mostrarSeparador();
        
        // EJERCICIO 1: Calcular distancia total
        cout << "🎯 EJERCICIO 1: CÁLCULO DE DISTANCIA TOTAL" << endl;
        cout << "   Emparejando el i-ésimo número más pequeño de cada lista..." << endl;
        
        long long distanciaTotal = calcularDistanciaTotal(listaIzquierda, listaDerecha, true);
        
        cout << endl;
        cout << "✅ RESULTADO EJERCICIO 1:" << endl;
        cout << "   🎯 Distancia total entre las listas: " << distanciaTotal << endl;
        cout << endl;
        
        mostrarSeparador();
        
        // EJERCICIO 2: Calcular similitud
        cout << "🎯 EJERCICIO 2: CÁLCULO DE PUNTUACIÓN DE SIMILITUD" << endl;
        cout << "   Multiplicando cada número por su frecuencia en la otra lista..." << endl;
        
        long long similitudTotal = calcularSimilitud(listaIzquierda, listaDerecha, true);
        
        cout << endl;
        cout << "✅ RESULTADO EJERCICIO 2:" << endl;
        cout << "   🎯 Puntuación de similitud: " << similitudTotal << endl;
        cout << endl;
        
        mostrarSeparador();
        
        // Verificación con ejemplos
        cout << "🧪 VERIFICACIÓN CON EJEMPLOS:" << endl;
        cout << "   Probando con los ejemplos del problema..." << endl;
        
        vector<int> ejemploIzquierda = {3, 4, 2, 1, 3, 3};
        vector<int> ejemploDerecha = {4, 3, 5, 3, 9, 3};
        
        cout << "   Ejemplo - Lista izquierda: ";
        for (int num : ejemploIzquierda) cout << num << " ";
        cout << endl;
        
        cout << "   Ejemplo - Lista derecha:   ";
        for (int num : ejemploDerecha) cout << num << " ";
        cout << endl << endl;
        
        long long ejemploDistancia = calcularDistanciaTotal(ejemploIzquierda, ejemploDerecha, false);
        long long ejemploSimilitud = calcularSimilitud(ejemploIzquierda, ejemploDerecha, false);
        
        cout << "   ✅ Distancia del ejemplo (debería ser 11): " << ejemploDistancia << endl;
        cout << "   ✅ Similitud del ejemplo (debería ser 31): " << ejemploSimilitud << endl;
        cout << endl;
        
        mostrarSeparador();
        
        // Resumen final
        cout << "🏆 RESUMEN FINAL:" << endl;
        cout << "   ⭐ Ejercicio 1 - Distancia total: " << distanciaTotal << endl;
        cout << "   ⭐ Ejercicio 2 - Puntuación de similitud: " << similitudTotal << endl;
        cout << "   🎉 ¡Ambos ejercicios completados exitosamente!" << endl;
        cout << endl;
        
        cout << "╔══════════════════════════════════════════════════════════════════════════════╗" << endl;
        cout << "║                              ¡NAVIDAD SALVADA! 🎄                            ║" << endl;
        cout << "║                    El Jefe Historiador puede descansar en paz               ║" << endl;
        cout << "╚══════════════════════════════════════════════════════════════════════════════╝" << endl;
        
    } catch (const exception& e) {
        cerr << "❌ Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
