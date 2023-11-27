#ifndef _BULLET_H_
#define _BULLET_H_

#include "ft_shmup.h"

class Bullet
{
private:
	int				_id;
	int				_damage;
	std::string		_char;
	int				_colorForeground;
	int				_colorBackground;
	float			_rx;
	float			_ry;
	int				_x;
	int				_y;
	float			_vx;
    float			_vy;
public:
	Bullet();
	~Bullet();

	void	move();

	int		getX();

	int		getY();

	int		getId();

	int		getDamage();

	void	display();
};

#endif /* _BULLET_H_ */
