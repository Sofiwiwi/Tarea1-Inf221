import numpy as np
import random

with open("dataset.txt", "w") as archivo:
    casos = 150
    temp = 0
    archivo.write(str(casos) + "\n")
    # genera matrices de nxm luego mxp luego pxo y asi sucesivamente 
    historial = [random.randint(1, 200)]
    while casos > 0:
        n = historial[-1]
        m = random.randint(1, 200)
        if random.random() < 0.6: # 60% de probabilidad de ser nxn
            m = n
        historial.append(m)
        casos -= 1
        archivo.write(str(n) + " " + str(m) + "\n")
        for i in range(n):
            for j in range(m):
                archivo.write(str(random.randint(1, 1000)) + " ")
            archivo.write("\n")
