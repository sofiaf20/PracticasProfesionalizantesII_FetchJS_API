#!/bin/bash

##Compilo el test
g++ -Wall -std=c++11 -I../../include/ test.cpp -o test.exe

##Doy permisos de ejecución al binario
chmod +x test.exe

##Ejecuto:
./test.exe