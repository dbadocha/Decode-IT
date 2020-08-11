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

int Actor::addRelation(const std::shared_ptr<Actor> &relation)
{
	_actorsSocialNetwork.push_back(relation);
	return 0;
}

int SocialNetwork::addActor(const std::string name, const unsigned int takeOverCost)
{
	Actor newActor(name, takeOverCost);
	_socialNetwork.emplace(name, std::make_shared<Actor>(newActor));
	return 0;
}

int SocialNetwork::addActor(const std::shared_ptr<Actor> actor)
{
	_socialNetwork.emplace(actor->getName(), actor);
	return 0;
}

const std::shared_ptr<Actor> SocialNetwork::findActor(std::string name)
{
	auto it = _socialNetwork.find(name);
	if (it != _socialNetwork.end())
		return it->second;

	return std::shared_ptr<Actor>();
}
