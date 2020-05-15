#pragma once
#include "Person.h"
using namespace std;

class Viking : public Person
{
public:
	Viking()
		: Person(120)
	{
		Equip("hand axe");
	}
};