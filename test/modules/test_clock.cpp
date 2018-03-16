/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "../../modules/Clock.hpp"

int main()
{
	Clock clock;


	std::cout << "Module Name : " << clock.getModuleName() << std::endl;
	std::cout << "Display Status : " << clock.isActive() << std::endl;
	std::cout << "Time : " << clock.getTime() << std::endl;
	std::cout << "UTC : "<< clock.getUtc() << std::endl;
	return 0;
}