#include "assetManager.h"

namespace fs = std::filesystem;
using namespace sf;

assetManager* assetManager::instance = nullptr;

assetManager::assetManager()
{
	// allow only one instance of asset manager
	if (instance != nullptr)
	{
		throw std::runtime_error("Asset manager already exists");
	}
	instance = this;
}

sf::Texture assetManager::getTexture(const std::string& name)
{
	auto& textures = instance->textures; // get textures from instance

	// see if texture is already loaded
	auto keyValuePair = textures.find(name);
	if (keyValuePair != textures.end())
	{
		return keyValuePair->second;
	}
	else
	{
		// get path to texture
		fs::path texturePath = fs::current_path().parent_path() / "resources" / "textures" / (name + ".png");

		// load texture
		if (!textures[name].loadFromFile(texturePath.string()))
		{
			throw std::runtime_error("Texture not found: " + texturePath.string());
		}

		return textures[name];
	}
}

sf::Font assetManager::getFont(const std::string& name)
{
	auto& fonts = instance->fonts; // get fonts from instance

	// see if font is already loaded
	auto keyValuePair = fonts.find(name);
	if (keyValuePair != fonts.end())
	{
		return keyValuePair->second;
	}
	else
	{
		// get path to font
		fs::path fontPath = fs::current_path().parent_path() / "resources" / "fonts" / (name + ".ttf");

		// load font
		if (!fonts[name].loadFromFile(fontPath.string()))
		{
			throw std::runtime_error("Font not found: " + fontPath.string());
		}

		return fonts[name];
	}
}
