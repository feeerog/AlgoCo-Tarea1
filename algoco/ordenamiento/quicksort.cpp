#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

// Función de Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

// Función para medir el tiempo de ejecución de Quick Sort
void medirTiempoQuickSort(const string& nombreArchivo) {
    vector<int> datos = leerArchivo(nombreArchivo);

    // Convertir el vector en un array
    int n = datos.size();
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = datos[i];
    }

    // Medir el tiempo de Quick Sort
    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duracion = end - start;
    cout << "Quick Sort para " << n << " elementos del archivo " << nombreArchivo << " toma "
         << duracion.count() << " segundos." << endl;

    // Liberar la memoria dinámica
    delete[] arr;
}

int main() {
    // Lista de archivos de entrada
    vector<string> archivos = {"numAleatorios.txt","numAlternantes.txt","numerosp.txt","numDuplicados.txt"};

    // Medir el tiempo para cada archivo
    for (const string& archivo : archivos) {
        medirTiempoQuickSort(archivo);
    }

    return 0;
}
