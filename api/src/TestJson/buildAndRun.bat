:: Compilo la biblioteca
g++ -shared -Wall -std=c++11 -fPIC -I..\..\include\ ..\..\src\compset\JsonDocumentGenerator.cpp -o JsonDocumentGenerator.dll

:: Compilo el test
g++ -Wall -std=c++11 -I..\..\include\ -c ..\..\src\compset\LibraryLoader.cpp
g++ -Wall -std=c++11 -I..\..\include\ -c ..\..\src\compset\ComponentFactory.cpp
g++ -Wall -std=c++11 -I..\..\include\ -c test.cpp
g++ -Wall -std=c++11 LibraryLoader.o ComponentFactory.o test.o -o test.exe

::  Limpio los códigos objeto
DEL .\*.o

:: Ejecuto:
test.exe