import os
import json
from __future__ import print_function
import mysql.connector
import time


DB_CONFIG = {
    'user': 'root',
    'password': 'root',
    'host': '138.201.126.216',
    'port': 44006,
    'database': 'pytest',
    'raise_on_warnings': False
}

def db():
    """
    коннектор к базе данных
    :return:
    """
    return DB(DB_CONFIG)

class DB:

    def __init__(self, config=None):
        self.config = config

    def _connect(self):
        for _ in range(13):
            try:
                return mysql.connector.connect(**self.config)
            except:
                if _ >= 11:
                    raise
                print('MySQL is not ready, waiting...')
                time.sleep(5)

    def queries(self, qs: []):
        cnx = self._connect()
        cursor = cnx.cursor()
        for q in qs:
            cursor.execute(q, None)
        cursor.close()
        cnx.close()

    def query(self, q, p=None):
        cnx = self._connect()
        cursor = cnx.cursor()
        cursor.execute(q, p)
        res = [item for item in cursor]
        cursor.close()
        cnx.close()
        return res

    def mquery(self, q, v):
        cnx = self._connect()
        cursor = cnx.cursor()
        cursor.executemany(q, v)
        cnx.commit()
        cursor.close()
        cnx.close()

    def query_from_file(self, file, replacements):
        file = open(file)
        sql = file.read()
        for k, v in replacements.items():
            sql = sql.replace(k, v)
        cnx = mysql.connector.connect(**self.config)
        cursor = cnx.cursor()

        for result in cursor.execute(sql, multi=True):
            if result.with_rows:
                print("Rows produced by statement '{}':".format(
                    result.statement))
                print(result.fetchall())
            else:
                print("Number of rows affected by statement '{}': {}".format(
                    result.statement, result.rowcount))
        cnx.close()

