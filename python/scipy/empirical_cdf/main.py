from statsmodels.distributions.empirical_distribution import ECDF
import matplotlib.pyplot as plt
import numpy as np
import scipy


class Ecdf:
    x: np.ndarray
    y: np.ndarray

    def __init__(self, array):
        self.x = np.sort(array)
        self.y = np.arange(1, len(self.x) + 1)/float(len(self.x))


# arr = np.array([1, 1, 2, 2, 3, 4])
#arr = np.array([2,2,2,2,2, 2,2,2,2, 3])

sample = scipy.stats.expon(loc=0, scale=3).rvs(size=1000)
ecdf = Ecdf(sample)

plt.plot(ecdf.x, ecdf.y)
print(ecdf.x)
print(ecdf.y)
plt.show()
ecdf = ECDF(sample)
plt.plot(ecdf.x, ecdf.y)
x = np.linspace(-7.5, 8, 1000)
plt.plot(x, scipy.stats.norm(loc=0, scale=3).cdf(x))

# plt.hist(sample, cumulative=True, density=True)

plt.show()



