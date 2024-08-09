FROM debian:bullseye

RUN apt update && apt upgrade -y \
    && apt install php-fpm php-mysql wget -y \
    && apt install curl -y

RUN mkdir -p /var/www/html && cd /var/www/html && mkdir -p /run/php \
    && wget https://wordpress.org/latest.tar.gz \
    && tar -xvzf latest.tar.gz \
    && mv wordpress/* . \
    && rm -rf wordpress latest.tar.gz

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# wp-config.php
# COPY wp-config.php /var/www/html/wp-config.php
# php-fpm
COPY www.conf /etc/php/7.4/fpm/pool.d/www.conf

RUN chown -R www-data:www-data /var/www/html && chmod -R 755 /var/www/html


EXPOSE 9000

COPY install.sh .
RUN chmod +x install.sh

CMD ["./install.sh"]

