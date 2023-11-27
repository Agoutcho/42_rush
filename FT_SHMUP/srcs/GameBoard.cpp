#include "GameBoard.h"
#include "ft_shmup.h"

extern volatile __sig_atomic_t toStop;

GameBoard::GameBoard() : _cols(SIZE_X), _rows(SIZE_Y), win(0)
{
}

GameBoard::~GameBoard()
{
    if (!isendwin())
    {
        endwin();
    }
    if (win)
        delwin(win);
    resetTerminal();
}

void GameBoard::init()
{
    resizeTerm();
    srand(time(NULL));
    win = initscr();
    start_color();
    if (noecho() == -1)
        std::cerr << "error" << std::endl;
    if (cbreak() == -1)
        std::cerr << "error" << std::endl;
    // if (nodelay(win, true) == -1)
    //     std::cerr << "error" << std::endl;
    timeout(1);
    clear();
    refresh();
    box(win, ACS_VLINE, ACS_HLINE);
    _players.push_back(genPlayers(SIZE_X - 5, SIZE_Y / 2));
}

void GameBoard::resizeTerm() const
{
    std::stringstream ss;
    ss << "resize -s ";
    ss << SIZE_Y << " " << SIZE_X;
    nocbreak();
    system(ss.str().c_str());
}

Ship	GameBoard::genBoss(int x, int y)
{
    Ship res;

    res.setPos(x, y);
    res.setColorForeground(COLOR_RED);
    return res;
}

Ship	GameBoard::genEnemies(int x, int y)
{
    Ship res;

    res.setPos(x, y);
    return res;
}

Ship	GameBoard::genPlayers(int x, int y)
{
    Ship res;

    res.setPos(x, y);
    res.setPos2(x, y);
    res.setChar("V");
    res.setColorForeground(COLOR_GREEN);
    res.setColorBackground(COLOR_WHITE);
    res.setId(0);
    res.setType(PLAYER);
    return res;
}

void	GameBoard::generation(int frameCount)
{
	if (frameCount == 1000)
	{
		_enemies.push_front(genBoss(SIZE_X / 2, 0));
	}
	else if (frameCount == 10)
	{
		for(int i = 0; i < SIZE_X; i++)
		if (rand() % 10 < 5)
			_enemies.push_front(genEnemies(i, 0));
	}
}

void	GameBoard::displayBoard()
{
	std::list<Bullet>::iterator	bulletIt;
	for (bulletIt = _bullets.begin(); bulletIt != _bullets.end(); bulletIt++)
	{
		bulletIt->display();
	}
	std::list<Ship>::iterator	shipIt;
	for (shipIt = _enemies.begin(); shipIt != _enemies.end(); shipIt++)
	{
		shipIt->display();
	}
	for (shipIt = _players.begin(); shipIt != _players.end(); shipIt++)
	{
		shipIt->display();
	}
	refresh();
}

int GameBoard::checkPlayerLife()
{
	std::list<Ship>::iterator	player;
	for (player = _players.begin(); player != _players.end(); player++)
	{
		if((*player).getLife() < 0)
			return 1;
	}
	return 0;
}

void	GameBoard::resolveKey(char c)
{
	// Ship player;
	switch(c)
	{
		case 'a':
			// player = _players.front();
			// player.moveLeft();
            _players.front().moveLeft();
			break;
		case 'd':
			// player = _players.front();
			// player.moveRight();
            _players.front().moveRight();
			break;
	}
}

void	GameBoard::run()
{
	size_t frameCount = 0;
	while (!toStop)
	{
        clear();
		while(kbhit())
			resolveKey(getch());
		updateBoard();
		if (checkPlayerLife())
			break;
		displayBoard();
		frameCount++;
	}
}

void	GameBoard::updateBoard()
{
	std::list<Bullet>::iterator	*hitMap[2][_cols][_rows];

	std::list<Bullet>::iterator	bulletIt;
	for (bulletIt = _bullets.begin(); bulletIt != _bullets.end(); bulletIt++)
	{
		Bullet b = *bulletIt;
		b.move();
		if (b.getX() < 0 || b.getX() > _cols || b.getY() < 0 || b.getY() > _rows)
		{
            bulletIt = _bullets.erase(bulletIt);
            bulletIt--;
			continue;
		}
		hitMap[b.getId()][b.getX()][b.getY()] = &bulletIt;
	}

	std::list<Ship>::iterator	shipIt;
	for (shipIt = _enemies.begin(); shipIt != _enemies.end(); shipIt++)
	{
		Ship	e = *shipIt;
		std::list<std::array<int, 2> >	            hitList;
		std::list<std::array<int, 2> >::iterator	hit;
		hitList = e.getHitBox();
		for (hit = hitList.begin(); hit != hitList.end(); hit++)
		{
			int		hx = (*hit)[0] + e.getX();
			int		hy = (*hit)[1] + e.getY();
			if (hx < 0 || hx > _cols || hy < 0 || hy > _rows)
				continue;
			std::list<Bullet>::iterator	*b = hitMap[e.getId()][hx][hy];

			if (b != NULL)
			{
				hitMap[e.getId()][hx][hy] = NULL;
				_bullets.erase(*b);
				e.setLife(e.getLife() - (*b)->getDamage());
				if (e.getLife() >= 0)
				{
                    _score += e.getScorePoint();
					shipIt = _enemies.erase(shipIt);
                    shipIt--;
					break;
				}
			}
		}
		e.move();
	}

	for (shipIt = _enemies.begin(); shipIt != _enemies.end(); shipIt++)
	{
		Ship	e = *shipIt;
		std::list<std::array<int, 2> >	            hitList;
		std::list<std::array<int, 2> >::iterator	hit;
		hitList = e.getHitBox();
		for (hit = hitList.begin(); hit != hitList.end(); hit++)
		{
			int		hx = (*hit)[0] + e.getX();
			int		hy = (*hit)[1] + e.getY();
			if (hx < 0 || hx > _cols || hy < 0 || hy > _rows)
				continue;
			std::list<Bullet>::iterator	*b = hitMap[e.getId()][hx][hy];
			if (b != NULL)
			{
				hitMap[e.getId()][hx][hy] = NULL;
				_bullets.erase(*b);
				e.setLife(e.getLife() - (*b)->getDamage());
				if (e.getLife() >= 0)
				{
					_score += e.getScorePoint();
					shipIt = _enemies.erase(shipIt);
                    shipIt--;
					break;
				}
			}
		}
	}

	for (shipIt = _players.begin(); shipIt != _players.end(); shipIt++)
	{
		int		hx = (*shipIt).getX();
		int		hy = (*shipIt).getY();
		std::list<Bullet>::iterator	*b = hitMap[(*shipIt).getId()][hx][hy];
		if (b != NULL)
		{
			hitMap[(*shipIt).getId()][hx][hy] = NULL;
			_bullets.erase(*b);
			(*shipIt).setLife((*shipIt).getLife() - (*b)->getDamage());
		}
	}
}
