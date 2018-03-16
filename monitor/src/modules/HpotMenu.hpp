/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by monty.criel@epitech.eu,
*/

#ifndef CPP_RUSH3_HPOTMENU_HPP
#define CPP_RUSH3_HPOTMENU_HPP

#include "../../../core/Data.hpp"

class HpotMenu
{
	public:
	HpotMenu(sf::RenderWindow *windowApp);
	virtual ~HpotMenu();

	Data pc;
	sf::RenderWindow *window;

	void draw();
};

#endif /* CPP_RUSH3_HPOTMENU_HPP */
