#include "functions.h"

void debug(const std::string &text) {
    std::cout << "\t[DEBUG] " << text << std::endl;
}

bool nameValidation(const std::string &name) {

    std::regex nameRegex("[a-zA-Z]{1,32}");
    return std::regex_match(name, nameRegex);
}

bool deadTamagotchiValidation(const std::string &name) {
    std::regex nameRegex("[a-zA-Z]{1,32}.dtf");
    return std::regex_match(name, nameRegex);
}

bool scoreLineValidation(const std::string &lineToValidate) {
    std::regex lineRegex("[a-zA-Z]{1,32}\\s\\d{1,}\\s\\d{1,}");
    return std::regex_match(lineToValidate, lineRegex);
}

bool foodConfigValidation(const std::string &lineToValidate) {
    std::regex lineRegex("[a-zA-Z]{1,32}\\s-?\\d+\\s-?\\d+\\s-?\\d+\\s-?\\d+\\s-?\\d+\\s-?\\d+");
    return std::regex_match(lineToValidate, lineRegex);
}

long long int getTime() {

    auto time = std::chrono::system_clock::now();
    auto since_epoch = time.time_since_epoch();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(since_epoch);
    return seconds.count();
}

void setIcon(sf::RenderWindow &window) {
    auto path = std::filesystem::current_path().parent_path().string() + "/resources/icon/cat.png";
    sf::Image icon;
    icon.loadFromFile(path);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}


void setCursor(sf::RenderWindow &window) {
    window.setMouseCursorVisible(false);
}

bool tamagotchiSaveValidation(const std::string &tamagotchiFile) {
    std::regex fileRegex(
            "[0-9]{1}\\n[a-zA-Z]{1,32}\\n\\d{1,3}\\n\\d{1,3}\\n\\d{1,3}\\n\\d{1,3}\\n\\d{1,3}\\n\\d{1,}\\n[0,1]{1}\\n\\d{1,}\\n\\d{1,}\\n\\d{1,}\\n?");
    return std::regex_match(tamagotchiFile, fileRegex);
}

bool foodSaveValidation(const std::string &lineToValidate) {
    std::regex lineRegex("[a-z]{1,}\\s\\d{1,3}");
    return std::regex_match(lineToValidate, lineRegex);
}
