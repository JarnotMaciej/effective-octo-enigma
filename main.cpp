// Google Test
#include <gtest/gtest.h>

// C++
//#include <iostream>

// asset manager
#include "interface/assetManager.h"

// Header files
// structures
#include "structures/tamagotchi.h"
// mechanics
#include "mechanics/tamagotchiMechanics.h"

// interface
#include "interface/menu/button.h"
#include "interface/tamagotchiScreen/indicator.h"
#include "interface/menu/programLogo.h"

using namespace sf;

int main()
{
	// Google Test initialization in new thread
	std::thread t([]
	{ testing::InitGoogleTest(); });

	// Tamagotchi
	tamagotchi myTamagotchi("Tamagotchi");
	//getting time test
	std::cout << getTime() << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(2));

	std::cout << getTime() << std::endl;
	tamagotchiMechanics::saveTamagotchi(myTamagotchi);
	// creating instance of asset manager
	assetManager manager;
/*
	// create window
	RenderWindow window(VideoMode(1536, 1024), "Tamagotchi");
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	// button
	button myButton("siema");
	float healthValue = 100;
	// health indicator
	indicator health("Health", Color::Red, healthValue);
	health.setPosition(20, 100);

	// logo
	programLogo myLogo;

	// testin
	sf::Text indicatorText;
	sf::Font font = assetManager::getFont("silkscreen");
	indicatorText.setFont(font);
	indicatorText.setString("siema");
	indicatorText.setCharacterSize(20);
	indicatorText.setFillColor(sf::Color::White);

	// indicator text position
	indicatorText.setOrigin(0, 0);
	indicatorText.setPosition(0, 0);



//logo
//    programLogo myLogo;

	// main loop
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
				break;
			}
		}

		window.clear();

//        myButton.draw(window);
//        myLogo.draw(window);
		health.update(healthValue);
		health.draw(window);
		healthValue -= 1;
		if (healthValue < 1)
		{
			healthValue = 100;
		}

		// testin
//        window.draw(indicatorText);


		window.display();

	}
*/

	// Google Test run
	t.join();
	return RUN_ALL_TESTS();
}
