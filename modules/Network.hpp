/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#ifndef CPP_RUSH3_NETWORK_HPP
#define CPP_RUSH3_NETWORK_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "AMonitorModule.hpp"

#define IN_BYTES 1
#define IN_PACKETS 2
#define OUT_BYTES 9
#define OUT_PACKETS 10
#define STAT_COLUMNS 17

template <typename T, typename U>
void fillValue(T &data, U &member)
{
	std::stringstream stream(data);
	stream >> member;
};

class Network : public AMonitorModule
{
	private:

	std::size_t _inBytes = 0;
	std::size_t _inPackets = 0;
	std::size_t _outBytes = 0;
	std::size_t _outPackets = 0;

	public:

	Network();

	virtual ~Network();

	std::size_t getInBytes();
	std::size_t getInPackets();
	std::size_t getOutBytes();
	std::size_t getOutPackets();

	void refreshCpuData();

};

#endif //CPP_RUSH3_NETWORK_HPP
