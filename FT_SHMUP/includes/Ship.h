#ifndef _SHIP_H_
#define _SHIP_H_

#include "ft_shmup.h"

class Ship
{
private:
    int             _life;
    std::string     _char;
    std::string     _colorForeground;
    std::string     _colorBackground;
    int             _point;
    int             _x;
    int             _y;
public:
    Ship();
    ~Ship();
};

#endif /* _SHIP_H_ */
