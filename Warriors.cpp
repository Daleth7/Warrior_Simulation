#include "Warriors.h"

#include <list>
#include <cstdlib>
#include <string>
#include <initializer_list>

using std::list;
using std::string;
using std::initializer_list;
	//Global constants for use in multiple functions/modules
const double
	__gravity(9.81),
	__average_bfat_ratio(0.15)
;
const unsigned name_num(15);
const string setnames[name_num] = {
	"Bobby Jones", "Billy the Kid", "Occam",
	"Yoda", "C#", "Parry Hotter", 
	"Lola Gitner", "Tammy Roan", "Tommy Dirsk", 
	"Michael Jackson", "Jack Finley", "Dudette"
		//+1 internet cookie if you get the references
	"Red", "Green", "Blue"
};
const int	//Maximum values
	max__accuracy(1),
	max__evasion_chance(1),
	max__intelligence(200),
	max__mass(150),
	max__height(3),
	max__strength(5500),
	max__swiftness(4),
		//Compensate for truncation by adding 0.5
	max__stamina(max__mass*__average_bfat_ratio*(__gravity+0.5)*max__height),
	max__hunger(85),
	max__speed(10),
	max__mental_fortitude(100)
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
	for(; liter != left.end(); ++liter, ++riter){
		if(*liter != *riter)
			return false;
	}
	return true;
}
/*********************Member functions of the Warrior Class************/
void Warrior::Attack(Warrior&, int=0);
Warrior Warrior::Defend();
Warrior Warrior::Counterattack();
Warrior Warrior::Run();

bool Warrior::Alive()const{return __alive;}
list<double> Warrior::Attributes()const{
	return {
		__accuracy, __evasion_chance, __intelligence,
		__mass, __height, __strength, 
		__swiftness, __stamina, __hunger,
		__speed, __mental_fortitude
	};
}
string Warrior::Name()const{return __name;}
Condition_t Warrior::Status()const{return __condition;}

void Warrior::Equip(const Weapon* newwep, const Armor* newarm);
void Warrior::Equip_from_Inventory(Weapon_t choice);
void Warrior::Unequip();
void Warrior::Unequip(Weapon_t choice, Armor_t choice)
void Warrior::Store(const Weapon* newwep, const Armor* newarm);

Warrior::Warrior():
	alive(true)
{
		//Set name
	__name = setnames[ rand()%15 ];
	
		//Set attribute values
	__accuracy 			= Generate_Rand_Val(max__accuracy);
	__evasion_chance	= Generate_Rand_Val(max__evasion_chance);
	__intelligence		= Generate_Rand_Val(max__intelligence);
	__mass				= Generate_Rand_Val(max__mass);
	__height 			= Generate_Rand_Val(max__height);
	__strength			= Generate_Rand_Val(max__strength);
	__swiftness			= Generate_Rand_Val(max__swiftness);
	__stamina 			= Generate_Rand_Val(max__stamina);
	__hunger 			= Generate_Rand_Val(max__hunger);
	__speed 			= Generate_Rand_Val(max__speed);
	__mental_fortitude	= Generate_Rand_Val(max__mental_fortitude);
}
Warrior::Warrior(W_Template newattr, const string& newname):
	__name(newname), __alive(true);
{
	switch(newattr){
		case Strongman:
			__accuracy			= max__accuracy*0.6;
			__evasion_chance	= max__evasion_chance*0.4;
			__intelligence		= max__intelligence/2;
			__mass				= max__mass*8/15;
			__height			= max__height*0.6;
			__strength			= max__strength*10/11;
			__swiftness			= max__swiftness/4;
			__stamina			= max__stamina*2/3;
			__hunger			= max__hunger*3/4;
			__speed				= max__speed/5;
			__mental_fortitude	= max__mental_fortitude*2/3;
			break;
		case Sharpeye:
			__accuracy			= max__accuracy*0.85;
			__evasion_chance	= max__evasion_chance*0.64;
			__intelligence		= max__intelligence*0.6;
			__mass				= max__mass*0.45;
			__height			= max__height*0.37;
			__strength			= max__strength*9/22;
			__swiftness			= max__swiftness/2;
			__stamina			= max__stamina*2/3;
			__hunger			= max__hunger/2;
			__speed				= max__speed*0.9;
			__mental_fortitude	= max__mental_fortitude/2;
			break;
	/*...........*/
		default:	Warrior();	break;
	}
}
Warrior::Warrior(const initializer_list<double>& newattr, const string& newname):
	__name(newname), __alive(true)
{
	auto iter = newattr.begin();
	__accuracy			= *iter;
	__evasion_chance	= *(++iter);
	__intelligence		= *(++iter);
	__mass				= *(++iter);
	__height			= *(++iter);
	__strength			= *(++iter);
	__swiftness			= *(++iter);
	__stamina			= *(++iter);
	__hunger			= *(++iter);
	__speed				= *(++iter);
	__mental_fortitude	= *(++iter);
}
Warrior::Warrior(const Warrior& original){Swap_Var(original);}
Warrior& Warrior::operator=(const Warrior& original){
	if(this != &original)
		Swap_Var(original);
	return *this;
}

