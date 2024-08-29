import random
with open("dataset.txt", "w") as archivo:
    casos = 500
    archivo.write(str(casos) + "\n")
    while casos > 0:
        casos -= 1
        n = random.randint(1, 10000)
        archivo.write(str(n) + "\n")
        for i in range(n):
            archivo.write(str(random.randint(1, 10000)) + " ")
        archivo.write("\n")