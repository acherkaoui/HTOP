/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#ifndef CPP_RUSH3_OPERATINGSYSTEM_HPP
#define CPP_RUSH3_OPERATINGSYSTEM_HPP

#include <sys/utsname.h>
#include <string>
#include "AMonitorModule.hpp"

class OperatingSystem : public AMonitorModule
{
	private:
	std::string _kernel;
	std::string _name;
	std::string _version;
	std::string _machine;
	std::string _domain;

	public:
	OperatingSystem();
	virtual ~OperatingSystem() = default;
	std::string getKernel();
	std::string getOSName();
	std::string getVersion();
	std::string getMachine();
	std::string getDomain();
};

#endif //CPP_RUSH3_OPERATINGSYSTEM_HPP
