#include "desk.h"
#include <iostream>
#include <algorithm>

Desk::Desk()
{
	m_Cards.reserve(52);
	Populate();
}

Desk::~Desk()
{}

void Desk::Populate()
{
	Clear();
	for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
	{
		for (int r = Card::ACE; r <= Card::KING; ++r)
		{
			Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
		}
	}
}

void Desk::Shuffle()
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Desk::Deal(Hand& aHand)
{
	if (!m_Cards.empty())
	{
		aHand.Add(m_Cards.back());
		DeckRelease.push_back(m_Cards.back());
		m_Cards.pop_back();
	}
	else
	{
		m_Cards = DeckRelease;
		DeckRelease.clear();
		std::cout << "Out of cards. Unable to deal. ";
	}
}

void Desk::AdditionalCards(GenericPlayer& aGenericPlayer)
{
	std::cout << std::endl;

	while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
	{
		Deal(aGenericPlayer);
		std::cout << aGenericPlayer << std::endl;
		if (aGenericPlayer.IsBusted())
		{
			aGenericPlayer.Bust();
		}
	}
}