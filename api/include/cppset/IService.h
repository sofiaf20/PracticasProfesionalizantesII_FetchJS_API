/**
* Copyright (c) 2016 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of API-CPP-SET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#ifndef I_SERVICE_H
#define I_SERVICE_H

#include <iostream>
#include <vendors/nlohmann/json.hpp>

class IService
{
	public:
		virtual void call(nlohmann::json data) = 0;
};

#endif // I_SERVICE_H