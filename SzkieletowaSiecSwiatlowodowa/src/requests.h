#pragma once
#include <vector>
#include <string>

struct Request
{
	char reqType;
	std::vector<int> ip1;
	std::vector<int> ip2;
};

std::vector<Request> collectRequests();
Request reqLineToRequest(std::string reqLine);
std::vector<std::string> splitRequestLine(std::string reqLine);