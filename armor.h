#ifndef ARMOR_H_
#define ARMOR_H_

#include <iostream>
#include <string>
using namespace std;
enum armor { head, chest, arms, legs };

struct CraftArmor {
	int AVOIDED[4];
	int DURABILITY[4];
	double WEIGHT;
	int CAMO;
	string NAME;
};

class Armor
{
private:
	int defenseRating; // calculated after the other variables are
	                   // entered.
	double weight; // in kg
	int camouflage; // % from 0 - 100
	int armorPieces[4]; // how many % does the pieces protect
	int armorDurability[4]; // hp of each individual part
	                        // 100 is the best possible normal humans
	                        // will use. (a robot suit would be more)
	string name;
public:
	Armor(const CraftArmor & armor)
	{
		for(int i = 0; i < 4; i++)
			armorPieces[i] = armor.AVOIDED[i];
		for(int i = 0; i < 4; i++)
			armorDurability[i] = armor.DURABILITY[i];
		weight = armor.WEIGHT;
		camouflage = armor.CAMO;
		name = armor.NAME;
	}

	Armor(int a[], int b[], double w=0, int camo=0, string nm = "not specified")
	{
		for(int i = 0; i < 4; i++)
			armorPieces[i] = a[i];
		for(int i = 0; i < 4; i++)
			armorDurability[i] = b[i];
		weight = w;
		camouflage = camo;
		name = nm;
	}
	Armor() // no armor
	{
		int a[4] = { 0 };
		int b[4] = { 0 };
		double w=0;
		int camo=0;

		for(int i = 0; i < 4; i++)
			armorPieces[i] = a[i];
		for(int i = 0; i < 4; i++)
			armorDurability[i] = b[i];
		weight = w;
		camouflage = camo;
		name = "no armor";
	}

	Armor(bool manual)
	{
		cout << "What is the name of the armor?\nname: ";
		cin >> name;

		cout << "How heavy is the armor? (kilograms)\nweight: "; 
		cin >> weight;

		cout << "How good is the camouflage? 0% no camo, 100% invisible\ncamo: "; 
		cin >> camouflage;

		string pieces[4] = { "head", "chest", "arms", "legs" };
		cout << "What is the % of damage avoided each attack\n"
			<<  "and how good is the durability of the armor?\n";
		for(int i = 0; i < 4; i++)
		{
			cout << "avoided, " << pieces[i] << ": ";
			cin >> armorPieces[i];
			cout << "durability, " << pieces[i] << ": ";
			cin >> armorDurability[i];
		}

	}

	void updateDefenseRating() // this is an average of the pieces 
		                     // of armor. Its only use will be get
							 // the overall defense.
	{
		defenseRating = 0;
		if(noDefenseLeft())
			defenseRating = 0;
		else
		{
			for(int i = 0; i < 4; i++)
				defenseRating += armorPieces[i];
			for(int i = 0; i < 4; i++)
				defenseRating += armorDurability[i];
			defenseRating += camouflage;
			defenseRating /= 9; // find the overall average!
		}
	}

	void showDefenseRating()
	{
		updateDefenseRating();
		cout << "Defense rating of the warrior: " << defenseRating
		     << endl;
	}

	int returnDefenseRating() { return defenseRating; }

	void updateArmor()
	{
		updateDefenseRating();
		if(armorDurability[head] == 0 && armorDurability[chest] == 0
			&& armorDurability[arms] == 0 && armorDurability[legs] == 0) 
		{ weight = 0; camouflage = 0; updateDefenseRating(); } // armor is destroyed
	}

	int armorDamaged(int attackDamage, int part)
	{
		int damageAvoided = 0;
		if(armorDurability[part] > 0 && armorPieces[part] > 0)
		{
			damageAvoided += attackDamage * float(armorPieces[part])/100.0;
			armorDurability[part] -= damageAvoided;
			// the design could be better, the % of damage blocked doesn't decrease as 
			// the armor gets damaged. This is not that important to have now
			// and can be added in the future.
		}

		if(0 <= attackDamage - damageAvoided) // returns the attack damage left after 
			                                 // damage avoided is subtracted.
			return attackDamage - damageAvoided;
		else
			return 0;
	}

	void Show()
	{
		updateArmor();
		cout << "Name: " << name << endl;
		cout << "Defense rating: " << defenseRating << endl;
		cout << "Weight: " << weight << endl << endl;
		if(!noDefenseLeft())
		{
			cout << "(percent of damage avoided, durability):\n"; // head, chest, arms, legs
			cout << "Head: (" <<  armorPieces[head] << ", " << armorDurability[head] << ")\n";
			cout << "Chest: (" <<  armorPieces[chest] << ", " << armorDurability[chest] << ")\n";
			cout << "Arms: (" <<  armorPieces[arms] << ", " << armorDurability[arms] << ")\n";
			cout << "Legs: (" <<  armorPieces[legs] << ", " << armorDurability[legs] << ")\n";
		}
		else
			cout << "No armor\n";
	}

	bool noDefenseLeft()
	{
		return (armorDurability[head] == 0 && armorDurability[chest]  == 0
			&& armorDurability[arms] == 0 && armorDurability[legs] == 0);
	}

	bool operator==(bool x)
	{
		if(noDefenseLeft() == true)
		{
			return (x == false);
		}
		else
			return (x == true);
	}

	friend bool operator==(bool x, Armor a)
	{
		return (a == x);
	}
};

#endif