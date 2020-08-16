#include "SocialNetwork.h"
#include <iostream>
#include <algorithm>

Actor::Actor(std::string name, unsigned int takeoverCost)
	:
	_name(name), _takeoverCost(takeoverCost)
{
}

std::string Actor::getName()
{
	return _name;
}

unsigned int Actor::getTakeoverCost()
{
	return _takeoverCost;
}

bool Actor::hasRelation(std::string name)
{
	if (_name == name)
		return true;

	for (auto it : _actorsSocialNetwork)
	{
		if (it->getName() == name)
			return true;
	}
	return false;
}

int Actor::addRelation(const ActorsPointer &relation)
{
	std::string relationName = relation->getName();

	for (auto it : _actorsSocialNetwork)
	{
		if (it->getName() == relationName)
			return 1;
	}

	_actorsSocialNetwork.insert(relation);
	return 0;
}

bool Actor::operator<(const Actor & rhs) const
{
	return _takeoverCost < rhs._takeoverCost;
}

Actor Actor::operator+(const Actor & rhs) const
{
	std::string name = _name + rhs._name.substr(0, 1);
	auto newTakeoverCost = _takeoverCost + rhs._takeoverCost;
	Actor newActor(name, newTakeoverCost);
	newActor._actorsSocialNetwork = std::move(_actorsSocialNetwork + rhs._actorsSocialNetwork);
	return newActor;
}

const ActorsPointerList Actor::getNetwork()
{
	return _actorsSocialNetwork;
}

SocialNetwork::SocialNetwork()
{
	SocialNetworkCreator creator;
	_socialNetwork = std::move(creator.createFromStdin());
}

int SocialNetwork::addActor(const std::string name, const unsigned int takeoverCost)
{
	Actor newActor(name, takeoverCost);
	_socialNetwork.emplace(name, std::make_shared<Actor>(newActor));

	auto actor = _socialNetwork.find(name);
	(actor->second)->addRelation(actor->second);
	return 0;
}

int SocialNetwork::addActor(const ActorsPointer actor)
{
	_socialNetwork.emplace(actor->getName(), actor);
	actor->addRelation(actor);
	return 0;
}

const ActorsPointer SocialNetwork::findActor(std::string name)
{
	auto it = _socialNetwork.find(name);
	if (it != _socialNetwork.end())
		return it->second;
	return ActorsPointer();
}

ActorsMap && SocialNetworkCreator::createFromStdin()
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
	unsigned int takeoverCost = 0;
	for (int i = 0; i < amountOfActors; ++i)
	{
		std::cin >> name >> takeoverCost;
		_socialNetwork.emplace(name, std::make_shared<Actor>(name, takeoverCost));
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

TakeoverStrategy_MapsProduct::TakeoverStrategy_MapsProduct(const ActorsMap & socialNetwork)
	:
	TakeoverStrategy(socialNetwork)
{
}

TakeoverList TakeoverStrategy_MapsProduct::findSolution()
{
	ActorsPointer nullActor = {};
	TakeoverList ret = {};
	return ret;
}

TakeoverList TakeoverStrategy_MapsProduct::checkNode(TakeoverList &list)
{
	ActorsPointerList nextActors = findDiscrepancy(list);
	if (nextActors.size() == 0)
		return list;


	TakeoverList tmplist = {}, retSolution = {};
	for (auto it : nextActors)
	{
		tmplist = list;
		tmplist.names.insert(it->getName());
		tmplist.takeoverCost += it->getTakeoverCost();

		auto solution = checkNode(list);

		if (solution.takeoverCost < retSolution.takeoverCost || solution.takeoverCost == 0)
		{
			retSolution = solution;
		}
	}
	return retSolution;
}

ActorsPointerList TakeoverStrategy_MapsProduct::findDiscrepancy(const TakeoverList &list)
{
	ActorsPointerList nextActors = {};
	for (auto it : _socialNetwork)
	{
		if(list.tookover.find(it.second) == list.tookover.end())
		{
			nextActors = it.second->getNetwork();
		}
		
	}
	return nextActors;
}

TakeoverStrategy::TakeoverStrategy(const ActorsMap &socialNetwork)
	:
	_socialNetwork(socialNetwork)
{
}

ActorsPointerList operator+(const ActorsPointerList &lhs, const ActorsPointerList &rhs)
{
	ActorsPointerList newList = lhs;
	newList.insert(rhs.begin(), rhs.end());
	return newList;
}