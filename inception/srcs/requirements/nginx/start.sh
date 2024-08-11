#!/bin/bash

echo -e "$CERT_PEM" > /etc/ssl/certs/cert.pem && chmod 644 /etc/ssl/certs/cert.pem
echo -e "$KEY_PEM" > /etc/ssl/private/key.pem && chmod 600 /etc/ssl/private/key.pem


echo "[inception] Starting nginx"
exec nginx -g "daemon off;"