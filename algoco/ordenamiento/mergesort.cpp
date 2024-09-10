#include <iostream>
#include <fstream>  // Para manejar archivos
#include <vector>   // Para manejar el array dinámico
#include <chrono>   // Para medir el tiempo
using namespace std;

// Función de Merge Sort
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
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

// Función para medir el tiempo de ejecución
void medirTiempoMergeSort(const string& nombreArchivo) {
    vector<int> datos = leerArchivo(nombreArchivo);

    // Convertir el vector en un array
    int n = datos.size();
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = datos[i];
    }

    // Medir el tiempo de Merge Sort
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duracion = end - start;
    cout << "Merge Sort para " << n << " elementos del archivo " << nombreArchivo << " toma " 
         << duracion.count() << " segundos." << endl;

    // Liberar la memoria dinámica
    delete[] arr;
}

int main() {
    // Lista de archivos de entrada
    vector<string> archivos = {"numAleatorios.txt","numAlternantes.txt", "numAscendentes.txt", "numDescendentes.txt","numerosp.txt","numDuplicados.txt"};

    // Medir el tiempo para cada archivo
    for (const string& archivo : archivos) {
        medirTiempoMergeSort(archivo);
    }

    return 0;
}
