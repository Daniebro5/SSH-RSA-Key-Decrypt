#!/bin/bash

clear

clave="$1"

echo "Programa que identifica el exponente y el modulo de una llave publica SSH-RSA"

> archivo.txt

openssl base64 -d -in $clave | hd >> llaveComparada.txt

openssl base64 -d -in $clave | xxd -p | tr -d '\n' >> llaveHexadecimal.txt

gcc -o claves claves.c -lm -w

./claves
