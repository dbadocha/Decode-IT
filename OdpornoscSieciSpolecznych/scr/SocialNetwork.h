#pragma once
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>

class Actor;
typedef std::shared_ptr<Actor> ActorsPointer;
typedef std::map<std::string, ActorsPointer> ActorsMap;

class Actor
{
public:
	Actor(const std::string name, const unsigned int takeoverCost);
	~Actor() = default;
	std::string getName();
	unsigned int gettakeoverCost();
	bool hasRelation(std::string name);
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
	SocialNetwork();
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


struct TakeoverList
{
	std::set<std::string> names;
	int takeoverCost;
};

class TakeoverStrategy
{
public:
	TakeoverStrategy(const ActorsMap &socialNetwork);
	virtual ~TakeoverStrategy() = default;
	virtual TakeoverList findSolution() = 0;
protected:
	const ActorsMap _socialNetwork;
};

class TakeoverStrategy_MapsProduct : public TakeoverStrategy
{
public:
	TakeoverStrategy_MapsProduct(const ActorsMap &socialNetwork);
	TakeoverList findSolution() override;
//private:
	TakeoverList checkNode(TakeoverList list, ActorsPointer &actor);
	std::vector<ActorsPointer> findDiscrepancy(const TakeoverList &list, const ActorsPointer &baseActor);
};