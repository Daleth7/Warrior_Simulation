#include "Warriors.h"
	//All number literals should be assumed to be a guess 
	//   based on limited information
	//   There are placeholder names because they have not been defined
	//   in other classes/enums; these names will be marked
#include <list>
#include <cstdlib>
#include <string>
#include <initializer_list>

using std::list;
using std::string;
using std::initializer_list;
	//Global constants for use in multiple functions
const double
	__gravity(9.81),
	__average_bfat_ratio(0.15),
	__epsilon(1e-15)
;
const unsigned name_num(21);
const string setnames[name_num] = {
	"Bobby Jones", "Billy the Kid", "Occam",
	"Yoda", "C#", "Parry Hotter", 
	"Lola Gitner", "Tammy Roan", "Tommy Dirsk", 
	"Michael Jackson", "Jack Finley", "Dudette",
	"Jill Jack", "Ben Doe", "Gregory Ferdinand",
	"Figman Srued", "Bobby Fischer", "Peekat Chyu",
//+1 internet cookie if you get the references below
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
	max__energy_consumption(85),
	max__speed(15),
	max__mental_fortitude(100),
	max__amicability(1)
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
Warrior* CraftWarrior(W_Template base, const string& input){
	string newname = input;
	if(newname.empty())	newname = setnames[ rand()%name_num ];
		/**All of the Equip calls have placeholder names currently**/
	Warrior* toreturn=nullptr;
	switch(base){
		case W_Template::Knight:
			toreturn = new Warrior(Attr_Template::Strongman, newname);
			toreturn.Equip(Broadsword, Iron_Cuirass);
			break;
		case W_Template::Demolitionist:
			toreturn = new Warrior(Attr_Template::Strongman, newname);
			toreturn.Equip(C_4, Heavy_Vest);
			break;
		case W_Template::Medic:
			toreturn = new Warrior(Attr_Template::Athlete, newname);
			toreturn.Equip(First_Aid_Kit, Desert_Camoflague);
			break;
		case W_Template::Sniper:
			toreturn = new Warrior(Attr_Template::Sharpeye, newname);
			toreturn.Equip(Sniper_Rifle, Forest_Camoflague);
			toreturn.Store_Amm(Bullet,75);
			break;
		case W_Template::Rogue:
			toreturn = new Warrior(Attr_Template::Athlete, newname);
			toreturn.Equip(Knife, Loose_Cloth);
			break;
		case W_Template::Archer:
			toreturn = new Warrior(Attr_Template::Sharpeye, newname);
			toreturn.Equip(Short_Bow, Vest);
			toreturn.Store_Amm(Arrow, 25);
			break;
		default:	return new Warrior(newname);
	}
	return toreturn;
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
		__swiftness, __stamina, __energy_consumption,
		__speed, __mental_fortitude, __amicability
	};
}
string Warrior::Name()const{return __name;}
Condition_t Warrior::Status()const{return __condition;}

void Warrior::Equip(const Weapon* newwep, const Armor* newarm);
void Warrior::Equip_from_Inventory(Weapon_t choice);
void Warrior::Unequip();
void Warrior::Unequip(Weapon_t choice, Armor_t choice)
void Warrior::Store(const Weapon* newwep, const Armor* newarm);

