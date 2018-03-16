/*
** EPITECH PROJECT, 2021
** cpp_rush3
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include "AMonitorModule.hpp"

AMonitorModule::AMonitorModule(bool _active, const std::string &_name)
	: _active(_active), _name(_name)
{
}

std::string AMonitorModule::getModuleName() const
{
	return _name;
}

bool AMonitorModule::isActive() const
{
	return _active;
}

void AMonitorModule::setActive(bool _active)
{
	AMonitorModule::_active = _active;
}
