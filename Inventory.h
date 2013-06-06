#ifndef INVENTORY_H
#define INVENTORY_H

#include "Weapons.h"
#include "Armor.h"

#include <vector>
#include <map>
#include <unordered_map>

class Inventory{
	using std::vector;
	using std::map;
	using std::unordered_map;
	public:
			//Checks for melee first
		Weapon EquippedWeapon()const;
		Weapon EquippedThrowing()const;
		const vector<Armor> EquippedArmor()const;
		const vector<Weapon>& WeaponInventory()const;
		const vector<Armor>& ArmorInventory()const;
			//Inventory functions
			//   Returns whether the operation was successful
			/**Using "Weapon_t" and "Armor_T" as a 
			//   placeholder for enums because I cannot
			//   figure out how to implement choices without
			//   one**/
		bool Equip(const Weapon& =NONE, const Armor& =NONE);
		bool Equip_from_Inventory(Weapon_t=NONE,Armour_t=NONE);
		void Unequip(); //No return because always successful
		bool Unequip(Weapon_t=NONE, Armor_t=NONE)
		bool Store(const Weapon& =NONE, const Armor& =NONE);
			/***Ammunition_t is a current placeholder***/
		bool Store_Amm(Ammunition_t,unsigned);
			//Boolean test functions
		bool MeleeEquipped();
		bool ThrowingEquipped();
		bool RangedEquipped();
			//Member access functions
		unsigned Get_Damage();
		unsigned Get_Defense(ARMOUR_T);
	private:
			//Equipped
		Weapon
			__melee,
			__throwing,
			__ranged
		;
			/***Armour_t is a placeholder**/
		unordered_map<Armour_t, Armor> __equippeda
			//Bitarray to determine which slots are open
		unsigned short notavailable;
		static enum available_bit_flags->unsigned short{
			ranged_equipped = 1,
			throwing_equipped = 1<<1,
			melee_equipped = 1<<2,
			
			legs_equipped = 1<<8,
			arms_equipped = 1<<9,
			chest_equipped = 1<<10,
			head_equipped = 1<<11
		};
			//Inventory
		vector<Weapon> __ownedw;
		vector<Armor> __owneda;
			//inventory of ammunitions for each type
			/**   "Ammunition_t" is a placeholder for an enum**/
		map<Ammunition_t,unsigned> __available_amm;
};

#endif