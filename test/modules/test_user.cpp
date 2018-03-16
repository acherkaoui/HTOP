/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "../../modules/User.hpp"

int main()
{
	User user;


	std::cout << "Module Name : " << user.getModuleName() << std::endl;
	std::cout << "Display Status : " << user.isActive() << std::endl;
	std::cout << "Hostname : "<< user.getHostName() << std::endl;
	std::cout << "Username : " << user.getUserName() << std::endl;
	return 0;
}