import functions_with_df as df
import pandas as pd


def main():
    frame = pd.read_csv("result.csv", sep=";", header=0)
    print(frame)
    print(frame.keys())
    print(frame.columns)
    for_deleting = ["new column", "phone", "address"]
    df.delete_columns(frame, for_deleting)
    print(frame)
    df.fill_col_with_rnd_string_dates("birthday", frame, sep="-")
    print(frame)
    print(frame.dtypes)


if __name__ == "__main__":
    main()

