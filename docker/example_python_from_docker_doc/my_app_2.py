from db import DB

DB_CONFIG = {
    'user': 'root',
    'password': 'f',
    'host': 'mysqldb',
    'database': 'domains'
}

mydb = DB(DB_CONFIG)

query = "insert into domains (name, allow) values ('mysite.com', 1)"
mydb.query(query)

