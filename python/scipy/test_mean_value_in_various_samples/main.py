import numpy as np
import numpy.random
import scipy.stats as stats
import matplotlib.pyplot as plt

rng = numpy.random.default_rng()


def get_distribution_tail(distribution: stats.rv_continuous, tail="min"):
    if tail == "min":
        return distribution.ppf(0.01)
    elif tail == "max":
        return distribution.ppf(0.99)


def get_distribution_bins(distribution: stats.rv_continuous, accuracy=0.01):
    d_min = get_distribution_tail(distribution, "min")
    d_max = get_distribution_tail(distribution, "max")
    return np.arange(d_min, d_max, accuracy)


def get_func_values(distribution=stats.rv_continuous, func_name="pdf", accuracy=0.01):
    x = get_distribution_bins(distribution, accuracy)
    func = getattr(distribution, func_name)
    return func(x)


def draw_distribution_func(distribution: stats.rv_continuous, func_name="pdf", accuracy=0.01, label="pdf", color="r"):
    x = get_distribution_bins(distribution, accuracy)
    func = getattr(distribution, func_name)
    y = func(x)
    plt.plot(x, y, label=label, color=color)


def get_distribution(distribution_type="norm", loc=0, scale=3) -> stats.rv_continuous:
    distribution = getattr(stats, distribution_type)
    return distribution(loc=loc, scale=scale)


def get_distribution_parameters(distribution: stats.rv_continuous, parameters="mvsk"):
    names = []
    if "m" in parameters:
        names.append("median")
    if "v" in parameters:
        names.append("variance")
    if "s" in parameters:
        names.append("skew")
    if "k" in parameters:
        names.append("kurtosis")

    values = distribution.stats(parameters)
    names_with_values = zip(names, values)
    return dict(names_with_values)


def print_parameters(parameters: dict):
    [ print(f"{name}: {value}") for name, value in parameters.items() ]


def get_distribution_sample(distribution_type="norm", size=10000, loc=0, scale=3) -> np.ndarray:
    if isinstance(distribution_type, str):
        distribution = get_distribution(distribution_type, loc, scale)
    else:
        distribution = distribution_type
    return distribution.rvs(size=size, random_state=rng)


def get_distribution_max_value(distribution: stats.rv_continuous, func_name="pdf", accuracy=0.01):
    y = get_func_values(distribution, func_name, accuracy)
    return np.max(y)


def get_random_sample(size=10):
    return np.random.randint(10, 99, size)


def draw_sample(sample: np.ndarray, density=True, cumulative=False, bins=60):
    plt.hist(x=sample, bins=bins, density=density, cumulative=cumulative)


def display():
    plt.show()


def print_sample(sample: np.ndarray):
    for number in sample:
        print(f"{number:.3f}", end="  ")
    print()


def print_sorted_sample(sample: np.ndarray):
    print("sorted sample: ", end="")
    print_sample(np.sort(sample))


def print_sample_median(sample: np.ndarray):
    print(f"sample median: {np.median(sample):.3f}")


def print_sample_mean(sample: np.ndarray):
    print(f"sample mean:   {np.mean(sample):.3f}")


def tmp_debug(distribution):
    d_min = get_distribution_tail(distribution, "min")
    d_max = get_distribution_tail(distribution, "max")
    print("d_min:", d_min, "d_max:", d_max)
    parameters = get_distribution_parameters(distribution, "mv")
    y = get_func_values(distribution, "pdf", 0.01)
    print("max:", np.max(y))


def main():
    distribution = get_distribution("norm", loc=0, scale=np.sqrt(3))
    sample = get_distribution_sample(distribution)
    parameters = get_distribution_parameters(distribution, "mv")
    print_parameters(parameters)
    tmp_debug(distribution)
    draw_distribution_func(distribution, func_name="pdf", label="pdf")
    # sample = get_random_sample(10)
    # sample = np.append(sample, [5000])
    draw_sample(sample)

    print_sorted_sample(sample)
    print_sample_median(sample)
    print_sample_mean(sample)

    display()


if __name__ == "__main__":
    main()
