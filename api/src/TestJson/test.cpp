/**
* Copyright (c) 2016 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved.
* This file is part of API-CPP-SET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#include <string>
#include <iostream>
#include <fstream>

#include <vendors/nlohmann/json.hpp>
using json = nlohmann::json;

int main()
{
    // create a JSON object
    //~ nlohmann::json j =
    //~ {
        //~ {"pi", 3.141},
        //~ {"happy", true},
        //~ {"name", "Niels"},
        //~ {"nothing", nullptr},
        //~ {
            //~ "answer", {
                //~ {"everything", 42}
            //~ }
        //~ },
        //~ {"list", {1, 0, 2}},
        //~ {
            //~ "object", {
                //~ {"currency", "USD"},
                //~ {"value", 42.99}
            //~ }
        //~ }
    //~ };

    // add new values
    //~ j["new"]["key"]["value"] = {"another", "list"};

    // count elements
    //~ auto s = j.size();
    //~ j["size"] = s;

    // pretty print with indent of 4 spaces
    //~ std::cout << std::setw(4) << j << '\n';


    // deserialize from standard input
    //~ nlohmann::json j;
    //~ std::cin >> j;

    // serialize to standard output
    //~ std::cout << j;

    // the setw manipulator was overloaded to set the indentation for pretty printing
    //~ std::cout << std::setw(4) << j << std::endl;

    // read a JSON file
    std::ifstream i("./example.json");
    json j;
    i >> j;
    std::cout << std::setw(4) << j << std::endl;

    // write prettified JSON to another file
    std::ofstream o("./pretty.json");
    o << std::setw(4) << j << std::endl;

    std::cout << "" << std::endl;
    std::cout << "RESULT:" << std::endl;
    std::cout << "\t\tTEST JSON FILE OK!!!!!" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "" << std::endl;
    std::cout << "STANDARD INPUT JSON:" << std::endl;
    // deserialize from standard input
    json j2;
    try
    {
        std::cin >> j2; 
        std::cout << std::setw(4) << j2 << std::endl; 
        std::cout << "\t\tTEST JSON STANDARD INPUT OK!!!!!" << std::endl;        
    }
    catch(json::exception& e)
    {
        std::cout << "\t\tTEST JSON STANDARD INPUT FAIL, INCORRECT FORMAT!!!!!" << std::endl;
        // output exception information
        std::cout << "message: " << e.what() << '\n'
                  << "exception id: " << e.id << std::endl;
    }

    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    return 0;
}