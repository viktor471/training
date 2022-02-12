import shutil
import sys
import os
from random import randint

target_folder = sys.argv[2]
list_of_folders = os.listdir(target_folder)

desired_amount = int(sys.argv[1])
real_amount = len(list_of_folders)
amount_of_iterations = desired_amount // real_amount


print("real_amount:", real_amount, "desired_amount:", desired_amount)
print(list_of_folders)
print(amount_of_iterations)
print(target_folder)

PREFIX = "SESSION_2022020"

names = []
first_parts = []


def get_random_first_part():
    rand_day = str(randint(1, 4))
    rand_hour = str(randint(11, 17))
    tens_of_minutes = "{:d}".format(randint(0, 5))
    return rand_day + "_" + rand_hour + tens_of_minutes


def get_random_full_name(first_part: str):
    rand_minutes = "{:d}".format(randint(0, 9))
    rand_seconds = "{:02d}".format(randint(0, 59))
    return PREFIX + first_part + rand_minutes + rand_seconds


def get_random_with_func(target_list: list, rand_func, *args):
    random_name = rand_func(*args)

    while random_name in target_list:
        random_name = rand_func(*args)

    target_list.append(random_name)

    return random_name


for k in range(amount_of_iterations):
    for i, folder in enumerate(list_of_folders):
        random_first_part = get_random_with_func(first_parts, get_random_first_part)
        random_full_name = get_random_with_func(names,
                                                get_random_full_name,
                                                random_first_part)

        original_folder = target_folder + "/" + folder
        copy_folder = "copies/" + random_full_name

        shutil.copytree(original_folder, copy_folder)

if __name__ == "__main__":
    pass
