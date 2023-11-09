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
	Rounds(std::string e_name, int e_hp, int e_dmg, int e_xp);

	// Setters
	void setEnemyName(std::string enemy_name);

	// Getters
	int getXP();
	int getEnemyHP();
	std::string getEnemyName();
	int getEnemyDmg();


	int takePlayerDmg();
	int atkPlayer();

	bool enemyDefeat();
	
	// Status Check
	bool enemyAlive();

	// Destructor
	~Rounds();


};