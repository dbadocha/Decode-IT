#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define DEBUG

struct Request;
struct IPconnections;
std::vector<Request> collectRequests();
std::vector<int> getIP();
std::vector<int> stringToIntIP(std::string &ipString);
std::string intToStringIP(std::vector<int> &ipString);

struct Request
{
	char reqType;
	std::vector<int> IP1;
	std::vector<int> IP2;
};

struct IPconnections
{
	std::vector<int> IP;
	std::vector<IPconnections> connections;
};

struct link
{
	int IP1[4];
	int IP2[2];
};

int main()
{
	std::vector<Request> requests = {};
	std::vector<link> links = {};

	requests = std::move(collectRequests());

#ifdef DEBUG
	for (auto r : requests)
	{
		std::cout << "type: " << r.reqType;
		std::cout << " IP1: " << intToStringIP(r.IP1);
		std::cout << " IP2: " << intToStringIP(r.IP2);
	}
	std::cout << '\n';
#endif



	return 0;
}

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

std::vector<int> stringToIntIP(std::string & ipString)
{
	std::vector<int> retIParray;

	int startPos = 0;
	int endPos = ipString.find('.');
	int len = endPos - startPos;
	std::string tmpIPsubstr = ipString.substr(startPos, len);
	int tempIPint = std::stoi(tmpIPsubstr);
	retIParray.push_back(tempIPint);

	while (endPos != std::string::npos)
	{
		startPos = endPos + 1;
		endPos = ipString.find('.', startPos);
		len = endPos - startPos;
		tmpIPsubstr = ipString.substr(startPos, len);
		tempIPint = std::stoi(tmpIPsubstr);
		retIParray.push_back(tempIPint);
	}
	return retIParray;
}

std::string intToStringIP(std::vector<int>& IP)
{
	std::string ret = {};

	for (auto it = IP.begin(); it != IP.end(); ++it)
	{
		ret += std::to_string(*it);
		if (it != IP.end() - 1)
			ret += ".";
	}
	return ret;
}

