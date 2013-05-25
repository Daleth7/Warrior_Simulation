#include "Warriors.h"
	//All number literals should be assumed to be a guess 
	//   based on limited information
	//   There are placeholder names because they have not been defined
	//   in other classes/enums; these names will be marked
#include <list>
#include <cstdlib>
#include <string>
#include <initializer_list>
#include <vector>
#include <cstddef>

using std::list;
using std::string;
using std::initializer_list;
	//Global constants for use in multiple functions
const double
	__gravity(9.81),
	__average_bfat_ratio(0.15),
	__epsilon(1e-15)
;
const std::vector<string> setnames = {
	"Bobby Jones", "Billy the Kid", "Occam",
	"Yoda", "C#", "Parry Hotter", 
	"Lola Gitner", "Tammy Roan", "Tommy Dirsk", 
	"Michael Jackson", "Jack Finley", "Dudette",
	"Jill Jack", "Ben Doe", "Gregory Ferdinand",
	"Figman Srued", "Bobby Fischer", "Peekat Chyu",
	"@", "Red Rogue", "Googal Plex",
	"Hank J. Wimbleton", "Jebus H. Christ", "Tricky the Clown",
	"Sanford", "Deimos", "The Auditor",
	"Giblit", "Filiprei", "Daleth",
//Real names of former commanders around the WWII period because why the hell not
//  Country order is alphabetical to avoid bias
	//Order: Army / Air Force / Navy
	//Australia
	"General Thomas Blamey", "Marshal Peter Roy Maxwell Drummond", "Vice Admiral John Gregory Crace",
	//Burma, Switzerland, Ukraine - All army, no air force or naval commander's name available
	"Major General Aung San", "General Henri Guisan", "General Roman Shukhevych",
	//Canada - All army, no air force or naval commander's name available
	"General Harry Crerar", "Lieutenant General Guy Simmonds", "Lieutenant General Andrew McNaughton",
	//Czechoslovakia - All army, no air force or naval commander's name available
	"General Ludvik Svoboda", "Brigadier General Jan Golian", "Brigadier General Rudolf Pilfousek",
	//Finland - All army, no air force or naval commander's name available
	"Colonel Hjalmar Siilasvuo", "Lieutenant General Karl Lennart Oesch", "Marshal Carl Gustaf Emil Mannerheim",
	//France - Two Army, no air force commander's name available
	"Brigadier General Charles de Gaulle", "Marshal Jean de Lattre de Tassigny", "Admiral Francois Darlan",
	//Germany
	"Field Marshal Erwin Rommel", "Field Marshal Wolfram Freiherr von Richthofen", "Grand Admiral Karl Donitz",
	//Greece - Two army, no air force commander's name available
	"General Napoleon Zervas", "Colonel Stefanos Sarafis", "Vice Admiral Alexandros Sakellariou",
	//India - All army, no air force or naval commander's name available
	"Supreme Commander Subhas Chandra Bose", "Captain Lakshmi Sahgal", "Major Mohan Singh Deb",
	//Italy - Two army, no air force commander's name available
	"Marshal Pietro Badoglio", "Marshal Giovanni Messe", "Admiral Arturo Riccardi",
	//Japan - Two navy, no air force commander's name available
	"General Tomoyuki Yamashita", "Admiral Osami Nagano", "Admiral Chuichi Nagumo",
	//Netherlands - Two navy, no air force commander's name available
	"Lieutenant General Hein ter Poorten", "Rear Admiral Karel Doorman", "Vice Admiral Conrad Helfrich",
	//New Zealand - two air force, no naval commander's name available
	"Lieutenant General 1st Baron Bernard Freyberg", "Marshal Arthur Coningham", "Chief Marshal Keith Park",
	//Poland - All army, no air force or naval commander's name available
	"General Wlayslaw Sikorski", "Lieutenant General Tadeusz Bor-Komorowski", "Commander-in-Chief Edward Rydz-Smigly",
	//Republic of China - All army, no air force or naval commander's name available
	"General Yan Xishan", "General Chen Cheng", "General Xue Yue",
	//Romania - All army, no air force or naval commander's name available
	"Marshal Ion Antonescu", "General Petre Dumitrescu", "Division General Platon Chirnoaga",
	//Slovakia - All army, no air force or naval commander's name available
	"Major General Ferdinand Catlos", "General Rudolf Viest", "Brigadier General Jan Golian",
	//Soviet Union
	"General Nikolai Vatutin", "Chief Marshal Alexander Novikov", "Admiral Ivan Isakov",
	//Thailand - All army, no air force or naval commander's name available
	"Lieutenant General Prince Arthit Trip-apha", "General Luang Haansongkhram", "Major Khunnimmarnkolayut",
	//United Kingdom
	"Field Marshal Archibald Wavell", "Chief Marshal Arthur Harris", "Admiral Sir Alfred Pound",
	//United States
	"General George Smith Patton Jr.", "General Carl Spaatz", "Admiral Chester William Nimitz", 
	//Yugoslavia - All army, no air force or naval commander's name available
	"General Draza Mihajlovic", "Marshal Josip Broz Tito", "Commander Droboslav Jevdevic",
//+1 internet cookie if you get the references below
	"Red", "Green", "Blue"
};
const size_t name_num(setnames.size());
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
			toreturn = new Warrior(Attr_Template::Brainiac, newname);
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
void Warrior::Attack(Warrior& Target, int reaction){
	Warrior Tcopy;
	switch(reaction){
		case 1:	Tcopy = Target.Defend();        break;
		case 2:	Tcopy = Target.Counterattack(); break;
		case 3:	Tcopy = Target.Run();           break;
		default:	break;
	}
		//Calculate loss in attribute values
/*****************************************************************************************/
		//Check if the warrior is dead
	list<double> _Health_ = this->HealthStatus();
	for(auto iter = _Health_.begin(); iter != _Health_.end(); ++iter){
		if(*iter == 0)	__alive = false;
	}
	_Health_ = Tcopy.HealthStatus();
	for(auto iter = _Health_.begin(); iter != _Health_.end(); ++iter){
		if(*iter == 0)	Tcopy.__alive = false;
	}
		//Copy back changes
	Target = Tcopy;
}
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
list<double> HealthStatus()const{
	return {
		__head, __neck, __chest,
		__stomach, __groin, __left_shoulder,
		__right_shoulder, __left_arm, __right_arm,
		__left_hand, __right_hand, __left_leg,
		__right_leg, __left_foot, __right_foot
	};
};
string Warrior::Name()const{return __name;}
Condition_t Warrior::Status()const{return __condition;}

