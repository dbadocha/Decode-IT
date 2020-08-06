#include <iostream>
#include <fstream>
#include <vector>

struct request;
request getRequest();
void getIP(int (&IP)[4]);

struct request
{
	char reqType;
	int IP1[4];
	int IP2[4];
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
}

request getRequest()
{
	request ret = {};
	std::cin >> ret.reqType;
	getIP(ret.IP1);
	getIP(ret.IP2);
	return request();
}

void getIP(int (&IP)[])
{
	for (int i = 0; i < 4; ++i)
	{
		std::cin >> IP[i];
	}
}
