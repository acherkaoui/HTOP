/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include <string>
#include <iostream>
#include <math.h>

std::string ProgressBar(float val)
{
	std::string bar = "[                    ]";
	int round = (int)floor(val / 5) *5;
	int nbBars = round / 5;

	for (int i = 1; i < bar.size() - 1; i++)
	{
		if (i <= nbBars)
			bar[i] = '=';
	}
	return bar;
}

int main(int ac, char **av)
{
	float n = atof(av[1]);

	std::cout << ProgressBar(n) << std::endl;
	return 0;
}