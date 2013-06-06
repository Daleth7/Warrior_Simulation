#include "Inventory.h"

using std::vector;
using std::map;
using std::unordered_map;

Weapon Inventory::EquippedWeapon()const{
	if(notavailable & Inventory::melee_equipped)	return __melee;
	if(notavailable & Inventory::ranged_equipped)	return __ranged;
}
Weapon Inventory::EquippedThrowing()const{return __throwing;}
const vector<Armor> EquippedArmor()const{return __equippeda;}
const vector<Weapon>& Inventory::WeaponInventory()const{return __ownedw;}
const vector<Armor>& Inventory::ArmorInventory()const{return __owneda;}
	/**Lots of placeholders in these inventory functions**/
bool Inventory::Equip(const Weapon& newwep, const Armor& newarm){
	bool toreturn(false);
	switch(newwep.GETTYPE()){
		case MELEE:
			if(notavailable & Inventory::melee_equipped){
				notavailable ^= Inventory::melee_equipped;
				__melee = newwep;
			}else __ownedw.push_back(newwep);
			toreturn = true;
			break;
		case THROWING:
			if(notavailable & Inventory::throwing_equipped){
				notavailable ^= Inventory::throwing_equipped;
				__throwing = newwep;
			}else __ownedw.push_back(newwep);
			toreturn = true;
			break;
		case RANGED:
			if(notavailable & Inventory::ranged_equipped){
				notavailable ^= Inventory::ranged_equipped;
				__ranged = newwep;
			}else __ownedw.push_back(newwep);
			__available_amm += newwep.GETDEFAULTAMM();
			toreturn = true;
			break;
		default:	break;
	}
	switch(newarm.GETTYPE()){
		case HEAD:
			if(notavailable & Inventory::head_equipped){
				notavailable ^= Inventory::head_equipped;
				__equippeda[HEAD] = newarm;
			}else __owneda.push_back(newarm);
			toreturn = true;
			break;
		case CHEST:
			if(notavailable & Inventory::chest_equipped){
				notavailable ^= Inventory::chest_equipped;
				__equippeda[CHEST] = newarm;
			}else __owneda.push_back(newarm);
			toreturn = true;
			break;
		case ARMS:
			if(notavailable & Inventory::arms_equipped){
				notavailable ^= Inventory::arms_equipped;
				__equippeda[ARMS] = newarm;
			}else __owneda.push_back(newarm);
			toreturn = true;
			break;
		case LEGS:
			if(notavailable & Inventory::legs_equipped){
				notavailable ^= Inventory::legs_equipped;
				__equippeda[LEGS] = newarm;
			}else __owneda.push_back(newarm);
			toreturn = true;
			break;
		default:	break;
	}
	return toreturn;
}
bool Inventory::Equip_from_Inventory(Weapon_t choice_w, Armor_t choice_a){
	Weapon newwep;
	for(auto iter = __ownedw.begin();; ++iter){
		if(iter == __ownedw.end())	return false;
		if(iter->GETTYPE() == choice_w){
			newwep = *iter;
			__owned.erase(iter);
			break;
		}
	}
	switch(choice_w){
		case MELEE:
			if(notavailable & Inventory::melee_equipped)
				__ownedw.push_back(__melee);
			__melee = newwep;
			break;
		case THROWING:
			if(notavailable & Inventory::throwing_equipped)
				__ownedw.push_back(__throwing);
			__throwing = newwep;
			break;
		case RANGED:
			if(notavailable & Inventory::ranged_equipped)
				__ownedw.push_back(__ranged);
			__ranged = newwep;
			break;
		default:	break;
	}
	Armor newarm;
	for(auto iter = __owneda.begin();; ++iter){
		if(iter == __owneda.end())	return false;
		if(iter->GETTYPE() == choice_a){
			newarm = *iter;
			__owned.erase(iter);
			break;
		}
	}
	switch(choice_a){
		case HEAD:
			if(notavailable & Inventory::head_equipped)
				__owneda.push_back(__equipped[choice_a]);
			break;
		case CHEST:
			if(notavailable & Inventory::chest_equipped)
				__owneda.push_back(__equipped[choice_a]);
			break;
		case ARMS:
			if(notavailable & Inventory::arms_equipped)
				__owneda.push_back(__equipped[choice_a]);
			break;
		case LEGS:
			if(notavailable & Inventory::legs_equipped)
				__owneda.push_back(__equipped[choice_a]);
			break;
		default:	break;
	}
	__equippeda[choice_a] = newarm;
}
void Inventory::Unequip(){
	if(notavailable & Inventory::melee_equipped){
		__ownedw.push_back(__melee);
		NULLIFY(__melee);
	}
	if(notavailable & Inventory::throwing_equipped){
		__ownedw.push_back(__throwing);
		NULLIFY(__throwing);
	}
	if(notavailable & Inventory::ranged_equipped){
		__ownedw.push_back(__ranged);
		NULLIFY(__ranged);
	}
	if(notavailable & Inventory::head_equipped){
		__owneda.push_back(__equippeda[HEAD]);
		NULLIFY(__equippeda[HEAD]);
	}
	if(notavailable & Inventory::chest_equipped){
		__owneda.push_back(__equippeda[CHEST]);
		NULLIFY(__equippeda[CHEST]);
	}
	if(notavailable & Inventory::arms_equipped){
		__owneda.push_back(__equippeda[ARMS]);
		NULLIFY(__equippeda[ARMS]);
	}
	if(notavailable & Inventory::legs_equipped){
		__owneda.push_back(__equippeda[LEGS]);
		NULLIFY(__equippeda[LEGS]);
	}
	notavailable = 0;
}
bool Inventory::Unequip(Weapon_t choice_w, Armor_t choice_a){
	bool toreturn(false);
	auto FinalCheck = [&](Weapon& this_eqp, list<Weapon>& inv, Inventory::available_bit_flags bflag){
			if(notavailable & bflag){
				inv.push_back(this_eqp);
				NULLIFY(this_eqp);
				notavailable ^= bflag;
				toreturn = true;
			}
		};
	switch(choice_w.GETTYPE()){
		case MELEE:
			(*FinalCheck)(__melee,__ownedw,Inventory::melee_equipped);
			break;
		case THROWING:
			(*FinalCheck)(__throwing,__ownedw,Inventory::throwing_equipped);
			break;
		case RANGED:
			(*FinalCheck)(__ranged,__ownedw,Inventory::ranged_equipped);
			break;
		default:	break;
	}
	FinalCheck = [&](Armor& this_eqp, list<Armor>& inv, Inventory::available_bit_flags bflag){
			if(notavailable & bflag){
				inv.push_back(this_eqp);
				Null(this_eqp);
				notavailable ^= bflag;
				toreturn = true;
			}
		};
	switch(choice_a.GETTYPE()){
		case HEAD:
			(*FinalCheck)(__equippeda[HEAD],__owneda,Inventory::head_equipped);
			break;
		case CHEST:
			(*FinalCheck)(__equippeda[CHEST],__owneda,Inventory::chest_equipped);
			break;
		case ARMS:
			(*FinalCheck)(__equippeda[ARMS],__owneda,Inventory::arms_equipped);
			break;
		case LEGS:
			(*FinalCheck)(__equippeda[LEGS],__owneda,Inventory::legs_equipped);
			break;
		default:	break;
	}
	return toreturn;
}
bool Inventory::Store(const Weapon& newwep, const Armor& newarm){
	bool toreturn(false);
	if(newwep.GETTYPE() != NONE){
		__ownedw.push_back(newwep);
		toreturn = true;
	}
	if(newarm.GETTYPE() != NONE){
		__owneda.push_back(newarm);
		toreturn = true;
	}
	return toreturn;
}
void Inventory::Store_Amm(Ammunition_t newammo, unsigned newammount)
{__available_amm[newammo] += newammount;}
//Boolean test functions
bool Inventory::MeleeEquipped()
{return (notavailable & Inventory::melee_equipped)>0;}
bool Inventory::ThrowingEquipped()
{return (notavailable & Inventory::throwing_equipped)>0;}
bool Inventory::RangedEquipped()
{return (notavailable & Inventory::ranged_equipped)>0;}
//Member access functions
unsigned Inventory::Get_Damage(){
	unsigned toreturn;
	if(
		notavailable & Inventory::melee_equipped || 
		notavailable & Inventory::throwing_equipped
	) toreturn = __melee.GETDAMAGE()+__throwing.GETDAMAGE();
	else if(notavailable & Inventory::ranged_equipped){
	//Make sure there is enough ammunition
		if(__available_amm[__ranged.GETAMMOTYPE()] < __ranged.GETAMMOUSAGE()){
			toreturn = __available_amm[__ranged.GETAMMOTYPE()];
			__available_amm[__ranged.GETAMMOTYPE()] = 0;
		}else if(__available_amm[__ranged.GETAMMOTYPE()] > 0){
			__available_amm -= __ranged.GETAMMOUSAGE();
			toreturn = __ranged.GETDAMAGE();
		}
	}
	return toreturn;
}
unsigned Inventory::Get_Defense(ARMOUR_T atype){return __equippeda[atype];}