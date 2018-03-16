/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "../../modules/RAM.hpp"
#include <iostream>

int main()
{
	RAM RAM;

	std::cout << "Module Name : " << RAM.getModuleName() << std::endl;
	std::cout << "Display Status : " << RAM.isActive() << std::endl;
	std::cout << "Total RAM : " << RAM.getTotalRam() << "\n"
		<< "Free RAM : " << RAM.getFreeRam() << "\n"
		<< "Percent Used RAM : " << RAM.getPercentRam() << " %" << "\n"
		<< "Total SWAP : " << RAM.getTotalSwap() << "\n"
		<< "Free SWAP : " << RAM.getFreeSwap() << "\n"
		<< "Percent Used SWAP : " << RAM.getPercentSwap() << " %" << "\n"
		<< "Total UPTIME : " << RAM.getUpTime() << std::endl
		<< "Processes : " << RAM.getProcesses() << std::endl;
	return 0;
}