#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>

class Actor
{
public:
	Actor(std::string name, unsigned int takeOverCost);
	~Actor() = default;
	std::string getName();
	unsigned int getTakeOverCost();
	int addRelation(const std::shared_ptr<Actor> relation);

private:
	std::string _name;
	unsigned int _takeOverCost;
	std::vector<Actor> _actorsSocialNetwork;
};

class SocialNetwork
{
public:
	SocialNetwork() = default;
	~SocialNetwork() = default;
	int addActor(const std::string name, const unsigned int takeOverCost);
	int addActor(const std::shared_ptr<Actor> actor);


private:
	std::map<std::string, std::shared_ptr<Actor>> socialNetwork;
};