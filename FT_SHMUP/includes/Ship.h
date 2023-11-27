#ifndef _SHIP_H_
#define _SHIP_H_

#include <sstream>
#include <list>
#include <array>

#include "ft_shmup.h"
#include "GameBoard.h"

#define RESET ("\033[0m")
#define PLAYER 0
#define BASIC_ENNEMY 1
#define MEDIUM_ENNEMY 2
#define LARGE_ENNEMY 3

class Ship
{
private:
    int                 _life;
    int                  _type;
	int					_id;
    std::string         _char;
    int                 _colorForeground;
    int                 _colorBackground;
    std::list<std::array<int, 2> >   _hitBox;
    float				_rx;
    float				_ry;
    int					_x;
    int					_y;
    float				_vx;
    float				_vy;
	int					_scorePoint;
public:
    Ship();
    ~Ship();

    void setLife(int life);
    void setType(int type);
    void setChar(std::string val);
    void setColorForeground(int color);
    void setColorBackground(int color);
    void setPos(int x, int y);
    void setPos2(int x, int y);
    void setId(int id);
	void moveLeft();
	void moveRight();
	void move();
	int getX();
	int getY();
	int getId();
	std::list<std::array<int, 2> > getHitBox();
	int getLife();
	int getScorePoint();
	void display();
};

#endif /* _SHIP_H_ */


