import pandas as pd
import matplotlib.pyplot as plt

# Nuevos datos de tiempo de ejecución para las matrices de diferentes tamaños
data_matriz = {
    'Algoritmo': ['Normal', 'Traspuesta', 'Strassen'],
    '2': [6e-07, 5e-07, 8.56e-05],
    '4': [1.2e-06, 1.7e-06, 0.0003503],
    '8': [7.8e-06, 8.2e-06, 0.0017015],
    '16': [5.29e-05, 6.1e-05, 0.0113289],
    '32': [0.0004008, 0.0004634, 0.0780327],
    '64': [0.0033073, 0.0033756, 0.490321],
    '128': [0.075869, 0.0779777, 3.49519],
    '256': [0.213368, 0.206396, 24.7724],
    '512': [1.97174, 1.72157, 186.117]
}

# Convertir los datos en un DataFrame
df_matriz = pd.DataFrame(data_matriz)

# Establecer el índice como el nombre del algoritmo
df_matriz.set_index('Algoritmo', inplace=True)

# Transponer el DataFrame para que las columnas sean los algoritmos y las filas los tamaños de las matrices
df_matriz = df_matriz.T

# Graficar los datos
df_matriz.plot(kind='line', marker='o')

# Configurar los títulos y etiquetas
plt.title('Comparación de Algoritmos - Multiplicación de Matrices Cuadradas')
plt.xlabel('Tamaño de la Matriz')
plt.ylabel('Tiempo de Ejecución (segundos)')
plt.grid(True)

# Mostrar la leyenda y el gráfico
plt.legend(title='Algoritmos')
plt.show()
