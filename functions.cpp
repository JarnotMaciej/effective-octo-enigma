//
// Created by menox on 08.04.2023.
//

#include "functions.h"


void debug(const std::string& text)
{
//    std::cout << "\t[DEBUG] " << text << std::endl;
}
bool nameValidation(const std::string& name)
{
//	std::regex nameRegex("[a-zA-Z]+");
    std::regex nameRegex("[a-zA-Z]{1,32}");
    return std::regex_match(name, nameRegex);
}

bool deadTamagotchiValidation(const std::string &name) {
    std::regex nameRegex("[a-zA-Z]{1,32}.dtf");
    return std::regex_match(name, nameRegex);
}
