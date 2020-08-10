#include "SocialNetwork.h"

Actor::Actor(std::string name, unsigned int takeOverCost)
	:
	_name(name), _takeOverCost(takeOverCost)
{
}

std::string Actor::getName()
{
	return _name;
}

unsigned int Actor::getTakeOverCost()
{
	return _takeOverCost;
}
