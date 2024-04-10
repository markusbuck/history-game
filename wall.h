#ifndef WALL_H
#define WALL_H
 #include <QPoint>

class Wall {
private:
    QPoint p1;
    QPoint p2;

    int width;
public:
    Wall(QPoint p1, QPoint p2);
};

#endif // WALL_H
