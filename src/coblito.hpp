/*
 * Copyright (c) ghgltggamer 2025
 * Written by ghgltggamer on Jan 3 2025
 * Coblito is a simple and lightweight AUR Helper written in C++ for promoting the simplicity and Open-Source software
 * No shady data collection practices are involved
 * Licensed under the MIT License
 * Must checkout the README.md file for more information
*/

// Source starts from here
// This is the Coblito header for downloading packages and other main functionality

// #include <cstddef>
#include <cstddef>
#ifndef COBLITO
#define COBLITO 67796676738479 // Coblito is defined as its ASCII Values

// Including the C++ STL
#include <iostream>
#include <string>
// #include <vector>
#include <fstream>
#include <limits.h>
#include <unistd.h>  // For Unix-like systems
#include <filesystem> // For std::filesystem::path

class coblito {
public:
    // Get the path to the executable directory (without the executable name)
    std::string path_to_bin() {
        char result[PATH_MAX];
        ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
        if (count == -1) {
            return "Error: Unable to determine the executable path.";
        }
        std::string full_path(result, count);
        // Use std::filesystem to extract the directory part of the path
        return std::filesystem::path(full_path).parent_path().string();
    }

    // Add To Dataset function will add the package name into the Coblito dataset which is your own private dataset used by coblito.
    void add_to_dataset(std::string package_name){
        std::ifstream ds_ifile(path_to_bin() + "/pckg.cobds");
        std::string file_content, temp;
        if (ds_ifile.is_open()){
            while (std::getline(ds_ifile, temp)){
                file_content += temp + "\n";
            }
        }
        std::ofstream ds_ofile(path_to_bin() + "/pckg.cobds");
        ds_ofile<<package_name<<"\n"<<file_content;
    }

    // Install function for downloading and building AUR package
    void install(const std::string& package_name) {
        std::cout << "Cleaninf the pckg...\n";
        std::system("rm -rf pckg");
        std::cout<<"making pckg...\n";
        std::system("mkdir pckg");
        std::cout<<"Trying to install the package...\n";
        std::system(std::string("git clone https://aur.archlinux.org/" + package_name + ".git " + path_to_bin() + "/pckg").c_str());
        std::cout << "Trying to build the package...\n";
        std::system(std::string("cd " + path_to_bin() + "/pckg/\nmakepkg -ci").c_str());
        // std::cout<<"path : "<<std::string("makepkg -ci " + path_to_bin() + "/pckg/")<<"\n";
        std::cout<<"Do you want to keep the package name in dataset ? (y for yes) : ";
        char p;
        std::cin>>p;
        if (p == 'y' or p == 'Y'){
            std::cout<<"Updating the dataset...\n";
            add_to_dataset(package_name);
        }
        std::cout << "The process was finished.\n";
    }

    // Find function will find the package if available in dataset
    void find(std::string package_name){
        std::ifstream ds_ifile(path_to_bin() + "/pckg.cobds");
        std::string file_content, temp;
        bool package_found = false;
        if (ds_ifile.is_open()){
            while (std::getline(ds_ifile, temp)){
                if (temp.find(package_name) != std::string::npos) {
                    package_found = true;
                    break;
                }
            }
        }
        else {
            std::cout<<"Error : No Dataset was found!\nDo you want to create a new dataset ? (y for yes) : ";
            std::string conf;
            std::cin>>conf;
            if (conf == "y" or conf == "Y"){
                std::ofstream ds_ofile(path_to_bin() + "/pckg.cobds");
                std::cout<<"An empty dataset was created!\n";
            }
            else  std::cout<<"Leaving with no dataset, Note the dataset will be automatically created when install a package\n";
        }
        // std::ofstream ds_ofile(path_to_bin() + "/pckg.cobds");
        // ds_ofile<<package_name<<"\n"<<file_content;
        if (package_found) std::cout<<"The package named <"<<package_name<<"> was found in installations\n";
        else std::cout<<"The package named <"<<package_name<<"> was not found in installations\n";
    }

    // Clean function willl clean the entire dataset
    void clean(){
        std::cout<<"This will wipe your entire dataset means that later you will lost the find and out functionality or any functionality of Coblito associeated with older packages of this dataset!\nSo do you still want to continue ? This is critical (y for yes) : ";
        char i;
        std::cin>>i;
        if (i == 'y' or i == 'Y') std::ofstream ds_ofile(path_to_bin() + "/pckg.cobds");
        else std::cout<<"The operation was cancled!\n";
    }

    // Show installed packages function will show the list of all the installed packages
    void list(){
        std::ifstream ds_ifile(path_to_bin() + "/pckg.cobds");
        std::string file_content, temp;
        if (ds_ifile.is_open()){
            for (size_t i = 1;std::getline(ds_ifile, temp);i++) std::cout<<" ["<<i<<"] "<<temp<<"\n";
        }
    }

    // Show version information
    std::string version = "coblito 1.0 community\n";

    // Show help documentation
    void help() {
        std::cout << "Coblito - Docs :-\n"
                  << "1> --help : This command will open the documentation for help\n"
                  << "2> --version : This command will show the coblito version you are using\n"
                  << "3> -S [package name] : This command will install the package from AUR as per the given name\n"
                  << "4> install [package name] : This command will work same as -S would work\n"
                  << "5> -Q [package name] : This command will check package installation status\n"
                  << "6> check [package name] : This command will work same as -Q would work\n"
                  << "7> -l : This command will show the list of all the installed packages\n"
                  << "8> list : This command will work same as -l would work\n"
                  << "9> -c : This command will clean or wipe the entire dataset resulting in not mentioning older packages of dataset when using any command relies on dataset\n"
                  << "0> clear : This command will work same as -c would work\n"
                  << "11> clean : This command will work same as -c would work\n"
                  << "12> version : This command will work same as --version would work\n"
                  << "13> -v : This command will work same as --version would work\n"
                  << "14> -h : This command will work same as --help would work\n"
                  << "15> help : This command will work same as --help would work\n"
                  << " -- Package removal -- : Use pacman for removing the package\n"
                  << "---- end ----\n";
    }
};

#endif

// The program was finished on same day