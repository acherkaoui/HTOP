/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#ifndef CPP_RUSH3_CPU_HPP
#define CPP_RUSH3_CPU_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <thread>
#include "AMonitorModule.hpp"

enum {S_USER, S_NICE, S_SYSTEM, S_IDLE, S_IOWAIT, S_IRQ, S_SOFTIRQ, S_STEAL,
	S_GUEST, S_GUEST_NICE};

const int NUM_CPU_STATES = 10;

typedef struct CPUData_s {

	std::string cpu;
	std::size_t times[NUM_CPU_STATES];
	float active;
	float idle;
} CPUData;

class Cpu : public AMonitorModule
{
	public:
	Cpu();
	virtual ~Cpu() = default;

	public:
	void updateCpu(std::vector<CPUData> &, std::vector<CPUData> &);
	std::vector<CPUData> getStats();
	void PrintStats();
};

#endif //CPP_RUSH3_CPU_HPP
