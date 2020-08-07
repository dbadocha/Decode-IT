#pragma once
#include "requests.h"

#include <set>
#include <map>
#include <memory>

struct IP;
typedef std::vector<int> ipAddress;
typedef std::map<ipAddress, std::shared_ptr<IP>> ipMap;


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
	int handleRequest(const Request &req);
	std::shared_ptr<IP> addIP(const ipAddress &ip);
	void printConnections();
};

int compareIP(const ipAddress &ip1, const ipAddress &ip2);
int checkConnection(const Request &req, const ipMap &ipMap);
int checkNode(Request req, const ipMap &ipMap, std::set<ipAddress> &checkedConn);

