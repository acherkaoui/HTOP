/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include <SFML/Graphics.hpp>
#include "HpotMenu.hpp"

void HpotMenu::initTitle()
{
	text.setFont(font);
	text.setCharacterSize(16);
	text.setString("HPOT");
	text.setColor(sf::Color::Black);
	text.setPosition(100, 110);
	text.setStyle(sf::Text::Bold);
}

HpotMenu::HpotMenu(sf::RenderWindow *windowApp)
{
	window = windowApp;

	if (!logoTexture.loadFromFile("./assets/logo.png")) {
		exit(84);
	}
	if (!font.loadFromFile("./assets/robotoMono.ttf")) {
		exit(84);
	}
	panel.setSize(sf::Vector2f((float)(WIDTH * 0.2), HEIGHT));
	panel.setFillColor(sf::Color(255,184,28));
	rightWindow.setSize(sf::Vector2f(WIDTH - (float)(WIDTH * 0.2), HEIGHT));
	rightWindow.setFillColor(sf::Color(71,81,91));
	rightWindow.setPosition((float)(WIDTH * 0.2), 0);
	logo.setTexture(logoTexture);
	logo.scale(0.25, 0.25);
	initTitle();
}

HpotMenu::~HpotMenu()
{
}

void HpotMenu::drawOs()
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

void HpotMenu::drawUser()
{
	if (!pc.user.isActive())
		return;
	int height = (int)(HEIGHT * 0.25) + (50 * 4 + 40);
	std::vector<std::string> name{"User", "Host Name"};
	std::vector<std::string> userProps{pc.user.getUserName(),
					  pc.user.getHostName()};

	text.setCharacterSize(16);
	text.setColor(sf::Color::Black);
	for (unsigned int i = 0; i < name.size(); i++) {
		text.setPosition(20, height);
		text.setStyle(sf::Text::Bold);
		text.setString(name[i]);
		window->draw(text);

		text.setPosition(20, height + 20);
		text.setStyle(sf::Text::Regular);
		text.setString(userProps[i]);
		window->draw(text);
		height += 50;
	}
}

void HpotMenu::drawClock()
{
	if (!pc.clock.isActive())
		return;
	int height = (int)(HEIGHT * 0.25) + 450;

	text.setCharacterSize(16);
	text.setColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);
	text.setPosition(20, height);
	text.setString("Clock");
	window->draw(text);

	text.setPosition(20, height + 20);
	text.setStyle(sf::Text::Regular);
	text.setString(pc.clock.getUtc());
	window->draw(text);

	sf::RectangleShape box;
	box.setSize(sf::Vector2f(200, 20));
	box.setFillColor(sf::Color::White);
	box.setPosition(sf::Vector2f(20, height + 40));
	text.setPosition(sf::Vector2f(25, height + 40));
	text.setString(pc.clock.getTime());
	box.setOutlineColor(sf::Color::Black);
	box.setOutlineThickness(1.0);
	window->draw(box);
	window->draw(text);
}

void HpotMenu::drawWidgets()
{
	sf::RectangleShape widgetBox;
	sf::Vector2f pos((float)(WIDTH * 0.2) + 150, 100.0);
	std::vector<sf::Vector2f> area{
		sf::Vector2f(pos.x, pos.y),
		sf::Vector2f(pos.x, pos.y + 400),
		sf::Vector2f(pos.x + 400, pos.y),
		sf::Vector2f(pos.x + 400, pos.y + 400)
	};

	widgetBox.setSize(sf::Vector2f(300, 200));
	widgetBox.setFillColor(sf::Color(61,71,81));
	widgetBox.setOutlineThickness(2.0);
	widgetBox.setOutlineColor(sf::Color(255,184,28));

	for (unsigned int i = 0; i < area.size(); i++) {
		widgetBox.setPosition(area[i]);
		window->draw(widgetBox);
	}
}

void HpotMenu::draw()
{
	window->draw(panel);
	window->draw(rightWindow);
	window->draw(logo);
	window->draw(text);
	drawOs();
	drawUser();
	drawClock();
	drawWidgets();
}
