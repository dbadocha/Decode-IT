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
	//std::set<IPconnections> links = {};


#ifdef DEBUG
	for (auto r : requests)
	{
		std::cout << "type: " << r.reqType;
		std::cout << " IP1: " << intToStringIP(r.ip1);
		std::cout << " IP2: " << intToStringIP(r.ip2);
	}
	std::cout << '\n';
#endif


	return 0;
}