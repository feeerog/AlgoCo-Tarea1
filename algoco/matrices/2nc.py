import pandas as pd
import matplotlib.pyplot as plt

# Datos de tiempo de ejecución para matrices no cuadradas - Normal y Traspuesta
data_matriz_no_cuadradas = {
    'Algoritmo': ['Normal', 'Traspuesta'],
    '2x3-3x4': [4e-07, 4e-07],
    '22x32-32x43': [0.0002182, 0.0002164],
    '50x64-64x70': [0.0015782, 0.0015646],
    '30x80-80x54': [0.0009266, 0.0009017],
    '100x200-200x150': [0.021805, 0.0204862],
    '230x335-335x200': [0.108592, 0.110055],
    '500x400-400x600': [0.960809, 0.829871],
    '400x700-700x300': [0.642818, 0.60213],
    '600x800-800x700': [2.69279, 2.34148],
    '1000x500-500x1000': [4.27117, 3.64584]
}

# Convertir los datos en un DataFrame
df_matriz_no_cuadradas = pd.DataFrame(data_matriz_no_cuadradas)

# Establecer el índice como el nombre del algoritmo
df_matriz_no_cuadradas.set_index('Algoritmo', inplace=True)

# Transponer el DataFrame para que las columnas sean los algoritmos y las filas los tamaños de las matrices
df_matriz_no_cuadradas = df_matriz_no_cuadradas.T

# Graficar los datos
df_matriz_no_cuadradas.plot(kind='line', marker='o')

# Configurar los títulos y etiquetas
plt.title('Comparación de Algoritmos - Multiplicación de Matrices No Cuadradas')
plt.xlabel('Tamaño de las Matrices A y B')
plt.ylabel('Tiempo de Ejecución (segundos)')
plt.xticks(rotation=45, ha='right')  # Rotar etiquetas para mejor visibilidad
plt.grid(True)

# Asegurar que el diseño no corte las etiquetas
plt.tight_layout()

# Mostrar la leyenda y el gráfico
plt.legend(title='Algoritmos')
plt.show()
