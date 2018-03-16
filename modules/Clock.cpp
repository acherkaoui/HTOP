/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "Clock.hpp"

Clock::Clock() : AMonitorModule(true, "CLOCK")
{
}

Clock::~Clock()
{
}

std::string Clock::getTime()
{
	time_t rawTime;
	struct tm *localTime;
	std::stringstream now;

	time(&rawTime);
	localTime = localtime(&rawTime);
	now << formatTime(localTime->tm_hour) << ":";
	now << formatTime(1 + localTime->tm_min) << ":";
	now << formatTime(1 + localTime->tm_sec);
	return now.str();
}

std::string Clock::getUtc()
{
	time_t now;
	struct tm *localTime;
	std::string utc;
	char buff[128];

	time(&now);
	localTime = localtime(&now);
	strftime(buff, 128, "%a %d %b %Y", localTime);
	utc = buff;
	return utc;
}