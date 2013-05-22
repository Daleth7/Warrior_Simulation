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
	//These are associated with certain,
	//   set attribute values
enum class W_Template{
	Strongman,
	Sharpeye,
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

class Warrior{
	public:
			//Action functions
			//int is for defend(1), counterattack(2), run(3),
			//   or nothing(0)
			//   -call respective defend/counterattack
			//   -swap change in stamina or alive variables
			//   between copy and original objects
		void Attack(Warrior&, int=0);
			//Return a copy with modified attribute values
		Warrior Defend();
		Warrior Counterattack();
		Warrior Run();
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
		void Equip(const Weapon*=nullptr, const Armor*=nullptr);
		void Equip_from_Inventory(Weapon_t=NONE);
		void Unequip();
		void Unequip(Weapon_t=NONE, Armor_t=NONE)
		void Store(const Weapon*=nullptr, const Armor*=nullptr);
			//Initializes attribute variables with
			//   random values and no equipment;
			//   Explicit to avoid implicit calls
		explicit Warrior();
		Warrior(W_Template,string);
			//Set attributes manually;
			//   order follows member double variables;
			//   0 will indicate attribute value to be 
			//   randomized
		Warrior(initializer_list<double>,string);
			//Deal with pointers
		Warrior(const Warrior&);
		Warrior& operator=(const Warrior&);
			//Deallocate memory from list objects
		~Warrior();
	protected:
		double Generate_Rand_Val(const int&);
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
				//Measured in meters/second
			__speed,
				//How much warrior can stand before being broken
				//   measured in ???
			__mental_fortitude
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
			//   "Ammunition_t" is a placeholder for an enum
		map<Ammunition_t,unsigned> __available_amm;
		Condition_t __condition;
};
	
#endif
