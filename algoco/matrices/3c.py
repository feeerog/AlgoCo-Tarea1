import pandas as pd
import matplotlib.pyplot as plt

# Datos nuevos de tiempo de ejecución para las matrices de diferentes tamaños
data_nueva_matriz = {
    'Algoritmo': ['Normal', 'Traspuesta', 'Strassen'],
    '5': [1.2e-06, 2.4e-06, 0.0004183],
    '25': [0.0001103, 0.000227, 0.008603],
    '50': [0.0008499, 0.000891, 0.0610591],
    '64': [0.0017832, 0.0018276, 0.593276],
    '100': [0.0069521, 0.0069248, 0.473294],
    '200': [0.0586367, 0.056149, 3.23158],
    '256': [0.116045, 0.116701, 31.0808],
    '500': [0.975242, 0.887027, 24.8921],
    '800': [4.62353, 3.51016, 155.526],
    '1000': [8.25058, 6.96647, 163.495]
}

# Convertir los datos en un DataFrame
df_nueva_matriz = pd.DataFrame(data_nueva_matriz)

# Establecer el índice como el nombre del algoritmo
df_nueva_matriz.set_index('Algoritmo', inplace=True)

# Transponer el DataFrame para que las columnas sean los algoritmos y las filas los tamaños de las matrices
df_nueva_matriz = df_nueva_matriz.T

# Graficar los datos
df_nueva_matriz.plot(kind='line', marker='o')

# Configurar los títulos y etiquetas
plt.title('Comparación de Algoritmos - Multiplicación de Matrices Cuadradas')
plt.xlabel('Tamaño de la Matriz')
plt.ylabel('Tiempo de Ejecución (segundos)')
plt.grid(True)

# Mostrar la leyenda y el gráfico
plt.legend(title='Algoritmos')
plt.show()
