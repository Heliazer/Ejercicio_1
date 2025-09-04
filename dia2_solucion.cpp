#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

void mostrarEncabezado() {
    cout << "╔══════════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                        ADVENT OF CODE - DÍA 2 (2024)                        ║" << endl;
    cout << "║                           RED-NOSED REPORTS                                  ║" << endl;
    cout << "║                                                                              ║" << endl;
    cout << "║  Los ingenieros del reactor necesitan analizar reportes de niveles          ║" << endl;
    cout << "║  para determinar cuáles son seguros según las reglas de seguridad.          ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════════════════════════╝" << endl;
    cout << endl;
}

void mostrarSeparador() {
    cout << "────────────────────────────────────────────────────────────────────────────────" << endl;
}

// Función para leer los reportes del archivo
vector<vector<int>> leerReportes(const string& nombreArchivo) {
    vector<vector<int>> reportes;
    ifstream archivo(nombreArchivo);
    string linea;
    
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
        return reportes;
    }
    
    while (getline(archivo, linea)) {
        vector<int> reporte;
        istringstream streamDeLinea(linea);
        int numero;
        
        while (streamDeLinea >> numero) {
            reporte.push_back(numero);
        }
        
        if (!reporte.empty()) {
            reportes.push_back(reporte);
        }
    }
    
    cout << "📊 Archivo leído: " << nombreArchivo << " - " << reportes.size() << " reportes encontrados" << endl;
    return reportes;
}

// Función para verificar si un reporte es seguro
bool esReporteSeguro(const vector<int>& reporte) {
    if (reporte.size() < 2) return true; // Reportes con menos de 2 niveles son seguros
    
    // Determinar si es creciente o decreciente
    bool esCreciente = false;
    bool esDecreciente = false;
    
    for (size_t i = 1; i < reporte.size(); i++) {
        int diferencia = reporte[i] - reporte[i-1];
        
        if (diferencia > 0) {
            esCreciente = true;
        } else if (diferencia < 0) {
            esDecreciente = true;
        } else {
            // Diferencia de 0, no es ni creciente ni decreciente
            return false;
        }
        
        // Verificar que la diferencia esté entre 1 y 3
        if (abs(diferencia) < 1 || abs(diferencia) > 3) {
            return false;
        }
    }
    
    // Debe ser solo creciente O solo decreciente, no ambos
    return !(esCreciente && esDecreciente);
}

// Función para analizar todos los reportes
pair<int, int> analizarReportes(const vector<vector<int>>& reportes, bool mostrarDetalles = false) {
    int reportesSeguros = 0;
    int reportesInseguros = 0;
    
    if (mostrarDetalles) {
        cout << "\n🔍 ANÁLISIS DETALLADO DE LOS PRIMEROS 10 REPORTES:" << endl;
        cout << "Reporte | Niveles                    | Estado   | Razón" << endl;
        cout << "--------|----------------------------|----------|-------------------" << endl;
    }
    
    for (size_t i = 0; i < reportes.size(); i++) {
        bool seguro = esReporteSeguro(reportes[i]);
        
        if (seguro) {
            reportesSeguros++;
        } else {
            reportesInseguros++;
        }
        
        // Mostrar detalles para los primeros 10 reportes
        if (mostrarDetalles && i < 10) {
            cout << "   " << (i+1) << "    | ";
            
            // Mostrar los niveles (máximo 8 para no hacer la línea muy larga)
            for (size_t j = 0; j < min((size_t)8, reportes[i].size()); j++) {
                cout << reportes[i][j] << " ";
            }
            if (reportes[i].size() > 8) {
                cout << "...";
            }
            
            // Completar con espacios para alinear
            int espacios = 25 - (int)min((size_t)8, reportes[i].size()) * 2;
            for (int k = 0; k < espacios; k++) {
                cout << " ";
            }
            
            cout << "| " << (seguro ? "✅ Seguro" : "❌ Inseguro") << " | ";
            
            // Explicar por qué es seguro o inseguro
            if (seguro) {
                if (reportes[i].size() >= 2) {
                    int primeraDif = reportes[i][1] - reportes[i][0];
                    if (primeraDif > 0) {
                        cout << "Creciente, dif 1-3";
                    } else {
                        cout << "Decreciente, dif 1-3";
                    }
                } else {
                    cout << "Menos de 2 niveles";
                }
            } else {
                cout << "Ver reglas de seguridad";
            }
            
            cout << endl;
        }
    }
    
    if (mostrarDetalles) {
        cout << "--------|----------------------------|----------|-------------------" << endl;
    }
    
    return make_pair(reportesSeguros, reportesInseguros);
}

