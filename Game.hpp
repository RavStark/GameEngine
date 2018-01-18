#pragma once

class Game
{
public:
	enum GameState
	{
		GAME_NONE,
		GAME_MAIN_MENU,
		GAME_STARTED,
		GAME_PAUSED
	};

	Game();
	~Game();
};