#pragma once
#include <string>
#include <vector>
#include <map>
#include <memory>

class Actor
{
public:
	Actor(const std::string name, const unsigned int takeoverCost);
	~Actor() = default;
	std::string getName();
	unsigned int gettakeoverCost();
	int addRelation(const std::shared_ptr<Actor> &relation);
	bool operator< (const Actor &rhs) const;

private:
	const std::string _name;
	const unsigned int _takeoverCost;
	std::vector<std::shared_ptr<Actor>> _actorsSocialNetwork;
};

class SocialNetwork
{
public:
	SocialNetwork() = default;
	SocialNetwork(std::map<std::string, std::shared_ptr<Actor>> &&socialNetwork);
	~SocialNetwork() = default;
	int addActor(const std::string name, const unsigned int takeoverCost);
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

struct ActorsData
{
	std::string name;
	unsigned int takeoverCost;
};

class SocialNetworkSearch
{
public:
	SocialNetworkSearch() = default;
	virtual ~SocialNetworkSearch() = default;
	virtual std::vector<std::shared_ptr<Actor>> findSolution() = 0;
};

class SocialNetworkSearch_First : public SocialNetworkSearch
{
public:
	virtual std::vector<std::shared_ptr<Actor>> findSolution() override;
private:
	std::vector<std::vector<ActorsData>> _tmpConnectionList;
};