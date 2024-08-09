FROM debian:bullseye

RUN apt update && apt upgrade -y && \
    apt install nginx -y

COPY ./nginx.conf /etc/nginx/sites-available/default
COPY ../../cert.pem /etc/ssl/certs/cert.pem
COPY ../../key.pem /etc/ssl/private/key.pem


EXPOSE 80
CMD ["nginx", "-g", "daemon off;"]

