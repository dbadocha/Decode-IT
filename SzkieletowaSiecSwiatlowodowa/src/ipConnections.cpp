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

int IPList::handleRequest(Request &req)
{
	if (req.reqType = 'B')
	{
		auto p1 = addIP(req.ip1);
		auto p2 = addIP(req.ip2);
		if (p1 == p2)
			return 1;
		(*p1).connections[(*p2)._ip] = p2;
		(*p2).connections[(*p1)._ip] = std::move(p1);
	}
	return 0;
}

std::shared_ptr<IP> IPList::addIP(const ipAddress & ip)
{
	auto it = _ipMap.find(ip);
	if (it != _ipMap.end())
		return (*it).second;

	IP tmpIP = {};
	tmpIP._ip = ip;
	tmpIP.connections = {};
	auto ret = std::make_shared<IP>(tmpIP);
	_ipMap[(*ret)._ip] = ret;
	
	return std::move(ret);
}

void IPList::printConnections()
{
	for (const auto con : _ipMap)
	{
		std::cout << "ip: " << intToStringIP(con.first) << "\nCon: ";
		for (auto ip : (*con.second).connections)
		{
			std::cout << intToStringIP(ip.first) << "\t";
		}
		std::cout << '\n';
	}
}
