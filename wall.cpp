#include "wall.h"

Wall::Wall() {
    this->p1 = QPoint();
    this->p2 = QPoint();
    this->width = 0;
}

Wall::Wall(QPoint p1, QPoint p2, int width) {
    this->width = width;
    this->p1 = p1;
    this->p2 = p2;
}
