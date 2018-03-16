/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include <SFML/Graphics.hpp>
#include "graphic.hpp"
#include "HpotMenu.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Monitor");
	HpotMenu menu(&window);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}
		window.clear(sf::Color::Black);
		menu.draw();
		window.display();
	}
	//sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue
	return 0;
}