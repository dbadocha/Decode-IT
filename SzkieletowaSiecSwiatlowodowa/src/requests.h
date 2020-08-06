#pragma once
#include <vector>

struct Request
{
	char reqType;
	std::vector<int> ip1;
	std::vector<int> ip2;
};

std::vector<Request> collectRequests();
std::vector<int> getIP();