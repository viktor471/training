import mysql.connector
import json
from flask import Flask

DB_CONFIG = {
    'user': 'root',
    'password': 'f',
    'host': 'mysqldb',
    'database': 'domains'
}

file = "prepare_database.sql"
if __name__ == "__main__":
  cnx = mysql.connector.connect(
    **DB_CONFIG
    # host="mysqldb",
    # user="root",
    # password="p@ssw0rd1",
    # database="pytest"
  )
  
  cursor = cnx.cursor()
  file = open(file)
  sql = file.read()
  results = cursor.execute(sql, multi=True)

  print("results type:", type(results))

  print("======== results:")
  print(results)
  print("===================")

  for result in results:
    if result.with_rows:
        print("Rows produced by statement '{}':".format(
            result.statement))
        print(result.fetchall())
    else:
        print("Number of rows affected by statement '{}': {}".format(
            result.statement, result.rowcount))
  cnx.close() 
