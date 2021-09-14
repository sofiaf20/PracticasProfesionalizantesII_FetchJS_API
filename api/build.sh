#!/bin/bash
##Borro el directorio si ya existiera
if [ -d ./api/ ];
	then rm -r ./api/;
fi
##Creo los directorios para el Binario y las bibliotecas
mkdir ./api/
mkdir ./api/lib/
mkdir ./api/lib/services/
cp ./configuration.ini ./api/

##compilo el Binario
g++ -Wall -std=c++11 -I./include/ main.cpp -ldl -o ./api/main.bin

##compilo las bibliotecas
g++ -shared -Wall -std=c++11 -fPIC -I./include/ ./src/Services/TestService.cpp -o ./api/lib/services/TestService.so

##otorgo permisos de escritura a los ejecutables
chmod +x ./api/main.bin
