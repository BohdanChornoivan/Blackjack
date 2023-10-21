#pragma once
#include "generic_player.h"
class Player : public GenericPlayer
{
public:
	Player(const std::string& name = "");
	virtual ~Player();
	virtual bool IsHitting() const;
	void Win() const;
	void Lose() const;
	void Push() const;
};

