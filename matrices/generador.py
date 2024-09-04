import numpy as np
import random

with open("datasets/dataset_mnp.txt", "w") as archivo:
    casos = 150
    temp = 0
    archivo.write(str(casos) + "\n")
    # genera matrices de nxm luego mxp luego pxo y asi sucesivamente 
    historial = [random.randint(1, 200)]
    while casos > 0:
        n = historial[-1]
        m = random.randint(1, 200)
        historial.append(m)
        casos -= 1
        archivo.write(str(n) + " " + str(m) + "\n")
        for i in range(n):
            for j in range(m):
                archivo.write(str(random.randint(1, 1000)) + " ")
            archivo.write("\n")


with open("datasets/dataset_nxn.txt", "w") as archivo:
    casos = 75
    temp = 0
    archivo.write(str(casos) + "\n")
    # genera matrices de nxn
    while casos > 0:
        n = random.randint(1, 200)
        casos -= 1
        cont = 0
        while cont < 2:
            archivo.write(str(n) + " " + str(n) + "\n")
            for i in range(n):
                for j in range(n):
                    archivo.write(str(random.randint(1, 1000)) + " ")
                archivo.write("\n")
            cont += 1
