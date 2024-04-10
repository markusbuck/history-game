#include "player.h"


Player::Player() {
    this->location = QPoint();
    this->hitBox = Wall();
}

Player::Player(QPoint location, Wall hitBox) {
    this->location = location;
    this->hitBox = hitBox;
}
