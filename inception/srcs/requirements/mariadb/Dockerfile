FROM debian:bullseye

RUN apt update && apt upgrade -y && \
    apt install mariadb-server -y

COPY ./my.cnf /etc/mysql/my.cnf

RUN chown -R mysql:mysql /var/lib/mysql

COPY ./init.sh .
RUN chmod +x init.sh

CMD ["./init.sh"] 

