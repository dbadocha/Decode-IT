#pragma once
#include <string>
#include <set>
#include <map>
#include <memory>

class Actor;
class TakeoverStrategy;
typedef std::shared_ptr<Actor> ActorsPointer;
typedef std::set<ActorsPointer> ActorsPointerList;
typedef std::map<std::string, ActorsPointer> ActorsMap;

ActorsPointerList operator+ (const ActorsPointerList &lhs, const ActorsPointerList &rhs);
ActorsPointerList &operator+= (ActorsPointerList &lhs, const ActorsPointerList &rhs);

class Actor
{
public:
	Actor(const std::string name, const unsigned int takeoverCost);
	~Actor() = default;
	std::string getName();
	unsigned int getTakeoverCost();
	bool hasRelation(std::string name);
	int addRelation(const ActorsPointer &relation);
	bool operator< (const Actor &rhs) const;
	Actor operator+ (const Actor &rhs) const;
	const ActorsPointerList getNetwork();

private:
	const std::string _name;
	const unsigned int _takeoverCost;
	ActorsPointerList _actorsSocialNetwork;
};

class SocialNetwork
{
public:
	SocialNetwork();
	~SocialNetwork() = default;
	int addActor(const std::string name, const unsigned int takeoverCost);
	int addActor(const ActorsPointer actor);
	const ActorsPointer findActor(std::string name);
	void findSolution();

private:
	ActorsMap _socialNetwork;
	std::unique_ptr<TakeoverStrategy> _strategy;
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
	ActorsPointerList tookover;
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
	virtual void print() = 0;
};

class TakeoverStrategy_MapsProduct : public TakeoverStrategy
{
public:
	TakeoverStrategy_MapsProduct(const ActorsMap &socialNetwork);
	TakeoverList findSolution() override;
private:
	TakeoverList _solution = {};
	void print() override;
	TakeoverList checkNode(TakeoverList list = {});
	ActorsPointerList findDiscrepancy(const TakeoverList &list);
};