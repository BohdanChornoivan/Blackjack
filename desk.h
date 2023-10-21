#pragma once
#include "hand.h"
#include "generic_player.h"
#include <vector>
#include "card.h"

class Desk : public Hand
{
public:
	Desk();
	virtual ~Desk();
	void Populate();
	void Shuffle();
	void Deal(Hand& aHand);
	void AdditionalCards(GenericPlayer& aGenericPlayer);
protected:
	std::vector<Card*> DeckRelease;
};

