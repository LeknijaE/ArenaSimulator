#pragma once
#include <vector>
#include <string>
#include "Rounds.h"
using namespace std;


class Player
{
private:
	
	int p_Health, p_Damage, p_Xp;

public:
	
	Player();

	bool playerAlive();
	bool defeatEnemy();
	int atkChoice(char atk);
	int getHealth();
	int getAtk();
	int takeDamage();


};

