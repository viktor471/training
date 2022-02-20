inner_list_1 = [2, 3]
inner_list_2 = [1, 4]

main_list = [inner_list_1, inner_list_2]

main_list.append(inner_list_1)

print(main_list)

main_list[0].append(0)
main_list.append(main_list)
main_list[3]
print(inner_list_1)

print(main_list)
print(main_list[3])

a = 3
b = a
b = 2

print(a)