Warrior Warrior::Temporary(const list<double>& changes){
	Warrior catalyst = *this;
	auto iter = changes.begin();
	if(iter == changes.end())	return;
	__accuracy         += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__evasion_chance   += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__intelligence     += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__mass             += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__height           += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__strength         += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__swiftness        += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__stamina          += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__energy_consumption           += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__speed            += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__mental_fortitude += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__amicability      += *iter;
		++iter;
	
	if(iter == changes.end()){	Check();	return;}
	__head           += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__neck           += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__chest          += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__stomach        += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__groin          += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__left_shoulder  += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__right_shoulder += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__left_arm       += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__right_arm      += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__left_hand      += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__right_hand     += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__left_leg       += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__right_leg      += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__left_foot      += *iter;
		++iter;
	if(iter == changes.end()){	Check();	return;}
	__right_foot     += *iter;
		
	Check();
}
void Warrior::SetCondition(Condition_t newcondition){
	if(__condition == newcondition)	return;
	__condition = newcondition;
		//Stage one: determine whether or not to make image
	switch(newcondition){
		case Condition_t::Cold:
		case Condition_t::Broken_Leg:
		case Condition_t::Burned:
		case Condition_t::Enraged:
			attr_copy = {
				__accuracy, __evasion_chance, __intelligence,
				__strength,
				__swiftness, __energy_consumption,
				__speed, __mental_fortitude, __amicability
			};
		default:	break;
	}
		//Stage two: determine what values to change
	switch(newcondition){
		case Condition_t::Cold:
			__accuracy         *= 0.5;
			__evasion_chance   *= 0.85;
			__intelligence     *= 0.95;
			__strength         *= 0.75;
			__swiftness        *= 0.5;
			__energy_consumption*= 1.2;
			__speed            *= 0.75;
			__mental_fortitude *= 0.95;
			__amicability      *= 0.5;
			break;
		case Condition_t::Broken_Leg:
			__accuracy         *= 0.75;
			__evasion_chance   *= 0.2;
			__intelligence     *= 1;
			__strength         *= 0.9;
			__swiftness        *= 0.9;
			__energy_consumption*= 0.65;
			__speed            *= 0.15;
			__mental_fortitude *= 0.75;
			__amicability      *= 0.95;
			break;
		case Condition_t::Burned:
			__accuracy         *= 0.4;
			__evasion_chance   *= 0.5;
			__intelligence     *= 0.9;
			__strength         *= 0.5;
			__swiftness        *= 0.45;
			__energy_consumption*= 1.1;
			__speed            *= 0.85;
			__mental_fortitude *= 0.5;
			__amicability      *= 0.7;
			break;
		case Condition_t::Enraged:
			__accuracy           *= 0.25;
			__evasion_chance     *= 1.5;
			__intelligence       *= 0.5;
			__strength           *= 1.5;
			__swiftness          *= 1.25;
			__energy_consumption *= 1.5;
			__speed              *= 1.25;
			__mental_fortitude   *= 0.35;
			__amicability        *= 0.1;
			break;
	/*....................................................*/
		default:
			auto iter = attr_copy.begin();
			__accuracy           = *iter;
			__evasion_chance     = *(++iter);
			__intelligence       = *(++iter);
			__strength           = *(++iter);
			__swiftness          = *(++iter);
			__energy_consumption = *(++iter);
			__speed              = *(++iter);
			__mental_fortitude   = *(++iter);
			__amicability        = *(++iter);
			attr_copy.clear();
			break;
	}
	Check();
}

