/** To-do
	-party class
	-Consider implementing consumable items in storage
**/
//There are placeholder names because they have not been defined
//   in other classes/enums; these names will be marked
#ifndef WARRIORS_H
#define WARRIORS_H
	
#include <list>
#include <map>
#include <string>
#include <initializer_list>

#include "Weapons.h"
#include "Armor.h"

using std::list;
using std::map;
using std::string;
using std::initializer_list;
//Strongly typed because these should never 
//   be compared with primitive types
	//These are associated with a set of equipment
	//   and one Attr_Template
enum class W_Template{
	Knight,
	Demolitionist,
	Medic,
	Sniper,
	Rogue,
	Archer,
	/*...*/
};
	//These are associated with certain,
	//   set attribute values
enum class Attr_Template{
	Strongman,
	Sharpeye,
	Obese,
	Athlete
	/*...*/
};
	//These are associated with certain attribute drops
enum class Condition_t{
	Cold,
	Broken_Leg,
	Burned,
	Enraged
	/*...*/
};
enum class Attack_t{
	Punch,
	Slice,
	Tackle,
	Shoot
	/*...*/
};
	//Prototype Warrior, so the associated non-member functions
	//   can be shown before the class
class Warrior;
	//Test if two warriors have the same attributes and name
bool operator==(const Warrior&,const Warrior&);
	//Base warrior on a template and return a new object on the heap
Warrior* CraftWarrior(W_Template, const string&="");

class Warrior{
	public:
			//Action functions
			//int is for the target's reaction:
			//   defend(1), counterattack(2), run(3),
			//   or nothing(0)
			//   -call respective defend/counterattack
			//   -swap change in stamina or alive variables
			//   between copy and original objects
			//   -Check hit points of both warriors and determine
			//   if the warrior is dead or not
		void Attack(Warrior&, int=0);
			//Read-only functions
		bool Alive()const;
		list<double> Attributes()const;
		string Name()const;
		Condition_t Status()const;
			//Inventory functions
			//   using "Weapon_t" and "Armor_T" as a 
			//   placeholder for enums because I cannot
			//   figure out how to implement choices without
			//   one
		void Equip(const Weapon* =nullptr, const Armor* =nullptr);
		void Equip_from_Inventory(Weapon_t=NONE);
		void Unequip();
		void Unequip(Weapon_t=NONE, Armor_t=NONE)
		void Store(const Weapon* =nullptr, const Armor* =nullptr);
			/***Ammunition_t is a current placeholder***/
		void Store_Amm(Ammunition_t,unsigned);
			//In the event that the warrior's attributes are temporarily changed;
			//Takes in a set of changes and adds those changes to the returned
			//   Warrior object
		Warrior Temporary(const list<double>&);
		void SetCondition(Condition_t);
			//Initializes attribute variables with
			//   random values and no equipment;
			//   Explicit to avoid implicit calls
		explicit Warrior(const string&="");
		Warrior(Attr_Template,const string&);
			//Set attributes manually;
			//   order follows member double variables;
			//   0 will indicate attribute value to be 
			//   randomized
		Warrior(const initializer_list<double>&,const string&);
			//Deal with pointers
		Warrior(const Warrior&);
		Warrior& operator=(const Warrior&);
			//Deallocate memory from list objects
		~Warrior();
	protected:
			//Return a copy with modified attribute values
		Warrior Defend();
		Warrior Counterattack();
		Warrior Run();
			//Functions for managing the object
		double Generate_Rand_Val(const int&);
		void Swap_Var(const Warrior&);
			//Make sure the attributes are within the correct range
		void Check();
	private:
		string __name;
		bool __alive;
		double
				//Successful hits per attempt
				//   measured as a ratio
			__accuracy,
				//Successful runs per attempt
				//   measured as a ratio
			__evasion_chance,
				//IQ
			__intelligence,
				//Measured in kilograms
			__mass,
				//Measured in meters
			__height,
				//Newtons(force) delivered per punch
				//   useful for actions involving thrusting arms
			__strength,
				//How many thrusts delivered per second
			__swiftness,
				//Energy reserve
				//   measured in Joules
			__stamina,
				//Stamina used up per hour
				//   measured in Joules/hour
			__hunger,
				//Maximum amount of time warrior can stay 
				//   awake before fainting
				//   equivalent to __stamina/__hunger
		//	__time_limit,
				//Measured in kilometers/hour
			__speed,
				//How much warrior can stand before being broken
				//   measured in ???
			__mental_fortitude,
				//The likeliness for others to follow this warrior
				//   measured as a ratio of persons per group of persons
			__amicability
		;
			//Only stores pointers to objects on the heap
			//   alternative: cow_ptr<T>
		list<Weapon*>
			__eqipppedw,
			__ownedw
		;
		list<Armour*>
			__equippeda,
			__owneda
		;
			//inventory of ammunitions for each type
			/**   "Ammunition_t" is a placeholder for an enum**/
		map<Ammunition_t,unsigned> __available_amm;
		Condition_t __condition;
			//Literal hit points; how many sharp blows a certain body part 
			//   can sustain before becoming a hinderance; for
			//   consistency, these will be measured in joules
		unsigned
		                  __head,
		                  __neck,
		 __left_shoulder, __chest, __right_shoulder,
		 __left_arm,     __stomach,     __right_arm, 
		 __left_hand,     __groin,     __right_hand,
		           __left_leg, __right_leg,
		           __left_foot, __right_foot
		;
};
	
#endif
