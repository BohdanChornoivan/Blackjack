#pragma once
#include <vector>
#include <string>
#include "player.h"
#include "desk.h"
#include "house.h"

class Game
{
public:
	Game(const std::vector<std::string>& names);
	~Game();
	void Play();
private:
	Desk m_Desk;
	House m_House;
	std::vector<Player> m_Players;
};