/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#ifndef CPP_RUSH3_IMONITORMODULE_HPP
#define CPP_RUSH3_IMONITORMODULE_HPP

#include <string>

class IMonitorModule
{
	public:
	virtual std::string getModuleName() const = 0;
	virtual  bool isActive() const = 0;
	virtual void setActive(bool _active) = 0;
};

#endif //CPP_RUSH3_IMONITORMODULE_HPP