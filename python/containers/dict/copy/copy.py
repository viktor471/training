DB_CONFIG = {
    'user': 'root',
    'password': 'root',
    'host': '138.201.126.216',
    'port': 44006,
    'database': 'pytest',
    'raise_on_warnings': False
}

copy = DB_CONFIG.copy()
not_copy = DB_CONFIG

not_copy["user"] = "viktor"

print("copy:", copy)
print()
print("not copy:", not_copy)

del not_copy["database"]

print()
print("DB_CONFIG:", DB_CONFIG)