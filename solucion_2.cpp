#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    
    string nombreArchivo = "input.txt";
    ifstream archivo(nombreArchivo);

    string linea;
    
    // El bucle principal para leer el archivo
    while (getline(archivo, linea)) {
        vector<int> reporte; // Vector para guardar los números
        istringstream streamDeLinea(linea);
        int numero;

        // Bucle para extraer los números del string
        while (streamDeLinea >> numero) {
            reporte.push_back(numero);
        }

        // Verificación para asegurarnos de que se leyeron bien
        cout << "Reporte leido con " << reporte.size() << " niveles: ";
        for (int nivel : reporte) {
            cout << nivel << " ";
        }
        cout << endl;
    }

    return 0;
}