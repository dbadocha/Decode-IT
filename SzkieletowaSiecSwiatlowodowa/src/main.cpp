#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct request;
request getRequest();
std::vector<int> getIP();
std::vector<int> stringToIntIP(std::string &ipString);

struct request
{
	char reqType;
	std::vector<int> IP1;
	std::vector<int> IP2;
};

struct link
{
	int IP1[4];
	int IP2[2];
};

int main()
{
	std::vector<request> requests = {};
	std::vector<link> links = {};

	std::vector<int> test = std::move(getIP());
	for (int i : test)
	{
		std::cout << i << ' ';
	}

	return 0;
}

request getRequest()
{
	request ret = {};
	std::cin >> ret.reqType;
	ret.IP1 = std::move(getIP());
	ret.IP2 = std::move(getIP());
	return request();
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