Warrior::~Warrior(){
		//These should be deleted iff we use smart pointers
	for(auto iter = __equippedw.begin(); iter != __equippedw.end(); iter++)
		delete iter;
	for(auto iter = __ownedw.begin(); iter != __ownedw.end(); iter++)
		delete iter;
	for(auto iter = __equippeda.begin(); iter != __equippeda.end(); iter++)
		delete iter;
	for(auto iter = __owneda.begin(); iter != __owneda.end(); iter++)
		delete iter;
}

double Warrior::Generate_Rand_Val(const int& max_value){
	return max_value - rand()%max_value - double(rand()%RAND_MAX)/RAND_MAX;
}
void Warrior::Swap_Var(const Warrior& original){
	__name 				= original.__name;
	__alive 			= original.__alive;
	__accuracy 			= original.__accuracy;
	__evasion_chance 	= original.__evasion_chance;
	__intelligence 		= original.__intelligence;
	__mass 				= original.__mass;
	__height 			= original.__height;
	__strength 			= original.__strength;
	__swiftness 		= original.__swiftness;
	__stamina			= original.__stamina;
	__hunger 			= original.__hunger;
	__speed 			= original.__speed;
	__mental_fortitude	= original.__mental_fortitude;
	//   __equippedw
	__equippedw.clear();
	__equippedw.resize(original.__equippedw.size());
	for(
		auto iter_this = __equippedw.begin(), iter_o = original.__equippedw.begin();
		iter_o != original.__equippedw.end();
		++iter_this, ++iter_o
	){
		iter_this = new Weapon;
		(*iter_this) = (*iter_o);
	}
	//   __ownedw
	__ownedw.clear();
	__ownedw.resize(original.__ownedw.size());
	for(
		auto iter_this = __ownedw.begin(), iter_o = original.__ownedw.begin();
		iter_o != original.__ownedw.end();
		++iter_this, ++iter_o
	){
		iter_this = new Weapon;
		(*iter_this) = (*iter_o);
	}
	//   __equippeda
	__equippeda.clear();
	__equippeda.resize(original.__equippeda.size());
	for(
		auto iter_this = __equippeda.begin(), iter_o = original.__equippeda.begin();
		iter_o != original.__equippeda.end();
		++iter_this, ++iter_o
	){
		iter_this = new Armor;
		(*iter_this) = (*iter_o);
	}
	//   __owneda
	__owneda.clear();
	__owneda.resize(original.__owneda.size());
	for(
		auto iter_this = __owneda.begin(), iter_o = original.__owneda.begin();
		iter_o != original.__owneda.end();
		++iter_this, ++iter_o
	){
		iter_this = new Armor;
		(*iter_this) = (*iter_o);
	}
	
	__available_amm = original.__available_amm;
	__condition = orignal.__condition;
}
/*****************End Member functions of the Warrior Class************/
