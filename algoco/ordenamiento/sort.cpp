#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>  // Para std::sort
using namespace std;

// Función para leer los datos del archivo .txt
vector<int> leerArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    vector<int> datos;
    int numero;

    if (archivo.is_open()) {
        while (archivo >> numero) {
            datos.push_back(numero);  // Añadir el número al vector
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
    }

    return datos;
}

// Función para medir el tiempo de ejecución de std::sort
void medirTiempoStdSort(const string& nombreArchivo) {
    vector<int> datos = leerArchivo(nombreArchivo);

    // Medir el tiempo de std::sort
    auto start = chrono::high_resolution_clock::now();
    std::sort(datos.begin(), datos.end());  // Usar la función std::sort
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duracion = end - start;
    cout << "std::sort para " << datos.size() << " elementos del archivo " << nombreArchivo << " toma " 
         << duracion.count() << " segundos." << endl;
}

int main() {
    // Lista de archivos de entrada
    vector<string> archivos = {"numAleatorios.txt","numAlternantes.txt", "numAscendentes.txt", "numDescendentes.txt","numerosp.txt","numDuplicados.txt"};

    // Medir el tiempo para cada archivo
    for (const string& archivo : archivos) {
        medirTiempoStdSort(archivo);
    }

    return 0;
}
