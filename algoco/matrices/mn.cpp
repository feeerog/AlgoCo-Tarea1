#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time() para inicializar el generador de números aleatorios

using namespace std;

// Función para generar una matriz aleatoria
void generarMatrizAleatoria(vector<vector<int>>& matriz, int tamaño) {
    for (int i = 0; i < tamaño; ++i) {
        for (int j = 0; j < tamaño; ++j) {
            matriz[i][j] = rand() % 100;  // Valores aleatorios entre 0 y 99
        }
    }
}

// Multiplicación tradicional de matrices
void multiplicacionMatrizTradicional(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    srand(time(0));  // Inicializar el generador de números aleatorios

    int tamaños[] = {5, 25, 50, 64, 100, 200, 256, 500, 800, 1000};  // Diferentes tamaños de matrices para probar
    for (int n : tamaños) {
        cout << "Prueba para el tamano de la matriz: " << n << " x " << n << endl;

        vector<vector<int>> A(n, vector<int>(n));
        vector<vector<int>> B(n, vector<int>(n));
        vector<vector<int>> C(n, vector<int>(n, 0));

        // Generar matrices aleatorias
        generarMatrizAleatoria(A, n);
        generarMatrizAleatoria(B, n);

        // Medir el tiempo para la multiplicación tradicional de matrices
        auto inicio = chrono::high_resolution_clock::now();
        multiplicacionMatrizTradicional(A, B, C);
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;

        cout << "Tiempo para multiplicacion cubica tradicional: " << duracion.count() << " segundos" << endl;
    }

    return 0;
}
