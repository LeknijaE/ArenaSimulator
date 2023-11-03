
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

// Check if player is still alive
bool Player::playerAlive()
{
	if (p_Health >= 0)
	{
		return true;
	}

	std::cout << "You died, try again." << endl;
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
int Player::atkChoice(char atk)
{
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

		break;
	}
	case 'w': case 'W':
	{
		const int heal = 10;
		p_Health = p_Health + heal;
		break;
	}
	case 'e' : case 'E':
	{
		int b = 10;
		p_Damage = ++b;
		break;
	}
	case 'r' : case 'R':
	{
		p_Damage = 20;
		break;
	}
	default:
		cout << "Incorrect selection, try again" << endl;
		cin >> atk;
	}

	return atk;
}


int Player::takeDamage()
{
	Rounds r;
	p_Health = p_Health - r.getEnemyDmg();
	return p_Health;
}
