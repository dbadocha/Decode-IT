#include "SocialNetwork.h"
#include <iostream>

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
	std::string relationName = relation->getName();

	for (auto it : _actorsSocialNetwork)
	{
		if (it->getName() == relationName)
			return 1;
	}

	_actorsSocialNetwork.push_back(relation);
	return 0;
}

SocialNetwork::SocialNetwork(std::map<std::string, std::shared_ptr<Actor>>&& socialNetwork)
	:
	_socialNetwork(std::move(socialNetwork))
{
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

std::map<std::string, std::shared_ptr<Actor>>&& SocialNetworkCreator::createFromStdin()
{
	unsigned int recordsAmount = 0;
	std::cin >> recordsAmount;
	addActors(recordsAmount);
	std::cin >> recordsAmount;
	addRelations(recordsAmount);
	return std::move(_socialNetwork);
}

int SocialNetworkCreator::addActors(int amountOfActors)
{
	std::string name = {};
	unsigned int takeOverCost = 0;
	for (int i = 0; i < amountOfActors; ++i)
	{
		std::cin >> name >> takeOverCost;
		_socialNetwork.emplace(name, std::make_shared<Actor>(name, takeOverCost));
	}
	return 0;
}

int SocialNetworkCreator::addRelations(int amountOfRelations)
{
	std::string name1, name2 = {};

	for (int i = 0; i < amountOfRelations; ++i)
	{
		std::cin >> name1 >> name2;
		auto pName1 = _socialNetwork.find(name1);
		auto pName2 = _socialNetwork.find(name2);
		(pName1->second)->addRelation(pName2->second);
		(pName2->second)->addRelation(pName1->second);
	}	
	return 0;
}
