import random

# Función para generar un dataset ordenado
def generar_dataset_ordenado(tamaño):
    return list(range(1, tamaño + 1))

# Función para generar un dataset inversamente ordenado
def generar_dataset_inversamente_ordenado(tamaño):
    return list(range(tamaño, 0, -1))

# Función para generar un dataset aleatorio
def generar_dataset_aleatorio(tamaño):
    return [random.randint(1, 1000000) for _ in range(tamaño)]

# Función para generar un dataset con elementos repetidos
def generar_dataset_repetido(tamaño):
    return [random.randint(1, 1000) for _ in range(tamaño)]

# Función para generar un dataset casi ordenado
def generar_dataset_casi_ordenado(tamaño):
    dataset = generar_dataset_ordenado(tamaño)
    # Desordenamos el 10% de los elementos
    for _ in range(int(tamaño * 0.1)):
        i, j = random.randint(0, tamaño-1), random.randint(0, tamaño-1)
        dataset[i], dataset[j] = dataset[j], dataset[i]
    return dataset

# Función para guardar un dataset en un archivo
def guardar_dataset_en_archivo(nombre_archivo, dataset):
    with open(nombre_archivo, 'w') as f:
        for valor in dataset:
            f.write(f"{valor} ")

# Tamaño del dataset
tamaño = 1000000
# Generación de los datasets
dataset_ordenado = generar_dataset_ordenado(tamaño)
dataset_inversamente_ordenado = generar_dataset_inversamente_ordenado(tamaño)
dataset_aleatorio = generar_dataset_aleatorio(tamaño)
dataset_repetido = generar_dataset_repetido(tamaño)
dataset_casi_ordenado = generar_dataset_casi_ordenado(tamaño)

# Guardar los datasets en archivos .txt
guardar_dataset_en_archivo("dataset_ordenado.txt", dataset_ordenado)
guardar_dataset_en_archivo("dataset_inversamente_ordenado.txt", dataset_inversamente_ordenado)
guardar_dataset_en_archivo("dataset_aleatorio.txt", dataset_aleatorio)
guardar_dataset_en_archivo("dataset_repetido.txt", dataset_repetido)
guardar_dataset_en_archivo("dataset_casi_ordenado.txt", dataset_casi_ordenado)

print("Datasets generados")
