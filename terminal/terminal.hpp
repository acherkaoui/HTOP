/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by ilyes,
*/

#ifndef CPP_RUSH3_TERMINAL_HPP
#define CPP_RUSH3_TERMINAL_HPP

#include <ncurses.h>
#include <string>
#include "../core/Data.hpp"
#include <math.h>

class Curses {
	public:
	int _lines;
	int _cols;
	int _ch;
	int _xlogo;
	int _side;
	bool _status;
	Data data;
	WINDOW *_ram;
	WINDOW *_cpu;
	WINDOW *_time;
	WINDOW *_user;
	WINDOW *_net;

	public:
	Curses(Data &newData);
	Curses();
	~Curses();


	void refreshTerminal();
	void refreshTerminal(WINDOW *win);
	void clearTerminal();
	void closeTerminal();
	void closeTerminal(WINDOW *win);
	int getchTerminal();
	void progresBar();
	void print(WINDOW *win, int y, int x,const char *str, int color);
	void printRam();
	void printCpu();
	void printUser();
	void printTime();
	void printNet();
	void printLion();
	void moveWindow(WINDOW *win, int y, int x);
	std::string ProgressBar(WINDOW *win, int y, int x, float val);

};

#endif //CPP_RUSH3_TERMINAL_HPP
