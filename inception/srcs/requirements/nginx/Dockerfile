FROM debian:bullseye

ARG CERT_PEM
ARG KEY_PEM
RUN apt update && apt upgrade -y && \
    apt install nginx -y

COPY ./nginx.conf /etc/nginx/sites-available/default
# COPY ../../cert.pem /etc/ssl/certs/cert.pem
# COPY ../../key.pem /etc/ssl/private/key.pem
RUN mkdir -p /etc/ssl/certs /etc/ssl/private
# RUN echo "$CERT_PEM" > /etc/ssl/certs/cert.pem && chmod 644 /etc/ssl/certs/cert.pem
# RUN echo "$KEY_PEM" > /etc/ssl/private/key.pem && chmod 600 /etc/ssl/private/key.pem

COPY ./start.sh .
RUN chmod +x start.sh

EXPOSE 443
CMD ["./start.sh"]

