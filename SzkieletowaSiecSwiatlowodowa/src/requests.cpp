#include "requests.h"
#include "ipConverter.h"

#include <iostream>

std::vector<Request> collectRequests()
{
	std::vector<Request> ret = {};
	Request req = {};
	std::string reqLine = {};

	while(std::getline(std::cin, reqLine) && !std::cin.eof())
	{
		ret.push_back(reqLineToRequest(reqLine));
	}

	return ret;
}

std::vector<std::string> splitRequestLine(std::string reqLine)
{
	size_t start = 0, end = 0;
	std::vector<std::string> ret;

	while (end != std::string::npos)
	{
		end = reqLine.find_first_of(" \n\t\0", start);
		ret.push_back(reqLine.substr(start, end - start));
		start = end + 1;
	}
	return ret;
}

Request reqLineToRequest(std::string reqLine)
{
	std::vector<std::string> tmpReq = {};
	tmpReq = std::move(splitRequestLine(reqLine));

	Request req = {};
	if (tmpReq.size() != 3)
		return req;

	req.reqType = tmpReq[0].c_str()[0];
	req.ip1 = stringToIntIP(tmpReq[1]);
	req.ip2 = stringToIntIP(tmpReq[2]);
	return req;
}