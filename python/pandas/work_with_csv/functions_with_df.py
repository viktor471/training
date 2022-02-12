import csv
import random as rnd
import datetime as dt
import random_date as rnd_date
import pandas as pd
import typing as tp

max_value = 100
amount_of_elements = 100
rows = 10
file_name = "file.csv"

headers = {1: "#",
           2: "Name",
           3: "phone",
           4: "address",
           5: "sex",
           6: "birthday",
           7: "hometown",
           8: "children",
           9: "marital status",
           10: "zip code"}


def get_random_list(size):
    rnd_numbers = []
    for i in range(size):
        rnd_numbers.append(rnd.randint(1, max_value))
    return rnd_numbers


def fill_csv_file(file_name_: str, headers_: list):
    elements_in_row = int(amount_of_elements / rows)

    file_csv_ = open(file_name_, "w")
    writer_ = csv.writer(file_csv_)
    writer_.writerow(headers_.values())

    rnd_numbers = get_random_list(amount_of_elements)
    for i in range(rows):
        a = i * elements_in_row
        b = i * elements_in_row + elements_in_row
        writer_.writerow(rnd_numbers[a:b])

    file_csv_.close()


def read_csv_file(file_name_):
    file_csv_ = open(file_name_, "r")
    print("".join(file_csv_.readlines()))
    file_csv_.close()


def get_frame_from_csv_file(file_name_: str):
    frame_ = pd.read_csv(file_name_, header=0, sep=',')
    return frame_


def get_dict_with_random_numbers() -> dict:
    new_line = {}
    for header in headers.values():

        new_line[header] = rnd.randint(1, 100)
    return new_line


def fill_col_with_dates(column_name: str, frame: pd.DataFrame) -> pd.DataFrame:
    for i in range(frame.shape[0]):
        frame.at[i, column_name] = dt.date.today()
    return frame


str_generator = tp.Callable[[...], str]


def date_generator(**args: list) -> str:
    start_date = args.values()[0]
    end_date = args.values()[1]
    sep = args.values()[2]
    return rnd_date.get_string_with_random_date(start_date, end_date, sep)


def fill_col_with_help_string_generator(column_name: str,
                                        frame: pd.DataFrame,
                                        generator: str_generator,
                                        **args) -> pd.DataFrame:
    for i in range(frame.shape[0]):
        frame.astype({column_name: str})
        frame.iloc[i, frame.columns.get_loc(column_name)] = str_generator(args)
    return frame


def delete_columns(my_frame: pd.DataFrame, list_of_columns: list):
    for string in list_of_columns:
        my_frame.drop(string, axis=1, inplace=True)
    return my_frame


