#ifndef WARRIORS_H
	#define WARRIORS_H
	
#include <list>
#include <map>
#include <string>

#include "Weapons.h"
#include "Armor.h"

using std::list;
using std::map;
using std::string;
	//Strongly typed because these should never 
	//   be compared with primitive types
	//   These are associated with certain,
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
		
			//Initializes attribute variables with
			//   a guess at the median and no
			//   equipment
			//   Explicit to avoid implicit calls
		explicit Warrior();
		Warrior(W_Template);
			//Set attributes manually
			//   order follows member double variables
		Warrior(
			double,double,double,double,
			double,double,double,double
		);
			//Deal with pointers
		Warrior(const Warrior&);
		Warrior& operator=(const Warrior&);
			//Deallocate memory from list objects
		~Warrior();
	private:
		string __name;
		bool __alive;
		double
				//Successful hits per attempt
				//   for simplicity measured as a ratio
			__accuracy,
				//IQ
			__intelligence,
				//Newtons(force) delivered per punch
				//   useful for actions involving thrusting arms
			__strength,
				//How many thrusts delivered per minute
			__swiftness,
				//Energy reserve
				//   for simplicity measured in Joules
			__stamina,
				//Stamina used up per hour
				//   for simplicity measured in Joules/hour
			__hunger,
				//Maximum amount of time warrior can stay 
				//   awake before fainting
				//   equivalent to __stamina/__hunger
		//  __time_limit,
				//Measured in meters/hour
			__speed,
				//???
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