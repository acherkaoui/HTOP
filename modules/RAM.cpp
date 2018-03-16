/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include <sys/sysinfo.h>
#include "RAM.hpp"

std::size_t RAM::getTotalRam()
{
	refresh();
	return _totalRam;
}

std::size_t RAM::getTotalSwap()
{
	refresh();
	return _totalSwap;
}

std::size_t RAM::getFreeRam()
{
	refresh();
	return _freeRam;
}

std::size_t RAM::getFreeSwap()
{
	refresh();
	return _freeSwap;
}

std::size_t RAM::getProcesses()
{
	refresh();
	return _processes;
}

std::string RAM::getUpTime()
{
	refresh();
	return _upTime;
}

std::size_t RAM::getPercentRam()
{
	std::size_t used = _totalRam - _freeRam;
	std::size_t percentUsed = 100 * used / _totalRam;
	return percentUsed;
}

std::size_t RAM::getPercentSwap()
{
	std::size_t used = _totalSwap - _freeSwap;
	std::size_t percentUsed = 100 * used / _totalSwap;
	return percentUsed;
}


void RAM::refresh()
{
	struct sysinfo _sysInfo;
	sysinfo(&_sysInfo);
	int minute = 60;
	int hour = minute * 60;
	int day = hour * 24;

	_upTime = std::to_string(_sysInfo.uptime / day) +
		" days " + std::to_string((_sysInfo.uptime % day) / hour) +
		" hours " + std::to_string((_sysInfo.uptime % hour) / minute) +
		" min.";
	_totalRam = _sysInfo.totalram / MB;
	_totalSwap = _sysInfo.totalswap / MB;
	_freeRam = _sysInfo.freeram / MB;
	_freeSwap = _sysInfo.freeswap / MB;
	_processes = _sysInfo.procs;
}

RAM::RAM() : AMonitorModule(true, "RAM")
{
	refresh();
}

RAM::~RAM()
{
}
