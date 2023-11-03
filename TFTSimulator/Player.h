#pragma once
#include <vector>
#include <string>
#include "Rounds.h"
using namespace std;


class Player
{
private:
	
	int p_Health, p_Damage, p_Xp;
	std::string p_name;

public:
	
	Player();
	Player(string name, int p_hp, int p_dmg, int p_xp);

	bool playerAlive();
	bool defeatEnemy();
	int atkChoice(char atk);
	int getHealth();
	int getAtk();
	int takeDamage();
	int buffDamage();


};

