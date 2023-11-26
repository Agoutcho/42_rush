#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_

#include <list>

#include "Ship.h"
#include "Bullet.h"


class GameBoard
{
private:
    int                 _id;
    std::list<Ship>     _ShipList;
    std::list<Bullet>   _BulletList;
public:
    GameBoard();
    ~GameBoard();
};


#endif /* _BOARD_H_ */
