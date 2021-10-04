/**
* Copyright (c) 2016-2019 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of API-CPP-SET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#ifndef COPONENT_FACTORY_H
#define COPONENT_FACTORY_H

#include <iostream>
#include <stdlib.h>
#include <memory>
#include <typeinfo>
#include <cppset/LibraryLoader.h>
#include <cppset/IniReader.h>

class ComponentFactory
{
    private:
        std::shared_ptr<LibraryLoader> loader;
        std::string componentsPath;
        
    public:
        ComponentFactory()
        { 
            //THE LOADER: // carga el puntero inteligente sobre la libreria
            this->loader = std::make_shared<LibraryLoader>();
            //INIREADER: // inicializa un nuevo reader
            std::shared_ptr<IniReader> iniReader( new IniReader() );
            iniReader->open("configuration.ini"); // lo abre
            this->componentsPath = iniReader->selectSection("GENERAL")->getValue("componentsPath"); // vincula el path
        }
        virtual ~ComponentFactory() //libera la libreria el destructor
        {
            this->loader->freeLibrary();
        }
        
        template<typename InterfaceType> std::shared_ptr<InterfaceType> create(std::string componentName) // crea el nombre del componente
        {
            //LOAD: //carga el path mas el nombre del componente en un puntero
            void* load = this->loader->loadLibrary(this->componentsPath + componentName);

            //NULL COMPONENT OBJECT:
            std::shared_ptr<InterfaceType> componentObject = nullptr;
            if(load) // su esta cargando..
            {
                //CREATE: llama a una funcion externa de crear y el puntero lo vincula con un string
                typedef std::shared_ptr<InterfaceType> ( *Factory ) (std::string);
                Factory factory = ( Factory ) this->loader->getExternalFunction( "create" );

                if(factory)
                {
                    //dice si el componente creado esta igualado con el nombre id  
                    std::shared_ptr<InterfaceType> createdComponent = factory(typeid(InterfaceType).name());//construyo una sola vez
                    if( std::dynamic_pointer_cast<InterfaceType> (createdComponent) != nullptr )
                    {   // si  el componente no esta vacio, se iguala el objeto con el componente creado
                        componentObject = createdComponent;
                    }
                    else
                    {
                        this->loader->freeLibrary(); // si no cumple la condicion muestra mensaje de error
                        std::cout << "Error: The component doesn't implement the interface: " << typeid(InterfaceType).name() << std::endl;
                        exit(-1);
                    }
                }
                else
                {
                    this->loader->freeLibrary();
                    std::cout << "Error:  Failed creating a component from "
                            << componentName << ", there is no external function \"create(void)\"." << std::endl;
                    exit(-1);
                }
            }
            else
            {
                this->loader->freeLibrary();
                std::cout << "Error: Failed to load the component: " << componentName << std::endl;
                exit(-1);
            }
            return componentObject; // retorna el objeto creado
        }
};
#endif // COPONENT_FACTORY_H
