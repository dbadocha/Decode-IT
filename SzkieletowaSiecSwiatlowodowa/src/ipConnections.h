#pragma once
#include "requests.h"
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <memory>

//extern struct Request;
struct IP;
typedef std::vector<int> ipAddress;
typedef std::map<ipAddress, std::shared_ptr<IP>> ipMap;


//prosi siê o klasê
struct IP
{
	ipAddress _ip;
	ipMap connections;
	bool operator== (const IP &ipc) const;
	bool operator== (const ipAddress &ip) const;
	bool operator< (const IP &ipc) const;
	bool operator< (const ipAddress &ip) const;
};

struct IPList
{
	ipMap _ipMap;
	int handleRequest(Request &req);
	std::shared_ptr<IP> addIP(const ipAddress &ip);
	void printConnections();
};

std::shared_ptr<IP> find(const ipAddress &ip, const ipMap &map);

int compareIP(const ipAddress &ip1, const ipAddress &ip2);
int checkConnections(const ipAddress ip, std::set<IP> &checkedConnections);