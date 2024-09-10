import numpy as np # type: ignore
import os # type: ignore

def generar_matriz_rectangular(filas, columnas):
    """
    Genera una matriz rectangular aleatoria de enteros.
    """
    matriz = np.random.randint(0, 100, size=(filas, columnas))  # Genera enteros entre 0 y 99
    return matriz

def guardar_matriz_en_txt(nombre_archivo, matriz):
    """
    Guarda una única matriz en un archivo .txt
    """
    with open(nombre_archivo, 'w') as archivo:
        archivo.write(f"{matriz.shape[0]} {matriz.shape[1]}\n")
        np.savetxt(archivo, matriz, fmt='%d')

# Tamaños de la otra dimensión (columnas)
columnas = [10, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
filas_fijas = 200  # Valor fijo para las filas

# Generar y guardar las matrices rectangulares
for columnas_var in columnas:
    matriz = generar_matriz_rectangular(filas_fijas, columnas_var)
    nombre_archivo = f'matrices_rectangulares/{filas_fijas}x{columnas_var}.txt'  # Crear un nombre de archivo basado en las dimensiones
    guardar_matriz_en_txt(nombre_archivo, matriz)

print("Matrices rectangulares generadas y guardadas en archivos separados.")
