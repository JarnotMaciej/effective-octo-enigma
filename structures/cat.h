//
// Created by menox on 03.05.2023.
//

// C++

// headers
#include "../structures/tamagotchi.h"

#ifndef PROJECT_NAME_CAT_H
#define PROJECT_NAME_CAT_H

/**
 * @brief Cat class
 */
class cat : public tamagotchi{
public:
    /**
     * @brief Method used for meowing
     */
    static void meow();

    /**
     * @brief Method used for getting tamagotchi type
     */
    tamagotchiType getTamagotchiType() override {return tamagotchiType::CAT;}
};


#endif //PROJECT_NAME_CAT_H
