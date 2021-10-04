/**
* Copyright (c) 2019 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of API-CPP-SET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#include <iostream>
#include <cppset/RequestHandler.h>

int main()
{
	std::shared_ptr<RequestHandler> requestHandler(new RequestHandler()); // con un puntero inteligente crea una solicitud
	requestHandler->handle(); // llama al metodo handle que es el que se encarga de traer la respuesta de los datos
}
