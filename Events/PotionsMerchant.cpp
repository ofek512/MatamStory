#include "PotionsMerchant.h"

void PotionsMerchant::runEvent(shared_ptr<Player> player) {
    player->getCharacter()->buyPotion(player);
}