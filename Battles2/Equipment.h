#pragma once
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Equipment
{
	list<string> _inventory;
	int _bucklerLife;
	bool _bucklerTwo;

	int _greatSword;

public:

	// Permet d ajouter un item a inventaire
	void AddItem(const string &item)
	{
		_inventory.push_back(item);

		if (item == "buckler")
		{
			_bucklerLife = 3;
			_bucklerTwo = false;
		}

		if (item == "Great Sword")
			_greatSword = 0;
	}

	// Affecter le nombre de degats
	int GetDamage()
	{
		int dmg;

		if (HasItem("Great Sword"))
		{
			if (_greatSword < 2)
			{
				dmg = 12;
				_greatSword++;
			}
			else
			{
				dmg = 0;
				_greatSword = 0;
			}
		}
		if (HasItem("hand sword"))
			dmg = 5;
		if (HasItem("hand axe"))
			dmg = 6;

		if (HasItem("armor"))
			dmg -= 1;

		return dmg;
	}

	// Renvoi l'existance d'un item
	bool HasItem(const string &an_item) const
	{
		for (const string &item : _inventory)
			if (item == an_item)
				return true;

		return false;
	}

	// Permet de bloquer en fonction du type d'arme
	bool Block(bool from_axe)
	{
		if (HasItem("buckler"))
		{
			_bucklerTwo = !_bucklerTwo;

			if (_bucklerTwo)
			{
				if (from_axe)
				{
					_bucklerLife--;

					if (_bucklerLife == 0)
						_inventory.remove("buckler");
				}

				return true;
			}
		}

		return false;
	}
};