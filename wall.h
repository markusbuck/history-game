#ifndef WALL_H
#define WALL_H
 #include <QPoint>

class Wall {

public:
    Wall();
    Wall(QPoint p1, QPoint p2, int width);
    QPoint p1;
    QPoint p2;
    int width;
};

#endif // WALL_H
