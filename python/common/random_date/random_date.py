import datetime as dt
import random as rnd


def generate_random_date(start_date=dt.date(1900, 1, 1,), end_date=dt.date(2022, 1, 1)) -> dt.date:
    time_between_dates = end_date - start_date
    days_between_dates = time_between_dates.days
    random_number_of_days = rnd.randrange(days_between_dates)
    random_date = start_date + dt.timedelta(days=random_number_of_days)
    return random_date


def get_string_with_random_date(start_date=dt.date(1900, 1, 1,), end_date=dt.date(2022, 1, 1), sep="-"):
    string = str(generate_random_date(start_date, end_date))
    if sep == "-":
        pass
    else:
        string.replace("-", sep)
    return string


