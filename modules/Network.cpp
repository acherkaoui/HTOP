/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "Network.hpp"

std::size_t Network::getInBytes()
{
	refreshCpuData();
	return _inBytes;
}

std::size_t Network::getInPackets()
{
	refreshCpuData();
	return _inPackets;
}

std::size_t Network::getOutBytes()
{
	refreshCpuData();
	return _outBytes;
}

std::size_t Network::getOutPackets()
{
	refreshCpuData();
	return _outPackets;
}

void  Network::refreshCpuData()
{
	std::ifstream file("/proc/net/dev", std::ifstream::in);
	std::string line;

	while (!file.eof())
	{
		std::getline(file, line);
		if (line.find("wlo1:") != std::string::npos)
			break;
	}
	std::string array[STAT_COLUMNS];
	std::size_t i = 0;
	std::stringstream ssin(line);
	while (ssin.good() && i < STAT_COLUMNS)
	{
		ssin >> array[i];
		i++;
	}
	fillValue(array[IN_BYTES], _inBytes);
	fillValue(array[IN_PACKETS], _inPackets);
	fillValue(array[OUT_BYTES], _outBytes);
	fillValue(array[OUT_PACKETS], _outPackets);
}

Network::Network() : AMonitorModule(true, "NETWORK")
{
	refreshCpuData();
}

Network::~Network()
{
}

