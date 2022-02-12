import functions_with_df as func


def main():
    func.fill_csv_file(func.file_name, func.headers)
    frame = func.get_frame_from_csv_file(func.file_name)
    dict_ = func.get_dict_with_random_numbers()
    print(dict_.keys())
    print(dict_.values())
    print(dict_.__len__())
    frame = frame.append(dict_, ignore_index=True)
    print(frame)
    frame["new column"] = func.get_random_list(frame.shape[0])
    print(frame)
    frame.drop([7, 8, 5], inplace=True, axis=0)
    print(frame)
    frame.drop("zip code", axis=1, inplace=True)
    print(frame)
    frame.to_csv("result.csv", sep=";", header=True)


if __name__ == '__main__':
    main()
