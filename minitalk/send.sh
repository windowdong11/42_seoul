#!/bin/bash

# Send a message to the server
echo "[Single client] Sending message to server."
./client $1 $2

echo "[Multiple clients] Sending message to server."
for i in $(seq 10)
do
	./client $1 $2 &
done