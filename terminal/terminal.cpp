/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include <csignal>
#include "terminal.hpp"

Curses::Curses(Data &newData)
{
	_status = true;
	_xlogo = 70;
	_side = false;
	data = newData;
	initscr();
	noecho();
	curs_set(FALSE);
	keypad(stdscr,TRUE);

	_time = newwin(10, 26, LINES - 10, COLS - 27);
	_ram = newwin(20, 36, 1, COLS - 38);
	_user = newwin(15, 65, LINES - 15, 1);
	_cpu = newwin(20, 58, 1, 1);
	_net = newwin(15, 65, LINES - 15 - 18,1);

	assume_default_colors(COLOR_RED, COLOR_BLACK);
	start_color();
	init_pair(0, COLOR_GREEN, COLOR_GREEN);
	init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(2, COLOR_RED, COLOR_RED);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_WHITE);
	init_pair(7, COLOR_YELLOW, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
}

Curses::Curses()
{
	_status = true;
	_xlogo = 70;
	_side = false;
	initscr();
	noecho();
	curs_set(FALSE);
	keypad(stdscr,TRUE);

	_time = newwin(10, 26, LINES - 10, COLS - 27);

	_ram = newwin(20, 36, 1, COLS - 38);
	_user = newwin(15, 65, LINES - 15, 1);
	_cpu = newwin(20, 58, 1, 1);
	_net = newwin(15, 65, LINES - 15 - 18,1);

	assume_default_colors(COLOR_RED, COLOR_BLACK);
	start_color();
	init_pair(0, COLOR_GREEN, COLOR_GREEN);
	init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(2, COLOR_RED, COLOR_RED);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_WHITE);
	init_pair(7, COLOR_YELLOW, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
}

Curses::~Curses()
{
	endwin();
}

void Curses::refreshTerminal()
{

	refresh();
	refreshTerminal(_ram);
	refreshTerminal(_user);
	refreshTerminal(_cpu);
	refreshTerminal(_time);
	refreshTerminal(_net);
}

void Curses::print(WINDOW *win, int y, int x, const char *str, int color)
{
	wattron(win, COLOR_PAIR(color));
	mvwprintw(win, y, x, str);
	wattroff(win, COLOR_PAIR(color));
}

void Curses::printLion()
{
	int i = LINES / 2 - 13;
	int j = COLS / 2 - 20;

	print(stdscr, i++, j,"                   .:\\\\|||||||//:.", 5);
	print(stdscr, i++, j,"                  \\\\.-.\\|||||/.-.//", 4);
	print(stdscr, i++, j,"                  ==(   \\\\|||//   )==", 7);
	print(stdscr, i++, j,"                 ==/\\           /\\==", 5);
	print(stdscr, i++, j,"                 =//| __     __ |\\\\=", 4);
	print(stdscr, i++, j,"                  '//| \\O\\   /O/ |\\\\`", 7);
	print(stdscr, i++, j,"                  //|\\  \"   \"  /|\\\\", 5);
	print(stdscr, i++, j,"________________  /|||\\_`-v-'_/|||\\   _______________", 4);
	print(stdscr, i++, j,"\\_________      `-./|||\\._|_./|||\\ .-'     _________/", 7);
	print(stdscr, i++, j,"   \\________       |/|||\\___/|||\\|/      ________/", 5);
	print(stdscr, i++, j,"      \\_______     | /|||||||||\\ |     _______/", 4);
	print(stdscr, i++, j,"         \\______   |  //|||||\\\\  |   ______/", 7);
	print(stdscr, i++, j,"                `-.|   |/|||\\|   |.-'", 5);
	print(stdscr, i++, j,"         .ww.     _|   |     |   |_", 4);
	print(stdscr, i++, j,"       .\\WWW=    / |   |     |   | \\", 7);
	print(stdscr, i++, j,"       \\WWW=    |  |   |     |   |  |", 5);
	print(stdscr, i++, j,"       \\WW=     |  |   |     |   |  |", 4);
	print(stdscr, i++, j,"       ( (      |  |   \\     /   |  |", 7);
	print(stdscr, i++, j,"        \\ \\___.-'\\  \\   \\   /   /  /", 5);
	print(stdscr, i++, j,"         `-.__.-(...(...)---(...)...)", 4);
	print(stdscr, i++, j,"               abderrahim.cherkaoui", 5);
	i += 4;
	print(stdscr, i++, _xlogo,"      _____  _____  _____  _____  ", 5);
	print(stdscr, i++, _xlogo,"     |  |  ||  _  ||     ||_   _| ", 4);
	print(stdscr, i++, _xlogo,"     |     ||   __||  |  |  | |   ", 7);
	print(stdscr, i++, _xlogo,"     |__|__||__|   |_____|  |_|   ", 5);
	print(stdscr, i++, _xlogo,"     |__|__||__|   |_____|  |_|   ", 4);
	print(stdscr, i++, _xlogo,"           The Lion Monitor       ", 7);
}

