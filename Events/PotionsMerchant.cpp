#include "PotionsMerchant.h"

void PotionsMerchant::runEvent(Player& player) {
    player.getCharacter()->buyPotion(player);
}