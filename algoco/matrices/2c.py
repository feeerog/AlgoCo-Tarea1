import pandas as pd
import matplotlib.pyplot as plt

# Filtrar los datos de Normal y Traspuesta
data_filtrada_matriz = {
    'Algoritmo': ['Normal', 'Traspuesta'],
    '5': [1.2e-06, 2.4e-06],
    '25': [0.0001103, 0.000227],
    '50': [0.0008499, 0.000891],
    '64': [0.0017832, 0.0018276],
    '100': [0.0069521, 0.0069248],
    '200': [0.0586367, 0.056149],
    '256': [0.116045, 0.116701],
    '500': [0.975242, 0.887027],
    '800': [4.62353, 3.51016],
    '1000': [8.25058, 6.96647]
}

# Convertir los datos en un DataFrame
df_filtrada_matriz = pd.DataFrame(data_filtrada_matriz)

# Establecer el índice como el nombre del algoritmo
df_filtrada_matriz.set_index('Algoritmo', inplace=True)

# Transponer el DataFrame para que las columnas sean los algoritmos y las filas los tamaños de las matrices
df_filtrada_matriz = df_filtrada_matriz.T

# Graficar los datos
df_filtrada_matriz.plot(kind='line', marker='o')

# Configurar los títulos y etiquetas
plt.title('Comparación de Algoritmos - Multiplicación de Matrices Cuadradas')
plt.xlabel('Tamaño de la Matriz')
plt.ylabel('Tiempo de Ejecución (segundos)')
plt.grid(True)

# Mostrar la leyenda y el gráfico
plt.legend(title='Algoritmos')
plt.show()
