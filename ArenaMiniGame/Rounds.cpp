#include "Rounds.h"
#include "Player.h"
#include <iostream>
using namespace std;
using std::string;
using std::to_string;

Rounds::Rounds() : e_name{ " " }, e_Health { 5 }, e_Damage{ 5 }, XP{ 10 }
{

}

Rounds::Rounds(string name, int e_hp, int e_dmg, int e_xp)
{
	e_name = name;
	e_Health = e_hp;
	e_Damage = e_dmg;
	XP = e_xp;
}

// Return Current Enemy Name
string Rounds::getEnemyName()
{
	return e_name;
}

// Return Enemy Health Points
int Rounds::getEnemyHP()
{
	return e_Health;
}

// Return XP Amount from Enemy
int Rounds::getXP()
{
	return XP;
}


void Rounds::setEnemyName(std::string enemy_name)
{
	e_name = enemy_name;
}

// Get Enemy Attack Damage Points
int Rounds::getEnemyDmg()
{
	return e_Damage;
}

// Check to see if Enemy is alive
bool Rounds::enemyAlive()
{
	if (e_Health != 0)
	{
		cout << e_name << "'s current health points is at : " << e_Health << "." << "\n";
		return true;
	}
	return false;

}

// Take damage from Player & Return Health
int Rounds::takePlayerDmg(int damage)
{
	e_Health -= damage;
	return e_Health;
}

int Rounds::atkPlayer()
{
	Player p;

	Rounds::getEnemyDmg();

	return p.getHealth();
}

bool Rounds::enemyDefeat()
{
	if (Rounds::enemyAlive() == false)
	{
		return true;
	}
	else
		return false;
}

Rounds::~Rounds()
{
	if (e_Health == 0)
	{
		// Deconstructor called before Enemy Attack
		
	}
	
}