FROM mysql:latest
ENV MYSQL_ROOT_PASSWORD f
ENV MYSQL_DATABASE pytests
ENV MYSQL_USER viktor
ENV MYSQL_PASSWORD ff
ADD script.sql /docker-entrypoint-initdb.d
EXPOSE 3306
