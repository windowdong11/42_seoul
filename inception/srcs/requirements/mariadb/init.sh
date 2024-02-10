#!/bin/sh

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld
chown -R mysql:mysql /var/lib/mysql


if [ -d "/var/lib/mysql/$MYSQL_DATABASE" ]; then
  echo "/var/lib/mysql/$MYSQL_DATABASE directory exists";
else
  echo "/var/lib/mysql/$MYSQL_DATABASE directory doesnt exist";


  # service mariadb start;
  echo "Run mariadb with bootstrap & skip-networking mode";
  mariadbd --skip-networking --user=root &
  sleep 5;

  mariadb -u root -e "CREATE DATABASE $MYSQL_DATABASE;"
  mariadb -u root -e "CREATE USER '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';"
  mariadb -u root -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%';"
  mariadb -u root -e "FLUSH PRIVILEGES;"

  # service mariadb stop;
  mysqladmin shutdown
  echo "mariadb stopped. finished setup"
fi


echo "[inception] Starting mariadbd";
exec mysqld --user=root
