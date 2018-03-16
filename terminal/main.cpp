/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "terminal.hpp"

#define DELAY 10000

int main() {
	Curses terminal;
	while(1) {

		terminal.clearTerminal();
		terminal.refreshTerminal();
		sleep(1);
		usleep(DELAY);
	}
}
