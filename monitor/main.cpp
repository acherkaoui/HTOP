/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include <SFML/Graphics.hpp>
#include "../core/Data.hpp"
#include "main.hpp"
#include "src/modules/HpotMenu.hpp"

void launchHpot()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Monitor");
	HpotMenu menu(&window);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		menu.draw();
		window.display();
	}
}

int main()
{
	launchHpot();
	return 0;
}