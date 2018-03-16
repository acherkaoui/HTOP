/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#ifndef CPP_RUSH3_USER_HPP
#define CPP_RUSH3_USER_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include "AMonitorModule.hpp"

class User : public AMonitorModule
{
	public:
	User();
	~User();

	public:
	std::string getUserName() const;
	std::string getHostName() const;

	private:
	char _hostName[1023];
	std::string _userName;

};

#endif //CPP_RUSH3_USER_HPP
