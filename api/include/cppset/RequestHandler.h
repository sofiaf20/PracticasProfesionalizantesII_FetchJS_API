/**
* Copyright (c) 2019 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of API-CPP-SET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/
#ifndef I_REQUEST_HANDLER_H
#define I_REQUEST_HANDLER_H

#include <iostream>
#include <memory>
#include <cppset/ComponentFactory.h>
#include <cppset/IService.h>
#include <cppset/IniReader.h>
#include <vendors/nlohmann/json.hpp>

// https://developer.mozilla.org/es/docs/Web/HTTP/Status
class RequestHandler
{
    private:
        nlohmann::json getRequestData()
        {
            //deserialize from standard input
            nlohmann::json requestData;
            
            try
            {
                std::cin >> requestData;
            }
            catch(nlohmann::json::exception& e)
            {
                nlohmann::json exception_response = {
                                {"error_status", true},
                                {"message", "415 Unsupported Media Type"},
                                {"debug_message", "json standard input fail, incorrect format"}, 
                                {"data",{ 
                                    {"message",e.what()},
                                    {"exception id", e.id}
                                }}
                            };
               std::cout << "Content-type:application/json; charset=utf-8\r\n\r\n";
               std::cout << exception_response; 
               exit (EXIT_FAILURE);            
            }

            return requestData;
        }
        
    public:
        RequestHandler(){}
        
        virtual ~RequestHandler(){}

        void handle()
        {
            std::shared_ptr<IniReader> iniReader( new IniReader() );
            iniReader->open("configuration.ini");
            std::string servicesPath = iniReader->selectSection("GENERAL")->getValue("servicesPath");

            nlohmann::json requestData = this->getRequestData();
            std::string serviceName = requestData["service"];

            std::shared_ptr<ComponentFactory> cF(new ComponentFactory());
            std::shared_ptr<IService> service = cF->create<IService>(servicesPath + serviceName);
            
            service->call(requestData);
        }
};
#endif // I_REQUEST_HANDLER_H
