/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "../../modules/OperatingSystem.hpp"
#include <iostream>

int main()
{
	OperatingSystem OS;

	std::cout << "Module Name : " << OS.getModuleName() << std::endl;
	std::cout << "Display Status : " << OS.isActive() << std::endl;
	std::cout << "Kernel: " << OS.getKernel() << "\n"
		<< "OS: " << OS.getOSName() << "\n"
		<< "Machine: " << OS.getMachine() << "\n"
		<< "Version: " << OS.getVersion() << std::endl;
	return 0;
}