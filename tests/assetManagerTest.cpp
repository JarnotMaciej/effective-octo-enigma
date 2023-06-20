//
// Created by menox on 24.04.2023.
//

// Google Test
#include <gtest/gtest.h>

// assetManager
#include "../mechanics/assetManager.h"

// SFML
#include "SFML/Graphics/Sprite.hpp"

//**
// * @brief Class for asset manager test
// */
class AssetManagerTest : public ::testing::Test {
protected:
    //**
    // * @brief Default constructor for asset manager test
    // */
    AssetManagerTest() {
        // Creating instance of asset manager
        assetManager::getInstance();
    }
};

// Test case for texture loading
TEST(AssetManagerTest, GetTexture) {
    // Load texture
    sf::Texture texture = assetManager::getInstance().getTexture("48x16white");

    // Check if texture is loaded
    ASSERT_TRUE(texture.getSize().x == 48);
    ASSERT_TRUE(texture.getSize().y == 16);
}

// Test case for font loading
TEST(AssetManagerTest, GetFont) {
    // Load font
    sf::Font font = assetManager::getInstance().getFont("silkscreen");

    // Check if font is loaded
    ASSERT_TRUE(font.getInfo().family == "Silkscreen");
}

// Test case for sound loading
TEST(AssetManagerTest, GetSound) {
    // Load sound
    sf::SoundBuffer soundBuffer = assetManager::getInstance().getSound("gameover", "wav");

    // Check if sound is loaded
    ASSERT_TRUE(soundBuffer.getDuration().asMilliseconds() > 0);
}

// GetInstanceSameReference
TEST(AssetManagerTest, GetInstanceSameReference) {
    assetManager &manager1 = assetManager::getInstance();
    assetManager &manager2 = assetManager::getInstance();
    EXPECT_EQ(&manager1, &manager2);
}

// instance is not a nullptr
TEST(AssetManagerTest, GetInstanceNotNull) {
    assetManager &manager = assetManager::getInstance();
    EXPECT_NE(&manager, nullptr);
}

