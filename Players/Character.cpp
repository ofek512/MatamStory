#include "Character.h"


void Responsible::buyPotion(Player& player) {
    while(player.getCoins() > 0 && player.getHealthPoints() != player.getMax_HP()){
        player.setCoins(player.getCoins() - 5);
        player.setCurrent_HP(player.getHealthPoints() + 10);
    }
}