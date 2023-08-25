#include <gtest/gtest.h>
#include "../mechanics/assetManager.h"
#include "SFML/Graphics/Sprite.hpp"

class AssetManagerTest : public ::testing::Test {
protected:
    AssetManagerTest() {
        assetManager::getInstance();
    }
};

TEST(AssetManagerTest, GetTexture) {
    sf::Texture texture = assetManager::getInstance().getTexture("48x16white");
    ASSERT_TRUE(texture.getSize().x == 48);
    ASSERT_TRUE(texture.getSize().y == 16);
}

TEST(AssetManagerTest, GetFont) {
    sf::Font font = assetManager::getInstance().getFont("silkscreen");
    ASSERT_TRUE(font.getInfo().family == "Silkscreen");
}

TEST(AssetManagerTest, GetSound) {
    sf::SoundBuffer soundBuffer = assetManager::getInstance().getSound("gameover", "wav");
    ASSERT_TRUE(soundBuffer.getDuration().asMilliseconds() > 0);
}

TEST(AssetManagerTest, GetInstanceSameReference) {
    assetManager &manager1 = assetManager::getInstance();
    assetManager &manager2 = assetManager::getInstance();
    EXPECT_EQ(&manager1, &manager2);
}

TEST(AssetManagerTest, GetInstanceNotNull) {
    assetManager &manager = assetManager::getInstance();
    EXPECT_NE(&manager, nullptr);
}

