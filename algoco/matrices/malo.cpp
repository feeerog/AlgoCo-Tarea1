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

// Función auxiliar para sumar matrices
vector<vector<int>> sumarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Función auxiliar para restar matrices
vector<vector<int>> restarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Multiplicación tradicional de matrices
vector<vector<int>> multiplicacionMatrizTradicional(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Algoritmo de Strassen para multiplicación de matrices
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B, int umbral = 64) {
    int n = A.size();
    if (n <= umbral) {
        return multiplicacionMatrizTradicional(A, B);  // Usar multiplicación tradicional para matrices pequeñas
    }

    vector<vector<int>> C(n, vector<int>(n, 0));

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int nuevoTamaño = n / 2;
    vector<vector<int>> A11(nuevoTamaño, vector<int>(nuevoTamaño)),
                        A12(nuevoTamaño, vector<int>(nuevoTamaño)),
                        A21(nuevoTamaño, vector<int>(nuevoTamaño)),
                        A22(nuevoTamaño, vector<int>(nuevoTamaño)),
                        B11(nuevoTamaño, vector<int>(nuevoTamaño)),
                        B12(nuevoTamaño, vector<int>(nuevoTamaño)),
                        B21(nuevoTamaño, vector<int>(nuevoTamaño)),
                        B22(nuevoTamaño, vector<int>(nuevoTamaño));

    // Dividir las matrices en submatrices
    for (int i = 0; i < nuevoTamaño; i++) {
        for (int j = 0; j < nuevoTamaño; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + nuevoTamaño];
            A21[i][j] = A[i + nuevoTamaño][j];
            A22[i][j] = A[i + nuevoTamaño][j + nuevoTamaño];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + nuevoTamaño];
            B21[i][j] = B[i + nuevoTamaño][j];
            B22[i][j] = B[i + nuevoTamaño][j + nuevoTamaño];
        }
    }

    // Calcular las 7 multiplicaciones de Strassen
    vector<vector<int>> M1 = strassen(sumarMatrices(A11, A22), sumarMatrices(B11, B22), umbral);
    vector<vector<int>> M2 = strassen(sumarMatrices(A21, A22), B11, umbral);
    vector<vector<int>> M3 = strassen(A11, restarMatrices(B12, B22), umbral);
    vector<vector<int>> M4 = strassen(A22, restarMatrices(B21, B11), umbral);
    vector<vector<int>> M5 = strassen(sumarMatrices(A11, A12), B22, umbral);
    vector<vector<int>> M6 = strassen(restarMatrices(A21, A11), sumarMatrices(B11, B12), umbral);
    vector<vector<int>> M7 = strassen(restarMatrices(A12, A22), sumarMatrices(B21, B22), umbral);

    // Combinar los resultados para obtener la matriz C
    vector<vector<int>> C11 = sumarMatrices(restarMatrices(sumarMatrices(M1, M4), M5), M7);
    vector<vector<int>> C12 = sumarMatrices(M3, M5);
    vector<vector<int>> C21 = sumarMatrices(M2, M4);
    vector<vector<int>> C22 = sumarMatrices(restarMatrices(sumarMatrices(M1, M3), M2), M6);

    // Unir las submatrices en la matriz resultado C
    for (int i = 0; i < nuevoTamaño; i++) {
        for (int j = 0; j < nuevoTamaño; j++) {
            C[i][j] = C11[i][j];
            C[i][j + nuevoTamaño] = C12[i][j];
            C[i + nuevoTamaño][j] = C21[i][j];
            C[i + nuevoTamaño][j + nuevoTamaño] = C22[i][j];
        }
    }

    return C;
}

int main() {
    srand(time(0));  // Inicializar el generador de números aleatorios

    int tamaños[] = {100, 200, 500, 1000};  // Diferentes tamaños de matrices para probar
    for (int n : tamaños) {
        cout << "Prueba para el tamano de la matriz: " << n << " x " << n << endl;

        vector<vector<int>> A(n, vector<int>(n));
        vector<vector<int>> B(n, vector<int>(n));

        // Generar matrices aleatorias
        generarMatrizAleatoria(A, n);
        generarMatrizAleatoria(B, n);

        // Medir el tiempo para la multiplicación de matrices con el algoritmo de Strassen
        auto inicio = chrono::high_resolution_clock::now();
        vector<vector<int>> C = strassen(A, B);
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;

        cout << "Tiempo para multiplicacion con algoritmo de Strassen: " << duracion.count() << " segundos" << endl;
    }

    return 0;
}
