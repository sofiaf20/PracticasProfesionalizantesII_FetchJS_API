::Creo los directorios para el binario y las bibliotecas
MD .\api\
MD .\api\lib\
MD .\api\lib\services\
COPY .\configuration.ini .\api\


::compilo el Binario
g++ -Wall -std=c++11 -I.\include\ main.cpp -o .\api\main.exe

::compilo las bibliotecas
g++ -shared -Wall -std=c++11 -I.\include\ .\src\Services\TestService.cpp -o .\api\lib\services\TestService.dll