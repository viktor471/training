# args = ["a", "b", "c"]

# for a in args:
#     match a:
#         case "a" | "b" as arg:
#             print(a)
#             print("hello")
#         case "c" as arg:
#             print(a)
#             print("bye")

dict_1 = dict(a=3, b=4)
dict_2 = dict(c=2, d=8)

for a, b in zip(dict_1, dict_2, strict=True):
    print(f"{a=}")
    print(f"{b=}")
