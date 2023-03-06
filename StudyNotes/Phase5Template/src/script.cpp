/**
 * @author AaronLi
 * @date 2023-03-05-下午9:52
 * @license GPL-3.0
 */
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include "script.hpp"

int Script01(){
    char data[100000];
    std::ifstream infile;
    infile.open("data.txt");
    if(!infile){
        std::cerr<<"ERROR. The file don't open"<<std::endl;
        return -1;
    }
    while (infile.getline(data, 100)) {
        std::cout << data << std::endl;
    }
    infile.close();

    std::string string_data=data;

    std::regex regex_data("[0-9a-z_-]");
    std::smatch result;
    regex_search(string_data, result, regex_data);

    std::cout<<"String that matches the pattern:"<<std::endl;
    for (auto x : result)
        std::cout << x << " ";
    return 0;
}