/**
* Copyright (c) 2019 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of API-CPP-SET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/
//archivo cpp que se vincula con las peticiones y respuestas del servicio
#include <iostream>
#include <memory>
#include <cppset/IService.h>
#include <cppset/ResponseHandler.h>

class TestService : public IService
{
    private:
    //atributo con datos json y puntero inteligente para el handler.
        nlohmann::json data;
        std::shared_ptr<ResponseHandler> responseHandler;

        //SERVICES ACTIONS: // acciones que llamara el servicio
        void create()
        {
            std::string service = this->data["service"]; // vincula el string servicio con los datos json para que retorne la respuesta como un string
            nlohmann::json responseData = {
                            {"error_status", false},
                            {"message", "Create OK"},
                            {"data",{ 
                                {"service", this->data["service"]},
                                {"message","¡Create Method!"}
                            }}
                        };
            this->responseHandler->handle(responseData);
        }

        void read()
        {
            std::string service = this->data["service"];
            nlohmann::json responseData = {
                            {"error_status", false},
                            {"message", "Read OK"},
                            {"data",{ 
                                {"service", this->data["service"]},
                                {"message","¡Read Method!"}
                            }}
                        };
            this->responseHandler->handle(responseData);
        }

        void update()
        {
            std::string service = this->data["service"];
            nlohmann::json responseData = {
                            {"error_status", false},
                            {"message", "Update OK"},
                            {"data",{ 
                                {"service", this->data["service"]},
                                {"message","¡Update Method!"}
                            }}
                        };
            this->responseHandler->handle(responseData);
        }

        void del()
        {
            std::string service = this->data["service"];
            nlohmann::json responseData = {
                            {"error_status", false},
                            {"message", "Delete OK"},
                            {"data",{ 
                                {"service", this->data["service"]},
                                {"message","¡Delete Method!"}
                            }}
                        };
            this->responseHandler->handle(responseData);
        }

    public:
        TestService()
        {
            this->responseHandler = std::make_shared<ResponseHandler>();
        }

        void call(nlohmann::json data) // metodo que llama de forma multiple con parametro json a las otras acciones_metodos
        {
            this->data = data;
            std::string action = this->data["action"];
            if(action == "create") this->create();
            if(action == "read") this->read();
            if(action == "update") this->update();
            if(action == "del") this->del();
        }
};

extern "C" std::shared_ptr<IService> create(std::string); // codigo en base de C para verificar si el nombre del servicio es igual al que pase, sino te devuelve un null

std::shared_ptr<IService> create(std::string typeinfo)
{
    return ( typeid(IService).name() == typeinfo )? std::make_shared<TestService>() : nullptr;
}
