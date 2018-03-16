/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "../../modules/CPU.hpp"

int main()
{
	Cpu cpu;
	std::cout << "Module Name : " << cpu.getModuleName() << std::endl;
	std::cout << "Display Status : " << cpu.isActive() << std::endl;
	cpu.PrintStats();
	return 0;
}