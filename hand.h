#pragma once
#include "card.h"
#include <vector>

class Hand
{
public:
	Hand();
	virtual ~Hand();
	void Add(Card* card);
	void Clear();
	int GetTotal() const;
protected:
	std::vector<Card*> m_Cards;
};