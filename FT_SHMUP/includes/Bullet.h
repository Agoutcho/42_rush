#ifndef _BULLET_H_
#define _BULLET_H_

#include "ft_shmup.h"

class Bullet
{
private:
    int             _id;
    int             _type;
    std::string     _char;
    std::string     _colorForeground;
    std::string     _colorBackground;
    int             _x;
    int             _y;
public:
    Bullet();
    ~Bullet();
};

#endif /* _BULLET_H_ */
