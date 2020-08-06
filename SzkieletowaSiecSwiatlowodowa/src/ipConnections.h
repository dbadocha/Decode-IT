#pragma once
#include <vector>
#include <set>

struct Request;
typedef std::vector<int> ipAddress;

//prosi siê o klasê
struct IPconnections
{
	ipAddress _ip;
	std::vector<IPconnections> connections;
	bool operator== (const IPconnections &ipc) const;
	bool operator== (const ipAddress &ip) const;
};

int compareIP(const ipAddress &ip1, const ipAddress &ip2);
int checkConnections(const ipAddress ip, std::set<IPconnections> &checkedConnections);