void Warrior::Equip(const Weapon* newwep, const Armor* newarm);
void Warrior::Equip_from_Inventory(Weapon_t choice);
void Warrior::Unequip();
void Warrior::Unequip(Weapon_t choice, Armor_t choice)
void Warrior::Store(const Weapon* newwep, const Armor* newarm);

Warrior Warrior::Temporary(list<double>& changes){
	Warrior catalyst = *this;
	changes.resize(catalyst.Attributes.size() + catalyst.HealthStatus().size());
	auto iter = changes.begin();
	__accuracy           += *iter;
		++iter;
	__evasion_chance     += *iter;
		++iter;
	__intelligence       += *iter;
		++iter;
	__mass               += *iter;
		++iter;
	__height             += *iter;
		++iter;
	__strength           += *iter;
		++iter;
	__swiftness          += *iter;
		++iter;
	__stamina            += *iter;
		++iter;
	__energy_consumption += *iter;
		++iter;
	__speed              += *iter;
		++iter;
	__mental_fortitude   += *iter;
		++iter;
	__amicability        += *iter;
		++iter;
	
	__head               += *iter;
		++iter;
	__neck               += *iter;
		++iter;
	__chest              += *iter;
		++iter;
	__stomach            += *iter;
		++iter;
	__groin              += *iter;
		++iter;
	__left_shoulder      += *iter;
		++iter;
	__right_shoulder     += *iter;
		++iter;
	__left_arm           += *iter;
		++iter;
	__right_arm          += *iter;
		++iter;
	__left_hand          += *iter;
		++iter;
	__right_hand         += *iter;
		++iter;
	__left_leg           += *iter;
		++iter;
	__right_leg          += *iter;
		++iter;
	__left_foot          += *iter;
		++iter;
	__right_foot         += *iter;
		
	Check();
}
void Warrior::SetCondition(Condition_t newcondition){
	if(__condition == newcondition)	return;
	__condition = newcondition;
		//Stage one: determine whether or not to make image
	switch(newcondition){
		case Condition_t::Healthy:	break;
		default:
			attr_copy = {
				__accuracy, __evasion_chance, __intelligence,
				__strength, __swiftness, __energy_consumption,
				__speed, __mental_fortitude, __amicability
			};
			break;
	}
		//Stage two: determine what values to change
	auto Multiply_Assign = 
		[](list<double*>::iterator var, double product){**var *= product;};
	switch(newcondition){
		case Condition_t::Cold:
			NonConstant_Transform(
				{&__accuracy, &__evasion_chance, &__intelligence,
				&__strength, &__swiftness, &__energy_consumption,
				&__speed, &__mental_fortitude, &__amicability},
				{0.5, 0.85, 0.95,
				0.75, 0.5, 1.2,
				0.75, 0.95, 0.5},
				Multiply_Assign
			);
/*			__accuracy         *= 0.5;
			__evasion_chance   *= 0.85;
			__intelligence     *= 0.95;
			__strength         *= 0.75;
			__swiftness        *= 0.5;
			__energy_consumption*= 1.2;
			__speed            *= 0.75;
			__mental_fortitude *= 0.95;
			__amicability      *= 0.5;
*/			break;
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
	alive(true), available(false),
	__Attr_list__({
		&__accuracy,  &__evasion_chance,   &__intelligence,
		&__mass,      &__height,           &__strength, 
		&__swiftness, &__stamina,          &__energy_consumption,
		&__speed,     &__mental_fortitude, &__amicability
	}),
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
	__alive(true), available(false),
	__Attr_list__({
		&__accuracy,  &__evasion_chance,   &__intelligence,
		&__mass,      &__height,           &__strength, 
		&__swiftness, &__stamina,          &__energy_consumption,
		&__speed,     &__mental_fortitude, &__amicability
	}),
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
	auto Assign = 
		[](list<double*>::iterator var,double newval){**var = newval;};
	switch(newattr){
		case Attr_Template::Strongman:
			Nonconstant_Transform(
				__Attr_list__,
				{max__accuracy*0.6, max__evasion_chance*0.4, max__intelligence/2,
				max__mass*8/15, max__height*0.6, max__strength*10/11,
				max__swiftness/4, max__stamina*2/3, max__energy_consumption*3/4,
				max__speed/5, max__mental_fortitude*2/3, max__amicability/3},
				Assign
			);
/*			__accuracy         = max__accuracy*0.6;
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
*/			break;
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
Warrior::Warrior(initializer_list<double>& newattr, const string& newname):
	__alive(true), available(false),
	__Attr_list__({
		&__accuracy,  &__evasion_chance,   &__intelligence,
		&__mass,      &__height,           &__strength, 
		&__swiftness, &__stamina,          &__energy_consumption,
		&__speed,     &__mental_fortitude, &__amicability
	}),
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
		//Copy attributes
	newattr.resize(this->Attributes().size());
	auto Assign = [](list<double*>::iterator var,double newval){**var = newval;};
	Nonconstant_Transform(__Attr_list__, newattr, Assign);
/*	auto iter = newattr.begin();
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
*/
	Check();
}
Warrior::Warrior(const Warrior& original):
	__Attr_list__({
		&__accuracy,  &__evasion_chance,   &__intelligence,
		&__mass,      &__height,           &__strength, 
		&__swiftness, &__stamina,          &__energy_consumption,
		&__speed,     &__mental_fortitude, &__amicability
	}),
{Swap_Var(original);}
Warrior& Warrior::operator=(const Warrior& original){
	if(this != &original)	Swap_Var(original);
	return *this;
}

Warrior::~Warrior(){}

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
	__melee              = original.__melee;
	__throwing           = original.__throwing;
	__ranged             = original.__ranged;
	available            = original.available;
	__ownedw             = original.__ownedw;
	__equippeda          = original.__equippeda;
	__owneda             = original.__owneda;
	__available_amm      = original.__available_amm;
	__condition          = orignal.__condition;
	attr_copy            = original.attr_copy;
	__head               = original.__head;
	__neck               = original.__neck;
	__chest              = original.__chest;
	__stomach            = original.__stomach;
	__groin              = original.__groin;
	__left_shoulder      = original.__left_shoulder;
	__right_shoulder     = original.__right_shoulder;
	__left_arm           = original.__left_arm;
	__right_arm          = original.__right_arm;
	__left_hand          = original.__left_hand;
	__right_hand         = original.__right_hand;
	__left_leg           = original.__left_leg;
	__right_leg          = original.__right_leg;
	__left_foot          = original.__left_foot;
	__right_foot         = original.__right_foot;
}
void Warrior::Check(){
		//Check if the attribute values are in the correct range
	auto Boundary_Checker = 
		[](list<double*>::iterator var, double maximum){
			if(**var > maximum - __epsilon)
				**var = maximum - 2*__epsilon;
			else if(**var < __epsilon)
				**var = 2*__epsilon;
		};
	Nonconstant_Transform(
		__Attr_list__,
		{max__accuracy, max__evasion_chance, max__intelligence,
		max__mass, max__height, max__strength,
		max__swiftness, max__stamina, max__energy_consumption,
		max__speed, max__mental_fortitude, max__amicability},
		Boundary_Checker
	);
/*	if(__accuracy         > max__accuracy-__epsilon)
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
*/		//Check for equipment
		//Fully capitalized words are placeholders
	if(
		(__ranged.TYPE == NONE && available^ranged_equipped) ||
		(__ranged.TYPE != NONE && available^ranged_equipped == 0)
	)	available ^= ranged_equipped;
	if(
		(__throwing.TYPE == NONE && available^throwing_equipped) ||
		(__throwing.TYPE != NONE && available^throwing_equipped == 0)
	)	available ^= throwing_equipped;
	if(
		(__melee.TYPE == NONE && available^melee_equipped) ||
		(__melee.TYPE != NONE && available^melee_equipped == 0)
	)	available ^= melee_equipped;
	if(
		(__equippeda[LEGS].TYPE == NONE && available^legs_equipped) ||
		(__equippeda[LEGS].TYPE != NONE && available^legs_equipped == 0)
	)	available ^= legs_equipped;
	if(
		(__equippeda[ARMS].TYPE == NONE && available^arms_equipped) ||
		(__equippeda[ARMS].TYPE != NONE && available^arms_equipped == 0)
	)	available ^= arms_equipped;
	if(
		(__equippeda[CHEST].TYPE == NONE && available^chest_equipped) ||
		(__equippeda[CHEST].TYPE != NONE && available^chest_equipped == 0)
	)	available ^= chest_equipped;
	if(
		(__equippeda[HEAD].TYPE == NONE && available^head_equipped) ||
		(__equippeda[HEAD].TYPE != NONE && available^head_equipped == 0)
	)	available ^= head_equipped;
}
inline void Nonconstant_Transform(
	list<double*>& variables,
	const list<double>& newvalues,
	void (*fptr)(list<double*>::iterator,double) 
){
	newvalues.resize(variables.size());
	auto iter = variables.begin();
	auto iter2 = newvalues.begin();
	//In case the issue arises:
	//   http://www.dreamincode.net/forums/topic/196133-inline-function-pointers/
	for(; iter != variables.end(); ++iter, ++iter2)
		(*fptr)(iter,*iter2);
}
/*****************End Member functions of the Warrior Class************/
