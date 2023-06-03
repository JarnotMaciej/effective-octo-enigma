//
// Created by menox on 03.06.2023.
//

#ifndef TAMAGOTCHI_MINIGAMECONNECTOR_H
#define TAMAGOTCHI_MINIGAMECONNECTOR_H


class minigameConnector {
private:
    int coinsValue; // coins value

public:
    /**
     * @brief Constructor
     */
    minigameConnector();

    /**
     * @brief Sets coinsValue
     * @param coinsValueToSet coinsValueToSet to set
     */
    void setCoinsValue(int coinsValueToSet);

    /**
     * @brief Gets coinsValue
     * @return coinsValue
     */
    int getCoinsValue() const;
};


#endif //TAMAGOTCHI_MINIGAMECONNECTOR_H
