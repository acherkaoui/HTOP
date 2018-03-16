/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "OperatingSystem.hpp"

OperatingSystem::OperatingSystem() : AMonitorModule(true, "OS")
{
	struct utsname data;
	uname(&data);
	_kernel = data.release;
	_name = data.sysname;
	_domain = data.domainname;
	_machine = data.machine;
	_version = data.version;
}

std::string OperatingSystem::getKernel()
{
	return (_kernel);
}

std::string OperatingSystem::getOSName()
{
	return (_name);
}

std::string OperatingSystem::getVersion()
{
	return (_version);
}

std::string OperatingSystem::getMachine()
{
	return (_machine);
}

std::string OperatingSystem::getDomain()
{
	return (_domain);
}