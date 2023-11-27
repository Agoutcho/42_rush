#include "Bullet.h"

Bullet::Bullet() : _colorForeground(COLOR_MAGENTA), _colorBackground(COLOR_BLACK)
{
}

Bullet::~Bullet()
{
}

void	Bullet::move()
{
	_rx += _vx;
	_ry += _vy;
	_x = _rx;
	_y = _ry;
}

int		Bullet::getX()
{
	return (_x);
}

int		Bullet::getY()
{
	return (_y);
}

int		Bullet::getId()
{
	return (_id);
}

int		Bullet::getDamage()
{
	return (_damage);
}


void	Bullet::display()
{
	std::stringstream ss;
    ss << _colorBackground << _colorForeground << _char << RESET;
	init_pair(2, _colorForeground, _colorBackground);
    attron(COLOR_PAIR(1));
    mvprintw(_x,_y, _char.c_str());
    attroff(COLOR_PAIR(1));
    // mvprintw(_x,_y, ss.str().c_str());
	// mvprintw(_x, _y, "%c%c%c",_colorBackground, _colorForeground, _char);
}