from scipy.stats import kstest
import random
import matplotlib.pyplot as plt
import matplotlib
import numpy
import scipy

matplotlib.use('QT5Agg')

actual = numpy.random.uniform(7,8, 20)

print(actual)

print(kstest(actual, scipy.stats.uniform(loc=0, scale=1).cdf))


plt.hist(actual, bins=100)

plt.show()