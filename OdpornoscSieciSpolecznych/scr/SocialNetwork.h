#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>

typedef std::shared_ptr<Actor> ActorsPointer;
typedef std::map<std::string, ActorsPointer> ActorsMap;

class Actor
{
public:
	Actor(const std::string name, const unsigned int takeoverCost);
	~Actor() = default;
	std::string getName();
	unsigned int gettakeoverCost();
	int addRelation(const ActorsPointer &relation);
	bool operator< (const Actor &rhs) const;
	const std::vector<ActorsPointer> getNetwork();

private:
	const std::string _name;
	const unsigned int _takeoverCost;
	std::vector<ActorsPointer> _actorsSocialNetwork;
};

class SocialNetwork
{
public:
	SocialNetwork() = default;
	SocialNetwork(ActorsMap &&socialNetwork);
	~SocialNetwork() = default;
	int addActor(const std::string name, const unsigned int takeoverCost);
	int addActor(const ActorsPointer actor);
	const ActorsPointer findActor(std::string name);

private:
	ActorsMap _socialNetwork;
};


class SocialNetworkCreator
{
public:
	SocialNetworkCreator() = default;
	~SocialNetworkCreator() = default;
	ActorsMap &&createFromStdin();
private:
	ActorsMap _socialNetwork;
	int addActors(int amountOfActors);
	int addRelations(int amountOfRelations);
};