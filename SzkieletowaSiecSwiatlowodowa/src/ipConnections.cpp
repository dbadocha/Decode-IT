#include "ipConnections.h"
#include "ipConverter.h"
#include <iterator>
#include <iostream>


bool IP::operator==(const IP & ipc) const
{
	return compareIP(ipc._ip, _ip);
}

bool IP::operator==(const ipAddress & ip) const
{
	return (compareIP(_ip, ip) == 0);
}

bool IP::operator<(const IP & ipc) const
{
	return _ip < ipc._ip;
}

bool IP::operator<(const ipAddress & ip) const
{
	if (compareIP(_ip, ip) == 2)
		return true;
	return false;
}


int compareIP(const ipAddress& ip1, const ipAddress& ip2)
{
	if (ip1.size() != ip2.size())
		return -1;
	
	for (int i = 0; i < ip1.size(); ++i)
	{
		if (ip1[i] > ip2[i])
			return 1;
		else if (ip1[i] < ip2[i])
			return 2;
	}
	return 0;
}


///////////////////////////////in progress
int checkConnections(const Request &req, const std::set<IP> &link, std::set<ipAddress> &checkedConnections)
{
	std::set<ipAddress>::iterator it;
	for (auto connection : link)
	{
		it = std::find(checkedConnections.begin(), checkedConnections.end(), req.ip1);
		if (it == checkedConnections.end())
			return 0;
	}
	
	return 1;
}

int check(const Request &req, const std::set<IP> &links)
{
	std::set<ipAddress> checkedConnections = { req.ip1 };
	return 1;// checkConnections(req, checkedConnections);
}

//vector iterator - invalid
int connectionSet::addLink(Request &req)
{
	auto it1 = find(req.ip1);
	if (it1 == std::vector<IP>::iterator())
		it1 = addIP(req.ip1);
	auto it2 = find(req.ip2);
	if (it2 == std::vector<IP>::iterator())
		it2 = addIP(req.ip2);
	(*it1).connections.insert(it2);
	(*it2).connections.insert(it1);
	return 0;
}

std::vector<IP>::iterator connectionSet::addIP(const ipAddress & ip)
{
	IP tmpIP = {};
	tmpIP._ip = ip;
	links.push_back(tmpIP);
	return --links.end();
}

std::vector<IP>::iterator connectionSet::find(const ipAddress &ip)
{
	std::vector<IP>::iterator it;
	for (it = links.begin(); it != links.end(); ++it)
	{
		if ((*it) == ip)
			return it;
	}
	return std::vector<IP>::iterator();
}

void connectionSet::printConnections()
{
	for (auto con : links)
	{
		std::cout << "ip: " << intToStringIP(con._ip) << "\nCon: ";
		for (auto ip : con.connections)
			std::cout << intToStringIP((*ip)._ip) << " ";
		std::cout << '\n';
	}
}
