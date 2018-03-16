/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#ifndef CPP_RUSH3_CORE_HPP
#define CPP_RUSH3_CORE_HPP

#include <map>

#include "Parser.hpp"
#include "Data.hpp"
#include "terminal.hpp"
#include "../terminal/terminal.hpp"
#include <unistd.h>

class Core
{
	public:
	Core(int ac, char **av);
	virtual ~Core() = default;

	public:
	void updateActivate(std::map<std::string, std::string> &map);
	void setModuleActive(std::string name, bool active);
	bool getModuleActive(std::string name) const;
	void graphicInterface();
	void terminalInterface();

	public:
	Parser parser;
	Data data;
	Curses *terminal;

};

#endif //CPP_RUSH3_CORE_HPP
