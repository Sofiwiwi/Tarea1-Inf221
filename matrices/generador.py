import numpy as np
import random

with open("datasets/dataset_mnp.txt", "w") as archivo:
    casos = 150
    temp = 0
    archivo.write(str(casos) + "\n")
    # genera matrices de nxm luego mxp luego pxo y asi sucesivamente 
    historial = [random.randint(1, 256)]
    while casos > 0:
        n = historial[-1]
        m = random.randint(1, 256)
        historial.append(m)
        casos -= 1
        archivo.write(str(n) + " " + str(m) + "\n")
        for i in range(n):
            for j in range(m):
                archivo.write(str(random.randint(1, 100)) + " ")
            archivo.write("\n")


with open("datasets/dataset_nxn.txt", "w") as archivo:
    casos = 75
    temp = 0
    archivo.write(str(casos) + "\n")
    # genera matrices de nxn
    while casos > 0:
        n = random.randint(1, 256)
        casos -= 1
        cont = 0
        while cont < 2:
            archivo.write(str(n) + " " + str(n) + "\n")
            for i in range(n):
                for j in range(n):
                    archivo.write(str(random.randint(1, 100)) + " ")
                archivo.write("\n")
            cont += 1

with open("datasets/dataset_strassen.txt", "w" ) as archivo:
    casos = 75
    temp = 0
    archivo.write(str(casos) + "\n")
    for i in range(casos):
        casos -= 1
        cont = 0
        k = random.randint(1, 8)
        n = 2**k
        while cont < 2:
            archivo.write(str(n) + " " + str(n) + "\n")
            for i in range(n):
                for j in range(n):
                    archivo.write(str(random.randint(1, 100)) + " ")
                archivo.write("\n")
            cont += 1
