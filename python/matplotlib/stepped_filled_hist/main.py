import string

import numpy as np
import matplotlib.pyplot as plt
import scipy.stats

data = np.genfromtxt("input.csv", delimiter=",")

# fig, ax = plt.subplots(1, 1)
# ax.hist([1,2,3,4], density=True, stacked=True, alpha=0.2)
#
# x = np.arange(0, 7, 0.1)
# print(type(x))
# norm = scipy.stats.norm()
# y = scipy.stats.norm.pdf(x, loc=5, scale=1)
# plt.plot(x, y)
# y = scipy.stats.norm.cdf(x, loc=5, scale=1)
# plt.plot(x, y)
# x = np.arange(0, 1, 0.01)
# y = scipy.stats.norm.ppf(x, loc=5, scale=1)
# plt.plot(x, y)
#
# ax.legend(loc="best", frameon=False)

plt.hist(scipy.stats.norm.rvs(size=10000, loc=5, scale=1, random_state=np.random.default_rng()), alpha=0.5)

dictionary = {"a": 1, "b": 2}

# for a, b in dictionary.items():
#     print(a)

# _ = "hello"
# print(_)

# [print("working:", a, b) for a, b in dictionary.items()]

numbers = [element for element in range(1,27)]
alphabet = string.ascii_lowercase

new_dict = zip(numbers, alphabet)

# for pair in new_dict:
#     print(pair)

# print(dict(new_dict))

import statistics

numbers = np.random.randint(10, 99, 10)
sorted_numbers = np.sort(numbers)
print("numbers:", numbers)
print("sorted_numbers:", sorted_numbers)
print("statistics:    mean:", statistics.mean(numbers), "median:", statistics.median(numbers))
print("np:            mean:", np.mean(numbers), "median:", np.median(numbers))
mean = sum(numbers)/len(numbers)
print(len(numbers))
print("number[4]:", sorted_numbers[4], "numbers[5]:", sorted_numbers[5])
sum_of_middle = sorted_numbers[5] + sorted_numbers[4]
print("sum_of_middle:", sum_of_middle)
median = (sorted_numbers[5] + sorted_numbers[4])/2
print("my:            mean:", mean, "median:", median)
# plt.show()
