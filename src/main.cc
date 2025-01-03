/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer on Jan 3 2025
 * Coblito is a simple and lightweight AUR Helper written in C++ for promoting the simplicity and Open-Source software
 * No shady data collection practices are involved
 * Licensed under the MIT License
 * Must checkout the README.md file for more information
*/

// Source starts from here
#include "coblito.hpp"

int main(int argc, char* argv[]){
    if (argc == 1){
        std::cout<<"Error : Need 1 argument at the least. Please use --help for help.\n";
        std::exit ( 3 );
    }
    // Define a coblito initaliser
    coblito pckg;
    // check the argv then
    std::string arg_string = argv[1];
    if (arg_string == "--help" or arg_string == "-h" or arg_string == "help") pckg.help();
    else if (arg_string == "--version" or arg_string == "-v" or arg_string == "version") std::cout<<pckg.version;
    else if (arg_string == "-l" or arg_string == "list") pckg.list();
    else if (arg_string == "-c" or arg_string == "clean" or arg_string == "clear") pckg.clean();
    else if (arg_string == "-S" or arg_string == "install"){
        if (argc < 3){
            std::cout<<"Error : Need the package name to install it. Please use --help for help.\n";
            std::exit ( 3 );
        }
        arg_string = argv[2];
        pckg.install(arg_string);
    }
    else if (arg_string == "-Q" or arg_string == "check"){
        if (argc < 3){
            std::cout<<"Error : Need the package name to search it. Please use --help for help.\n";
            std::exit ( 3 );
        }
        arg_string = argv[2];
        pckg.find(arg_string);
    }
    else {
        std::cout<<"Error : Invalid command found!\n";
    }
}