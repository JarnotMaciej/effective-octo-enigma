////
//// Created by menox on 24.04.2023.
////
//
//// Google Test
//#include <gtest/gtest.h>
//
//// AssetManager
//#include "../interface/assetManager.h"
//
//// SFML
//#include "SFML/Graphics/Sprite.hpp"
//
////**
//// * @brief Class for asset manager test
//// */
//class AssetManagerTest : public ::testing::Test
//{
// protected:
//	//**
//	// * @brief Default constructor for asset manager test
//	// */
//	AssetManagerTest()
//	{
//		// Creating instance of asset manager
//		assetManager manager;
//	}
//};
//
//// Test case for texture loading
//TEST(AssetManagerTest, GetTexture)
//{
//	// Load texture
//	sf::Texture texture = assetManager::getTexture("48x16white");
//
//	// Check if texture is loaded
//	ASSERT_TRUE(texture.getSize().x == 48);
//	ASSERT_TRUE(texture.getSize().y == 16);
//}
//
//// Test case for font loading
//TEST(AssetManagerTest, GetFont)
//{
//	// Load font
//	sf::Font font = assetManager::getFont("silkscreen");
//
//	// Check if font is loaded
//	ASSERT_TRUE(font.getInfo().family == "Silkscreen");
//}