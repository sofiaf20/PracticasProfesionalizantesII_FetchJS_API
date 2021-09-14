/**
* Copyright (c) 2019 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of API-CPP-SET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/
#ifndef I_RESPONSE_HANDLER_H
#define I_RESPONSE_HANDLER_H

#include <iostream>
#include <memory>
#include <vendors/nlohmann/json.hpp>

// https://developer.mozilla.org/es/docs/Web/HTTP/Status
class ResponseHandler
{
    private:
        bool errorStatus;
        // std::string message;
        // nlohmann::json data;

    public:   
        // ResponseHandler()
        // {
        //    this->errorStatus = false;
        //    this->message = "Ok"; 
        // }

        // void setErrorStatus(bool errorStatus)
        // {
        //     this->errorStatus = errorStatus;
        // }
        
        // void setErrorMessage(std::string message)
        // {
        //     this->message = message;
        // }

        // virtual void setData(nlohmann::json data)
        // {
        //     this->data = data;
        // }

        virtual void handle(nlohmann::json responseData)
        {
            std::cout << "Content-type:application/json; charset=utf-8\r\n\r\n";
            std::cout << responseData;
        }
};
#endif // I_RESPONSE_HANDLER_H
