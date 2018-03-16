/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "../../modules/Network.hpp"

int main()
{
	Network network;

	std::cout << "Module Name : " << network.getModuleName() << std::endl;
	std::cout << "Display Status : " << network.isActive() << std::endl;
	network.setActive(false);
	std::cout << "Display Status after setActive : " << network.isActive() << std::endl;

	std::cout << "Receive Bytes : " << network.getInBytes() << std::endl
		<< "Receive Packets : " << network.getInPackets() << std::endl
		<< "Transmit Bytes : " << network.getOutBytes() << std::endl
		<< "Transmit Packets : " << network.getOutPackets() << std::endl;
}