int main() {
    try {
        mostrarEncabezado();
        
        // Leer los reportes del archivo
        vector<vector<int>> reportes = leerReportes("input_ej2.txt");
        
        cout << "📋 INFORMACIÓN DE LOS DATOS:" << endl;
        cout << "   • Número total de reportes: " << reportes.size() << endl;
        cout << "   • Archivo procesado: input_ej2.txt" << endl;
        cout << endl;
        
        // Mostrar algunos reportes de ejemplo
        cout << "🔍 PRIMEROS 5 REPORTES DE EJEMPLO:" << endl;
        for (int i = 0; i < min(5, (int)reportes.size()); i++) {
            cout << "   Reporte " << (i+1) << ": ";
            for (int nivel : reportes[i]) {
                cout << nivel << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        mostrarSeparador();
        
        // Analizar los reportes
        cout << "🎯 ANÁLISIS DE SEGURIDAD DE REPORTES:" << endl;
        cout << "   Verificando reglas de seguridad..." << endl;
        cout << "   • Los niveles deben ser todos crecientes O todos decrecientes" << endl;
        cout << "   • Cualquier par adyacente debe diferir entre 1 y 3 (inclusive)" << endl;
        cout << endl;
        
        auto [reportesSeguros, reportesInseguros] = analizarReportes(reportes, true);
        
        cout << endl;
        mostrarSeparador();
        
        // Mostrar resultados
        cout << "✅ RESULTADOS:" << endl;
        cout << "   🎯 Reportes seguros: " << reportesSeguros << endl;
        cout << "   ❌ Reportes inseguros: " << reportesInseguros << endl;
        cout << "   📊 Total de reportes: " << (reportesSeguros + reportesInseguros) << endl;
        cout << "   📈 Porcentaje de seguridad: " << fixed << setprecision(1) 
             << (double)reportesSeguros / (reportesSeguros + reportesInseguros) * 100 << "%" << endl;
        cout << endl;
        
        // Verificación con ejemplos del problema
        cout << "🧪 VERIFICACIÓN CON EJEMPLOS DEL PROBLEMA:" << endl;
        vector<vector<int>> ejemplos = {
            {7, 6, 4, 2, 1},    // Debería ser seguro
            {1, 2, 7, 8, 9},    // Debería ser inseguro
            {9, 7, 6, 2, 1},    // Debería ser inseguro
            {1, 3, 2, 4, 5},    // Debería ser inseguro
            {8, 6, 4, 4, 1},    // Debería ser inseguro
            {1, 3, 6, 7, 9}     // Debería ser seguro
        };
        
        vector<bool> resultadosEsperados = {true, false, false, false, false, true};
        
        for (size_t i = 0; i < ejemplos.size(); i++) {
            bool resultado = esReporteSeguro(ejemplos[i]);
            bool esperado = resultadosEsperados[i];
            
            cout << "   Ejemplo " << (i+1) << ": ";
            for (int nivel : ejemplos[i]) {
                cout << nivel << " ";
            }
            cout << "-> " << (resultado ? "✅ Seguro" : "❌ Inseguro");
            cout << " " << (resultado == esperado ? "✓" : "✗") << endl;
        }
        cout << endl;
        
        mostrarSeparador();
        
        cout << "╔══════════════════════════════════════════════════════════════════════════════╗" << endl;
        cout << "║                              ¡REACTOR SEGURO! ⚛️                            ║" << endl;
        cout << "║                    " << reportesSeguros << " reportes seguros de " << (reportesSeguros + reportesInseguros) << " totales                    ║" << endl;
        cout << "║                    Los ingenieros pueden trabajar tranquilos                ║" << endl;
        cout << "╚══════════════════════════════════════════════════════════════════════════════╝" << endl;
        
    } catch (const exception& e) {
        cerr << "❌ Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
