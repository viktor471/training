import numpy as np
import matplotlib.pyplot as plt


def hyperbola(x: np.ndarray):
    return 1/x


def main():
    x = np.linspace(0.1, 7, 1000)
    y = hyperbola(x)
    plt.plot(y)
    plt.show()


if __name__ == "__main__":
    main()
