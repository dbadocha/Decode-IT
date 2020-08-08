#include "requests.h"
#include "ipConverter.h"
#include "ipConnections.h"

#include <iostream>
#include <vector>
#include <set>

struct Request;
struct IPconnections;

int main()
{
	std::vector<Request> requests = std::move(collectRequests());
	IPList links = {};

	std::cout << '\n';
	for (auto req : requests)
	{
		links.handleRequest(req);
	}

	return 0;
}