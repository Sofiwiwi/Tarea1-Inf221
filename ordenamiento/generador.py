import random

with open("datasets/dataset_aleatorio.txt", "w") as archivo:
    casos = 150
    archivo.write(str(casos) + "\n")
    while casos > 0:
        casos -= 1
        # Tamaño del arreglo
        n = random.randint(1, 1000)
        # Para que el archivo tenga casos grandes sin pesar mucho.
        # Hay un 20% de probabilidad de que el tamaño del arreglo sea mayor a 1000
        if random.randint(1, 100) <= 20:
            n = random.randint(1000, 100000)
        archivo.write(str(n) + "\n")
        # Elementos del arreglo
        for i in range(n):
            archivo.write(str(random.randint(1, 100000)) + " ")
        archivo.write("\n")


with open ("datasets/dataset_ordenado.txt", "w") as archivo:
    casos = 100
    archivo.write(str(casos) + "\n")
    while casos > 0:
        casos -= 1
        n = random.randint(1, 1000)
        # Para que el archivo tenga casos grandes sin pesar mucho.
        # Hay un 20% de probabilidad de que el tamaño del arreglo sea mayor a 1000
        if random.randint(1, 100) <= 20:
            n = random.randint(1000, 100000)
        archivo.write(str(n) + "\n")
        for i in range(1, n + 1):
            archivo.write(str(i) + " ")
        archivo.write("\n")


with open("datasets/dataset_inverso.txt", "w") as archivo:
    casos = 100
    archivo.write(str(casos) + "\n")
    while casos > 0:
        casos -= 1
        n = random.randint(1, 1000)
        # Para que el archivo tenga casos grandes sin pesar mucho.
        # Hay un 20% de probabilidad de que el tamaño del arreglo sea mayor a 1000
        if random.randint(1, 100) <= 20:
            n = random.randint(1000, 100000)
        archivo.write(str(n) + "\n")
        for i in range(n, 0, -1):
            archivo.write(str(i) + " ")
        archivo.write("\n")