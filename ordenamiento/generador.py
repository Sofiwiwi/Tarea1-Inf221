import random
with open("dataset.txt", "w") as archivo:
    casos = 300
    archivo.write(str(casos) + "\n")
    while casos > 0:
        casos -= 1
        # Tamaño del arreglo
        n = random.randint(1, 1000)
        if random.randint(1, 100) <= 10:
            n = random.randint(1000, 100000)
        archivo.write(str(n) + "\n")
        # hay un 40 % de probabilidad de que el arreglo esté ordenado
        ordenado = random.randint(1, 100) <= 30
        if ordenado:
            crec = random.randint(0, 1)
            if crec:
                for i in range(1, n + 1):
                    archivo.write(str(i) + " ")
            else:
                for i in range(n, 0, -1):
                    archivo.write(str(i) + " ")
        else:
            for i in range(n):
                archivo.write(str(random.randint(1, 100000)) + " ")
        archivo.write("\n")