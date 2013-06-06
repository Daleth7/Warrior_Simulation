/** To-do
	-party class
	-Consider implementing consumable items in storage
**/
//There are placeholder names because they have not been defined
//   in other classes/enums; these names will be marked
#ifndef WARRIORS_H
#define WARRIORS_H
	
#include <vector>
#include <array>
#include <string>
#include <initializer_list>

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
	Martial_Artist,
	/*...*/
	None
};
	//These are associated with certain, set attribute values
enum class Attr_Template{
	Strongman,
	Sharpeye,
	Obese,
	Athlete,
	Brainiac,
	Amateur,
	Zen,
	Quickster,
	/*...*/
	None
};
	//These are associated with certain attribute drops
enum class Condition_t{
	Cold,
	Broken_Leg,
	Burned,
	Enraged,
	Drunk,
	/*...*/
	Healthy
};
	//Prototype Warrior, so the associated non-member functions
	//   can be shown before the class
class Warrior;
class Inventory;
	//Test if two warriors have the same attributes and name
bool operator==(const Warrior&,const Warrior&);
	//Base warrior on a template and return a new object on the heap
Warrior* CraftWarrior(W_Template, const string&="");

class Warrior{
	static constexpr size_t __num_of_attr(12);
	using std::vector;
	using std::array;
	using std::string;
	using std::initializer_list;
	public:
			//Inventory
		Inventory* __inventory;
			//Action functions
			//int is for the target's reaction:
			//   defend(1), counterattack(2), run(3),
			//   or nothing(0)
		void Attack(Warrior&, int=0);
			//Read-only functions
		bool Alive()const;
		array<double,__num_of_attr> Attributes()const;
		vector<double> HealthStatus()const;
		string Name()const;
		Condition_t Status()const;
			//In the event that the warrior's attributes are temporarily changed;
			//Takes in a set of changes and adds those changes to the returned
			//   Warrior object
		Warrior Temporary(array<double>&);
		void SetCondition(Condition_t);
			//Initializes attribute variables with
			//   random values and no equipment;
			//   Explicit to avoid implicit calls
		explicit Warrior(const string&="");
		Warrior(Attr_Template,const string&="");
			//Set attributes manually;
			//   order follows member double variables;
			//   0 will indicate attribute value to be 
			//   randomized
		Warrior(initializer_list<double>&,const string&="");
			//Deal with pointers
		Warrior(const Warrior&);
		Warrior& operator=(const Warrior&);
			//Deallocate memory from list objects
		~Warrior();
	protected:
		//Action functions called by Attack()
			//Return a copy with modified attribute values
		Warrior Defend();
		Warrior Counterattack();
		Warrior Run();
		//Functions for managing the class
		double Generate_Rand_Val(const int&);
		void Swap_Var(const Warrior&);
			//Make sure the attributes are within the correct range
		void Check();
		//Inline auxillary functions
		void Nonconstant_Transform(
			array<double*>&,              //List of variables to change
			array<double>&,               //Values used in change
			void (*fptr)(array<double*,__num_of_attr>::iterator,double) //Function that makes changes
		);
	private:
		string __name;
		bool __alive;
		double
				//Successful hits per attempt
				//   measured as a ratio - Successes:attempt
			__accuracy,
				//Successful runs per attempt
				//   measured as a ratio - Successes:attempt
			__evasion_chance,
				//IQ
			__intelligence,
				//Measured in kilograms
			__mass,
				//Measured in meters
			__height,
				//Newtons(force) delivered per "burst"
			__strength,
				//How many "bursts" delivered per second
			__swiftness,
				//Energy reserve measured in Joules
			__stamina,
				//Stamina used up per hour
				//   measured in Joules/hour
			__energy_consumption,
				//Maximum amount of time warrior can stay 
				//   awake before fainting
				//   equivalent to __stamina/__energy_consumption
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
			//Points to above attributes for ease of modification
		const array<double*,__num_of_attr> __Attr_list__;
		Condition_t __condition;
			//Hold a temporary image of past attribute values
		array<double,__num_of_attr> attr_copy;
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
