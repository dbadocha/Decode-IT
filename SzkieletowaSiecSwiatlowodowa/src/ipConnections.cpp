#include "ipConnections.h"
#include <iterator>


bool IPconnections::operator==(const IPconnections & ipc) const
{
	return compareIP(ipc._ip, _ip);
}

bool IPconnections::operator==(const ipAddress & ip) const
{
	return compareIP(_ip, ip);
}

int compareIP(const ipAddress& ip1, const ipAddress& ip2)
{
	if (ip1.size() != ip2.size())
		return -1;
	
	for (int i = 0; i < ip1.size(); ++i)
	{
		if (ip1[i] != ip2[i])
			return 0;
	}
	return 1;
}

int checkConnections(const ipAddress ip, std::set<ipAddress> &checkedConnections)
{
	checkedConnections.find(ip);
	return 0;
}
