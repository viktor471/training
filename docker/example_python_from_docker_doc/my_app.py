import mysql.connector
from mysql.connector import Error
import json

DB_CONFIG = {
    'user': 'root',
    'password': 'f',
    'host': 'mysqldb',
    'database': 'pytests'
}

if __name__ == "__main__":
  query = "insert into domains (name, allow) values ('mysite.com', 1)"

  try:
    conn = mysql.connector.connect(**DB_CONFIG)

    cursor = conn.cursor()
    cursor.execute(query)
    res = [item for item in cursor]
    print(res)
    conn.commit()

    cursor.close()
    conn.close()

  except Error as error:
        print(error)

  finally:
    pass
