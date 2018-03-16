/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "Parser.hpp"

Parser::Parser(int ac, char **av)
{
	this->_map["ram"] = "true";
	this->_map["cpu"] = "true";
	this->_map["network"] = "true";
	this->_map["os"] = "true";
	this->_map["process"] = "true";
	this->_map["user"] = "true";
	this->_map["clock"] = "true";
	this->parse(this->_file);
	this->flagHandler(ac, av);
}

int Parser::printUsage()
{
	std::cout << "Usage htop [OPTION]...\n"
		"\n"
		"activate / desactivate module\n"
		"\t-CLOCK={true || false}\n"
		"\t-CPU={true || false}\n"
		"\t-NETWORK={true || false}\n"
		"\t-OS={true || false}\n"
		"\t-RAM={true || false}\n"
		"\t-USER={true || false}\n"
		"\n"
		"Choose wich display mode use\n"
		"\t-terminal\n"
		"\t-graphic"
		<< std::endl;
	return (1);
}

bool Parser::isMandatoryModule(const std::string name) const
{
	return (this->toLower(name) == "ram" ||
		this->toLower(name) == "cpu" ||
		this->toLower(name) == "network" ||
		this->toLower(name) == "os" ||
		this->toLower(name) == "process" ||
		this->toLower(name) == "user" ||
		this->toLower(name) == "clock");
}

int Parser::setModuleActive(std::string str) {
	if (str.find('=') == std::string::npos ||
		!isMandatoryModule(str.substr(0, str.find('='))))
		return (1);
	if (!this->isBool(str.substr(str.find('=') + 1)))
		return (1);
	this->_map[str.substr(0, str.find('='))] =
		str.substr(str.find('=') + 1);
	return (0);
}

void Parser::flagHandler(int ac, char **av)
{
	std::vector<std::string> argv;

	for (int i = 1; i < ac; i += 1)
		argv.emplace_back(av[i]);

	for (unsigned int i = 0; i < argv.size(); i += 1) {
		if (argv[i] == "--help")
			exit(printUsage());
		else if (argv[i] == "-terminal") {
			this->_graphicMode = false;
		}
		else if (argv[i] == "-graphic") {
			this->_graphicMode = true;
		}
		else if (argv[i][0] != '-' || this->setModuleActive(
			argv[i].substr(1))) {
			std::cout << "htop: invalid option "
				<< argv[i].substr(1)
				<< "\nTry 'htop --help' for more information"
				<< std::endl;
			exit(1);
		}
	}
}

std::map<std::string, std::string> &Parser::getMap()
{
	return (this->_map);
}

bool Parser::getComponent(const std::string name)
{
	if (!isMandatoryModule(name) || this->_map[name].empty())
		return (false);
	return (this->toBool(name));
}

std::string Parser::toLower(const std::string str) const
{
	std::string tmp(str);

	std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
	return (tmp);
}

bool Parser::isBool(std::string boolean) const
{
	return (boolean == "1" ||
		boolean == "0" ||
		boolean == "true" ||
		boolean == "false");
}

bool Parser::toBool(const std::string boolean) const
{
	return (boolean == "true" ||
		boolean == "1");
}

int Parser::parse(std::string file)
{
	std::ifstream input(file);
	std::string line;

	if (!input.is_open())
		return (1);
	while (!input.eof()) {
		getline(input, line);
		if (line.find('=') == std::string::npos)
			return (1);
		this->_map[line.substr(0, line.find('='))] =
		line.substr(line.find('=') + 1);
	}
	return (0);
}

bool Parser::isGraphicMode() const
{
	return (this->_graphicMode);
}

