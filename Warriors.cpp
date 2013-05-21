#include "Warriors.h"

#include <list>
#include <cstdlib>
#include <string>

using std::list;
using std::string;
	//Global constants
const double
	__gravity(9.81),
	__average_bfat_ratio(0.25)
;

bool operator==(const Warrior& lhs,const Warrior& rhs){
	if(
		lhs.Name() != rhs.Name() ||
		lhs.Alive() != rhs.Alive() ||
		lhs.Status() != rhs.Status()
	)	return false;

	list<double>
		left = lhs.Attributes(),
		right = rhs.Attributes()
	;
		auto liter = left.begin();
		auto riter = right.begin();
	for(; liter != left.end(); ++liter){
		if(*liter != *riter)
			return false;
	}
	return true;
}
/*********************Member functions of the Warrior Class************/
void Attack(Warrior&, int=0);
Warrior Defend();
Warrior Counterattack();
Warrior Run();

bool Alive()const;
list<double> Attributes()const;
string Name()const;
Condition_t Status()const;

Warrior():
	alive(true)
{
		//Set name
	const unsigned name_num(15);
	string setnames[name_num] = {
		"Bobby Jones", "Billy the Kid", "Occam",
		"Yoda", "C#", "Parry Hotter", 
		"Lola Gitner", "Tammy Roan", "Tommy Dirsk", 
		"Michael Jackson", "Jack Finley", "Dudette"
			//+1 internet cookie if you get the references
		"Red", "Green", "Blue"
	};
	__name = setnames[ rand()%15 ];
	
		//Set attribute values
	const int	//Maximum values
		max__accuracy(1),
		max__evasion_chance(1),
		max__intelligence(200),
		max__mass(600),
		max__height(3),
		max__strength(5500),
		max__swiftness(4),
			//Compensate for truncation by adding 1
		max__stamina(max__mass*__average_bfat_ratio*(__gravity+1)*max__height),
		max__hunger(85),
		max__speed(10),
		max__mental_fortitude(100)
	;
	__accuracy = Generate_Rand_Val(max__accuracy);
	__evasion_chance = Generate_Rand_Val(max__evasion_chance);
	__intelligence = Generate_Rand_Val(max__intelligence);
	__mass = Generate_Rand_Val(max__mass);
	__height = Generate_Rand_Val(max__height);
	__strength = Generate_Rand_Val(max__strength);
	__swiftness = Generate_Rand_Val(max__swiftness);
	__stamina = Generate_Rand_Val(max__stamina);
	__hunger = Generate_Rand_Val(max__hunger);
	__speed = Generate_Rand_Val(max__speed);
	__mental_fortitude = Generate_Rand_Val(max__mental_fortitude);
}
Warrior(W_Template);
Warrior(initializer_list<double>);
Warrior(const Warrior&);
Warrior& operator=(const Warrior&);

~Warrior();

double Generate_Rand_Val(const int& max_value){
	return max_value - rand()%max_value + double(rand()%RAND_MAX)/RAND_MAX;
}
/*****************End Member functions of the Warrior Class************/