#include "hand.h"

Hand::Hand()
{
	m_Cards.reserve(7);
}

Hand::~Hand()
{
	m_Cards.clear();
}

void Hand::Add(Card* card)
{
	m_Cards.push_back(card);
}

void Hand::GetClear()
{
	std::vector<Card*>::iterator iter = m_Cards.begin();
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		delete* iter;
		*iter = 0;
	}
	m_Cards.clear();
}

int Hand::GetTotal() const
{
	if (m_Cards.empty())
	{
		return 0;
	}

	if (m_Cards[0]->GetValue() == 0)
	{
		return 0;
	}

	int total = 0;

	std::vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		total += (*iter)->GetValue();
	}

	bool containsAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		if ((*iter)->GetValue() == Card::ACE)
		{
			containsAce = true;
		}
	}

	if (containsAce && total <= 10)
	{
		total += 10;
	}
	return total;
}