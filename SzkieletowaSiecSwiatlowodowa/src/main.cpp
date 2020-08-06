#include "requests.h"
#include "ipConverter.h"
#include "ipConnections.h"

#include <iostream>
#include <vector>
#include <set>

#define DEBUG

struct Request;
struct IPconnections;


int main()
{
	std::vector<Request> requests = std::move(collectRequests());
	connectionSet links = {};

#ifdef DEBUG
	for (auto r : requests)
	{
		std::cout << "type: " << r.reqType;
		std::cout << " IP1: " << intToStringIP(r.ip1);
		std::cout << " IP2: " << intToStringIP(r.ip2);
	}
	std::cout << '\n';
#endif

	for (auto req : requests)
	{
		if (req.reqType == 'B')
			links.addLink(req);
#ifdef DEBUG
		links.printConnections();
#endif
		//else if (req.reqType == 'T')
		//in progress
	}
	return 0;
}