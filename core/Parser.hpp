/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#ifndef CPP_RUSH3_PARSER_HPP
#define CPP_RUSH3_PARSER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <algorithm>
#include <vector>

class Parser
{
	public:
	Parser(int ac, char **av);
	virtual ~Parser() = default;

	public:
	void flagHandler(int ac, char **av);
	int printUsage();
	int setModuleActive(std::string str);

	public:
	int parse(std::string file);
	std::map<std::string, std::string> &getMap();

	public:
	bool isMandatoryModule(std::string name) const;

	public:
	bool getComponent(std::string name);
	bool isGraphicMode() const;

	public:
	std::string toLower(const std::string str) const;
	bool isBool(std::string boolean) const;
	bool toBool(const std::string boolean) const;

	private:
	std::map<std::string, std::string> _map;
	const std::string _file = "config.cfg";
	bool _graphicMode = false;
};

#endif //CPP_RUSH3_PARSER_HPP
