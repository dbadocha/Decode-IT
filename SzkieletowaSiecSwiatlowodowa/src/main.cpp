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
	IPList links = {};

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
		links.handleRequest(req);
		//else if (req.reqType == 'T')
		//in progress
	}
#ifdef DEBUG
	links.printConnections();
#endif
	return 0;
}