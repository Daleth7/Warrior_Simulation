// WarriorsSimulation.cpp : Defines the entry point for the console application.
//

#include "armor.h"
#include <windows.h>

void TestArmor(Armor & a,int n)
{
	cout << "\n\nArmor simulation\n\n";
	cout << "Damage done to head: " << a.armorDamaged(n, head) << endl;
	cout << "Damage done to chest: " << a.armorDamaged(n, chest) << endl;
	cout << "Damage done to arms: " << a.armorDamaged(n, arms) << endl;
	cout << "Damage done to legs: " << a.armorDamaged(n, legs) << endl;
}


int main()
{
	// useful notes:
	// enums: head, chest, arms, legs
	// constructor: Armor(int a[] (% avoided), int b[](durability), double w=0, int camo=0, string nm = "not specified")

	CraftArmor temporaryArmor = { 0, 15, 5, 5,
					  0, 15, 5, 10,
					  5.5, 25, 
					  "leather armor" };

	Armor leather(temporaryArmor);
	std::cout << (Armor() == false);
	
	cin.get();
	return 0;
}

