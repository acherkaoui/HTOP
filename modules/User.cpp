/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "User.hpp"
#include <stdlib.h>

User::User() : AMonitorModule(true, "USER")
{
	this->_hostName[1023] = '\0';
	gethostname(this->_hostName, 1023);
	this->_userName = getenv("USERNAME") ? getenv("USERNAME") : "";
}

std::string User::getUserName() const
{
	return (_userName);
}

std::string User::getHostName() const
{
	return (this->_hostName);
}

User::~User()
{
}