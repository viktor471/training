import matplotlib.pyplot as plt
import numpy as np

array = np.array([1,2,3,4])

plt.hist(array, density=True, bins=np.linspace(np.min(array), np.max(array), len(array)))

# print(np.histogram(array, density=True))

plt.show()