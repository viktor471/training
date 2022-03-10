# Derived from offiical mysql image
FROM mysql

# Add root credentials
ENV MYSQL_ROOT_PASSWORD f

# Add a database
ENV MYSQL_DATABASE domains

# Add user credentials
ENV MYSQL_USER viktor
ENV MYSQL_PASSWORD ff

# Add th content of the sql-scripts/ directory to your image
# All scripts in docker-entrypoint-initdb.d/ are automatically
# executed during container startup

ADD create-table.sql /docker-entrypoint-initdb.d
#ADD sql-scripts/* /docker-entrypoint-initdb.d/
#ADD sql-scripts/insert_additional_data.sql /docker-entrypoint-initdb.d
EXPOSE 5007
