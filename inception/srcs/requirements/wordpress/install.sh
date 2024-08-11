#!/bin/bash

echo "running wordpress install.sh";

if [ -f /var/www/html/wp-config.php ]; then
	echo "wp-config.php exists";
else
	echo "wp-config.php doesnt exist";
	cd /var/www/html
	wp config create --dbname=${MYSQL_DATABASE} --dbuser=${MYSQL_USER} --dbpass=${MYSQL_PASSWORD} --dbhost=${MYSQL_HOST} --allow-root
	wp core install --allow-root --url=${WP_DOMAIN} --title="inception-dowon" --admin_user=${WP_USER} --admin_password=${WP_PASSWORD} --admin_email=${WP_EMAIL}
	wp user create ${USER_NAME} ${USER_EMAIL} --user_pass=${USER_PASSWORD}
fi

exec php-fpm7.4 -F