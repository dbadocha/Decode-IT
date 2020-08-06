#pragma once
#include "requests.h"
#include <vector>
#include <set>
#include <algorithm>

//extern struct Request;
typedef std::vector<int> ipAddress;

//prosi siê o klasê
struct IP
{
	ipAddress _ip;
	std::set<std::vector<IP>::iterator> connections;
	bool operator== (const IP &ipc) const;
	bool operator== (const ipAddress &ip) const;
	bool operator< (const IP &ipc) const;
	bool operator< (const ipAddress &ip) const;
};

struct connectionSet
{
	std::vector<IP> links;
	int addLink(Request &req);
	std::vector<IP>::iterator addIP(const ipAddress &ip);
	std::vector<IP>::iterator find(const ipAddress &ip);
	void printConnections();
};

int compareIP(const ipAddress &ip1, const ipAddress &ip2);
int checkConnections(const ipAddress ip, std::set<IP> &checkedConnections);