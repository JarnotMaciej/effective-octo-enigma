//
// Created by menox on 07.04.2023.
//

#ifndef PROJECT_NAME_ASSETMANAGER_H
#define PROJECT_NAME_ASSETMANAGER_H

// SFML
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Font.hpp"

// C++
#include <map>
#include <string>
#include <filesystem>

// Header files

//**
// * @brief Class for asset manager
// */
class assetManager
{
 private:
	std::map<std::string, sf::Texture> textures; // map of textures
	std::map<std::string, sf::Font> fonts; // map of fonts

	static assetManager* instance; // instance of asset manager

 public:
	//**
	// * @brief Default constructor for asset manager
	// */
	assetManager();

	//**
	// * @brief Load texture from asset manager
	// * @param name - name of texture
	// * @return texture
	// */
	static sf::Texture getTexture(const std::string& name);

	//**
	// * @brief Load font from asset manager
	// * @param name - name of font
	// * @return font
	// */
	static sf::Font getFont(const std::string& name);
};

#endif //PROJECT_NAME_ASSETMANAGER_H
