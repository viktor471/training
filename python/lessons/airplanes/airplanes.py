import numpy as np
import codecs
with codecs.open('input.csv', encoding="utf-8") as file:
    airplane = np.genfromtxt(file, delimiter=",")
    print(airplane.shape)
    print(airplane)
    print(airplane[0:10, 1:1+1])
    parts = [ np.mean(line) for line in airplane.transpose()]
    min_avg = np.min(parts)
    print("Часть:", parts.index(min_avg), "среднее наибольшее число попаданий:", min_avg)
