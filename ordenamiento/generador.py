import random
with open("dataset.txt", "w") as archivo:
    casos = 500
    archivo.write(str(casos) + "\n")
    while casos > 0:
        casos -= 1
        # Genera un número aleatorio que tenga un 5% de probabilidad de ser mayor a 10000
        n = random.randint(1, 1000)
        if random.randint(1, 100) <= 2:
            n = random.randint(1000, 100000)
        archivo.write(str(n) + "\n")
        for i in range(n):
            n = random.randint(1, 1000)
            if random.randint(1, 100) <= 2:
                n = random.randint(1000, 100000)
            archivo.write(str(n) + " ")
        archivo.write("\n")