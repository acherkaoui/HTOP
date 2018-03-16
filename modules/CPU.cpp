/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "CPU.hpp"


Cpu::Cpu() : AMonitorModule(true, "CPU")
{
}

static size_t GetIdleTime(const CPUData &data)
{
	return  (data.times[S_IDLE] +
		data.times[S_IOWAIT]);
}

static size_t GetActiveTime(const CPUData &data)
{
	return  (data.times[S_USER] +
		data.times[S_NICE] +
		data.times[S_SYSTEM] +
		data.times[S_IRQ] +
		data.times[S_SOFTIRQ] +
		data.times[S_STEAL] +
		data.times[S_GUEST] +
		data.times[S_GUEST_NICE]);
}

 void ReadStatsCpu(std::vector<CPUData> &stat)
{
	std::ifstream fileStat("/proc/stat");
	std::string line;

	const std::string STR_CPU("cpu");
	const std::size_t LEN_STR_CPU = STR_CPU.size();
	const std::string STR_TOT("tot");

	while(std::getline(fileStat, line)) {
		if(!line.compare(0, LEN_STR_CPU, STR_CPU)) {
			std::istringstream stringstream(line);

			stat.emplace_back(CPUData());
			CPUData &entry = stat.back();

			stringstream >> entry.cpu;
			if (entry.cpu.size() > LEN_STR_CPU)
				entry.cpu.erase(0, LEN_STR_CPU);
			else
				entry.cpu = STR_TOT;
			for (int i = 0; i < NUM_CPU_STATES; ++i)
				stringstream >> entry.times[i];
		}
	}
}

void Cpu::updateCpu(std::vector<CPUData> &stat1, std::vector<CPUData> &stat2)
{
	ReadStatsCpu(stat1);

	// 100ms pause
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	ReadStatsCpu(stat2);

}

std::vector<CPUData> Cpu::getStats()
{
	std::vector<CPUData> stat1;
	std::vector<CPUData> stat2;
	std::vector<CPUData> cpu;

	this->updateCpu(stat1, stat2);
	const size_t NUM_STAT = stat1.size();

	for(size_t i = 0; i < NUM_STAT; ++i) {
		const float ACTIVE_TIME	= static_cast<float>(
			GetActiveTime(stat2[i]) -
				GetActiveTime(stat1[i]));
		const float IDLE_TIME	= static_cast<float>(
			GetIdleTime(stat2[i]) - GetIdleTime(stat1[i]));
		const float TOTAL_TIME	= ACTIVE_TIME + IDLE_TIME;

		cpu.emplace_back(CPUData());
		CPUData &entry = cpu.back();

		entry.cpu = stat1[i].cpu;
		entry.active = 100.f * ACTIVE_TIME / TOTAL_TIME;
		entry.idle = 100.f * IDLE_TIME / TOTAL_TIME;
	}
	return (cpu);
}

void Cpu::PrintStats()
{
	std::vector<CPUData> cpu = this->getStats();
	const size_t NUM_STAT = cpu.size();

	for(size_t i = 0; i < NUM_STAT; ++i) {

		std::cout.width(3);
		std::cout << cpu[i].cpu << "] ";
		std::cout << "active: ";
		std::cout.setf(std::ios::fixed, std::ios::floatfield);
		std::cout.width(6);
		std::cout.precision(2);
		std::cout << cpu[i].active << "%";

		std::cout << " - idle: ";
		std::cout.setf(std::ios::fixed, std::ios::floatfield);
		std::cout.width(6);
		std::cout.precision(2);
		std::cout << cpu[i].active << "%" << std::endl;

		std::cout << std::endl;
	}
}

