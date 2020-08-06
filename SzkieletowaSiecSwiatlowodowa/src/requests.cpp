#include "requests.h"
#include "ipConverter.h"

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
		req.ip1 = std::move(getIP());
		req.ip2 = std::move(getIP());
		ret.push_back(req);
		std::cin >> type;
	}

	return ret;
}

std::vector<int> getIP()
{
	std::string ip = {};
	std::cin >> ip;
	return stringToIntIP(ip);
}