void Curses::printRam()
{
	int i = 0;
	print(_ram , i++, 2, "                                  ", 2);
	print(_ram , i++, 2, ("                " +
		data.ram.getModuleName()).c_str(), 8);
	print(_ram , i++, 2, "                                  ", 2);
	i++;

	print(_ram, i++, 15, (std::to_string(data.ram.getPercentRam()).substr(0, 5) + "%%").c_str(), 5);
	print(_ram, i, 2, (" RAM:  "), 5);
	ProgressBar(_ram,i++,  9,data.ram.getPercentRam());

	wattron(_ram, COLOR_PAIR(5));
	mvwprintw(_ram, i++, 2, " Total RAM: %s        ", std::to_string(data.ram.getTotalRam()).c_str());
	mvwprintw(_ram, i++, 2, " Available RAM: %s      ", std::to_string(data.ram.getFreeRam()).c_str());
	wattroff(_ram, COLOR_PAIR(5));

	i++;
	print(_ram, i++, 15, (std::to_string(data.ram.getPercentSwap()).substr(0, 4) + "%%").c_str(), 4);
	print(_ram, i, 2, (" SWAP: "), 4);
	ProgressBar(_ram,i++, 9,data.ram.getPercentSwap());
	wattron(_ram, COLOR_PAIR(4));
	mvwprintw(_ram, i++, 2, " Total SWAP : %s    ", std::to_string(data.ram.getTotalSwap()).c_str());
	mvwprintw(_ram, i++, 2, " Available SWAP : %s     ", std::to_string(data.ram.getFreeSwap()).c_str());
	wattroff(_ram, COLOR_PAIR(4));

	i++;
	print(_ram , i++, 2, (" Tasks: " + std::to_string(data.ram.getProcesses()) + "         ").c_str(), 7);
	print(_ram , i++, 2, (" UpTime: " + data.ram.getUpTime()).c_str(), 7);
	i++;
	print(_ram , i++, 2, "                                  ", 2);
	mvwin(_ram  , 1, COLS - 38);
}

void Curses::printUser()
{
	int i = 0;
	print(_user, i++, 2, "                                     "
		"                   ", 2);
	print(_user, i++, 2, ("                         " +
		data.user.getModuleName()).c_str(), 8);
	print(_user, i++, 2, "                                     "
		"                   ", 2);
	i++;
	wattron(_user, COLOR_PAIR(5));
	mvwprintw(_user, i++, 2, " HostName: %s", data.user.getHostName().c_str());
	mvwprintw(_user, i++, 2, " UserName: %s", data.user.getUserName().c_str());
	wattroff(_user, COLOR_PAIR(5));
	i++;
	wattron(_user, COLOR_PAIR(4));
	mvwprintw(_user, i++, 2, " Os: %s", data.os.getOSName().c_str());
	mvwprintw(_user, i++, 2, " Version: %s", data.os.getVersion().c_str());
	wattroff(_user, COLOR_PAIR(4));
	i++;
	wattron(_user, COLOR_PAIR(7));
	mvwprintw(_user, i++, 2, " Machine: %s", data.os.getMachine().c_str());
	mvwprintw(_user, i++, 2, " Kernel: %s", data.os.getKernel().c_str());
	wattroff(_user, COLOR_PAIR(7));
	i++;
	print(_user, i++, 2, "                                     "
		"                   ", 2);
	mvwin(_user, LINES - 15, 1);
}


std::string Curses::ProgressBar(WINDOW *win, int y, int x, float val)
{
	std::string bar = "[                    ]";
	wattron(win, COLOR_PAIR(8));
	mvwaddch(win, y, x, ACS_CKBOARD);
	wattroff(win, COLOR_PAIR(8));
	int round = (int)floor(val / 5) *5;
	int nbBars = round / 5;
	int i;
	for (i = 1; i < nbBars - 1; i++)
	{
		if (i <= nbBars && i <= 6)
		{
			wattron(win, COLOR_PAIR(4));
			mvwaddch(win, y, x + i, ACS_CKBOARD);
			wattroff(win, COLOR_PAIR(4));
			bar[i] = '=';
		}
		else if (i <= nbBars && i <= 9)
		{
			wattron(win, COLOR_PAIR(7));
			mvwaddch(win, y, x + i, ACS_CKBOARD);
			wattroff(win, COLOR_PAIR(7));
			bar[i] = '=';
		}
		else if (i <= nbBars && i <= 23)
		{
			wattron(win, COLOR_PAIR(5));
			mvwaddch(win, y, x + i, ACS_CKBOARD);
			wattroff(win, COLOR_PAIR(5));
			bar[i] = '=';
		}
	}
	wattron(win, COLOR_PAIR(8));
	mvwaddch(win, y, x + 22, ACS_CKBOARD);
	wattroff(win, COLOR_PAIR(8));
	return bar;
}

