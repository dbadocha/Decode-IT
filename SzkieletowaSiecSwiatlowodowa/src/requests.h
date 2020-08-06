#pragma once
#include <vector>

struct Request
{
	char reqType;
	std::vector<int> IP1;
	std::vector<int> IP2;
};

std::vector<Request> collectRequests();
std::vector<int> getIP();