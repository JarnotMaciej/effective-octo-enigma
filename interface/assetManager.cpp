//
// Created by menox on 05.05.2023.
//

#include "assetManager.h"

assetManager &assetManager::getInstance() {
    static assetManager instance; // lazy initialization
    return instance;
}

sf::Texture &assetManager::getTexture(const std::string &id) {
    auto iter = m_textures.find(id);
    if (iter == m_textures.end()) {
        std::unique_ptr<sf::Texture> texture(new sf::Texture());
        // Getting the path
        std::filesystem::path path = std::filesystem::current_path().parent_path() / "resources" / "textures" / (id + ".png");
        if (!texture->loadFromFile(path.string())) {
            // Handle error
            return *m_defaultTexture;
        }
        iter = m_textures.emplace(id, std::move(texture)).first;
    }
    return *iter->second;
}

sf::SoundBuffer &assetManager::getSound(const std::string &id) {
    auto iter = m_sounds.find(id);
    if (iter == m_sounds.end()) {
        std::unique_ptr<sf::SoundBuffer> sound(new sf::SoundBuffer());
        std::filesystem::path path = std::filesystem::current_path().parent_path() / "resources" / "sounds" / (id + ".wav");
        if (!sound->loadFromFile(path.string())) {
            // Handle error
            return *m_defaultSound;
        }
        iter = m_sounds.emplace(id, std::move(sound)).first;
    }
    return *iter->second;
}

sf::Font &assetManager::getFont(const std::string &id) {
    auto iter = m_fonts.find(id);
    if (iter == m_fonts.end()) {
        std::unique_ptr<sf::Font> font(new sf::Font());
        std::filesystem::path path = std::filesystem::current_path().parent_path() / "resources" / "fonts" / (id + ".ttf");
        if (!font->loadFromFile(path.string())) {
            // Handle error
            return *m_defaultFont;
        }
        iter = m_fonts.emplace(id, std::move(font)).first;
    }
    return *iter->second;
}
