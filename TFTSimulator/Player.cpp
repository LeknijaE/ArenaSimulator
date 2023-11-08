
#include "Player.h"
#include "Rounds.h"
#include <iostream>
using std::vector;
using std::string;
using std::to_string;

// Player Starting Life Points & Attack Damage
Player::Player() : p_Health{ 100 }, p_Damage{ 5 }, p_Xp{ 0 }
{

}

Player::Player(string name, int p_hp, int p_dmg, int p_xp, int p_Enr)
{
	p_name = name;
	p_Damage = p_dmg;
	p_Health = p_hp;
	p_Energy = p_Enr;
	p_Xp = p_xp;
}

// Return Player's Current Health Points
int Player::getHealth()
{
	return p_Health;
}

// Return Player's Attack Damage Points
int Player::getAtk()
{
	return p_Damage;

}

// Return Player's Current Energy Points
int Player::getEnergy()
{
	return p_Energy;
	cout << "Current Energy: " << p_Energy << "." << "\n";
}


// Check if player is still alive
bool Player::playerAlive()
{
	if (p_Health != 0)
	{
		cout << "=============================" << endl;
		cout << p_name << "'s Current Health Points: " << p_Health << ". " << endl;

		return true;
	}
	return false;
}

// Check if Player defeated enemy
bool Player::defeatEnemy()
{
	Rounds r;
	if (r.enemyAlive() == false)
	{
		return true;
	}

	p_Xp = p_Xp + r.getXP();
	return false;
}

// Allow Player to choose attack method
char Player::atkChoice()
{
	Rounds r;

	char atk;

	cout << "\n" << "=============================" << endl;
	cout << "Choose your attack : " << endl; 
	cout << "=============================" << endl;
	cout << "Q - Slash" << endl;
	cout << "W - Heal" << endl;
	cout << "E - Amplify / Buff Your Next Attack" << endl;
	cout << "R - Ultimate" << endl;
	cout << "=============================" << endl;
	cin >> atk;

	switch (atk)
	{
	case 'q': case 'Q':
	{
		Player::getAtk();
		Player::getEnergy();

		cout << p_name + " hit " << r.getEnemyName() << " for " << p_Damage << " Hit Points!" << "\n";
		cout << "=========================" << "\n";

		r.takePlayerDmg();

		break;
	}
	case 'w': case 'W':
	{
		const int heal = 10;
		p_Health = p_Health + heal;

		cout << p_name + " Healed up and their health is now " << p_Health << endl;
		cout << "=========================" << "\n";

		break;
	}
	case 'e' : case 'E':
	{
		Player::buffDamage();
		Player::getAtk();

		cout << p_name + " has amplified their next attack!" << endl;
		cout << p_name + " damage is now " << p_Damage + ". " << "\n";

		cout << "=========================" << "\n";

		break;
	}
	case 'r' : case 'R':
	{
		if (p_Energy != 4 || p_Energy <= 0)
		{
			cout << "Not enough Energy." << "\n";
			cout << "=========================" << "\n";
		}
		else

		p_Damage = 20;
		p_Energy = p_Energy - 4;
		cout << p_name + " has unleashed their ultimate attack, damaging " << r.getEnemyName() << " for " << p_Damage << ". " << "\n";
		cout << "=========================" << "\n";

		break;
	}
	default:
		cout << "Incorrect selection, try again" << endl;
		cin >> atk;
	}

	return atk;
}

// Call during attack (Q)
int Player::gainEnergy()
{
	int obtainEnergy = 1;
	p_Energy = p_Energy + obtainEnergy;
	return p_Energy;
	
}

// Check how much damage player took & Return Current Health
int Player::takeDamage()
{
	Rounds r;
	p_Health = p_Health - r.getEnemyDmg();
	cout << r.getEnemyName() + " attacks for " << r.getEnemyDmg() << " leaving you with " << p_Health << " Health points." << endl;
	return p_Health;
}

// Increase Player Damage (for Limited Turns)
int Player::buffDamage()
{
	if (p_Damage <= 5)
	{
		const int buff = 3;
		p_Damage = p_Damage + buff;
	}
	return p_Damage;
}

Player::~Player()
{
	if (p_Health == 0)
	{
		std::cout << "You died, try again." << endl;
	}
}