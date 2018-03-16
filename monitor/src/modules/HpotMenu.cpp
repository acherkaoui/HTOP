/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by monty.criel@epitech.eu,
*/

#include <SFML/Graphics.hpp>
#include "HpotMenu.hpp"
#include "../../main.hpp"

HpotMenu::HpotMenu(sf::RenderWindow *windowApp)
{
	window = windowApp;
}

HpotMenu::~HpotMenu()
{
}

void HpotMenu::draw()
{
	sf::RectangleShape line(sf::Vector2f((float)(WIDTH * 0.2), 5));
}
