#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>

class Actor
{
public:
	Actor(const std::string name, const unsigned int takeOverCost);
	~Actor() = default;
	std::string getName();
	unsigned int getTakeOverCost();
	int addRelation(const std::shared_ptr<Actor> &relation);

private:
	const std::string _name;
	const unsigned int _takeOverCost;
	std::vector<std::shared_ptr<Actor>> _actorsSocialNetwork;
};

class SocialNetwork
{
public:
	SocialNetwork() = default;
	SocialNetwork(std::map<std::string, std::shared_ptr<Actor>> &&socialNetwork);
	~SocialNetwork() = default;
	int addActor(const std::string name, const unsigned int takeOverCost);
	int addActor(const std::shared_ptr<Actor> actor);
	const std::shared_ptr<Actor> findActor(std::string name);

private:
	std::map<std::string, std::shared_ptr<Actor>> _socialNetwork;
};

class SocialNetworkCreator
{
public:
	SocialNetworkCreator() = default;
	~SocialNetworkCreator() = default;
	std::map<std::string, std::shared_ptr<Actor>> &&createFromStdin();
private:
	std::map<std::string, std::shared_ptr<Actor>> _socialNetwork;
	int addActors(int amountOfActors);
	int addRelations(int amountOfRelations);
};

