/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "Core.hpp"

Core::Core(int ac, char **av) : parser(Parser(ac, av))
{
	std::map<std::string, std::string> map = this->parser.getMap();
	this->updateActivate(this->parser.getMap());
	if (!parser.isGraphicMode()) {

		this->terminal =  new Curses(this->data);
		this->terminalInterface();
	} else {
		execve("graphic/myHpot", av, av);
	}
}

void Core::updateActivate(std::map<std::string, std::string> &map)
{
	if (map.find("cpu") != map.end())
		this->setModuleActive(map["cpu"],
			this->parser.toBool(map["cpu"]));
	if (map.find("clock") != map.end())
		this->setModuleActive(map["clock"],
			this->parser.toBool(map["clock"]));
	if (map.find("network") != map.end())
		this->setModuleActive(map["network"],
			this->parser.toBool(map["network"]));
	if (map.find("os") != map.end())
		this->setModuleActive(map["os"],
			this->parser.toBool(map["os"]));
	if (map.find("process") != map.end())
		this->setModuleActive(map["process"],
			this->parser.toBool(map["process"]));
	if (map.find("ram") != map.end())
		this->setModuleActive(map["ram"],
			this->parser.toBool(map["ram"]));
	if (map.find("user") != map.end())
		this->setModuleActive(map["user"],
			this->parser.toBool(map["user"]));
}

void Core::terminalInterface()
{
	std::map<std::string, std::string> map = this->parser.getMap();

	while(true) {
		(*terminal).clearTerminal();
		if(data.clock.isActive())
			(*terminal).printTime();
		if(data.cpu.isActive())
			(*terminal).printCpu();
		if(data.ram.isActive())
			(*terminal).printRam();
		if(data.user.isActive())
			(*terminal).printUser();
		if(data.network.isActive())
			(*terminal).printNet();
		(*terminal).refreshTerminal();
		usleep(30000);
	}
}

bool Core::getModuleActive(const std::string name) const
{
	if (parser.toLower(name) == "ram")
		return (this->data.ram.isActive());
	else if (parser.toLower(name) == "user")
		return (this->data.user.isActive());
	else if (parser.toLower(name) == "clock")
		return (this->data.clock.isActive());
	else if (parser.toLower(name) == "network")
		return (this->data.network.isActive());
	else if (parser.toLower(name) == "os")
		return (this->data.os.isActive());
	else if (parser.toLower(name) == "cpu")
		return (this->data.cpu.isActive());
	return (false);
}

void Core::setModuleActive(const std::string name, bool active)
{
	if (parser.toLower(name) == "ram")
		this->data.ram.setActive(active);
	else if (parser.toLower(name) == "user")
		this->data.user.setActive(active);
	else if (parser.toLower(name) == "clock")
		this->data.clock.setActive(active);
	else if (parser.toLower(name) == "network")
		this->data.network.setActive(active);
	else if (parser.toLower(name) == "os")
		this->data.os.setActive(active);
	else if (parser.toLower(name) == "cpu")
		this->data.cpu.setActive(active);
}