/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#ifndef CPP_RUSH3_AMONITORMODULE_HPP
#define CPP_RUSH3_AMONITORMODULE_HPP

#include <string>

#include "IMonitorModule.hpp"

class AMonitorModule : public IMonitorModule
{
	protected:
	bool _active;
	std::string _name;

	public:
	explicit AMonitorModule(bool _active = false, const std::string &_name = "");
	virtual ~AMonitorModule() = default;

	std::string getModuleName() const override;
	bool isActive() const override;

	void setActive(bool _active) override;
};

#endif //CPP_RUSH3_AMONITORMODULE_HPP
