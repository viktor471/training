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

db = DB(DB_CONFIG)
httpserver_url = f"http://{HTTP_CONFIG['host']}:{HTTP_CONFIG['port']}"

nodatabase_config = db.config.copy()
del nodatabase_config["database"]
nodatabase_db = DB(nodatabase_config)
database = db.config["database"]
nodatabase_db.queries([f'DROP DATABASE IF EXISTS {database}', f'CREATE DATABASE {database}'])

db.query_from_file('pytest.sql', {'@URL@': httpserver_url})

id = 2
ep_id = 2
channel_id = 2
pool_id = 1

db.query("update dsps set status='active' where id={}".format(id))
db.query("update pools set status='active' where id={}".format(pool_id))
db.query("update channel_endpoints set channel_id={} where endpoint_id={}".format(channel_id, ep_id))
db.query("insert into channel_domain_pools values({}, {}, 'allow')".format(channel_id, pool_id))

db.query("select * from dsps where id={}".format(id))
db.query("select * from pools where id={}".format(pool_id))
db.query("select * from channel_endpoints where endpoint_id={}".format(ep_id))
db.query("select * from channel_domain_pools where channel_id={} and pool_id={}".format(channel_id, pool_id))
