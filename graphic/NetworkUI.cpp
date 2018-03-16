/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "NetworkUI.hpp"

NetworkUI::NetworkUI()
{
}

NetworkUI::~NetworkUI()
{
}

void NetworkUI::drawOs()
{
	if (!pc.os.isActive())
		return;
	auto height = (int)(HEIGHT * 0.25);
	std::vector<std::string> name{"OS", "Kernel", "Version", "Machine"};
	std::vector<std::string> osProps{pc.os.getOSName(),
		pc.os.getKernel(),
		pc.os.getVersion().substr(0,
			pc.os.getVersion().find(" ")),
		pc.os.getMachine()
	};
	text.setCharacterSize(16);
	text.setColor(sf::Color::Black);
	for (unsigned int i = 0; i < name.size(); i++) {
		text.setPosition(20, height);
		text.setStyle(sf::Text::Bold);
		text.setString(name[i]);
		window->draw(text);

		text.setPosition(20, height + 20);
		text.setStyle(sf::Text::Regular);
		text.setString(osProps[i]);
		window->draw(text);
		height += 50;
	}

}



