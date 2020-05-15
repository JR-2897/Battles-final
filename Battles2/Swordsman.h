#pragma once
#include <string>
#include "Person.h"
using namespace std;

class Swordsman : public Person
{
public:
	Swordsman(string level = string())
		: Person(100)
	{
		Equip("hand sword");
	}
};