/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#ifndef CPP_RUSH3_RAM_HPP
#define CPP_RUSH3_RAM_HPP

#include <sys/sysinfo.h>
#include <string>
#include "AMonitorModule.hpp"

#define MB 1024 * 1024

class RAM : public AMonitorModule
{
	private:
	std::string _upTime;
	std::size_t _totalRam;
	std::size_t _freeRam;
	std::size_t _totalSwap;
	std::size_t _freeSwap;
	std::size_t _processes;

	public:
	RAM();
	virtual ~RAM();

	std::string getUpTime();
	std::size_t getTotalRam();
	std::size_t getFreeRam();
	std::size_t getTotalSwap();
	std::size_t getFreeSwap();
	std::size_t getProcesses();
	std::size_t getPercentRam();
	std::size_t getPercentSwap();
	void refresh();

};

#endif //CPP_RUSH3_RAM_HPP