Warrior::Warrior(const string& newname):
	alive(true), available_w(false), available_a(false),
	__head(15000),
	__neck(9000),
	__chest(30000),
	__stomach(22500),
	__groin(10000),
	__left_shoulder(17500),
	__right_shoulder(17500),
	__left_arm(13500),
	__right_arm(13500), 
	__left_hand(10000),
	__right_hand(10000),
	__left_leg(13500),
	__right_leg(13500),
	__left_foot(10000),
	__right_foot(10000)
{
		//Set name
	if(newname.empty())	__name = setnames[ rand()%15 ];
	else __name = newname;
	
		//Set attribute values
	__accuracy           = Generate_Rand_Val(max__accuracy);
	__evasion_chance     = Generate_Rand_Val(max__evasion_chance);
	__intelligence       = Generate_Rand_Val(max__intelligence);
	__mass               = Generate_Rand_Val(max__mass);
	__height             = Generate_Rand_Val(max__height);
	__strength           = Generate_Rand_Val(max__strength);
	__swiftness          = Generate_Rand_Val(max__swiftness);
	__stamina            = Generate_Rand_Val(max__stamina);
	__energy_consumption = Generate_Rand_Val(max__energy_consumption);
	__speed              = Generate_Rand_Val(max__speed);
	__mental_fortitude   = Generate_Rand_Val(max__mental_fortitude);
	__amicability        = Generate_Rand_Val(max__amicability);
}
Warrior::Warrior(Attr_Template newattr, const string& newname):
	__name(newname), __alive(true), available_w(false), available_a(false),
	__head(15000),
	__neck(9000),
	__chest(30000),
	__stomach(22500),
	__groin(10000),
	__left_shoulder(17500),
	__right_shoulder(17500),
	__left_arm(13500),
	__right_arm(13500), 
	__left_hand(10000),
	__right_hand(10000),
	__left_leg(13500),
	__right_leg(13500),
	__left_foot(10000),
	__right_foot(10000)
{
	switch(newattr){
		case Attr_Template::Strongman:
			__accuracy         = max__accuracy*0.6;
			__evasion_chance   = max__evasion_chance*0.4;
			__intelligence     = max__intelligence/2;
			__mass             = max__mass*8/15;
			__height           = max__height*0.6;
			__strength         = max__strength*10/11;
			__swiftness        = max__swiftness/4;
			__stamina          = max__stamina*2/3;
			__energy_consumption= max__energy_consumption*3/4;
			__speed            = max__speed/5;
			__mental_fortitude = max__mental_fortitude*2/3;
			__amicability      = max__amicability/3;
			break;
		case Attr_Template::Sharpeye:
			__accuracy         = max__accuracy*0.85;
			__evasion_chance   = max__evasion_chance*0.645;
			__intelligence     = max__intelligence*0.7;
			__mass             = max__mass*0.45;
			__height           = max__height*0.37;
			__strength         = max__strength*9/22;
			__swiftness        = max__swiftness/2;
			__stamina          = max__stamina*2/3;
			__energy_consumption= max__energy_consumption/2;
			__speed            = max__speed*0.9;
			__mental_fortitude = max__mental_fortitude/2;
			__amicability      = max__amicability/3;
			break;
		case Attr_Template::Obese:
			__accuracy         = max__accuracy*0.4;
			__evasion_chance   = max__evasion_chance*0.15;
			__intelligence     = max__intelligence*0.5;
			__mass             = max__mass*0.985;
			__height           = max__height*0.45;
			__strength         = max__strength*3/11;
			__swiftness        = max__swiftness/8;
			__stamina          = max__stamina/5;
			__energy_consumption= max__energy_consumption*0.9;
			__speed            = max__speed*0.2;
			__mental_fortitude = max__mental_fortitude/3;
			__amicability      = max__amicability/5;
			break;
		case Attr_Template::Athlete:
			__accuracy         = max__accuracy*0.6;
			__evasion_chance   = max__evasion_chance*0.64;
			__intelligence     = max__intelligence*0.6;
			__mass             = max__mass*0.55;
			__height           = max__height*0.6;
			__strength         = max__strength*0.725;
			__swiftness        = max__swiftness*3/4;
			__stamina          = max__stamina*0.6005;
			__energy_consumption= max__energy_consumption*0.8;
			__speed            = max__speed*0.75;
			__mental_fortitude = max__mental_fortitude/3;
			__amicability      = max__amicability/2;
			break;
		case Attr_Template::Brainiac:
			__accuracy         = max__accuracy*0.3;
			__evasion_chance   = max__evasion_chance*0.45;
			__intelligence     = max__intelligence*0.9;
			__mass             = max__mass*0.35;
			__height           = max__height*0.4;
			__strength         = max__strength*0.425;
			__swiftness        = max__swiftness*3/4;
			__stamina          = max__stamina*0.45;
			__energy_consumption= max__energy_consumption*0.8;
			__speed            = max__speed*0.8;
			__mental_fortitude = max__mental_fortitude/3;
			__amicability      = max__amicability/4;
			break;
		case Attr_Template::Amateur:
			__accuracy         = max__accuracy*0.5;
			__evasion_chance   = max__evasion_chance*0.5;
			__intelligence     = max__intelligence*0.5;
			__mass             = max__mass*0.5;
			__height           = max__height*0.5;
			__strength         = max__strength*0.5;
			__swiftness        = max__swiftness*0.5;
			__stamina          = max__stamina*0.5;
			__energy_consumption= max__energy_consumption*0.5;
			__speed            = max__speed*0.5;
			__mental_fortitude = max__mental_fortitude/2;
			__amicability      = max__amicability/2;
			break;
		case Attr_Template::Zen:
			__accuracy         = max__accuracy*0.875;
			__evasion_chance   = max__evasion_chance*0.75;
			__intelligence     = max__intelligence*0.55;
			__mass             = max__mass*0.525;
			__height           = max__height*0.65;
			__strength         = max__strength*0.65;
			__swiftness        = max__swiftness*3/4;
			__stamina          = max__stamina*0.875;
			__energy_consumption= max__energy_consumption*0.335;
			__speed            = max__speed*0.5;
			__mental_fortitude = max__mental_fortitude*0.865;
			__amicability      = max__amicability/2;
			break;
	/*.....................................................*/
		default:	Warrior();	break;
	}
}
Warrior::Warrior(const initializer_list<double>& newattr, const string& newname):
	__name(newname), __alive(true), available_w(false), available_a(false),
	__head(15000),
	__neck(9000),
	__chest(30000),
	__stomach(22500),
	__groin(10000),
	__left_shoulder(17500),
	__right_shoulder(17500),
	__left_arm(13500),
	__right_arm(13500), 
	__left_hand(10000),
	__right_hand(10000),
	__left_leg(13500),
	__right_leg(13500),
	__left_foot(10000),
	__right_foot(10000)
{
	auto iter = newattr.begin();
	__accuracy           = *iter;
	__evasion_chance     = *(++iter);
	__intelligence       = *(++iter);
	__mass               = *(++iter);
	__height             = *(++iter);
	__strength           = *(++iter);
	__swiftness          = *(++iter);
	__stamina            = *(++iter);
	__energy_consumption = *(++iter);
	__speed              = *(++iter);
	__mental_fortitude   = *(++iter);
	__amicability        = *(++iter);
	
	Check();
}
Warrior::Warrior(const Warrior& original){Swap_Var(original);}
Warrior& Warrior::operator=(const Warrior& original){
	if(this != &original)
		Swap_Var(original);
	return *this;
}

