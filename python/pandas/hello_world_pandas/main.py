import pandas as pd
import csv
import random as rnd

from sklearn.datasets import load_iris

a = []

for i in range(100):
    a.append(rnd.randint(0, 100))

f = open("file.csv", "w")
writer = csv.writer(f)

for i in range(10):
    string = ";".join(a[:10])
    print("string:", string)
    writer.writerow(string)

f.close()

df = pd.DataFrame({'numbers': tuple(range(10)), 'chars': tuple(['a'] * 10)})

f = open("file.csv", "r")

print(f.readlines())
