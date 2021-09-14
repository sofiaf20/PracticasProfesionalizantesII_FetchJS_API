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
	std::shared_ptr<RequestHandler> requestHandler(new RequestHandler());
	requestHandler->handle();
}