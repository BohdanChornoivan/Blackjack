#include "card.h"

Card::Card(rank r, suit s, bool ifu) :
	m_Rank(r),
	m_Suit(s),
	m_IsFaceUp(ifu)
{}

std::ostream& operator<<(std::ostream& os, Card& aCard)
{}

int Card::GetValue() const
{
	int value = 0;
	if (m_IsFaceUp)
	{
		value = m_Rank;

		if (value > 10)
		{
			value = 10;
		}
	}
	return 0;
}

void Card::Flip() {
	m_IsFaceUp = !(m_IsFaceUp);
}