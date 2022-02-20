import datetime as dt
from functions_with_df import pd
import functions_with_df as df
import random_date


def main():
    frame = pd.read_csv("result.csv", sep=";", header=0)
    print(frame)
    print(frame.dtypes)
    frame = df.fill_col_with_dates("birthday", frame)
    print(frame)
    frame.to_csv("result2.csv", sep=",", header=0)
    print(frame["birthday"])
    print()
    print(type(dt.date.today()))
    print(dt.date)
    frame.ap


if __name__ == "__main__":
    main()
