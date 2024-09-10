#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <algorithm>  // para std::max

using namespace std;
using namespace std::chrono;

// Función para imprimir una matriz
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

// Rellenar una matriz con ceros para hacerla cuadrada
vector<vector<int>> makeSquare(const vector<vector<int>>& matrix, int newSize) {
    vector<vector<int>> squareMatrix(newSize, vector<int>(newSize, 0));
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            squareMatrix[i][j] = matrix[i][j];
        }
    }
    return squareMatrix;
}

// Función para sumar matrices
vector<vector<int>> add(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Función para restar matrices
vector<vector<int>> subtract(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Algoritmo de Strassen para multiplicar matrices cuadradas
vector<vector<int>> strassenMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }
    
    int newSize = n / 2;
    vector<vector<int>> a11(newSize, vector<int>(newSize)),
                        a12(newSize, vector<int>(newSize)),
                        a21(newSize, vector<int>(newSize)),
                        a22(newSize, vector<int>(newSize)),
                        b11(newSize, vector<int>(newSize)),
                        b12(newSize, vector<int>(newSize)),
                        b21(newSize, vector<int>(newSize)),
                        b22(newSize, vector<int>(newSize));
    
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + newSize];
            a21[i][j] = A[i + newSize][j];
            a22[i][j] = A[i + newSize][j + newSize];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + newSize];
            b21[i][j] = B[i + newSize][j];
            b22[i][j] = B[i + newSize][j + newSize];
        }
    }
    
    vector<vector<int>> m1 = strassenMultiply(add(a11, a22), add(b11, b22));
    vector<vector<int>> m2 = strassenMultiply(add(a21, a22), b11);
    vector<vector<int>> m3 = strassenMultiply(a11, subtract(b12, b22));
    vector<vector<int>> m4 = strassenMultiply(a22, subtract(b21, b11));
    vector<vector<int>> m5 = strassenMultiply(add(a11, a12), b22);
    vector<vector<int>> m6 = strassenMultiply(subtract(a21, a11), add(b11, b12));
    vector<vector<int>> m7 = strassenMultiply(subtract(a12, a22), add(b21, b22));

    vector<vector<int>> c11 = add(subtract(add(m1, m4), m5), m7);
    vector<vector<int>> c12 = add(m3, m5);
    vector<vector<int>> c21 = add(m2, m4);
    vector<vector<int>> c22 = add(subtract(add(m1, m3), m2), m6);

    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            result[i][j] = c11[i][j];
            result[i][j + newSize] = c12[i][j];
            result[i + newSize][j] = c21[i][j];
            result[i + newSize][j + newSize] = c22[i][j];
        }
    }

    return result;
}

// Función para medir el tiempo de ejecución
void measureStrassen(int rowsA, int colsA, int rowsB, int colsB) {
    vector<vector<int>> A(rowsA, vector<int>(colsA, 1));
    vector<vector<int>> B(rowsB, vector<int>(colsB, 1));

    // Encuentra el tamaño cuadrado mínimo en potencias de 2
    int maxSize = max(max(rowsA, colsA), max(rowsB, colsB));
    int newSize = pow(2, ceil(log2(maxSize)));

    vector<vector<int>> newA = makeSquare(A, newSize);
    vector<vector<int>> newB = makeSquare(B, newSize);

    auto start = high_resolution_clock::now();
    vector<vector<int>> result = strassenMultiply(newA, newB);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Prueba para el tamano de la matriz: " << rowsA << "x" << colsA << " - " << rowsB << "x" << colsB << endl;
    cout << "Tiempo para multiplicacion con algoritmo de Strassen: " << duration.count() / 1e6 << " segundos" << endl;
}

int main() {
    measureStrassen(2, 3, 3, 4);
    measureStrassen(22, 32, 32, 43);
    measureStrassen(50, 64, 64, 70);
    measureStrassen(30, 80, 80, 54);
    measureStrassen(100, 200, 200, 150);
    measureStrassen(230, 335, 335, 200);
    measureStrassen(500, 400, 400, 600);
    measureStrassen(400, 700, 700, 300);
    measureStrassen(600, 800, 800, 700);
    measureStrassen(1000, 500, 500, 100);

    return 0;
}
