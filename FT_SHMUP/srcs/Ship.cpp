#include "Ship.h"

Ship::Ship() :  _life(1),
                _type(BASIC_ENNEMY),
                _id(1),
                _char("@"),
                _colorForeground(COLOR_BLACK),
                _colorBackground(COLOR_RED),
                _rx(0),
                _ry(0),
                _x(0),
                _y(0),
                _vx(1),
                _vy(1),
	            _scorePoint(0)
{
}

Ship::~Ship()
{
}

void	Ship::move()
{
	_rx += _vx;
	_ry += _vy;
	_x = _rx;
	_y = _ry;
}

void Ship::moveLeft()
{
    _rx -= _vx;
    if (_rx < 0 + 1)
        _rx = 0;
    _x = _rx;
}

void Ship::moveRight()
{
    _rx += _vx;
    if (_rx > SIZE_X - 1)
        _rx = 0;
    _x = _rx;
}

int		Ship::getX()
{
    return (_x);
}

int		Ship::getY()
{
    return (_y);
}

int		Ship::getId()
{
    return (_id);
}

std::list<std::array<int, 2> >	Ship::getHitBox()
{
    return (_hitBox);
}

int		Ship::getLife()
{
    return (_life);
}

int		Ship::getScorePoint()
{
    return (_scorePoint);
}

void	Ship::display()
{
    std::stringstream ss;
    ss << _colorForeground << _char << RESET;
    init_pair(1, _colorForeground, _colorBackground);
    attron(COLOR_PAIR(1));
    mvprintw(_x,_y, _char.c_str());
    attroff(COLOR_PAIR(1));
    // mvprintw(_x, _y, "%c%c%c",_colorBackground, _colorForeground, _char);
}

void Ship::setLife(int life)
{
    _life = life;
}

void Ship::setType(int type)
{
    _type = type;
}

void Ship::setChar(std::string val)
{
    _char = val;
}

void Ship::setColorForeground(int color)
{
    _colorForeground = color;
}

void Ship::setColorBackground(int color)
{
    _colorBackground = color;
}

void Ship::setPos(int x, int y)
{
    _x = x;
    _y = y;
}

void Ship::setPos2(int x, int y)
{
    _rx = x;
    _ry = y;
}


void Ship::setId(int id)
{
    _id = id;
}
