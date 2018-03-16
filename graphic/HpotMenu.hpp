/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#ifndef CPP_RUSH3_HPOTMENU_HPP
#define CPP_RUSH3_HPOTMENU_HPP

#include <SFML/Graphics.hpp>
#include "../core/Data.hpp"
#include "graphic.hpp"

class HpotMenu
{
	public:
	HpotMenu(sf::RenderWindow *windowApp);
	void initTitle();
	virtual ~HpotMenu();

	sf::RenderWindow *window;

	void drawOs();
	void drawUser();
	void drawClock();
	void drawWidgets();
	void draw();


	private:
	Data pc;
	sf::RectangleShape panel;
	sf::RectangleShape rightWindow;
	sf::Sprite logo;
	sf::Texture logoTexture;
	sf::Font font;
	sf::Text text;

};

#endif /* CPP_RUSH3_HPOTMENU_HPP */
