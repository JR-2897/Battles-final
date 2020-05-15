#pragma once
#include <string>
#include "Person.h"
using namespace std;

class Highlander : public Person
{
public:
	Highlander(string level = string())
		: Person(150)
	{
		Equip("Great Sword");
	}
};