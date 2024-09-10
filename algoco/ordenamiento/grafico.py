import pandas as pd
import matplotlib.pyplot as plt

# 1. Datos para numAleatorios.txt
data_aleatorio = {
    'Algoritmo': ['Insertion Sort', 'Quick Sort', 'Merge Sort', 'Función Sort'],
    '100': [5.6e-06, 5.2e-06, 3.77e-05, 1.02e-05],
    '5000': [0.0108641, 0.0004658, 0.0056142, 0.0007797],
    '10000': [0.0478013, 0.0012349, 0.0115152, 0.0016596],
    '20000': [0.175615, 0.0020538, 0.0232082, 0.0036281],
    '30000': [0.394064, 0.0035997, 0.0430103, 0.0054491],
    '40000': [0.708659, 0.0043455, 0.0619285, 0.0074892]
}

df_aleatorio = pd.DataFrame(data_aleatorio)
df_aleatorio.set_index('Algoritmo', inplace=True)
df_aleatorio = df_aleatorio.T
df_aleatorio.plot(kind='line', marker='o')
plt.title('Comparación de Algoritmos - Numeros Aleatorios')
plt.xlabel('Cantidad de Datos')
plt.ylabel('Tiempo de Ejecución (segundos)')
plt.grid(True)
plt.legend(title='Algoritmos')
plt.show()


# 2. Datos para numAlternantes.txt
data_alternantes = {
    'Algoritmo': ['Insertion Sort', 'Quick Sort', 'Merge Sort', 'Función Sort'],
    '100': [5.8e-06, 2.17e-05, 2.51e-05, 9e-06],
    '5000': [0.0113325, 0.0209707, 0.0052464, 0.0007632],
    '10000': [0.0452712, 0.0840626, 0.0107867, 0.0012791],
    '20000': [0.178742, 0.333926, 0.0220085, 0.0034977],
    '30000': [0.406282, 0.743951, 0.0411744, 0.0042969],
    '40000': [0.730526, 1.32853, 0.0581269, 0.007397]
}

df_alternantes = pd.DataFrame(data_alternantes)
df_alternantes.set_index('Algoritmo', inplace=True)
df_alternantes = df_alternantes.T
df_alternantes.plot(kind='line', marker='o')
plt.title('Comparación de Algoritmos - Numeros Alternantes')
plt.xlabel('Cantidad de Datos')
plt.ylabel('Tiempo de Ejecución (segundos)')
plt.grid(True)
plt.legend(title='Algoritmos')
plt.show()


# 3. Datos para numAscendentes.txt
data_ascendentes = {
    'Algoritmo': ['Insertion Sort', 'Quick Sort', 'Merge Sort', 'Función Sort'],
    '100': [1e-06, 2.97e-05, 2.71e-05, 6.1e-06],
    '5000': [1.37e-05, 0.0723224, 0.0054215, 0.000451],
    '10000': [2.67e-05, 0.286276, 0.0108038, 0.0009374],
    '20000': [5.26e-05, 1.14513, 0.0226983, 0.0020602],
    '30000': [7.89e-05, 2.58162, 0.0505437, 0.0029169],
    '40000': [0.0001056, None, 0.0560457, 0.0042808]
}

df_ascendentes = pd.DataFrame(data_ascendentes)
df_ascendentes.set_index('Algoritmo', inplace=True)
df_ascendentes = df_ascendentes.T
df_ascendentes.plot(kind='line', marker='o')
plt.title('Comparación de Algoritmos - Numeros Ascendentes')
plt.xlabel('Cantidad de Datos')
plt.ylabel('Tiempo de Ejecución (segundos)')
plt.grid(True)
plt.legend(title='Algoritmos')
plt.show()


# 4. Datos para numDescendentes.txt
data_descendentes = {
    'Algoritmo': ['Insertion Sort', 'Quick Sort', 'Merge Sort', 'Función Sort'],
    '100': [9.4e-06, 1.85e-05, 2.52e-05, 6.8e-06],
    '5000': [0.0225239, 0.0440222, 0.0056981, 0.000365],
    '10000': [0.088261, 0.172094, 0.0113131, 0.0007583],
    '20000': [0.366274, 0.684091, 0.0231248, 0.001634],
    '30000': [0.816116, 1.53279, 0.0506016, 0.0023005],
    '40000': [1.45026, None, 0.0553084, 0.0033708]
}

df_descendentes = pd.DataFrame(data_descendentes)
df_descendentes.set_index('Algoritmo', inplace=True)
df_descendentes = df_descendentes.T
df_descendentes.plot(kind='line', marker='o')
plt.title('Comparación de Algoritmos - Numeros Descendentes')
plt.xlabel('Cantidad de Datos')
plt.ylabel('Tiempo de Ejecución (segundos)')
plt.grid(True)
plt.legend(title='Algoritmos')
plt.show()


# 5. Datos para numerosp.txt (Ordenados parcialmente)
data_numerosp = {
    'Algoritmo': ['Insertion Sort', 'Quick Sort', 'Merge Sort', 'Función Sort'],
    '100': [2.2e-06, 5.2e-06, 1.63e-05, 7.1e-06],
    '5000': [0.0003901, 0.0014627, 0.0052935, 0.0006799],
    '10000': [0.0006241, 0.002225, 0.0109513, 0.0012584],
    '20000': [0.0004329, 0.0076082, 0.0241939, 0.0027388],
    '30000': [0.0056375, 0.0118022, 0.0507114, 0.0052408],
    '40000': [0.0092813, 0.0191806, 0.0548299, 0.0084074]
}

df_numerosp = pd.DataFrame(data_numerosp)
df_numerosp.set_index('Algoritmo', inplace=True)
df_numerosp = df_numerosp.T
df_numerosp.plot(kind='line', marker='o')
plt.title('Comparación de Algoritmos - Numeros Ordenados Parcialmente')
plt.xlabel('Cantidad de Datos')
plt.ylabel('Tiempo de Ejecución (segundos)')
plt.grid(True)
plt.legend(title='Algoritmos')
plt.show()


# 6. Datos para numDuplicados.txt
data_duplicados = {
    'Algoritmo': ['Insertion Sort', 'Quick Sort', 'Merge Sort', 'Función Sort'],
    '100': [5.4e-06, 4.4e-06, 3.71e-05, 9.8e-06],
    '5000': [0.0109353, 0.0004518, 0.0055032, 0.0008007],
    '10000': [0.0435264, 0.0009189, 0.0128232, 0.0016244],
    '20000': [0.180896, 0.002079, 0.0239849, 0.0035558],
    '30000': [0.412582, 0.0031653, 0.049772, 0.0055178],
    '40000': [0.714708, 0.0045865, 0.0603718, 0.0076231]
}

df_duplicados = pd.DataFrame(data_duplicados)
df_duplicados.set_index('Algoritmo', inplace=True)
df_duplicados = df_duplicados.T
df_duplicados.plot(kind='line', marker='o')
plt.title('Comparación de Algoritmos - Numeros Duplicados')
plt.xlabel('Cantidad de Datos')
plt.ylabel('Tiempo de Ejecución (segundos)')
plt.grid(True)
plt.legend(title='Algoritmos')
plt.show()
