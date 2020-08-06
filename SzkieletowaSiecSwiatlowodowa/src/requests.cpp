#include "requests.h"
#include <iostream>

std::vector<Request> collectRequests()
{
	std::vector<Request> ret = {};
	Request req = {};
	char type = {};
	std::cin >> type;

	while (type != 'E')
	{
		req = {};
		req.reqType = type;
		req.IP1 = std::move(getIP());
		req.IP2 = std::move(getIP());
		ret.push_back(req);
		std::cin >> type;
	}

	return ret;
}

std::vector<int> getIP()
{
	std::string IP = {};
	std::cin >> IP;
	return stringToIntIP(IP);
}