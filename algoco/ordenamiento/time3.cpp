#include <iostream>
#include <fstream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time(), que se usa en srand()
#include <set>

int main() {
    // Semilla para números aleatorios
    std::srand(std::time(0));

    // Archivo de números aleatorios
    std::ofstream numAleatorios("numAleatorios.txt");
    if (numAleatorios.is_open()) {
        for (int i = 0; i < 10000; ++i) {
            int numero = std::rand() % 10001 + 1;  // Números entre 1 y 10001
            numAleatorios << numero << " ";
        }
        numAleatorios.close();
    } else {
        std::cerr << "No se pudo abrir el archivo numAleatorios.txt\n";
    }

    // Archivo de números ascendentes
    std::ofstream numAscendentes("numAscendentes.txt");
    if (numAscendentes.is_open()) {
        for (int numero = 1; numero <= 10000; ++numero) {
            numAscendentes << numero << " ";
        }
        numAscendentes.close();
    } else {
        std::cerr << "No se pudo abrir el archivo numAscendentes.txt\n";
    }

    // Archivo de números descendentes
    std::ofstream numDescendentes("numDescendentes.txt");
    if (numDescendentes.is_open()) {
        for (int numero = 10000; numero >= 1; --numero) {
            numDescendentes << numero << " ";
        }
        numDescendentes.close();
    } else {
        std::cerr << "No se pudo abrir el archivo numDescendentes.txt\n";
    }

    // Archivo de números ordenados parcialmente
    std::ofstream numerosp("numerosp.txt");
    if (numerosp.is_open()) {
        int numero = 1;
        for (int i = 1; i <= 10000; ++i) {
            if (i % 100 == 0) {  // Cada 100 números, insertar un número aleatorio
                int numero_r = std::rand() % 10001 + 1;
                numerosp << numero_r << " ";
            } else {
                numerosp << numero << " ";
                ++numero;
            }
        }
        numerosp.close();
    } else {
        std::cerr << "No se pudo abrir el archivo numerosp.txt\n";
    }

    // Archivo de números aleatorios con duplicados
    std::ofstream numDuplicados("numDuplicados.txt");
    std::set<int> generatedNumbers;  // Para almacenar números únicos
    if (numDuplicados.is_open()) {
        for (int i = 0; i < 10000; ++i) {
            int numero;
            if (i % 2 == 0) {  // Cada 2 números, duplica uno de los generados
                if (!generatedNumbers.empty()) {
                    numero = *std::next(generatedNumbers.begin(), std::rand() % generatedNumbers.size());
                } else {
                    numero = std::rand() % 10001 + 1;
                    generatedNumbers.insert(numero);
                }
            } else {
                numero = std::rand() % 10001 + 1;
                generatedNumbers.insert(numero);
            }
            numDuplicados << numero << " ";
        }
        numDuplicados.close();
    } else {
        std::cerr << "No se pudo abrir el archivo numDuplicados.txt\n";
    }

    // Archivo de secuencia alternante creciente y decreciente
    std::ofstream numAlternantes("numAlternantes.txt");
    if (numAlternantes.is_open()) {
        for (int i = 1, j = 10000; i <= 5000 && j >= 5000; ++i, --j) {
            numAlternantes << i << " " << j << " ";
        }
        numAlternantes.close();
    } else {
        std::cerr << "No se pudo abrir el archivo numAlternantes.txt\n";
    }

    return 0;
}
