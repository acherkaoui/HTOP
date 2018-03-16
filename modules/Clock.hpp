/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#ifndef CPP_RUSH3_CLOCK_HPP
#define CPP_RUSH3_CLOCK_HPP

#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
#include "AMonitorModule.hpp"

template <typename T>
std::string formatTime(T time)
{
	std::stringstream str;
	if (time < 10) {
		str << 0;
	}

	str << time;
	return str.str();
};

class Clock : public AMonitorModule
{
	public:
	Clock();
	virtual ~Clock();

	std::string getTime();
	std::string getUtc();
};

#endif /* CPP_RUSH3_CLOCK_HPP */
