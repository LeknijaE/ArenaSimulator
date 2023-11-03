#pragma once
#include <vector>
#include <string>
#include "Player.h"



class Rounds
{
private:
	int e_Health, e_Damage, XP;
	std::string e_name;

public:

	Rounds();
	Rounds(std::string e_name, int e_hp, int e_xp);
	int getXP();
	int getEnemyHP();
	void setEnemyName(std::string enemy_name);
	int getEnemyDmg();
	int takePlayerDmg();
	std::string getEnemyName();
	bool enemyAlive();

	// Destructor
	~Rounds();


};