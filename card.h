#pragma once
#include <iostream>

class Card
{
	friend std::ostream& operator<<(std::ostream& os, Card& aCard);
public:
	enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
	JACK, QUEEN, KING};
	enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};
	Card(rank r = ACE, suit s = CLUBS, bool ifu = true);
	int GetValue() const;
	void Flip();
private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

