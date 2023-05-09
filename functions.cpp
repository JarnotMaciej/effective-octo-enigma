//
// Created by menox on 08.04.2023.
//

#include "functions.h"


void debug(const std::string& text)
{
    std::cout << "\t[DEBUG] " << text << std::endl;
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
long long int getTime()
{
	// to be more precise, this functions gets time in seconds since 1.1.1970
	auto time = std::chrono::system_clock::now();
	auto since_epoch = time.time_since_epoch();
	auto seconds = std::chrono::duration_cast<std::chrono::seconds>(since_epoch);
	return seconds.count();
}

void setIcon(sf::RenderWindow &window) {
    auto path = std::filesystem::current_path().parent_path().string() + "/resources/icon/tamagotchi.png";
    sf::Image icon;
    icon.loadFromFile(path);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}
