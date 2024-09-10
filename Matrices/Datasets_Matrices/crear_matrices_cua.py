import numpy as np # type: ignore
import os # type: ignore

def generar_matriz_cuadrada(tamano):
    """
    Genera una matriz cuadrada aleatoria de enteros.
    """
    matriz = np.random.randint(0, 100, size=(tamano, tamano))  # Genera enteros entre 0 y 99
    return matriz

def guardar_matriz_en_txt(nombre_archivo, matriz):
    """
    Guarda una única matriz en un archivo .txt
    """
    with open(nombre_archivo, 'w') as archivo:
        archivo.write(f"{matriz.shape[0]} {matriz.shape[1]}\n")
        np.savetxt(archivo, matriz, fmt='%d')

# Tamaños de matrices especificados
tamanos = [10, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]

# Generar y guardar las matrices
for tamano in tamanos:
    matriz = generar_matriz_cuadrada(tamano)
    nombre_archivo = f'matrices_cuadradas/{tamano}x{tamano}.txt'  # Crear un nombre de archivo basado en el tamaño
    guardar_matriz_en_txt(nombre_archivo, matriz)

print("Matrices generadas y guardadas en archivos separados.")
