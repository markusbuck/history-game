#include "player.h"


Player::Player() {
    this->location = QPoint();
}

Player::Player(QPoint location) {
    this->location = location;
}
