/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#ifndef CPP_RUSH3_DATA_HPP
#define CPP_RUSH3_DATA_HPP

#include "../modules/Clock.hpp"
#include "../modules/Network.hpp"
#include "../modules/OperatingSystem.hpp"
#include "../modules/Processes.hpp"
#include "../modules/RAM.hpp"
#include "../modules/User.hpp"
#include "../modules/CPU.hpp"

class Data
{
	public:
	Data() = default;
	virtual ~Data() = default;

	public:
	Cpu cpu;
	Clock clock;
	Network network;
	OperatingSystem os;
	Processes processes;
	RAM ram;
	User user;
};

#endif //CPP_RUSH3_DATA_HPP
