#pragma once
#include "generic_player.h"
class House : public GenericPlayer
{
public:
	House(const std::string& name = "House");
	virtual ~House();
	virtual bool IsHitting() const;
	void FlipFirstCard();
};

