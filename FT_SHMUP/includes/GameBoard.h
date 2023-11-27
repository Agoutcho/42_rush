#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_

#include <list>
#include <sstream>

#include "Ship.h"
#include "Bullet.h"
#include "ft_shmup.h"

class Ship;
class Bullet;

class GameBoard
{
private:
    std::list<Ship>		_enemies;
	std::list<Ship>		_players;
	std::list<Bullet>	_bullets;
	int					_score;
	int					_cols;
	int					_rows;
    // std::list<Ship>     _ShipList;
    // std::list<Bullet>   _BulletList;

    void resizeTerm() const;
public:
    WINDOW *win;
    GameBoard();
    ~GameBoard();

    void init();

	void    run();
	Ship	genBoss(int x, int y);
	Ship	genEnemies(int x, int y);
    Ship	genPlayers(int x, int y);
	void	generation(int frameCount);
	void    displayBoard();
	int     checkPlayerLife();
	void    resolveKey(char c);
	void    updateBoard();
};


#endif /* _BOARD_H_ */
