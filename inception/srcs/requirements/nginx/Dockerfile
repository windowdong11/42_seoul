FROM debian:bullseye

RUN apt update && apt upgrade -y && \
    apt install nginx -y

COPY ./nginx.conf /etc/nginx/sites-available/default


EXPOSE 80
CMD ["nginx", "-g", "daemon off;"]

