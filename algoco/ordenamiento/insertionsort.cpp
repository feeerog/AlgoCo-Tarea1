#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

// Función de Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

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

// Función para medir el tiempo de ejecución de Insertion Sort
void medirTiempoInsertionSort(const string& nombreArchivo) {
    vector<int> datos = leerArchivo(nombreArchivo);

    // Convertir el vector en un array
    int n = datos.size();
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = datos[i];
    }

    // Medir el tiempo de Insertion Sort
    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr, n);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duracion = end - start;
    cout << "Insertion Sort para " << n << " elementos del archivo " << nombreArchivo << " toma "
         << duracion.count() << " segundos." << endl;

    // Liberar la memoria dinámica
    delete[] arr;
}

int main() {
    // Lista de archivos de entrada
    vector<string> archivos = {"numAleatorios.txt","numAlternantes.txt", "numAscendentes.txt", "numDescendentes.txt","numerosp.txt","numDuplicados.txt"};

    // Medir el tiempo para cada archivo
    for (const string& archivo : archivos) {
        medirTiempoInsertionSort(archivo);
    }

    return 0;
}