Warrior::~Warrior(){
		//These should be removed iff we use smart pointers
	delete __melee, delete __throwing, delete __ranged;
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
	__name               = original.__name;
	__alive              = original.__alive;
	__accuracy           = original.__accuracy;
	__evasion_chance     = original.__evasion_chance;
	__intelligence       = original.__intelligence;
	__mass               = original.__mass;
	__height             = original.__height;
	__strength           = original.__strength;
	__swiftness          = original.__swiftness;
	__stamina            = original.__stamina;
	__energy_consumption = original.__energy_consumption;
	__speed              = original.__speed;
	__mental_fortitude   = original.__mental_fortitude;
	__amicability        = original.__amicability;
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
	
	__head           = original.__head;
	__neck           = original.__neck;
	__chest          = original.__chest;
	__stomach        = original.__stomach;
	__groin          = original.__groin;
	__left_shoulder  = original.__left_shoulder;
	__right_shoulder = original.__right_shoulder;
	__left_arm       = original.__left_arm;
	__right_arm      = original.__right_arm;
	__left_hand      = original.__left_hand;
	__right_hand     = original.__right_hand;
	__left_leg       = original.__left_leg;
	__right_leg      = original.__right_leg;
	__left_foot      = original.__left_foot;
	__right_foot     = original.__right_foot;
}
void Warrior::Check(){
	if(__accuracy         > max__accuracy-__epsilon)
		__accuracy = max__accuracy-2*__epsilon;
	else if(__accuracy < __epsilon)
		__accuracy = 2*__epsilon;
	if(__evasion_chance   > max__evasion_chance-__epsilon)
		__evasion_chance = max__evasion_chance-2*__epsilon;
	else if(__evasion_chance < __epsilon)
		__evasion_chance = 2*__epsilon;
	if(__intelligence     > max__intelligence-__epsilon)
		__intelligence = max__intelligence-2*__epsilon;
	else if(__intelligence < __epsilon)
		__intelligence = 2*__epsilon;
	if(__mass             > max__mass-__epsilon)
		__mass = max__mass-2*__epsilon;
	else if(__mass < __epsilon)
		__mass = 2*__epsilon;
	if(__height           > max__height-__epsilon)
		__height = max__height-2*__epsilon;
	else if(__height < __epsilon)
		__height = 2*__epsilon;
	if(__strength         > max__strength-__epsilon)
		__strength = max__strength-2*__epsilon;
	else if(__strength < __epsilon)
		__strength = 2*__epsilon;
	if(__swiftness        > max__swiftness-__epsilon)
		__swiftness = max__swiftness-2*__epsilon;
	else if(__swiftness < __epsilon)
		__swiftness = 2*__epsilon;
	if(__stamina          > max__stamina-__epsilon)
		__stamina = max__stamina-2*__epsilon;
	else if(__stamina < __epsilon)
		__stamina = 2*__epsilon;
	if(__energy_consumption           > max__energy_consumption-__epsilon)
		__energy_consumption = max__energy_consumption-2*__epsilon;
	else if(__energy_consumption < __epsilon)
		__energy_consumption = 2*__epsilon;
	if(__speed            > max__speed-__epsilon)
		__speed = max__speed-2*__epsilon;
	else if(__speed < __epsilon)
		__speed = 2*__epsilon;
	if(__mental_fortitude > max__mental_fortitude-__epsilon)
		__mental_fortitude = max__mental_fortitude-2*__epsilon;
	else if(__mental_fortitude < __epsilon)
		__mental_fortitude = 2*__epsilon;
	if(__amicability      > max__amicability-__epsilon)
		__amicability = max__amicability-2*__epsilon;
	else if(__amicability < __epsilon)
		__amicability = 2*__epsilon;
	//Check if body part is dead********************************************
}
/*****************End Member functions of the Warrior Class************/
