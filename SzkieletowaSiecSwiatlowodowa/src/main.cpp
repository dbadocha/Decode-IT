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

	for (auto req : requests)
	{
		links.handleRequest(req);
	}
#ifdef DEBUG
	std::cout << '\n';
	links.printConnections();
	std::cout << '\n';
#endif
	return 0;
}