import pandas

dataset = pandas.read_csv("input.csv")
# for index, row in dataset.iterrows():
#     print(row.values.mean())

mean_month = dataset.stack().mean()
print(mean_month)
dataset["mean"] = dataset.mean(axis=1)
print(dataset)
means = {}
# means[dataset]
