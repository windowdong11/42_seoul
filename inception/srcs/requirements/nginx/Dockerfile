FROM debian:bullseye

ARG CERT_PEM
ARG KEY_PEM
RUN apt update && apt upgrade -y && \
    apt install nginx -y

COPY ./nginx.conf /etc/nginx/sites-available/default
COPY ./start.sh .
RUN chmod +x start.sh

EXPOSE 443
CMD ["./start.sh"]

