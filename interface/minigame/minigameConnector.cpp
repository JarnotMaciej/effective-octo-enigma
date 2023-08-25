#include "minigameConnector.h"

minigameConnector::minigameConnector() : coinsValue(0) {}

void minigameConnector::setCoinsValue(int coinsValueToSet) {
    coinsValue = coinsValueToSet;
}

int minigameConnector::getCoinsValue() const {
    return coinsValue;
}
