#include "level.h"

Level::Level(QVector<Wall> walls, QVector<Door> doors, Player player)
{
	this->walls = walls;
	this->doors = doors;
	this->player = player;
}

bool Level::isCollidingWall()
{
	for (Wall wall : this->walls)
	{
		// QPoint p1;
		// QPoint p2;

		// if(wall.p1.x() < wall.p2.x() || (wall.p1.y() < wall.p2.y())) {

		//     p1 = wall.p1;
		//     p2 = wall.p2;
		// }

		// else {

		//     p1 = wall.p2;
		//     p2 = wall.p1;
		// }

		// if(p1.x() - wall.width - this->player.hitBox.width < this->player.location.x()) {
		// if(p1.x() - wall.width - this->player.hitBox.width < this->player.location.x() && this->player.location.x() << p2.x() + wall.width + this->player.hitBox.width
		//     && p1.y() - wall.width - this->player.hitBox.width < this->player.location.y()) {

		//     return true;
		// }

		// if (p1.GetX() - wallWidth - snakeWidth < snakeHeadX && snakeHeadX < p2.GetX() + wallWidth + snakeWidth
		//     && p1.GetY() - wallWidth - snakeWidth < snakeHeadY && snakeHeadY < p2.GetY() + wallWidth + snakeWidth)
		// {

		return false;
	}
}
