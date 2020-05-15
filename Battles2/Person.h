#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include "Equipment.h"
using namespace std;

class Person
{
	int _hitPoints;
	Equipment _equipment;
	string _level;
	int round = 0;

public:
	Person(int hp)
	{
		_hitPoints = hp;
	}

	int HitPoints() const
	{
		return _hitPoints;
	}

	string Level() const
	{
		return _level;
	}

	void Equip(const string &item)
	{
		_equipment.AddItem(item);
	}

	// Fonction permettant le combat
	void Engage(Person &opponent)
	{
		
		while (HitPoints() > 0 && opponent.HitPoints() > 0)
		{
			if (round % 2 == 0)
				Attack(opponent);
			
			else
				opponent.Attack(*this);

			round++;
		}
	}

	// Fonction permettant de savoir si on peut infliger les degats
	void Attack(Person &opponent)
	{
		if (!opponent.Block(*this))
			opponent.DoDamage(_equipment.GetDamage(), *this);

	}

	// Fonction permettant de bloque une attaque de hache
	bool Block(Person &opponent)
	{
		return _equipment.Block(opponent._equipment.HasItem("hand axe"));
	}

	// Fonction permet d infliger les degats
	void DoDamage(int damage, Person me)
	{
		if (_equipment.HasItem("armor"))
			damage -= 3;
		if (me.Level() == "Vicious" && round < 2)
			damage += 20;
		if (me.Level() == "Veteran" && _hitPoints < 45)
			damage *= 2;

		_hitPoints -= min(damage, _hitPoints);
	
	}
};