void Curses::printNet()
{
	int x = 0;
	print(_net, x++, 2, "                                     "
		"                   ", 2);
	print(_net, x++, 2, ("                         " +
		data.network.getModuleName()).c_str(), 8);
	print(_net, x++, 2, "                                     "
		"                   ", 2);
	x++;
	wattron(_net, COLOR_PAIR(4));
	mvwprintw(_net, x++, 2, " Receive Bytes:\t%s        ", std::to_string(data.network.getInBytes()).c_str());
	mvwprintw(_net, x++, 2, " Transmit Bytes:\t%s        ", std::to_string(data.network.getOutBytes()).c_str());
	wattroff(_net, COLOR_PAIR(4));
	x++;
	wattron(_net, COLOR_PAIR(7));
	mvwprintw(_net, x++, 2, " Receive Packets:\t%s        ", std::to_string(data.network.getInPackets()).c_str());
	mvwprintw(_net, x++, 2, " Transmit Packets:\t%s        ", std::to_string(data.network.getOutPackets()).c_str());
	wattroff(_net, COLOR_PAIR(7));
	x++;
	print(_net, x++, 2, "                                     "
		"                   ", 2);

	mvwin(_net  , LINES - 15 - 18, 1);

}

void Curses::printCpu()
{
	int x = 0;
	print(_cpu, x++, 2, "                                     "
		"                   ", 2);
	print(_cpu, x++, 2, ("                         " +
		data.cpu.getModuleName()).c_str(), 8);
	print(_cpu, x++, 2, "                                     "
		"                   ", 2);

	x++;
	std::vector<CPUData> cpu = data.cpu.getStats();

	mvwprintw(_cpu, x++, 2, " Threads: %s", std::to_string(cpu.size()).c_str());
	x++;
	print(_cpu, x, 2, " cpu", 7);
	print(_cpu, x, 35, "Active", 8);
	print(_cpu, x++, 42, "Idle", 4);
	x++;

	for(size_t i = 0; i < cpu.size(); ++i) {
		print(_cpu, x, 2,  (" " + cpu[i].cpu).c_str(), 7);
		ProgressBar(_cpu, x, 9, cpu[i].active);
		print(_cpu, x, 32, ( "   " + std::to_string(cpu[i].active).substr(0, 5) + "%%").c_str(), 8);
		print(_cpu, x++, 40, ( "   " + std::to_string(cpu[i].idle).substr(0, 5) + "%%").c_str(), 4);
		x++;
	}
	print(_cpu, x++, 2, "                                     "
		"                   ", 2);

	mvwin(_cpu  , 1, 1);
}

void Curses::printTime()
{
	int i = 0;
	print(_time, i++, 2, "                        ", 2);
	print(_time, i++, 2, ("          " + data.clock.getModuleName()
		+  "         ").c_str(), 8);
	print(_time, i++, 2, "                        ", 2);
	i++;
	print(_time, i++, 2, ("  Local Time: " +
		data.clock.getTime()).c_str(), 4);
	i++;
	print(_time, i++, 2, ("  Date: " + data.clock.getUtc()).c_str(), 7);
	i++;
	print(_time, i++, 2, "                        ", 2);
	mvwin(_time , LINES - 10, COLS - 27);
}

void Curses::clearTerminal()
{
	int i = 4;
	wclear(stdscr);
	wclear(_ram);
	wclear(_cpu);
	wclear(_user);
	wclear(_time);
	wclear(_net);
	if(COLS > 200)
	{
		print(stdscr, i++, _xlogo, "  _____  _____  _____  _____  ", 5);
		print(stdscr, i++, _xlogo, " |  |  ||  _  ||     ||_   _| ", 4);
		print(stdscr, i++, _xlogo, " |     ||   __||  |  |  | |   ", 7);
		print(stdscr, i++, _xlogo, " |__|__||__|   |_____|  |_|   ", 5);
		print(stdscr, i++, _xlogo, " |__|__||__|   |_____|  |_|   ", 4);
		print(stdscr, i++, _xlogo, "       The Lion Monitor       ", 7);
		print(stdscr, i++, _xlogo, "                              ", 7);
		printLion();
	}
	if(_xlogo == COLS - 30 - 45)
		_side = false;
	else if(_xlogo == 69)
		_side = true;
	if(_side != 0)
		_xlogo++;
	else
		_xlogo--;
}

void Curses::refreshTerminal(WINDOW *win)
{
	wrefresh(win);
}

void Curses::closeTerminal(WINDOW *win)
{
	delwin(win);
}

void Curses::closeTerminal()
{
	closeTerminal(_ram);
	closeTerminal(_user);
	closeTerminal(_cpu);
	closeTerminal(_time);
//	clearTerminal(_net);
	endwin();
}

int Curses::getchTerminal()
{
	_ch = getch();
	if (_ch == KEY_ENTER)
	{
		printw("UP");
	}
	else if(_ch == KEY_DOWN)
	{
		wprintw(_ram, "DOWN");
		waddch(_ram, 'B');
	}
	wclear(stdscr);
	wclear(_ram);
	wclear(_cpu);
	wclear(_user);
	wclear(_time);
	return _ch;
}

void Curses::progresBar()
{
	printw("[================]");
}

void Curses::moveWindow(WINDOW *win, int y, int x)
{
	wmove(win, y, x);
}

