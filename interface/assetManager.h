// SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// C++
#include <map>
#include <memory>
#include <filesystem>

#ifndef TAMAGOTCHI_ASSETMANAGER_H
#define TAMAGOTCHI_ASSETMANAGER_H

class assetManager {
public:
    /**
     * @brief Get instance of assetManager
     * @return instance of assetManager
     */
    static assetManager &getInstance();

    /**
     * @brief Load texture from file
     * @param id - name of the texture and the file
     * @return texture
     */
    sf::Texture &getTexture(const std::string &id);

    /**
     * @brief Load sound from file
     * @param id - name of the sound and the file
     * @param extension - extension of the file
     * @return sound
     */
    sf::SoundBuffer &getSound(const std::string &id, const std::string &extension = "wav");

    /**
     * @brief Load font from file
     * @param id - name of the font and the file
     * @return font
     */
    sf::Font &getFont(const std::string &id);

private:
    /**
     * @brief Default constructor for asset manager
     */
    assetManager() :
            m_defaultTexture(std::make_unique<sf::Texture>()),
            m_defaultSound(std::make_unique<sf::SoundBuffer>()),
            m_defaultFont(std::make_unique<sf::Font>()) {
        // Set default texture to a 1x1 white pixel
        sf::Image img;
        img.create(1, 1, sf::Color::White);
        m_defaultTexture->loadFromImage(img);

        // Set default sound and font to null
        m_defaultSound = nullptr;
        m_defaultFont = nullptr;
    }

    /**
     * @brief Copy constructor for asset manager
     * @param assetManager - asset manager to copy
     * @return asset manager
     */
    assetManager(const assetManager &) = delete;

    /**
     * @brief Assignment operator for asset manager
     * @param assetManager - asset manager to assign
     * @return asset manager
     */
    assetManager &operator=(const assetManager &) = delete;

    std::map<std::string, std::unique_ptr<sf::Texture>> m_textures; // map of textures
    std::map<std::string, std::unique_ptr<sf::SoundBuffer>> m_sounds; // map of sounds
    std::map<std::string, std::unique_ptr<sf::Font>> m_fonts; // map of fonts

    std::unique_ptr<sf::Texture> m_defaultTexture; // default texture
    std::unique_ptr<sf::SoundBuffer> m_defaultSound; // default sound
    std::unique_ptr<sf::Font> m_defaultFont; // default font
};

#endif //TAMAGOTCHI_ASSETMANAGER_H