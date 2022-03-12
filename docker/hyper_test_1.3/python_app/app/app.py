from db import DB

HTTP_CONFIG = {
    'host': '127.0.0.1',
    'port': 65065
}

DB_CONFIG = {
    'user': 'root',
    'password': 'f',
    'host': 'mysqldb',
    'database': 'pytests'
}

mydb = DB(DB_CONFIG)
httpserver_url = f"http://{HTTP_CONFIG['host']}:{HTTP_CONFIG['port']}"

mydb.query_from_file('pytest.sql', {'@URL@': httpserver_url})



